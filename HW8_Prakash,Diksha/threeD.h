/* Name: Diksha Prakash
Date: 11/1/2018
HomeWork 8 : Shape inheritence
Header file for declaration of derived class threedimension_Shape */

#include<iostream>    // Standard input/output library

// Standard declarations
using std::cout;
using std::cin;
using std::endl;

#ifndef THREED_H
#define THREED_H

#include "shape_Prakash.h"    //Including the header file of the parent class 'shape'

//Class '2DShape' inherits from the parent class 'shape'
class threeDimension_Shape : public shape
{
public:
	threeDimension_Shape();   //Constructor
	void setZ(float);   //Function prototype to set the 'Z' co-ordinate

	float side;   //Variable to store the edge
	float radius;   //Variable to store the radius
	float z;    //Variable to store the 'Z' co-ordinate
};

#endif
#pragma once
