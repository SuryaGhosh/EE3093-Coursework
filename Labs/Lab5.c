#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define BUFFER 50 // buffer for string read


typedef struct entry {
	char word[BUFFER]; // holds data of current element
	struct entry* next; // is pointing to the next element in the list
} entry;

static void insert(char* word, struct entry** head); // the static keyword scopes the function/variable to the file
static void read_data(struct entry** head);
static void match_word(struct entry* head);
static char* file_path = "C:\\Users\\surya\\OneDrive\\Documents\\UoA\\Courses\\2025-26\\Fall Semester\\EE3093\\C\\Labs\\words.txt";
static int total_words = 0;


void run_lab_5() {
	entry *head = NULL; // creates head ptr

	read_data(&head); // read_data updates head list
	match_word(head); // sends head by value, so it doesn't get changed 
}

static void read_data(struct entry** head) {
	FILE* fp = fopen(file_path, "r");
	if (fp == NULL) {
		printf("File not found! Exiting.\n");
		return;
	}
	printf("File found!\n\n");
	char word[BUFFER]; // buffer

	while (fscanf(fp, "%49s", word) != EOF) {
		total_words++;
		insert(word, head);
	}
	printf("Number of words loaded: %d\n", total_words);
}

static void insert(char* word, struct entry** head) {
	// insert the word into the struct head

	entry *p = (entry*)malloc(sizeof(entry));

	// p->word = word; Error: we cannot assign strings this way, they are arrays!
	// strncpy(char* destination, char* source, int digits)

	strncpy(p->word, word, BUFFER); //copies word into the entry node
	p->next = *head; // the next node points to the head node 

	*head = p; // the head node gets updated to p
}

static void match_word(struct entry* head) {
	int comparisons = 0;
	char word [50];
	
	printf("Enter phrase to match (no spaces): ");
	scanf("%49s", word); // we need to leave a bit for \n
	word[49] = '\n';

	printf("\nWords matching '%s': \n", word);
	//printf("head: %s", head->next->next->next->word);

	// determines word length, used to specify strcmp. this length calculation is correct
	int i = 0;
	while (word[i] != '\0') {
		i++;
	}
	
	while (head != NULL) {
		comparisons++;
		// strncmp (char* destination, char* source, int n)
		// compares n letters. returns 0 if they are the same, a positive num if destination is greater, or negative if source is
		if (strncmp(word, head->word, i) == 0) {
			printf("%s\n", head->word);
		}
		
		head = head->next; // increments head to the next node
	}
}