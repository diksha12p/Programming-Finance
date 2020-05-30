/* Name: Diksha Prakash
Date: 11/1/2018
HomeWork 8 : Shape inheritence
File for definition of derived class triangle */

#include<iostream>    // Standard input/output library

// Standard declarations
using std::cout;
using std::cin;
using std::endl;

#include "triangle.h"   //Including the header file of the class 'triangle'

triangle::triangle(float CoordX, float CoordY, float edge)    //Constructor
{
	setX(CoordX);   //Setting the X co-ordinate
	setY(CoordY);   //Setting the Y co-ordinate
	side = edge;    //Setting the edge of the equilateral triangle
}

double triangle::calcArea()   //Function to calculate teh area of the equilateral triangle
{
	area = 0.4330127019*side*side;    //Formula for calculating the area of the equilateral triangle
	return area;    //returning the area post computation
}

void triangle::print()    //Function to print out the results to the user
{
	cout << "The area of traingle centered at (" << getX() << "," << getY() << ") and having edge " << side << " has an area of " << area << "sq. units" << endl;
}
