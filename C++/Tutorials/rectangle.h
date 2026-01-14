# pragma once
# include <iostream>

using namespace std;

class rectangle {

protected: 
	// tracks instances/initializations 
	// protected; since we want children to be able to access this 
	static int rectangle_instances_created_count;		// instances that have been instantiated at some point 
	static int rectangle_instances_alive_count;			// instances that are still active 
	static int initialized_rectangle_instances_count;	// instances that have been initialized 

private:
	// id: is unique for each rectangle instance 
	// is initialized when constructor is called
	const int rectangle_ID;

	// variables
	double sideA, sideB; 
	double perimeter;
	double area;

	// initialization flag
	bool init_flag;

	void basicInitializion() {
		sideA = 0;
		sideB = 0;
		perimeter = 0;
		area = 0;

		set_init_flag(false);
		rectangle_instances_alive_count++;
	}

	void computeArea() {
		if (isInitialized()) {
			area = sideA * sideB;
		}
		else {
			cout << "Error in getArea(): rectangle not initialized" << endl;
			area = 0;
		}
	}

	void computePerimeter() {
		if (isInitialized()) {
			perimeter = sideA * 2 + sideB * 2;
		} 
		else {
			cout << "Error in getPerimeter(): rectangle not initialized" << endl;
			perimeter = 0;
		}
	}

	double computeIncrement(const rectangle& other) {
		double A = other.sideA * other.sideB;
		double B = sideA + sideB;
		double disc = B * B + 4.0 * A;

		if (disc < 0.0) {
			return 0.0;
		}

		double x = (-B + sqrt(disc)) / 2.0; 
		return x;

	}

public:
	// constructor 
	rectangle() : rectangle_ID(rectangle_instances_created_count++) {
		cout << "rectangle constructor called" << endl;
		basicInitializion();
	}
	
	// overloaded constructor, initializes rectangle  
	rectangle(double set_sideA, double set_sideB) : rectangle_ID(rectangle_instances_created_count++){
		cout << "rectangle overloaded constructor called" << endl;
		basicInitializion();
		sideA = set_sideA;
		sideB = set_sideB;
		computeArea();
		computePerimeter();
		set_init_flag(true);
	}

	// destructor 
	~rectangle() {
		cout << "rectangle destructor called" << endl;
		set_init_flag(false);
		rectangle_instances_alive_count--;
	}

	// copies rectangle object 
	// &: passes by reference, so a copy isn't made unnecessarily 
	// const: so the original rectangle cannot be accidentally edited 
	void copyFrom(const rectangle& other) {
		if (other.isInitialized()) {
			reset();
			inputSides(other.getSideA(), other.getSideB());
		}
		else {
			cout << "Error in copyFrom(): rectangle to copy is not initialized." << endl;
		}
	}

	// copy constructor 
	// used to instantiate a new rectangle as a copy of an existing one 
	rectangle(const rectangle& other) : rectangle_ID(rectangle_instances_created_count++) {
		cout << "rectangle copy constructor called" << endl;
		basicInitializion();
		copyFrom(other);
	}

	// overloads '=' operator 
	// operator: keyword
	// const: ensures that we cannot change the assignee 
	// rectangle&: returns address; ie not a reference 
	// this: points to the current object
	// ->copyFrom: explicitly calls the copyFrom function of the current object
	// *this: returns a pointer to the current object
	rectangle& operator = (const rectangle& other) {
		this->copyFrom(other);
		return *this;
	}

	// overloads '+' operator 
	rectangle operator + (const rectangle& other) {
		// adds sides together  
		rectangle temp;
		temp.inputSides(other.getSideA() + this->getSideA(), other.getSideB() + this->getSideB());
		return temp;
	}

	// tut 4 part 2
	// overloads '+=' operator
	// adds the sides together, and updates area
	/* rectangle& operator += (const rectangle& other) {
		// uses previously overloaded operators '=', '+'
		rectangle temp = *this + other;

		//return this + other
		this->copyFrom(temp);
		return *this;
	}*/

	// tut 4 part 3
	// overloads '+=' operator; adds areas, and updates sides
	rectangle& operator += (const rectangle& other) {
		// determining x
		double x = computeIncrement(other);
		sideA += x;
		sideB += x;

		set_init_flag(true);
		return *this;
	}

	// getter
	int getRectangleID() const {
		if (isInitialized()) {
			return rectangle_ID;
		}
		cout << "Rectangle is not initialized." << endl;
		return -1;
	}

	// getter
	bool isInitialized() const {
		return init_flag;
	}

	// getter
	// non const functions cannot be called from inside a const function
	double getSideA() const {
		if (isInitialized()) {
			return sideA;
		} 
		else {
			cout << "Rectangle is not initialized." << endl;
			return 0;
		}
	}

	// getter
	double getSideB() const {
		if (isInitialized()) {
			return sideB;
		}
		else {
			cout << "Rectangle is not initialized." << endl;
			return 0;
		}
	}

	// getter
	double getArea() {
		if (isInitialized()) {
			computeArea();
			return area;
		}
		else {
			cout << "Rectangle is not initialized." << endl;
			return 0;
		}
	}

	// getter
	double getPerimeter() {
		if (isInitialized()) {
			computePerimeter();
			return perimeter;
		}
		else {
			cout << "Rectangle is not initialized." << endl;
			return 0;
		}
	}

	// getter
	int getRectangleID() {
		return rectangle_ID;
	}

	// getter
	int getActiveRectanglesCount() {
		return rectangle_instances_alive_count;
	}

	// getter
	int getInitializedRectanglesCount() {
		return initialized_rectangle_instances_count;
	}

	// setter
	void inputSides(double in_sideA, double in_sideB) {
		if (!isInitialized()) {
			if (in_sideA > 0 && in_sideB > 0) {
				sideA = in_sideA;
				sideB = in_sideB;
				set_init_flag(true);
			}
			else {
				cout << "Error in inputSides(): incorrect input values" << endl;
			}
		}
		else {
			cout << "Rectangle is already initialized!" << endl;
		}
	}

	// setter
	void inputSidesFromKeyboard() {
		if (!isInitialized()) {
			double in_sideA, in_sideB;

			cout << "Please enter base: ";
			cin >> in_sideA;
			cout << endl;
			cout << "Please enter height: ";
			cin >> in_sideB;
			cout << endl;

			inputSides(in_sideA, in_sideB);
		}
		else {
			cout << "Rectangle is already initialized!" << endl;
		}
	}

	// setter
	void set_init_flag(bool setval) {
		if (init_flag != setval) {
			if (setval)
				initialized_rectangle_instances_count++;
			else if (initialized_rectangle_instances_count > 0)
				initialized_rectangle_instances_count--;
		}
		init_flag = setval;
	}

	// setter 
	void inputRandomSides(double max_val=10) {
		if (!isInitialized()) {
			double sideA = (double(rand()) / RAND_MAX) * (max_val-1);
			double sideB = (double(rand()) / RAND_MAX) * (max_val-1);
			inputSides(sideA, sideB);
		}
	}

	// reset
	void reset() {
		init_flag = false;
		sideA = 0;
		sideB = 0;
		perimeter = 0;
		area = 0;
	}

	// prints rectangle info
	void printRectangleInfo() {
		if (isInitialized()) {
			cout << "\nRectangle info:";
			cout << "\nSide A length: " << getSideA();
			cout << "\nSide B length: " << getSideB();
			cout << "\nArea: " << getArea();
			cout << "\nPerimeter: " << getPerimeter() << "\n";
		}
		else {
			cout << "Error in printRectangleInfo(): rectangle not initialized" << endl;
		}
	}

	// prints rectangle instance counts
	static void printRectangleCount() {
		cout << "Total rectangles instantiated: " << rectangle_instances_created_count << endl;
		cout << "Total rectangles alive: " << rectangle_instances_alive_count << endl;
		cout << "Total rectangles initialized: " << initialized_rectangle_instances_count << endl;
	}
};

// initializing static variables
int rectangle::rectangle_instances_created_count = 0;
int rectangle::rectangle_instances_alive_count = 0;
int rectangle::initialized_rectangle_instances_count = 0;