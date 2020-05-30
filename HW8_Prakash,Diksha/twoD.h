/* Name: Diksha Prakash
Date: 11/1/2018
HomeWork 8 : Shape inheritence
Header file for declaration of derived class twodimensionalshape */

#include<iostream>    // Standard input/output library

// Standard declarations
using std::cout;
using std::cin;
using std::endl;

#ifndef TWOD_H
#define TWOD_H

#include "shape_Prakash.h"

//Class '2DShape' inherits from the parent class 'shape'
class twoDimension_Shape : public shape
{
public:
	twoDimension_Shape();   //Constructor

	float side;   //Variable for the 'side'
	float radius;   //Variable for the 'radius'
};
#endif
#pragma once
