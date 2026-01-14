#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <math.h>


using namespace std;


class circle {
private:
	bool initCoord;
	bool initSide;
	double radius;
	double x, y; // center coordinates

public: 
	circle () {
		initCoord = false;
		initSide = false;
		radius = 0;
		x = 0;
		y = 0;
	}

	double getArea() {
		if (isInitialized()) {
			return getSide() * getSide() * M_PI;
		}
		cout << "Error in getArea(): cirle not initialized." << endl;
		return 0;
	}

	double getPerimeter() {
		if (isInitialized()) {
			return getSide() * M_PI * 2;
		}
		cout << "Error in getPerimeter(): cirle not initialized." << endl;
		return 0;
	}

	// gets radius
	double getSide() {
		if (isInitialized()) {
			return radius;
		}
		cout << "Error in getSide(): circle not initalized." << endl;
		return 0;
	}

	bool getCoord(double& out_Cx, double& out_Cy) {
		if (isInitialized()) {
			out_Cx = x;
			out_Cy = y;
			return true;
		}

		cout << "Error in getCoord(): circle not initialized." << endl;
		return false;
	}

	void printShapeAndCoordInfo() {
		if (!isInitialized()) {
			cout << "Error in printShapeAndCoordInfo(): circle not initialized" << endl;
			return;
		}
		cout << endl << "Circle Information:" << endl;

		double x;
		double y;
		getCoord(x, y);

		cout << "Center: (" << x << ", " << y << ")" << endl;
		cout << "Radius: " << getSide() << endl;
		cout << "Perimeter: " << getPerimeter() << endl;
		cout << "Area: " << getArea() << endl;
	}
	
	// sets radius 
	bool inputSide(double in_side) {
		if (isInitialized()) {
			cout << "Error in inputSide(): circle already initialized" << endl;
			return false;
		}
		radius = in_side;
		initSide = true;
		return true;
	}

	bool inputCoord(double in_Cx, double in_Cy) {
		if (initCoord) {
			cout << "Error in inputCoord(): center already initialized" << endl;
			return false;
		}
		initCoord = true;
		x = in_Cx;
		y = in_Cy;
		return true;
	}

	void resetShape() {
		initSide = false;
		initCoord = false;
		radius = 0;
		x = 0;
		y = 0;
	}

	void resetCoord() {
		initCoord = false;
		x = 0;
		y = 0;
	}

	bool inputRandomSide(double max_val = 10) {

	}

	bool inputCoordFromKeyBoard() {

	}

	bool isInitialized() {
		return initCoord * initSide;
	}
};