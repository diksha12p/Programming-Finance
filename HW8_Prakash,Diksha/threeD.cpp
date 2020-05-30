/* Name: Diksha Prakash
Date: 11/1/2018
HomeWork 8 : Shape inheritence
File for definition of derived class triangle */

#include<iostream>    // Standard input/output library

// Standard declarations
using std::cout;
using std::cin;
using std::endl;

#include "threeD.h"   //Including the header file of the class 'triangle'

threeDimension_Shape::threeDimension_Shape()    //Constructor
{
	radius = 0;   //Initialize the variables
	side = 0;
}

void threeDimension_Shape::setZ(float CoordZ)   //Function definition to set the Z co-ordinate
{
	z = CoordZ;   //Storing the value in the variable 'z'
}
