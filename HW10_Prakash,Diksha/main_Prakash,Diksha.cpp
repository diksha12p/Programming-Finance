/*  Name: Diksha Prakash
Date: 11/16/2018
Homework 10
main_Prakash,Diksha.cpp : Main function file		*/

#include <iostream>
#include "node.h"  //call class node
#include "linkedList.h" //call the class linkedlist
#include <string>

using std::string;
using std::cout;
using std::cin;


int main()
{
	Node *n;
	LinkedList L;
	int choice; //to store choice of used
	int i_no; //to store item number
	string i_name; //to store item name

	do
	{
		//menu
		cout << "\n			MENU :			 \n";
		cout << "\n 1.  Add a new node at the beginning";
		cout << "\n 2.  Add a new node at the end";
		cout << "\n 3.  Remove the beginning node";
		cout << "\n 4.  Remove the end node";
		cout << "\n 5.  Remove a node from the list by entering an item number";
		cout << "\n 6.  Remove a node from the list by entering an item name";
		cout << "\n 7.  Print out the list";
		cout << "\n 0.  Quit the program\n";
		//read the choice
		cin >> choice;S

		switch (choice)
		{
		case 1:
			cout << "\nPlease enter product number to insert at beginning\n";
			cin >> i_no;
			cout << "\nPlease enter the name for the product\n";
			cin >> i_name;
			n = new Node(i_name, i_no);
			L.addToStart(n);//adds the new addition to the list
			L.printList(); //printing the list
			break;

		case 2:
			cout << "\nPlease enter product number to insert at end\n";
			cin >> i_no;
			cout << "\nPlease enter the name for the product\n";
			cin >> i_name;
			n = new Node(i_name, i_no); //new node created
			L.addToEnd(n); //adds to the end of the list
			L.printList();//printing the list
			break;

		case 3:
			if (L.removeFromStart())//if list is not empty
				cout << "\nDelete Successful \n";
			else
				cout << "\nNo node to delete \n";//if list is empty
			//Printing the list
			L.printList();
			break;

		case 4:
			//if list is not empty
			if (L.removeFromEnd())
				cout << "\nDelete Successful \n";
			else
				cout << "\nNo node to delete \n";//if list is empty
			L.printList();//printing the list
			break;

		case 5:
			cout << "\nEnter the item Number you want to delete\n";
			cin >> i_no;
			L.removeNodeFromList(i_no); //removes the specific i_no node
			L.printList();//printing the updated list
			break;

		case 6:
			cout << "\nEnter the item Name you want to delete\n";
			cin >> i_name;
			L.removeNodeFromList(i_name);//removes the specific i_name node
			L.printList();//printing the updated list
			break;

		case 7:
			//Printing the list
			L.printList();
			break;

		case 0:
			std::exit(1);  //quit the program
		}

	} while (choice != 0);
	return 0;//successfully terminated the program
}
