/*
Name : Diksha Prakash
RUID : 186001757
Date of Submission : 11/30/18
Program to perform operations on entered ISBNs list -- file for main function source
*/

#include<iostream>    // Standard input/output library
using std::cout;	  // Standard cout declaration
using std::cin;		  // Standard cin declaration
using std::endl;	  // Standard end line declaration

#include<iomanip>    // Input/output manipulation library
using std::setw;     // Set width function

#include "ISBNs_PrakashDiksha.h"


int main()			// Start of main function
{
	booklist< string > b;		// local object instance of class for calling booklist class functions
	int choice;		// Initialise variable for storing the user choice
	int B[max] = { 0 };
	int element = 0;
	int position = 0;
	bool sort = 0;
	int s = 0;		// Variable to store number of books
	int i;
	cout << "Book list is empty. ";
	cout << endl << "Enter first book  :  ";
	cin >> B[0];
	while (cin.fail() || B[0] <= 0)        // If input is not valid
	{
		cout << "  INVALID ENTRY ! Try again: \n";    // Error message
		cin.clear();                                // Clear console
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
		cin >> B[0];    // input again
	}
	++s;
	b.display(B, s);

	do
	{
		// MAIN MENU -
		cout << "What operation would you like to perform ? \n \n";  //Asking the user for an input corresponding to the choice of operation to be performed
    cout << "  " << " 1. Add an element to end of list\n";
  	cout << "  " << " 2. Add an element at a location\n";
  	cout << "  " << " 3. Find an element by ISBN number (linear search)\n";
  	cout << "  " << " 4. Find an element by ISBN number (binary search)\n";
  	cout << "  " << " 5. Delete an element at position\n";
  	cout << "  " << " 6. Delete an element by ISBN number\n";
  	cout << "  " << " 7. Sort the list using selection sort\n";
  	cout << "  " << " 8. Sort the list using bubble sort\n";
  	cout << "  " << " 9. Print the list\n";
  	cout << "  " << " 0. Exit\n";
    cout << "\n" << "\n" << "Enter your choice : \n";

		cin >> choice;	// Store in the variable
		while (cin.fail() || choice > 9 || choice < 0)        // If input is not valid
		{
			cout << "  INVALID ENTRY ! Try again: ";    // Error message
			cin.clear();                                // Clear console
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
			cin >> choice;    // input again
		}
		switch (choice)
		{

		case 1:
			cout << " Enter element to add at end : ";	// Take user input
			cin >> element;
			while (cin.fail() || element <= 0)        // If input is not valid
			{
				cout << "  INVALID ENTRY ! Try again: ";    // Error message
				cin.clear();                                // Clear console
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
				cin >> element;    // input again
			}
			b.append(B, s, element);	// Function call to add element at end
			if (s < max && b.flag == 1)	// While size not out of bound and new element added
			{
				++s;			// update size
				b.display(B, s);	// display the list
			}
			break;


		case 2:
			if (s == 0)	// if no elements exist
			{
				cout << "\n List is empty. Add first element :  ";
				cin >> B[0];	// add to first index
				while (cin.fail() || B[0] <= 0)        // If input is not valid
				{
					cout << "  INVALID ENTRY ! Try again: ";    // Error message
					cin.clear();                                // Clear console
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
					cin >> B[0];    // input again
				}
				++s;	// update size
				b.display(B, s); // display the list
				break;
			}
			cout << " Enter the element to add : ";// Take user input
			cin >> element;
			while (cin.fail() || element <= 0)        // If input is not valid
			{
				cout << "  INVALID ENTRY ! Try again: ";    // Error message
				cin.clear();                                // Clear console
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
				cin >> element;    // input again
			}
			cout << " Enter the position to add : ";
			cin >> position;
			while (cin.fail() || position > s || position < 1)        // If input is not valid
			{
				cout << "  INVALID ENTRY ! Try again: ";    // Error message
				cin.clear();                                // Clear console
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
				cin >> position;    // input again
			}
			b.insert(B, s, position - 1, element);	// function call to insert element at a position
			if (s < max)	// if size is not out of bounds
			{
				s++;			//update size
				b.display(B, s);	// display the list
			}
			break;


		case 3:
			cout << " Enter the ISBN number to find : ";// Take user input
			cin >> element;
			while (cin.fail() || element <= 0)        // If input is not valid
			{
				cout << "  INVALID ENTRY ! Try again: ";    // Error message
				cin.clear();                                // Clear console
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
				cin >> element;    // input again
			}
			position = b.linear(B, s, element);	// Get the value of position
			if (position != -1)	// If element found
			{
				cout << "\n ISBN # " << element << " Found at position:  " << position << "." << endl;
			}
			else { cout << " \n ISBN Not Found ! \n\n"; }	// If element not found
			break;


		case 4:
			cout << "\n Enter ISBN number to search :  ";// Take user input
			cin >> element;
			while (cin.fail() || element <= 0)        // If input is not valid
			{
				cout << "  INVALID ENTRY ! Try again: ";    // Error message
				cin.clear();                                // Clear console
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
				cin >> element;    // input again
			}
			for (i = 0; i < s - 1; i++)			// Check if the booklist is in order / sorted or not
			{
				if (B[i] <= B[i + 1]) { sort = 1; continue; }	// If already sorted, set sort =1, else 0
				else { sort = 0; break; }
			}
			position = b.binary(B, s, element, sort);	// Get the value of position
			if (position == 0) { break; }	// Come out of loop if array not sorted
			if (position != -1)		// If element found
			{
				cout << "\n ISBN # " << element << " Found at position: " << position << " ." << endl;
			}
			else	// If element not found
			{
				cout << "\n\n ISBN Not Found ! \n\n";
			}
			break;


		case 5:
			if (s == 0)		// If list is empty
			{
				cout << "\n List is empty. Cannot delete ! " << endl;
				break;
			}
			cout << "\nEnter the position to delete: ";// Take user input
			cin >> position;
			while (cin.fail() || position > s || position < 1)        // If input is not valid
			{
				cout << "  INVALID ENTRY ! Try again: ";    // Error message
				cin.clear();                                // Clear console
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
				cin >> position;    // input again
			}
			b.deletepos(B, s, position);	// Function call to delete by position
			s--;		// update the size
			b.display(B, s);	// display the list
			break;


		case 6:
			if (s == 0)	// If list is empty
			{
				cout << "\n List is empty. Cannot delete ! " << endl;
				break;
			}
			cout << "\n Enter ISBN number to delete:  ";// Take user input
			cin >> element;
			while (cin.fail() || element <= 0)        // If input is not valid
			{
				cout << "  INVALID ENTRY ! Try again: ";    // Error message
				cin.clear();                                // Clear console
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
				cin >> element;    // input again
			}
			b.deleteisbn(B, s, element);	// Function call to delete by ISBN
			s--;	// update the size
			b.display(B, s);
			break;


		case 7:
			b.selectionsort(B, s);	// Function call to sort by selection
			b.display(B, s);	// display the list
			break;


		case 8:
			b.bubblesort(B, s);	// Function call to bubble sort
			b.display(B, s);	// display the list
			break;


		case 9:
			b.display(B, s);	// display the list
			break;


		case 0:		cout << "\n Program exited. ";	break;	// Successfully exit program
		default:	choice = 0;
			break;
		}
	} while (choice != 0);	// While choice is not to exit

	return 0;	// Successfully exit program
}	// End of main function
