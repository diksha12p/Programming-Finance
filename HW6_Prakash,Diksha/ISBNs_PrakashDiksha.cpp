/*
Name : Diksha Prakash
RUID : 186001757
Date of Submission : 11/30/18
Program to perform operations on entered ISBNs list -- class member function definitions
*/

#include<iostream>    // Standard input/output library
using std::cout;	  // Standard cout declaration
using std::cin;		  // Standard cin declaration
using std::endl;	  // Standard end line declaration

#include<iomanip>     // Input/output manipulation library
using std::setw;      // Set width function

#include "ISBNs_PrakashDiksha.h"	// Linking of the .h file containing class declaration

int i, j;				// iteration variables

template <class T>
booklist<T>::booklist()	// Default contructor for the class
{
	sizeofarray = 0;			// Variable to store number of books
	A[max] = { 0 };		// Array to store ISBN numbers of upto 20 books
	sorted = 1;			// Set that booklist is sorted
}

template <class T>
booklist<T>::~booklist() {
	A.clear();
}

template <class T>
void booklist<T>::append(int A[max], int sizeofarray, T &new_element) // Function to add at end
{
	if (sizeofarray == 20)   // Check if sizeofarray out of bounds
	{
		cout << "\n Cannot add more. Maximum limit reached. Can contain 20 books only ! \n\n";
	}
	else
	{
		for (i = 0; i < sizeofarray; i++)		// Check if new_element is repeated
		{
			if (A[i] == new_element)		// if new_element already exists, delete previous one and replace new one
			{
				A[i] = new_element;
				flag = 0;				// Sets that sizeofarray has not increased
				cout << "\n    This ISBN is already at the list. " << endl;
				break;
			}
			else
			{
				A[sizeofarray] = new_element;	// Update the array
				flag = 1;			// set that a new element has been added
			}
		}
	}
}


template <class T>
void booklist<T>::insert(int A[max], int sizeofarray, int pos, T &new_element)	// function to insert new_element at given position
{
	if (sizeofarray == 20)   // Check if out of bounds
	{
		cout << "\n Cannot add more. Maximum limit reached. Can contain 20 books only ! \n\n";
	}
	else
	{
		T i;
		for (i = sizeofarray; i > pos; i--)
		{
			A[i] = A[i - 1];	// shift the new_elements
		}
		A[pos] = new_element;	// add the new element
	}
}


template <class T>
int booklist<T>::linear(int A[max], int sizeofarray, T &new_element)	// function for linear search
{
	int pos = -1;	// initial pos is invalid
	for (i = 0; i < sizeofarray; i++)
	{
		if (A[i] == new_element)	// if found at current location
		{
			pos = i + 1;	// new pos
		}
	}
	return pos;	// return the final pos
}


template <class T>
int booklist<T>::binary(int A[max], int sizeofarray, T &new_element, bool sorted)	// Function to search an new_element using binary search
{
	if (sorted == 1)			// If the booklist is already sorted
	{
		T middle = -1;					// variable to store middle value
		T low = 0, high = sizeofarray;	// set values of lowest and highest values
		while (low <= high)			// check is lowest value is less than highest
		{
			// determine middle new_element
			middle = (low + high) / 2;
			// if new_element matches middle new_element, return middle
			if (new_element == A[middle])  // match
			{
				return middle + 1;	// middle + 1 is the pos as per display menu
				//break;
			}
			else
			{	 // if new_element less than middle new_element,
				 // set a new high new_element
				if (new_element < A[middle])
					high = middle - 1;  // search low end of array
				else
					low = middle + 1;   // search high end of array
			}
		}
		return -1;
	}
	else		// If the booklist is not sorted, ask user to sort it first
	{
		cout << "\n The list needs to be sorted first. Please sort the list using option 7 or 8.";
		return 0;  // new_element not found
	}
}

template <class T>
void booklist<T>::deletepos(int A[max], int sizeofarray, T &pos)	// function to delete at pos
{

	for (i = pos; i < sizeofarray; i++)
	{
		A[i - 1] = A[i];	// shift the new_elements upwards
	}
	cout << " \n ISBN deleted. ";
}
void booklist::deleteisbn(int A[max], int sizeofarray, T &new_element)	// function to delete ISBN
{
	int pos;
	pos = linear(A, sizeofarray, new_element);	// find its pos
	deletepos(A, sizeofarray, pos);	// delete new_element using pos
}


template <class T>
void booklist<T>::selectionsort(int A[max], int sizeofarray)	// function to sort using selection sort,  using pointers to access array
{

	int first, temp;	// temporary variables
	for (i = sizeofarray - 1; i > 0; i--)
	{
		first = 0;                 // initialize first new_element
		for (j = 1; j <= i; j++)   // find smallest between poss 1 and i.
		{
			if (*(A + j) > *(A + first))
				first = j;
		}
		temp = *(A + first);   // Swap smallest with new_element at pos i.
		*(A + first) = *(A + i);
		*(A + i) = temp;
	}
}

template <class T>
void booklist<T>::bubblesort(int A[max], int sizeofarray)	// function for bubble sort, using pointers to access array
{

	int temp; // holding variable
	int flag = 1;
	for (i = 1; (i <= sizeofarray) && flag; i++)
	{
		flag = 0;
		for (j = 0; j < (sizeofarray - 1); j++)
		{
			if (*(A + j + 1) < *(A + j))     // check if smaller than previous new_element
			{
				temp = *(A + j);             // swap new_elements
				*(A + j) = *(A + j + 1);
				*(A + j + 1) = temp;
				flag = 1;               // indicates that a swap occurred.
			}
		}
	}
	flag = 1;
}

template <class T>
void booklist<T>::display(int A[max], int s)	// function to display the final list
{
	if (s == 0) { cout << "\n List empty. No books in list. Press 1 at menu to add first new_element. " << endl; }
	else
	{
		cout << "\n The list is now: \n\n";// display the list
		cout << "  pos   ISBN ";
		for (i = 0; i < s; i++)
		{
			cout << endl << "         " << i + 1 << " :  " << A[i];
		}
		cout << endl;
	}
}
