/*
Name : Diksha Prakash
RUID : 186001757
Date of Submission : 11/30/18
Program to perform operations on entered ISBNs list -- class declaration file
*/

#include<iostream>    // Standard input/output library
using std::cout;	  // Standard cout declaration
using std::cin;		  // Standard cin declaration
using std::endl;	  // Standard end line declaration

#include<iomanip>     // Input/output manipulation library
using std::setw;      // Set width function

#ifndef ISBNs_PrakashDiksha_h	// Define start of .h file
#define ISBNs_PrakashDiksha_h
const int max = 20;			// Constant maximum size of booklist is 20

template <class T>
class booklist		// declaration of class booklist
{
private:			// Private entities
	bool sorted;	// variable to tell if array sorted
	int size;		// Variable to store number of books
	int A[max];		// Array to store ISBN numbers of upto 20 books
	int sizeofarray;  // Variable to store array size
public:				// Public entities
	int flag;		// temporary counter variable to set if books added

	booklist();		// Constructor to initialize value
	void append(int[max], int, T&);		// Function to add element at end
	void insert(int[max], int, int, T&);	// Function to insert element at position
	int linear(int[max], int, T&);		// Function for linear search
	int binary(int[max], int, T&, bool);	// Function for binary search
	void deletepos(int[max], int, T&);	// Function for delete element at a position
	void deleteisbn(int[max], int, T&);// Function for  deleting a book
	void selectionsort(int[max], int);	// Function for selection sort
	void bubblesort(int[max], int);		// Function for bubble sort
	void display(int[max], int);		// function to display the list
};
#endif				// End of .h file
