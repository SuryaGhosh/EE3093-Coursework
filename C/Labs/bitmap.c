#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "bitmap.h"


/*  color map */
/*  uint32_t = GG BB 00 RR */
const uint32_t cmap[] = 
{ 0x00000000, /* black  */
  0x000000FF, /* red    */
  0x00FF0000, /* blue   */
  0xFF000000, /* green  */
  0xFFFF0000, /* cyan   */
  0xFF0000FF, /* yellow */
  0x00FF00FF, /* purple */
  0xC0C000FF  /* pink   */
};


/* Write 32 Litte Endian */
uint32_t write32le(uint32_t x)
{
	const uint32_t test = 0x00000001;
	if (*(uint8_t*)&test) return x;
	return x<<24 | x>>24 |
		   (0x00FF0000 & x)<<8 |
		   (0x0000FF00 & x)<<8;
}

/* Write 16 Litte Endian */
uint16_t write16le(uint16_t x)
{
	const uint16_t test = 0x0001;
	if (*(uint8_t*)&test) return x;
	return x<<8 | x>>8;
}

struct {
	uint32_t img_size;
	uint32_t rsvd;
	uint32_t img_offs;
	uint32_t hdr_size;
	uint32_t width, height;
	uint16_t planes;
	uint16_t depth;
	uint32_t unused[6];
} header;

void save_bitmap(canvas* cp, char* filename)
{
uint32_t w = cp->width, h = cp->height;
FILE* fp = fopen(filename, "wb");
uint16_t signature;
int i;

	/* init bmp header */	
	signature       = write16le(0x4d42);
	header.img_size = write32le(54 + 4*w*h);
	header.img_offs = write32le(54);
	header.hdr_size = write32le(40);
	header.width    = write32le(w);
	header.height   = write32le(h);
	header.planes   = write32le(1);
	header.depth    = write32le(32);

	fwrite(&signature, 1, 2, fp);  // write signature
    fwrite(&header, 1, 54, fp);    // write header    
    fwrite(cp->map, w*h, 4, fp);   // write map

    fclose(fp);
}

canvas* make_canvas()
{
canvas* cp;

	cp = (canvas*)malloc(sizeof(canvas));
	cp->map = (uint32_t*)malloc(WIDTH*HEIGHT*4);
	cp->width = WIDTH;
	cp->height = HEIGHT;
	memset(cp->map, 0xFF, WIDTH*HEIGHT*4);
	
	return cp;
}

void draw_point(canvas* cp, point p, int col)
{
	if (0<=p.x && p.x<(int)cp->width && 
		0<=p.y && p.y<(int)cp->height)
		cp->map[p.x + p.y*cp->width] = write32le(cmap[col]);
}

/* Bresenham's algorithm */
void draw_line(canvas* cp, point p0, point p1, int col)
{
point w = p0;
int dx, dy, p, q1, q2;
int sgn = 1, fx, fy, sx, sy, qx, qy;

	dx = p1.x - p0.x;
	if (dx<0) {
		/* p0 always left point */
		w = p1; p1 = p0; p0 = w;
		dx = -dx;
	}
	
	dy = p1.y - p0.y;
	if (dy<0) {
		dy = -dy;
		sgn = -1;
	}
 
 	if (dx>dy) {
 		p = 2*dy-dx;
		while(w.x <= p1.x) {
			draw_point(cp, w, col);
			if(p>=0) {
				w.y += sgn;
				p -= 2*dx;
			}
			w.x++;
			p += 2*dy;
		}
	} else {
 		p = 2*dx-dy;
		while(w.y-p0.y <= dy && w.y-p0.y>=-dy) {
			draw_point(cp, w, col);
			if(p>=0) {
				w.x++;
				p -= 2*dy;
			}
			w.y+=sgn;
			p += 2*dx;
		}
	}
		
}


