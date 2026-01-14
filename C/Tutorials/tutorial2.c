# include <stdio.h>
# include <math.h>
# include <stdlib.h>

#define TOL 0.0001
double x = 1.;
double xp = 0.; // x previous 
double a;
double root;


void run_tutorial_2() {
	printf("Enter a number: ");
	scanf_s("%lf", &a);
	printf("Enter root: ");
	scanf_s("%lf", &root);

	while (fabs(x - xp) > TOL) {
		xp = x; // increment x
		x = (1 / root) * ((root - 1) * xp + a / pow(xp, root - 1)); // using the current x
	}
	printf("x: %f", x);
}



