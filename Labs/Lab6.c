#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"

#define BLACK 0
#define RED 1
#define BLUE 2
#define GREEN 3
#define CYAN 4
#define YELLOW 5
#define PURPLE 6
#define PINK 7

typedef struct coord {
	int x, y;
} coord;

typedef struct shape {
	coord* s_pvec;  // list of points dictating shape structure 
	int s_len;	    // number of points in the shape
	int s_closed;   // 1: closed, 0: not closed
	int s_color;	// the s_ prefix distinguishes that it is in a struct 
	struct shape* s_next;
} shape;


void run_lab_6() {
		
}

void rectangle(coord p1, coord p2, shape** slist, int color) {
	coord* pvec = (coord*)(malloc(sizeof(coord) * 4)); //allocates memory for 4 vertices 

	// p1 and p2 are opposite corners 
	coord p3 = {p1.x, p2.y};
	coord p4 = {p1.y, p2.x};

	pvec[1] = p1;
	pvec[2] = p2;
	pvec[3] = p3;
	pvec[4] = p4;

	shape* new_shape = (shape*)(malloc(sizeof(shape)));
	new_shape->s_pvec = pvec;
	new_shape->s_closed = 1;
	new_shape->s_color = color;
	new_shape->s_next = *slist;

	*slist = new_shape;

}

