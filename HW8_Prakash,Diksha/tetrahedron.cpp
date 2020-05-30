/*Name: Diksha Prakash
Date: 11/1/2018
HomeWork 8 : Shape inheritence
header file for declaration of derived class tetrahedron*/

#include<iostream>    // Standard input/output library

// Standard declarations
using std::cout;
using std::cin;
using std::endl;

#include "tetrahedron.h"		// include H file of class tetrahedron

tetrahedron::tetrahedron(float CoordX, float CoordY, float CoordZ, float edge)	// constructor
{
	// set functions for coordinates
	setX(CoordX);
	setY(CoordY);
	setZ(CoordZ);
	side = edge;
}

double tetrahedron::calcArea()	// function to find area
{
	area = 1.732*side*side;
	return area;	// return area
}
double tetrahedron::calcVolume()		// function to find volume
{
	volume = side * side*side / (6 * 1.414);
	return volume;		// return volume
}
void tetrahedron::print()	// function to print the final output
{
	cout << "\n The area of tetrahedron with side " << side << " located at (" << getX() << ", " << getY() << ", " << z << ")" << " is : " << calcArea() << " sq. units" << endl;
	cout << "\n And the volume is : " << calcVolume() << " cubic units" << endl;
}
