#include<iostream>    // Standard input/output library
#include<iomanip>     // Input/output manipulation library

using namespace std;

#include "Booklist.h"

// Class Function Declarations
template<class Book>
inline Booklist<Book>::Booklist()
{
}

//Display the List
template<class Book>
inline void Booklist<Book>::display_list()
{
cout << "-----LIST------" << endl;
for (auto itr = listBooks.begin(); itr != listBooks.end(); ++itr)
{
  cout << " " << *itr << "\t";
}
cout << endl;
}

//To add the Book name at End of the list
template<class Book>
void Booklist<Book>::add_at_end()
{
Book input;
cout << "Enter the name of the book to be added : " << endl;
cin >> input;
listBooks.push_back(input); this->display_list();
}

//	Add book at specific position
template<class Book>
inline void Booklist<Book>::add_at_pos()
{
Book input;
int pos;
bool found=false;
do {
if (found)
{
  cout << "ERROR : Position out of bound !!!!" << endl;
}
cout << "Enter a valid the position at which you want to add book" << endl;
cin >> pos;
found = true;
} while (pos > listBooks.size());

cout << "Enter the name of the book you want to add : " << endl; cin >> input;
listBooks.insert(listBooks.begin() + pos, input);
// STL insert function
this->display_list();
}


//	Delete at specific postion
template<class Book>
inline void Booklist<Book>::delete_at_pos()
{
int pos;
bool found = false;
do {
if (found) cout << "Position out of bound" << endl;
cout << "Enter a valid the position at which you want to delete book" << endl;
cin >> pos;
found=pos<listBooks.size();
} while (!found);
listBooks.erase(listBooks.begin() + pos);// Erase Function
this->display_list();
}

//	Delete by specific user input name template<class Book>
inline void Booklist<Book>::delete_by_name()
{
Book input;
bool found = false;
do {
if (found) cout << "Book name not in list. Enter correct name" << endl; found = true;
cout << "Enter a valid book name you want to delete" << endl; cin >> input;
for (int i = 0; i < listBooks.size(); i++) {
if (listBooks[i] == input) {
listBooks.erase(listBooks.begin() + i);
found = false;
break;
}
}

} while (found); this->display_list();
}

//	Linear Search
template<class Book>
inline int Booklist<Book>::linear_searcher(Book input)
{
for (int i = 0; i < listBooks.size(); i++)
if (listBooks[i] == input)
return i;
return -1;
}

//	Linear search for finding input
template<class Book>
inline void Booklist<Book>::find_using_linear_search()
{
Book input;
cout << "\n Enter a valid book name you want to search" << endl;
cin >> input;
int pos = linear_searcher(input);
if (pos != -1)
{
  cout << "Element found in List at position " << pos << endl;
}
else
{
  cout << "Book name not in list." << endl;
}
this->display_list();
}

//	Binary Search
template<class Book>
inline int Booklist<Book>::binary_searcher(Book input,int start_pos,int end_pos)
{
if (end_pos >= start_pos) {
int midpos = start_pos + (end_pos - start_pos) / 2;
if (listBooks[midpos] == input)
return midpos;
if (listBooks[midpos] > input)
return binary_searcher(input, start_pos, midpos - 1); return binary_searcher(input,midpos + 1, end_pos);
}
return -1;
}

//Binary search for finding input
template<class Book>
inline void Booklist<Book>::find_using_binary_search()
{
sort(listBooks.begin(), listBooks.end());
cout << " Sorted List is:";
this->display_list();
Book input;
cout << "\n Enter a valid book name you want to search" << endl;
cin >> input;
int pos = binary_searcher(input,0,listBooks.size());
if (pos != -1)
{
  cout << "Element found in List at position " << pos << endl;
}
else
{
  cout << "Book name not in list." << endl;
}
this->display_list();

}

//	Selection Sort
template<class Book>
inline void Booklist<Book>::selection_sort()
{
for (auto itr = listBooks.begin(); itr != listBooks.end(); itr++) {
  iter_swap(itr, min_element(itr, listBooks.end()));
}
this->display_list();
}

//	Bubble Sort template<class Book>

inline void Booklist<Book>::bubble_sort()
{
for (int i = 0; i < listBooks.size() - 1; i++)
for (int j = 0; j < listBooks.size() - i - 1; j++)
if (listBooks[j] > listBooks[j + 1])
swap(listBooks[j], listBooks[j + 1]);
this->display_list();
}

// Function for testing.
template<class Book>
inline vector<Book> Booklist<Book>::getBook()
{
return listBooks;
}
