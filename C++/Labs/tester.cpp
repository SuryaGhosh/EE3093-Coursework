#include "circle.h"

#include <stdio.h>


void testPart1()
{
	const int tot_test = 10;
	circle testobj_array[tot_test];
	for (int i = 0; i < tot_test; i++)
	{
		cout << "Test item i=" << i << endl;
		cout << "Before initialization" << endl;
		testobj_array[i].printShapeAndCoordInfo();
		cout << "Init shape :" << endl;
		// uncomment the one relative to your selection
		//testobj_array[i].inputRandomSide();
		//testobj_array[i]. inputSideFromKeyboard();
		testobj_array[i].printShapeAndCoordInfo();
		cout << "Init coordinates:" << endl;
		// uncomment the one relative to your selection
		//testobj_array[i].inputRandomCoord();
		//testobj_array[i].inputCoordFromKeyboard();
		testobj_array[i].printShapeAndCoordInfo();
		// insert here additional tests for all other required functions
		//
		cout << "Done" << endl << endl;
	}
}