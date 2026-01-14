#include "rectangle.h"
#include "rightTriangle.h"
#include "rightTriangleWColor.h"
#include "rectangleWColor.h"
#include "TestQuestion.h"
#include "square.h"

#include <time.h>      



void Part_1(rightTriangle obj_array[], int arraysize)
{
	for(int i=0; i<arraysize; i++)		
	{
		cout << "object position "<< i << ":" << endl;
		obj_array[i].inputSidesFromKeyboard();
		cout << endl << "object side A is: " << obj_array[i].getSide(1) << endl;
		cout << "object side B is: " << obj_array[i].getSide(2) << endl;
		cout << "object side C is: " << obj_array[i].getSide(3) << endl;
		cout << "object Area is: " << obj_array[i].getArea() << endl;
		cout << " ******** " << endl << endl;
	}
}

void Part_2(rightTriangle obj_array[], int arraysize)
{
	// intialize this to the value of the first entry in the array
	int minval_index=-1;
	double val, minval;	

	// scan all objects
	for(int i=0; i<arraysize; i++)		
	{
		// current area
		val=obj_array[i].getArea();	
		
		if( ( (minval_index==-1)||(val<minval) ) && (val>0) )
		{
			// the current object has the smallest noon-zero area
			minval=val;
			minval_index=i;
		}		
	}
	if(minval_index>=0)
	{
		cout << endl << "object position "<< minval_index << " has the smallest area:" << endl;
		cout << "object side A is: " << obj_array[minval_index].getSide(1) << endl;
		cout << "object side B is: " << obj_array[minval_index].getSide(2) << endl;
		cout << "object side C is: " << obj_array[minval_index].getSide(3) << endl;
		cout << "object Area is: " << obj_array[minval_index].getArea() << endl;
	}
	else
		cout << endl << " No object matched the search cirteria." << endl;

	cout << " ******** " << endl << endl;
}

void Part_4(double min_area, polygonColorOption pcolr_target)
{
	double area;
	polygonColorOption pcolr;
	const int arraysize=100;	
	int count=0;
	
	// these are N instantiations (objects) of the class rectangle
	// i.e. variables of the user-defined type "right_triangleWcolor" 
	rightTriangleWColor obj_array_1[arraysize];
	rightTriangleWColor obj_array_2[arraysize];
	
	// initialize random seed via srand() 
	// using the current time to set the seed
	srand(time(NULL));
	/////

	for(int i=0; i<arraysize; i++)
	{
		obj_array_1[i].inputRandomValues();
		obj_array_1[i].printInfo();
	}
	cout << endl << endl << "      ////////////  " << endl << endl;	
	for(int i=0; i<arraysize; i++)
	{
		area=obj_array_1[i].triangle.getArea();		
		pcolr=obj_array_1[i].color.getColor();
		if( (area>min_area) && (pcolr==pcolr_target)  ) 
		{
			obj_array_2[count]=obj_array_1[i];
			count++;
		}
	}

	cout << endl << " " << count << " objects out of " << arraysize << " matched the search criteria." << endl;
	
	for(int i=0; i<count; i++)
		obj_array_2[i].printInfo();

}

void Part_5() {
	rectangle obj1;
	square obj2;
	
	cout << "-----------------" << endl;
	rectangle::printRectangleCount();
	square::printSquareCount();
	cout << "-----------------" << endl;

	obj1.inputRandomSides();
	rectangle::printRectangleCount();
	square::printSquareCount();
	cout << "-----------------" << endl;

	square obj3;
	square obj4;
	rectangle::printRectangleCount();
	square::printSquareCount();
	cout << "-----------------" << endl;

	obj3.inputRandomSide();
	rectangle::printRectangleCount();
	square::printSquareCount();
	cout << "-----------------" << endl;

	obj4.inputRandomSide();
	rectangle::printRectangleCount();
	square::printSquareCount();
	cout << "-----------------" << endl;

}

void test_part1()
{
	rectangle obj1;
	rightTriangle obj2;
	rectangleWColor obj3;
	rightTriangleWColor obj4;
	cout << "object 1:" << endl;
	obj1.inputRandomSides();
	obj1.printRectangleInfo();
	cout << "object 1 (again):" << endl;
	//obj1.reset();
	obj1.inputRandomSides(5);
	obj1.printRectangleInfo();
	cout << endl << endl;
	cout << "object 2:" << endl;
	obj2.inputRandomSides(10);
	obj2.printTriangleInfo();
	cout << endl << endl;
	cout << "object 3:" << endl;
	obj3.inputRandomValues(3);
	obj3.printInfo();
	cout << endl << endl;
	cout << "object 4:" << endl;
	obj4.inputRandomValues();
	obj4.printInfo();
	cout << "object 4 (again):" << endl;
	//obj4.reset();
	obj4.inputRandomValues();
	obj4.printInfo();
}

void test_static_counters()
{
	rectangle::printRectangleCount();
	rectangle testobj1;
	rectangle::printRectangleCount();
	cout << "testobj1 ID: " << testobj1.getRectangleID() << endl;
	testobj1.inputRandomSides();
	rectangle::printRectangleCount();
	{
		cout << endl << "Entering a local scope:" << endl;
		const int localaraysize = 5;
		rectangle testobjarray[localaraysize];
		rectangle::printRectangleCount();
		for (int i = 0; i < localaraysize; i++)
		{
			cout << "testobjarray[" << i << "] ID: " << testobjarray[i].getRectangleID() << endl;
			testobjarray[i].inputRandomSides();
			rectangle::printRectangleCount();
		}
		cout << "Exiting local scope;" << endl << endl;
	}
	rectangle::printRectangleCount();
	testobj1.reset();
	rectangle::printRectangleCount();
}

void test_tutorial4_part1() {
	rectangle testobj0, testobj1;
	testobj0.inputSides(10, 1);
	testobj1 = testobj0;
}

void test_more_operators() {
	rectangle testobj0, testobj1;
	testobj0.inputSides(6, 10);
	cout << "testobj0:" << endl;
	testobj0.printRectangleInfo();
	rectangle::printRectangleCount();
	cout << endl;

	testobj1.inputSides(50, 20);
	cout << "testobj1:" << endl;
	testobj1.printRectangleInfo();
	rectangle::printRectangleCount();
	cout << endl;

	rectangle testobj2 = testobj0 + testobj1;
	cout << "testobj2:" << endl;
	testobj2.printRectangleInfo();
	rectangle::printRectangleCount();
	cout << endl;
}



//////////////////////////////////////////////////////////////////////////////////////////


int main(int argc, char** argv)
{
	// these are N instantiations (objects) of the class rectangle
	// i.e. variables of the user-defined type "rectangle" 
	//const int arraysize = 3;
	//rightTriangle obj_array[arraysize];

	// Part 1:
	// The content of "obj_array" can be changed by the following function; 
	// the content of "arraysize" will not. Why? (It has nothing to do with "arraysize" being "const".) 
	//Part_1(obj_array, arraysize);

	// Part 2:
	//Part_2(obj_array, arraysize);


	// Part 3:
	//rightTriangleWColor test_object;


	// Part 4:
	//double min_area=30;
	//polygonColorOption pcolr_target=orange;
	//Part_4(min_area, pcolr_target);

	// Part 5:
	//Part_5();

	// Test Question
	//testQuestion();

	// tutorial 3
	//test_static_counters();

	// tutorial 4
	test_more_operators();

	return 0;
}