#define _CRT_SECURE_NO_WARNINGS true 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define CLEN 4
#define COLS 6


int game_round;
int correct;
int misplaced;
void run_game();
void generate_sequence();
int sequence[4];
int in_seq[4];
int rounds;
bool check_color();


void run_tutorial_3() {
	int peg[CLEN], ch[CLEN];
	rounds = 0;
	int seq[CLEN];

	printf("\nMastermind\n");
	srand(time(NULL)); // the time(NULL) is the seed. it will generate the same random value for the same seed

	generate_sequence();
	run_game();
}

void run_game() {
	int i;
	correct = 0;
	while (correct < CLEN) {
		misplaced = 0;
		correct = 0;
		printf("round %d: ", rounds);
		scanf("%d %d %d %d", &in_seq[0], &in_seq[1], &in_seq[2], &in_seq[3]);


		for (i = 0; i < CLEN; i++) {
			int y;
			if (sequence[i] == in_seq[i]) {
				correct += 1;
			}
			else {
				for (y = 0; y < CLEN; y++) {
					if (sequence[i] == in_seq[y] && i != y) {
						misplaced++;
					}
				}
			}
		}

		rounds = rounds + 1;

		printf("Correct: %d\tMisplaced: %d\n\n", correct, misplaced);
	}
}

void generate_sequence() {
	int size = sizeof(sequence) / sizeof(int);
	int random_color;

	int i;
	for (i = 0; i < size; i++) {
		random_color = generate_color();
		while (!check_color(random_color)) {
			random_color = generate_color();
		}
		sequence[i] = random_color;
	}
}

bool check_color(int color) {
	int i;
	for (i = 0; i < sizeof(sequence) / sizeof(int); i++) {
		if (sequence[i] == color) {
			return false;
		}
	}
	return true;
}

int generate_color() {
	return rand() % 5;
}
