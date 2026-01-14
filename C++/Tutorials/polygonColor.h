#pragma once

#include <iostream>
#include <cstdlib>

// enumerator: finite set of choices for the colors 
// blank and color_stop "bookend" the allowed colors
enum polygonColorOption {
	blank = 0, white, red, orange, yellow, green,
	light_blue, dark_blue, purple, brown, black, color_stop
};

class polygonColor {
private:
	polygonColorOption color;
public:
	polygonColor() { color = blank; }
	void setColor(polygonColorOption inp_color)
	{
		// only set once
		if (color == blank)
		{
			// make sure input color is within the limits
			if ((inp_color > blank) && (inp_color < color_stop))
				color = inp_color;
		}
	}

	polygonColorOption getColor() {
		if (color == blank) {
			cout << "Error in getColor(): color is not initialized." << endl;
		}
		return color;
	}

	void inputColorFromKeyboard()
	{
		if (color == blank)
		{
			int inp_color;
			cout << "Please choose one of the following colors for the Rectangle (then hit ENTER)" << endl;
			cout << " white = " << white << ";" << endl;
			cout << " red = " << red << ";" << endl;
			cout << " orange = " << orange << ";" << endl;
			cout << " yellow = " << yellow << ";" << endl;
			cout << " green = " << green << ";" << endl;
			cout << " light_blue = " << light_blue << ";" << endl;
			cout << " dark_blue = " << dark_blue << ";" << endl;
			cout << " purple = " << purple << "." << endl;
			cout << " brown = " << brown << "." << endl;
			cout << " black = " << black << "." << endl;
			cin >> inp_color;
			setColor((polygonColorOption)inp_color);
		}
		else
			cout << "Error in inputColorFromKeyboard(): Color is already initialized " << endl;
	}
	void printColorInfo()
	{
		if (color != blank)
		{
			cout << "Rectangle color is: ";
			switch (color) {
			case white:
				cout << " white." << endl;
				break;
			case red:
				cout << " red." << endl;
				break;
			case orange:
				cout << " orange." << endl;
				break;
			case yellow:
				cout << " yellow." << endl;
				break;
			case green:
				cout << " green." << endl;
				break;
			case light_blue:
				cout << " light_blue." << endl;
				break;
			case dark_blue:
				cout << " dark_blue." << endl;
				break;
			case purple:
				cout << " purple." << endl;
				break;
			case brown:
				cout << " brown." << endl;
				break;
			case black:
				cout << " black." << endl;
				break;
			default:
				cout << "Error in printInfo(): Color num not recognized" << endl;
			}
		}
		else
			cout << "Error in printInfo(): Color is not initialized " << endl;
	}

	void inputRandomColor(double max_val = RAND_MAX)
	{
		// this produces a random integer within [0 , RAND_MAX]
		unsigned int rand_value = rand();
		// this produces a random int within [1 , color_stop-1]
		int inp_color = (int)((((double)rand_value) / max_val) * (color_stop - 2) + 1);

		setColor((polygonColorOption)inp_color);
	}
};