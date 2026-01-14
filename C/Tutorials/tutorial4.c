#define _CRT_SECURE_NO_WARNINGS true
#include <stdlib.h>
#include <stdio.h> 

#define NUM_LETTERS 26

// struct to hold letter and its quantity
typedef struct letter {
	char character;
	int quantity;
} letter;

// holds all of the letters and their quantities; this allocates memory for the array 
letter letters[26];

// keeps track of total letters read
int total_letters = 0;

// file path 
char* file_path = "C:\\Users\\surya\\OneDrive\\Documents\\UoA\\Courses\\2025-26\\Fall Semester\\EE3093\\C\\Tutorials\\shakespeare.txt";

// function prototypes
void read_txt(char* file_path);
void init_array(letter letters[NUM_LETTERS], int size);
void bubble_sort();

void run_tutorial_4() {
	init_array(letters, NUM_LETTERS);
	read_txt(file_path);
	bubble_sort();
}

void bubble_sort() {
	for (int i = 0; i < NUM_LETTERS; i++) {
		for (int j = 0; j < i - 1; j++) {
			// index 0 holds the letter with highest quantity
			// we compare the current letter with the next letter
			// if it is smaller, then we swap them
			// ie if we start at index 0, then it should have the highest quantity

			if (letters[j].quantity < letters[j + 1].quantity) {
				letter temp_letter = letters[j];
				letters[j] = letters[j + 1];
				letters[j + 1] = temp_letter;
			}
		}
	}


	int n;
	for (n = 0; n < NUM_LETTERS; n++) {
		printf("%c - %5.2f%%\n", letters[n].character, 100*(letters[n].quantity)/(double)total_letters); // we need to cast at least one operand to double as they are both int
	}
}

void read_txt(char* file_path) {
	FILE* fp; // file handler 
	char c;
	fp = fopen(file_path, "r"); // if we are trying to write to a file and it doesn't exist, then it will be created
								// for any type of reading operation, if the file doesn't exist, then fopen will return NULL
	if (fp == NULL) {
		printf("File not found\n");
		return;
	}

	while (fscanf(fp, "%c", &c) != EOF) {
		if ('a' <= c && c <= 'z') {
			letters[c-'a'].quantity++;
			total_letters++;
		}
	}
	return;
}

void init_array(letter letters[NUM_LETTERS], int size) { // letter letters[26] is valid syntax, but it decays to a pointer: letter *letters
	for (int i = 0; i < size; i++) { // make sure the condition is correct
		letters[i].character = 97 + i; // ASCII for 'a': 97
		letters[i].quantity = 0;
	}
	return;
}