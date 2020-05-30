/*Name: Diksha Prakash
Date: 11/1/2018
HomeWork 8 : Shape inheritence
File for definition of base class Shape*/

// Standard input/output library
#include<iostream>

// Standadrd Declarations
using std::cout;
using std::cin;
using std::endl;

// include the header file of class shape
#include "shape_Prakash.h"

// Default constructor
shape::shape()
{
	x = 0;
	y = 0;
}

// Constructor to overload the values
shape::shape(float CoordX, float CoordY)
{// set functions for coordinates
	setX(CoordX);
	setY(CoordY);
}

// Set function for X co-ordinate
void shape::setX(float CoordX)
{
	x = CoordX;
}

// Set function for Y co-ordinate
void shape::setY(float CoordY)
{
	y = CoordY;
}

// Get function for X co-ordinate
float shape::getX()
{
	return x;
}

// Get function for Y co-ordinate
float shape::getY()
{
	return y;
}
