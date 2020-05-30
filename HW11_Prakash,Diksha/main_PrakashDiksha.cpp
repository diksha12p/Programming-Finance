/*
Name : Diksha Prakash
RUID : 186001757
Date of Submission : 11/30/18
Program to perform operations on entered ISBNs list -- file for main function source
*/


#include <iostream>
#include <string>
#include <vector>
#include "Booklist.h"

using namespace std;

int main() {

Booklist<string> listOfBooks;

int choice;

do

{
cout << "What operation would you like to perform ? \n \n";  //Asking the user for an input corresponding to the choice of operation to be performed
cout << "  " << " 1. Add an element to end of list\n";
cout << "  " << " 2. Add an element at a location\n";
cout << "  " << " 3. Delete an Element based on Book Name";
cout << "  " << " 4. Find an element by ISBN number (binary search)\n";
cout << "  " << " 5. Sort the list using selection sort \n";
cout << "  " << " 6. Sort the list using bubble sort\n";
cout << "  " << " 7. Find an Element by Book Name using Linear Search \n";
cout << "  " << " 8. Find an Element by Book Name using Binary Search\n";
cout << "  " << " 9. Print the list\n";
cout << "  " << " 0. Exit\n";
cout << "\n" << "\n" << "Enter your choice : \n";

cin >> choice;

switch (choice)
{
case 1:
  listOfBooks.add_at_end();
  break;

case 2:
  listOfBooks.add_at_pos();
  break;

case 3:
  listOfBooks.delete_at_pos();
  break;

case 4:
  listOfBooks.delete_by_name();
  break;

case 5:
  listOfBooks.selection_sort();
  break;

case 6:
  listOfBooks.bubble_sort();
  break;

case 7:
  listOfBooks.find_using_linear_search();
  break;

case 8:
  listOfBooks.find_using_binary_search();
  break;

case 9:
  listOfBooks.display_list();
  break;
}

} while (choice != 0);
return 0;
}
