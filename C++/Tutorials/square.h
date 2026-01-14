#pragma once
#include "rectangle.h"

class square {

protected:
	static int square_instances_alive_count;
	static int square_instances_created_count;
	static int initialized_square_instances_count;

private:
	rectangle rect; // rectangle constructor is called 
	const int squareID;

public:
	// constructor
	square() : squareID(rect.getRectangleID()) {
		square_instances_alive_count++;
		square_instances_created_count++;
		cout << "square constructor called" << endl;
	}

	// destructor 
	~square() {
		square_instances_alive_count--;
		cout << "square destructor called" << endl;
	}

	double getSide() {
		if (rect.isInitialized()) {
			return rect.getSideA();
		}
		else {
			cout << "Square is not initialized!" << endl;
		}
	}

	void inputSide(double in_side) {
		if (rect.isInitialized()) {
			initialized_square_instances_count++;
			cout << "Square is intiailized already!" << endl;
		}
		else {
			rect.inputSides(in_side, in_side);
		}
	}

	void inputSidesFromKeyboard() {
		if (!rect.isInitialized()) {
			double in_sideA;

			cout << "Please enter base: ";
			cin >> in_sideA;
			initialized_square_instances_count++;
			rect.inputSides(in_sideA, in_sideA);
		}
		else {
			cout << "Square is already initialized!" << endl;
		}
	}

	void inputRandomSide(double max_val = 100) {
		if (!rect.isInitialized()) {
			double sideA = (double(rand()) / RAND_MAX) * (max_val - 1);
			initialized_square_instances_count++;
			rect.inputSides(sideA, sideA);
		}
		else {
			cout << "Square is already initialized!" << endl;
		}
	}

	static void printSquareCount() {
		cout << "Total squares instantiated: " << square_instances_created_count << endl;
		cout << "Total squares alive: " << square_instances_alive_count << endl;
		cout << "Total squares initialized: " << initialized_square_instances_count << endl;
	}
};

int square::square_instances_alive_count=0;
int square::square_instances_created_count=0;
int square::initialized_square_instances_count=0;