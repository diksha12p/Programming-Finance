#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#ifndef SHAPE_PRAKASH_H
#define SHAPE_PRAKASH_H

class shape
{
public:
	//Default constructor
	shape();
	//Constructor
	shape(float, float);

	//Function prototypes
	void setX(float);			//Function to set the value of X co-ordinate
	void setY(float);			//Function to set the value of Y co-ordinate
	float getX();			//Function to get the value of X co-ordinate
	float getY();			//Function to get the value of Y co-ordinate

	//Variables to store the co-ordinates X and Y
	float x, y;
};

#endif
#pragma once
