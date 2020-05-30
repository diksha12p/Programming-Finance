/*Name: Diksha Prakash
Date: 11/1/2018
HomeWork 8 : Shape inheritence
File for definition of derived class sphere*/

#include<iostream>    // Standard input/output library

// Standard declarations
using std::cout;
using std::cin;
using std::endl;

#include "sphere.h"	// include Header file of class sphere

sphere::sphere(float CoordX, float CoordY, float CoordZ, float rad)	// constructor
{
	// set functions for coordinates
	setX(CoordX);
	setY(CoordY);
	setZ(CoordZ);
	radius = rad;
}

double sphere::calcArea()	// function to find area
{
	area = 4*3.14*radius*radius;   //Formula for the calculation of the area
	return area;	// Return the computed area
}
double sphere::calcVolume()	// function to find volume
{
	volume = 4.188790205*radius*radius*radius;
	return volume;	// return volume
}
void sphere::print()	// function to print output
{
	cout << "\n The area of sphere with radius " << radius << " and located at (" << getX() << ", " << getY() << ", " << z << ")" << " is : " << calcArea() << " Sq. units" << endl;
	cout << "\n And the volume is : " << calcVolume() << " cubic units" << endl;
}
