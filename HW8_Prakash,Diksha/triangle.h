/* Name: Diksha Prakash
Date: 11/1/2018
HomeWork 8 : Shape inheritence
Header file for declaration of derived class triangle */

#include<iostream>    // Standard input/output library

// Standard declarations
using std::cout;
using std::cin;
using std::endl;

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "twoD.h"   //Including the header file for the parent class 'twoDimension_Shape'

class triangle : public twoDimension_Shape    //Triangle class inherits from the parent class 'twoDimension_Shape'
{
private:
	double area;    //Variable to store the computed area

public:
	triangle(float = 0, float = 0, float = 0);   //constructor
	double calcArea();    //Function prototype for calculating the area
	void print();   //Function prototype for returning the computed result to the user
};

#endif
#pragma once
