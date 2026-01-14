#pragma once

# include "rectangle.h"
# include "polygonColor.h"

class rectangleWColor {

private:
	rectangle rect;
	polygonColor color;

public:
	void inputFromKeyboard() {	
		rect.inputSidesFromKeyboard();
		color.inputColorFromKeyboard();
	}

	void inputRandomValues(double max_val = 10, double max_color = RAND_MAX) {
		rect.inputRandomSides(max_val);
		color.inputRandomColor(max_color);
	}

	void printInfo() {
		rect.printRectangleInfo();
		color.printColorInfo();
	}
};
