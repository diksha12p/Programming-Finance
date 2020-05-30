/*Name: Diksha Prakash
Date: 11/1/2018
HomeWork 8 : Shape inheritence
header file for declaration of derived class tetrahedron*/

#include<iostream>    // Standard input/output library

// Standard declarations
using std::cout;
using std::cin;
using std::endl;

#ifndef TETRAHEDRON_H	// if not defined
#define TETRAHEDRON_H	// define

#include "threeD.h"	// include Header file of parent class threedimensionalshape

class tetrahedron : public threeDimension_Shape // class tetrahedron inherits from parent class threedimensionalshape
{
public:
	tetrahedron(float = 0, float = 0, float = 0, float = 0);	// constructor
	double calcArea();	// function to find area
	double calcVolume();	// function to find volume
	void print();	// function to print output
private:
	double area;	// variable to store area
	double volume;	// variable to store volume
};

#endif
#pragma once
