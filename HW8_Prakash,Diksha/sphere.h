/* Name: Diksha Prakash
Date: 11/1/2018
HomeWork 8 : Shape inheritence
Header file for declaration of derived class sphere */

#include<iostream>    // Standard input/output library

// Standard declarations
using std::cout;
using std::cin;
using std::endl;

#ifndef SPHERE_H
#define SPHERE_H

#include "threeD.h"

class sphere : public threeDimension_Shape
{
public:
	sphere(float = 0, float = 0, float = 0, float = 0); // constructor
	double calcVolume();	// function to get volume
	double calcArea();	// function to get area
	void print();	//  function to print output
private:
	double area;	// variable to store area
	double volume;// variable to store volume
};

#endif
#pragma once
