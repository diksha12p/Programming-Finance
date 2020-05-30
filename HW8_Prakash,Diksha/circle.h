/* Name: Diksha Prakash
Date: 11/1/2018
HomeWork 8 : Shape inheritence
Header file for declaration of derived class circle */

#include<iostream>    // Standard input/output library

// Standard declarations
using std::cout;
using std::cin;
using std::endl;

#ifndef CIRCLE_H
#define CIRCLE_H

#include "twoD.h"

class circle : public twoDimension_Shape    //Circle class inherits from the parent class 'twoDimension_Shape'
{
private:
	double area;    //Variable to store the value of the computed area

public:
	circle(float = 0, float = 0, float = 0);   //Constructor
	double calcArea();    //Function prototype for calculating the area of the circle
	void print();   //Function prototype for printing the result to the user

};
#endif
