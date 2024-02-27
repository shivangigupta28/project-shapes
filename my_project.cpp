// my_project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"
using namespace std;


int main()
{
	Menu m;
	Warehouse warehouse;

	int choice;

	do
	{
		m.printMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			warehouse.addShape();
			break;
		case 2:
			warehouse.searchShape();
			break;
		case 3:
			warehouse.updateShape();
			break;
		case 4:
			warehouse.deleteShape();
			break;
		case 5:
			warehouse.displayAll();
			break;
		case 6:
			warehouse.display2d_perimeter();
			break;
		case 7:
			warehouse.display3d_volume();
			break;
		default:
			cout << "Invalid" << endl;
			break;
		}
	} while (choice > 0 && choice < 8);

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
