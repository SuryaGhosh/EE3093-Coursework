#include "tutorial6.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

typedef struct pairs {
	int* pin;
	int s;
	int* reversed;
} pairs;

static double findmin(double* v, int size);
static void findmin2(double v[], int size, double* pmin);
static void reverse(int* v, int size);
static void print_double(double* v, int size);
static void print_int(int* v, int size);
static int* concat(int* v1, int s1, int* v2, int s2);
static int* clip(int vin[10], int min, int max, int* res);	
static void reverse2(struct pairs* par);

void run_tutorial_6() {
	double v[5] = { 7.2, -2.5, 0.0, 4.8, 9 };
	int vr[4] = { 4, 5, 10, 3 };
	int v1[3] = { 3, 1, -9 };
	int v2[2] = { 4, 7 };
	int v4[10] = { 7, 2, 3, 0, 5, 6, 7, -1, 4, 6 };
	double v_min = findmin(v, 5);
	double pmin;

	printf("\nQ1: Min value: %f", v_min);
	
	findmin2(v, 5, &pmin);
	printf("\n\nQ2: Min value (pmin): %f", pmin);

	printf("\n\nQ3: Reversing");
	reverse(vr, 4);
	print_int(vr, 4);

	printf("\n\nQ4: Concatenating");
	int* v3 = concat(v1, 3, v2, 2);
	print_int(v3, 5);

	printf("\n\nQ5: Clip");
	int* res = NULL;
	res = clip(v4, 3, 6, res);
	print_int(res, 4);
	
	printf("\n\nQ6: Reverse 2");
	pairs* p1 = (pairs*)malloc(sizeof(pairs));
	int arr[5] = {3, 1, -9, 4, 7};
	p1->pin = arr;
	p1->s = 5;
	reverse2(p1);
	print_int(p1->reversed, 5);

} 

static double findmin(double* v, int size) {
	if (size > 0) {
		double curr_min = DBL_MAX;

		for (int i = 0; i < size; i++) {
			if (v[i] < curr_min) {
				curr_min = v[i];
			}
		}
		return curr_min;
	}
	printf("Array size must be bigger than 0!");
	return 0;
}

static void findmin2(double v[], int size, double* pmin) {
	*pmin = DBL_MAX;

	for (int i = 0; i < size; i++) {
		if (v[i] < *pmin) {
			*pmin = v[i];
		}
	}
	return;
}

static void reverse(int* v, int size) {
	int temp = 0;

	for (int i = 0; i < size/2; i++) {
		temp = v[size-i-1];
		v[size-i-1] = v[i];
		v[i] = temp;
	}
	return;
}

static void print_double(double* v, int size) {
	for (int i = 0; i < size; i++) {
		printf("\nElem [%d] = %f", i, v[i]);
	}
}

static void print_int(int* v, int size) {
	for (int i = 0; i < size; i++) {
		printf("\nElem [%d] = %d", i, v[i]);
	}
	
	return;
}

static int* concat(int* v1, int s1, int* v2, int s2) {
	int x = 3;
	int* r = (int*)malloc(sizeof(int) * (s1+s2));

	// concatenate v2 to v1 
	for (int i = 0; i < s1 + s2; i++) {
		if ((0 <= i) && (i < s1)) {
			r[i] = v1[i];
		} 
		// this is not equivalent: s1 <= i < s1+s2 and (s1 <= i) && (i < s1+s2)
		// this expression is parsed left to right, so s1 <= i < s1+s2 is actually interpreted as: (s1<=i) < s1+s2
		else if ((s1 <= i) && (i < s1+s2)) { 
			r[i] = v2[i-s1];
		}
	}
	return r;
}

static int* clip(int vin[10], int min, int max, int* res) {
	// removes all nodes outside of the node range [min, max]

	res = (int*)malloc(sizeof(int) * (max - min + 1));

	for (int i = 0; i < 10; i++) {
		if ((i >= min) && (i <= max)) {
			res[i - min] = vin[i];
		}
	}
	
	return res;
}

static void reverse2(struct pairs* par) {
	// reverse pin of size s
	// store it in reversed 

	par->reversed = (int*)(malloc(sizeof(int) * par->s));

	for (int i = 0; i < par->s; i++) {
		par->reversed[i] = par->pin[(par->s)-i-1];
	}
}