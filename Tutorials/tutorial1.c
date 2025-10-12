// Tutorial 1 C 
// 9/25

// allows the use of scanf
#define _CRT_SECURE_NO_WARNINGS true 

#include <stdio.h>
#include <math.h>

int run_tutorial_1() {
	int x, base;
	int x_mod;
	int index = 0;


	printf("Base conversion\n");
	printf("Input x: ");
	scanf("%d", &x);
	printf("Input base: ");
	scanf("%d", &base);

	while (x > 0) {
		x_mod = x % base;
		printf("%d", x_mod);
		x = x / base;
		index++;
	}
}
/*
int main() {
	int x, base;
	int x_mod;
	int index = 0;


	printf("Base conversion\n");	
	printf("Input x: ");
	scanf("%d", &x);
	printf("Input base: ");
	scanf("%d", &base);

	for (int i=0; i=i+1; 10) {

	}
	
	while (x > 0) {
		x_mod = x % base;
		printf("%d", x_mod);
		x = x / base;
		index++;
	}
}*/