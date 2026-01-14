#ifndef _bitmap_h
#define _bitmap_h

#include <stdint.h>

/* canvas size */
#define WIDTH 640
#define HEIGHT 400 

/* colors */
#define BLACK   0
#define RED     1
#define BLUE    2
#define GREEN   3
#define CYAN    4
#define YELLOW  5
#define PURPLE  6
#define PINK    7

/* geometrical entities */
/* provides a matrix 32bit per pixel */
typedef struct {
	uint32_t* map;
	uint32_t width, height; 
} canvas;


/* point integer coordinates */
typedef struct point {
	int x, y;
} point;


/* return a pointer to a new canvas */
canvas* make_canvas();

/* draw the point p with color col on canvas */
void draw_point(canvas* cp, point p, int col);

/* draw a line between p0 and p1 on canvas */
void draw_line(canvas* cp, point p0, point p1, int col);


/* save canvas into the bitmap file filename */
void save_bitmap(canvas* cp, char* filename);

#endif  /* bitmap.h */

