/*Name: Diksha Prakash
Date: 11/1/2018
HomeWork 8 : Shape inheritence
File for main function*/

#include<iostream>    // Standard input/output library
using std::cout;	  // Standard cout declaration
using std::cin;		  // Standard cin declaration
using std::endl;	  // Standard end line declaration

#include "shape_Prakash.h"		// Include H file of class shape
#include "circle.h"				// Include H file of class circle
#include "triangle.h"			// Include H file of class triangle
#include "sphere.h"				// Include H file of class sphere
#include "tetrahedron.h"		// Include H file of class tetrahedron

int main()	// Start of main function
{
	int choice = 0;		// Variable to store choice at menu
	float CoordX, CoordY, CoordZ, radius, side;	// Variables to store X,Y,Z coordinates, radius and edge 

	shape a;	// Local instance of object for base class shape

	do		// Run Menu once
	{
		cout << "\n			AVAILABLE SHAPES :		\n";
		cout << "Choice # 1. Circle\n";
		cout << "Choice # 2. Equilateral Triangle\n";
		cout << "Choice # 3. Sphere\n";
		cout << "Choice # 4. Regular Tetrahedron \n";
		cout << "Choice # 0. Exit \n";
		cout << "\n Please enter your choice :  ";
		cin >> choice;		// Store user choice 
		while (cin.fail() || choice < 0)		// If input is invalid
		{
			cout << "\n Invalid input. Try again: ";
			cin.clear();	// Clear console
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
			cin >> choice;	// Take input again
		}
		switch (choice)		// Switch network for choices
		{
		case 1:	//Circle
		{
			cout << "  Your choice is Cirle";
			cout << "\n Please enter coordinates of the center -";
			cout << "\n X co-ordinate  : ";
			cin >> CoordX;
			while (cin.fail() || CoordX < 0)		// If input is invalid
			{
				cout << "\n Invalid input. Please try again: ";
				cin.clear();	// Clear console
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
				cin >> CoordX;	// Take input again
			}
			a.setX(CoordX);	// use Set function to store via instance
			
			cout << " Y : ";
			cin >> CoordY;
			while (cin.fail() || CoordY < 0)		// If input is invalid
			{
				cout << "\n Invalid input. Try again: ";
				cin.clear();	// Clear console
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
				cin >> CoordY;	// Take input again
			}
			a.setY(CoordY);

			cout << "\n Enter radius : ";
			cin >> radius;
			while (cin.fail() || radius < 0)		// If input is invalid
			{
				cout << "\n Invalid input. Try again: ";
				cin.clear();	// Clear console
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
				cin >> radius;	// Take input again
			}
			circle c(a.getX(), a.getY(), radius);	// Use of get functions via instance
			c.calcArea();	// Get area
			c.print();		// Print final output
			break;
		}
		case 2:	// Triangle
		{
			cout << "  Your choice : Triangle";
			cout << "\n Enter coordinates of center-";
			cout << "\n X : ";
			cin >> CoordX;
			while (cin.fail() || CoordX < 0)		// If input is invalid
			{
				cout << "\n Invalid input. Try again: ";
				cin.clear();	// Clear console
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
				cin >> CoordX;	// Take input again
			}
			a.setX(CoordX);

			cout << " Y : ";
			cin >> CoordY;
			while (cin.fail() || CoordY < 0)		// If input is invalid
			{
				cout << "\n Invalid input. Try again: ";
				cin.clear();	// Clear console
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
				cin >> CoordY;	// Take input again
			}
			a.setY(CoordY);

			cout << "\n Enter side : ";
			cin >> side;
			while (cin.fail() || side < 0)		// If input is invalid
			{
				cout << "\n Invalid input. Try again: ";
				cin.clear();	// Clear console
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
				cin >> side;	// Take input again
			}
			triangle t(a.getX(), a.getY(), side);
			t.calcArea();
			t.print();
			break;
		}
		case 3:		// Sphere 
		{
			cout << "  Your choice is Sphere";
			cout << "\n Enter coordinates of center-";
			cout << "\n X : ";
			cin >> CoordX;
			while (cin.fail() || CoordX < 0)		// If input is invalid
			{
				cout << "\n Invalid input. Try again: ";
				cin.clear();	// Clear console
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
				cin >> CoordX;	// Take input again
			}
			cout << " Y : ";
			cin >> CoordY;
			while (cin.fail() || CoordY < 0)		// If input is invalid
			{
				cout << "\n Invalid input. Try again: ";
				cin.clear();	// Clear console
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
				cin >> CoordY;	// Take input again
			}
			shape a(CoordX, CoordY);	// Direct instance use
			cout << " Z : ";
			cin >> CoordZ;
			while (cin.fail() || CoordZ < 0)		// If input is invalid
			{
				cout << "\n Invalid input. Try again: ";
				cin.clear();	// Clear console
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
				cin >> CoordZ;	// Take input again
			}
			cout << "\n Enter radius : ";
			cin >> radius;
			while (cin.fail() || radius < 0)		// If input is invalid
			{
				cout << "\n Invalid input. Try again: ";
				cin.clear();	// Clear console
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
				cin >> radius;	// Take input again
			}
			sphere sph(CoordX, CoordY, CoordZ, radius);	// Instance for X,Y,Z and radius 
			sph.calcArea();
			sph.calcVolume();		// Get volume
			sph.print();
			break;
		}
		case 4:		// tetrahedron
		{
			cout << "  Your choice : Tetrahedron";
			cout << "\n Enter coordinates of center-";
			cout << "\n X : ";
			cin >> CoordX;
			while (cin.fail() || CoordX < 0)		// If input is invalid
			{
				cout << "\n Invalid input. Try again: ";
				cin.clear();	// Clear console
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
				cin >> CoordX;	// Take input again
			}
			cout << " Y : ";
			cin >> CoordY;
			while (cin.fail() || CoordY < 0)		// If input is invalid
			{
				cout << "\n Invalid input. Try again: ";
				cin.clear();	// Clear console
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
				cin >> CoordY;	// Take input again
			}
			shape a(CoordX, CoordY);
			cout << " Z : ";
			cin >> CoordZ;
			while (cin.fail() || CoordZ < 0)		// If input is invalid
			{
				cout << "\n Invalid input. Try again: ";
				cin.clear();	// Clear console
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
				cin >> CoordZ;	// Take input again
			}
			cout << "\n Enter edge : ";
			cin >> side;
			while (cin.fail() || side < 0)		// If input is invalid
			{
				cout << "\n Invalid input. Try again: ";
				cin.clear();	// Clear console
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
				cin >> side;	// Take input again
			}
			tetrahedron tetra(CoordX, CoordY, CoordZ, side);
			tetra.calcArea();
			tetra.calcVolume();
			tetra.print();
			break;
		}
		case 0:		// Exit program
			cout << "\n Program exited. ";
			break;
		}
	} while (choice != 0);	// Check if choice not to exit

	return 0;	// Successfully exit program
}
// End of main function