#include <stdio.h>
#include <math.h>
#include <stdbool.h> // allows us to use boolean values

#define MS          1000.     /* rocket weight in kg   */
#define FUEL_INI    5000.     /* initial fuel in kg    */
#define H_INI     100000.     /* initial altitude in m */
#define STEP          10.     /* update on thrust      */ 
#define g            1.62     /* planet gravity */
#define vg       (g*STEP)
#define VR            400.    /* exit velocity         */

void run_lab_2() {

	double h = H_INI;        /* altitude in m  */
	double t = 0.;           /* time in seconds, update period is 10s */
	double vk = 0.;          /* velocity in m/s */
	double fuel = FUEL_INI;  /* remaining fuel in kg  */
	double mt;               /* mass of fuel + rocket */
	double mk;               /* fuel used at time t   */
	char input[4];			 /* stores input in a char array of length 4 */

	printf("\n\nPlanet Landing\n\n");
	printf("-----------------------------------\n");
	printf("Initial fuel: %.0lf kg\n", FUEL_INI);
	printf("Rocket weight: %.0lf kg\n", MS);
	printf("Initial altitutde %.0lf m\n", H_INI);
	printf("Planet gravity: %lf m/s2\n", g);
	printf("===================================\n");

	printf("\nGood luck.\n\n");
	printf("time  altitude[m] fuel[kg]  speed[m/s] \n");
	while (h > 0 && fuel > 0) {
		printf("%4.0lf %9.0lf %8.0lf %10.02lf", t, h, fuel, vk);
		printf("\tburn[kg]: ");
		scanf("%s", &input);

		while (!isValidNum(input)) {
			printf("\nInvalid input!\n");
			printf("burn[kg]: ");
			scanf("%s", &input);
		}

		while (atof(input) > fuel) {
			printf("\nDesired fuel to burn exceeds remaining fuel!\n");
			printf("burn[kg]: ");
			scanf("%s", &input);
		}

		mk = atof(input);


		/* update */
		mt = fuel + MS; // total weight 
		h += vk * STEP;
		vk += -vg + mk / mt * VR; // -vg: velocity due to gravity in timestep 
		fuel -= mk; // correct, how much fuel is left after the burst 
		t += STEP; // correct
	}

	if (h > 0) {
		/* free fall */
		printf("Fuel ends at %.0lf m\n", h);
		vk = fabs(vk) + sqrt(vk * vk + 2 * g * h);
	}

	printf("Impact velocity: %.02lf\n", vk);
	if (abs(vk) > 10.) {
		printf("Mission failed\n");
	}
	else {
		if (abs(vk) > 5.) {
			printf("Rough landing, vehicle damaged\n");
		}
		else {
			printf("Perfect landing\n");
		}
	}
}


static int isValidNum(char *input) {
	if (strlen(input) == 0) {
		return 0;
	} 
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] < '0' || input[i] > '9') {
			return 0;
		}
	}
	return 1;
}
