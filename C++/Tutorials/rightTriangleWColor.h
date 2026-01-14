# pragma once 
# include "rightTriangle.h"
# include "polygonColor.h"

// Combines the right triangle and polygon color classes

class rightTriangleWColor {

public:
	rightTriangle triangle;
	polygonColor color;

public:	
	void inputFromKeyboard() {
		triangle.inputSidesFromKeyboard();
		color.inputColorFromKeyboard();
	}

	void inputRandomValues(double max_val = 10, double max_color = RAND_MAX) {
		triangle.inputRandomSides(max_val);
		color.inputRandomColor(max_color);
	}

	void printInfo() {
		triangle.printTriangleInfo();
		color.printColorInfo();
	}
};
