/*
Name : Diksha Prakash
RUID : 186001757
Date of Submission : 10/20/18
Member-function definitions for class IntegerSet.
*/

#include <iostream>
#include <iomanip>
using namespace std;

/* Write include directive for IntegerSet.h here */
#include"IntegerSet.h"


// constructor
IntegerSet::IntegerSet()
{
	for (int i = 0; i < 101; i++) set[i] = 0;
} // end IntegerSet constructor

  // input a set from the user
void IntegerSet::inputSet()
{
	int number;

	do
	{
		cout << "Enter an element (-1 to end): ";
		cin >> number;

		if (validEntry(number))
			set[number] = 1;
		else if (number != -1)
			cout << "Invalid Element\n";
	} while (number != -1); // end do...while

	cout << "Entry complete\n";
} // end function inputSet

  // prints the set to the output stream
void IntegerSet::printSet() const
{
	cout << "{ ";

	for (int u = 0; u < 101; u++)
		if (set[u]) cout << u << " ";

	cout << "}" << endl;
	} // end function printSet


	  /* Write definition for unionOfSets */
IntegerSet IntegerSet::UnionOfSets(IntegerSet set2)			//function definition of unionset return type as class name
{
	IntegerSet set3;										//to store result matrix
	for (int i = 0; i < 101; i++)
	{														//logic for finding union of set
		if (set[i] == 1 || set2.set[i] == 1)
			set3.set[i] = 1;
	}
	return set3;
}

	  /* Write definition for intersectionOfSets */
IntegerSet IntegerSet::IntersectionOfSets(IntegerSet set2)			//function definition of intersection of set return type as class name
{
	IntegerSet set3;											//to store result of matrix
	for (int i = 0; i < 101; i++)								//logic for finding intersection of sets
	{
		if (set[i] == 1 && set2.set[i] == 1)
			set3.set[i] = 1;
	}
	return set3;
}
