# pragma once
# include "rectangle.h"
# include <cmath>

# include <iostream>

class rightTriangle {

protected:
	// holds information about sides A and B
	rectangle legs;


	double sideC = -1;
	double area = -1;
	double perimeter = -1;

	void computeArea() {
		// checks if triangle is initialized
		if (isInitialized()) {
			// computes area 
			area = 0.5 * legs.getSideA() * legs.getSideB();
		}
		else {
			// throws error
			cout << "Error in computeArea(): right triangle is not initialized" << endl;
			area = 0;
		}
	}

	void computePerimeter() {
		if (isInitialized()) {
			perimeter = legs.getSideA() + legs.getSideB() + sideC;
		}
		else {
			cout << "Error in computePerimeter(): right triangle is not initialized" << endl;
			perimeter = 0;
		}
	}
	void computeHypotenuse() {
		if (isInitialized()) {
			sideC = sqrt(pow(legs.getSideA(), 2) + pow(legs.getSideB(), 2));
		}
		else {
			cout << "Error in computeHypotenuse(): right triangle is not initialized" << endl;
			sideC = 0;
		}
	}

public:
	double getPerimeter() {
		if (isInitialized()) {
			computePerimeter();
			return perimeter;
		}
		else {
			cout << "Error in getPerimeter(): right triangle is not initialized" << endl;
			return 0;
		}
	}
	double getArea() {
		if (isInitialized()) {
			computeArea();
			return area;
		}
		else {
			cout << "Error in getArea(): right triangle is not initialized" << endl;
			return 0;
		}
	}

	bool isInitialized() {
		return legs.isInitialized();
	}

	double getSide(int sideNum) {
		if (isInitialized()) {
			if (sideNum == 1) {
				return legs.getSideA();
			}
			if (sideNum == 2) {
				return legs.getSideB();
			}
			if (sideNum == 3) {
				return sideC;
			}
			else {
				cout << "Error in getSide(): Side invalid!" << endl;
				return 0;
			}
		}
		else {
			cout << "Error in getSide(): right triangle is not initialized" << endl;
			return 0;
		}
	}

	void inputSides(double in_sideA, double in_sideB) {
		if (!isInitialized()) {
			// sets the legs of the triangle 
			// sets the initialized flag to true
			legs.inputSides(in_sideA, in_sideB);

			// sets the hypotenuse
			if (in_sideA > 0 && in_sideB > 0) {
				computeHypotenuse();
			}
		}
		else {
			cout << "Error in inputSides(), right triangle is already initialized" << endl;
		}
	}

	void inputSidesFromKeyboard() {
		if (!isInitialized()) {
			legs.inputSidesFromKeyboard();
			computeHypotenuse();
		}
		else {
			cout << "Right triangle is already initialized!" << endl;
		}
	}

	void inputRandomSides(double max_val) {
		if (!isInitialized()) {
			double sideA = (double(rand()) / RAND_MAX) * (max_val - 1) + 1;
			double sideB = (double(rand()) / RAND_MAX) * (max_val - 1) + 1;
			inputSides(sideA, sideB);
			computeHypotenuse();
		}
	}

	void printTriangleInfo() {
		if (!isInitialized()) {
			cout << "Error in printTriangleInfo(): right triangle not initialized" << endl;
		}
		else {
			cout << "\nLeg A length: " << getSide(1) << endl;
			cout << "\nLeg B length: " << getSide(2) << endl;
			cout << "\nHypotenuse length: " << getSide(3) << endl;

			cout << "\nArea: " << getArea() << endl;
			cout << "\nPerimeter: " << getPerimeter() << endl;
		}
	}

	void reset() {
		legs.reset();
		sideC = 0;
		area = 0;
		perimeter = 0;
	}
};
