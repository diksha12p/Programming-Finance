/* Name: Diksha Prakash
Date: 11/1/2018
HomeWork 8 : Shape inheritence
File for definition of derived class circle */

#include<iostream>    // Standard input/output library

// Standard declarations
using std::cout;
using std::cin;
using std::endl;

#include "circle.h"

circle::circle(float CoordX, float CoordY, float rad)    //Constructor
{
	setX(CoordX);          //Setting the x co-ordinate
	setY(CoordY);         //Setting the y co-ordinate
	radius = rad;     //Setting the radius of the circle
}

double circle::calcArea()   //Function to calculate the area
{
	area = 3.14*radius*radius;    //Formula to calculate the area of the circle
	return area;                 //Returning the area to the user
}

void circle::print()    //Function to print the output to the user
{
	cout << "The area of the circle with centre (" << getX() << "," << getY() << ") and radius " << radius << "is : " << area << endl;
}
