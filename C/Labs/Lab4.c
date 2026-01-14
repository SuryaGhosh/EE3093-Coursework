#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define NUM_FLIGHTS 20
#define DESTINATION_LEN 8
#define FLIGHT_CODE_LEN 5

typedef struct {
	char destination[DESTINATION_LEN];
	char code[FLIGHT_CODE_LEN];
	int hour;
	int minute;
} flight;

flight flights[20];
void read_data();
void sort_data();
void print_range();
char* file_path = "C:\\Users\\surya\\OneDrive\\Documents\\UoA\\Courses\\2025-26\\Fall Semester\\EE3093\\C\\Labs\\departures.txt";

void run_lab_4() {
	read_data();
	sort_data();
	print_range();
}

void read_data() {
	FILE* fp;
	fp = fopen(file_path, "r");

	if (fp == NULL) {
		printf("File not found! Exiting.\n");
		return;
	}
	printf("File found!\n\n");

	char c;
	flight flight;
	int flight_num = 0;

	while (flight_num < NUM_FLIGHTS && fscanf(fp, "%s %s %d %d", &flights[flight_num].destination, &flights[flight_num].code, &flights[flight_num].hour, &flights[flight_num].minute)) {
		flight_num++;
	}

	fclose(fp);
}

void sort_data() {
	flight temp_flight;
	for (int i = 0; i < NUM_FLIGHTS; i++) {
		// each pass places the next earliest flight at the front
		for (int j = 0; j < NUM_FLIGHTS - i - 1; j++) {
			// checks if current flight is later than the next flight
			if (flights[j].hour > flights[j + 1].hour || 
				(flights[j].hour == flights[j + 1].hour && flights[j].minute > flights[j + 1].minute)) {
				// swaps flights, the earlier flight comes first 
				temp_flight = flights[j];
				flights[j] = flights[j + 1];
				flights[j + 1] = temp_flight;
			} 
		}
	}
}

void print_range() {
	int start_hour, end_hour;

	printf("Enter start hour: ");
	scanf("%d", &start_hour);
	printf("Enter end hour: ");
	scanf("%d", &end_hour);

	while (start_hour > end_hour || start_hour > 23 || start_hour < 0 || end_hour > 23 || end_hour < 0) {
		printf("\nInvalid range! Please try again.\n");
		printf("Enter start hour: ");
		scanf("%d", &start_hour);
		printf("Enter end hour: ");
		scanf("%d", &end_hour);
	}

	printf("Departures between %d:00 and %d:59\n\n", start_hour, end_hour);
	for (int i = 0; i <= NUM_FLIGHTS; i++) {
		if (flights[i].hour >= start_hour && flights[i].hour <= end_hour) {
			if (flights[i].minute < 10) {
				printf("%-8s %5s %2d:0%1d\n", flights[i].destination, flights[i].code, flights[i].hour, flights[i].minute);
			}
			else {
				printf("%-8s %5s %2d:%2d\n", flights[i].destination, flights[i].code, flights[i].hour, flights[i].minute);

			}
		}
	}
}

