#include <stdio.h>
#include <math.h>
#include <windows.h> // needed for the sleep function

#define PLAYER_TURN    0
#define COMPUTER_TURN  1
#define PLAYER_WINS    2
#define COMPUTER_WINS  3

// this must be declared before any instances of it can be created 
typedef struct {
	int heap;
	int coins;
} Move;

int num_heaps;
int game_round;
int game_state;
int heaps[5]; // we must create the max number of possible heaps, since my C version doesn't allow for variable length arrays 
void run_game();
void initialize_game();
void print_heaps();
void update_state();
int is_valid_num(char* input);
int is_valid_turn(char* a, char* b);
int get_board_sum();
Move getCompMove();
Move playerMove();
char input_s[4]; 

void run_lab_3() {
	initialize_game();
	run_game();
}

void run_game() {
	Move playerMove;
	char heap;
	char coins;

	while (1) {
		if (game_state == PLAYER_WINS) {
			printf("\n------------------------------");
			printf("\nYou won!!! You are smarter than a 5th grader!\n\n");
			break;
		}
		if (game_state == COMPUTER_WINS) {
			printf("\n------------------------------");
			printf("\nYou lost :,( You're not going to survive the AI uprising.\n\n");
			break;
		}

		print_heaps();
		//printf("\nGame State: %d", game_state);
		if (game_state == PLAYER_TURN) {
			do {
				// when input is read by scanf, it exits when enter is pressed, so '\n' is left sitting on the buffer. 
				// this is immediately parsed by fgets and therefore stops reading other input
				// we can clear this '\n' character by pulling bits from the stack until we don't encounter '\n'
				//getchar();
				printf("\n\nYour Turn (heap coins): ");
				//fgets(input_s, 4, stdin); // reads 4 bits from the buffer stdin
				scanf("%c %c", &heap, &coins);
				//printf("_%c_  _%c_", heap, coins);
				while ((getchar()) != '\n');
			} while (!is_valid_turn(heap, coins));

			playerMove.heap = heap;
			playerMove.coins = coins; 
			//printf("\nValid: ");
			//printf("%c %c", playerMove.heap, playerMove.coins);
			int heapi = playerMove.heap - '0';
			int coinsi = playerMove.coins - '0';

			heaps[heapi] = heaps[heapi] - coinsi;
			// check if player won, switch state
		}
		else if (game_state == COMPUTER_TURN) {
			printf("\n\nComputer Turn\nThinking");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			printf("\n");

			Move comp_move = getCompMove();
			heaps[comp_move.heap] = heaps[comp_move.heap] - comp_move.coins;
			// check if computer won, switch state
		}
		update_state();
	}
}

void update_state() {
	//printf("\nsum: %d game_state: %d", get_board_sum(), game_state);
	if (game_state == PLAYER_TURN && get_board_sum() == 0) {
		game_state = PLAYER_WINS;
	}
	else if (game_state == COMPUTER_TURN && get_board_sum() == 0) {
		game_state = COMPUTER_WINS;
	}
	else if (game_state == PLAYER_TURN) {
		game_state = COMPUTER_TURN;
	}
	else {
		game_state = PLAYER_TURN;
	}
}

void print_heaps() {
	int i;
	int j;
	for (i=0; i<num_heaps; i=i+1) {
		printf("\nheap[%d]: ", i);
		for (j=0; j<heaps[i]; j=j+1) {
			printf("o");
		}
	}
}

void initialize_game() {
	game_round = 0;
	game_state = PLAYER_TURN;

	printf("\n------------- Nim ------------");
	printf("\nHow many heaps [2-5]? ");
	scanf("%s", &input_s);

	// validates that num_heaps is within range and an integer 
	while (!is_valid_num(input_s) || (num_heaps > 5) || (num_heaps < 2)) {
		if (!is_valid_num(input_s)) {
			printf("\nInvalid input!");
			printf("\nHow many heaps [2-5]? ");
			scanf("%s", &input_s);
			while ((getchar()) != '\n');
		}
		else {
			num_heaps = atof(input_s);
			if ((num_heaps > 5) || (num_heaps < 2)) {
				printf("\nInvalid number of heaps!");
				printf("\nHow many heaps [2-5]? ");
				scanf("%s", &input_s);
			}
		}
	}
	getchar(); // removes \n from buffer

	// initializes board 
	int i;
	for (i=0; i<num_heaps; i=i+1) {
		heaps[i] = 1 + 2 * i;
	}
}

// the static keyword makes functions private, so it doesn't interfere with functions with the same name in other files 
static int is_valid_num(char* input) {
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

// checks if selected heap/coin combination is possible 
static int is_valid_turn(char* heap, char* coins) { 

	// 1: valid
	// 0: invalid
	
	// is the heap a valid heap
	// does the heap have enough coins 
	// turn[0] : heap
	// turn[1] : space
	// turn[2] : coins
	// turn[4] : space

	int heap_int = heap - '0';
	int coin_int = coins - '0';

	if (heap_int > num_heaps) {
		printf("\nInvalid input, heap (%d) out of bounds.", heap_int);
		return 0;
	} 
	/*if (turn[1] != ' '  || (turn[3] != ' ' && turn[3] != '\n')) {
		printf("\nInvalid input, spacing is incorrect.");
		return 0;
	}*/
	if (coin_int > heaps[heap_int]) {
		printf("\nInvalid input, too many coins (%d) entered.", coin_int);
		return 0;
	} 
	if (coin_int == 0) {
		printf("\nInvalid input, must enter more than 1 coin!", coin_int);
		return 0;
	}
	return 1;
}


// the function getCompMove() returns the struct Move, which contains 2 ints
Move getCompMove() {
	// logic to determine the best move 
	Move computer_m;
	computer_m.heap = 0;
	computer_m.coins = 0;

	// XOR sum of zero indicates a losing postion
	// we want to play this move so that the next turn will result in an xor sum of zero 
	// last player to take a coin wins

	int current_sum = get_board_sum();
	int i;
	int j;

	// tries to calculate a winning move 
	for (i = num_heaps-1; i >= 0; i = i - 1) {
		if (heaps[i] != 0){
			for (j = heaps[i]; j > 0; j = j - 1) {
				if ((current_sum - j) % 2 == 0) {
					printf("\nMove found: heap: %d coins: %d", i, j);
					computer_m.heap = i;
					computer_m.coins = j;
					return computer_m;
				}
			}
		}
	}
	// calculates first possible move if no winning moves are possible 
	printf("\nNo winning move found. Trying to find possible move.");
	printf("\nThinking harder");
	Sleep(250);
	printf(".");
	Sleep(250);
	printf(".");
	Sleep(250);
	printf(".");
	Sleep(250);
	printf(".");
	Sleep(250);
	printf(".");
	Sleep(250);
	printf(".");
	Sleep(250);
	printf(".");
	printf("\n");
	for (i = 0; i < num_heaps; i = i + 1) {
		if (heaps[i] > 0) { 
			computer_m.heap = i;
			computer_m.coins = heaps[i];
			printf("\nPossible move found, heap: %d coins: %d\n", computer_m.heap, computer_m.coins);
			return computer_m;
		}
	}
	printf("\nNo possible move found! ~~ Something is wrong :( ~~");
	return computer_m;
}

Move playerMove() {
	Move player_m;
	player_m.heap = 0;
	player_m.coins = 0;
	return player_m;
}

// calculates how many chips are on the board
int get_board_sum() {
	int i;
	int board_sum = 0;

	for (i = 0; i < num_heaps; i = i + 1) {
		board_sum = board_sum + heaps[i];
	}
	return board_sum;
}

//comp
// comp needs to play so that their turn ends with xor_sum = 1 ie odd num of pieces 
// they will also try to create a board where the next turn ends with xor_sum = 0
// o
// o o
// xor sum=1
// loop through board, add up all of the 'o' 
// starting from 1, see the max number of chips that can be removed while meeting win conditions
