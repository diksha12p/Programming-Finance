/*  Name: Diksha Prakash
Date: 11/16/2018
Homework 10
linkedlist.cpp : Definition of friend class		*/

#include <stdio.h>
#include "node.h"//call class node
#include "linkedlist.h"
#include <iostream>
using std::cout;

LinkedList::LinkedList() //constructor definition
	:myHead(0), myTail(0)
{
	mySize = 0; //intialisation
}

LinkedList::~LinkedList()//destructor 
{
	if (size() != 0) // List is not empty
	{
		cout << "Destroying nodes ...\n";

		Node *currentptr = myHead;
		Node *tempptr;

		while (currentptr != 0)// delete remaining nodes
		{
			tempptr = currentptr;
			currentptr = currentptr->next;
			delete tempptr;

		}//end while
	}//end if
}

int LinkedList::size() const
{
	return mySize; //returns current size of list
}

void LinkedList::addToStart(Node *n)
{
	if (size() == 0)// List is empty
		myHead = myTail = n;
	else                    // List is not empty
	{
		n->next = myHead;
		myHead = n;
	}
	mySize++;
}

void LinkedList::addToEnd(Node *n)
{
	if (size() == 0) //list is empty
		myHead = myTail = n;
	else               //list is not empty
	{
		myTail->next = n;
		myTail = n;
	}
	mySize++;
}

void LinkedList::printList()
{
	if (size() == 0)//list is empty
	{
		cout << "The list is empty\n\n";
		return;

	} // end if

	Node *currentptr = myHead;
	cout << "\n THE LIST: \n ";
	cout << "ITEM NO \t ITEM NAME \n";
	while (currentptr != 0)//printing the list with item no and name
	{
		cout << currentptr->itemNo << " \t\t " << currentptr->itemName << "\n";
		currentptr = currentptr->next;

	} // end while

	cout << "\n\n";

}

bool LinkedList::removeFromStart()
{
	if (size() == 0)     // List is empty
		return false;    // delete unsuccessful
	else
	{
		Node *tempptr = myHead;
		if (myHead == myTail)
			myHead = myTail = 0;
		else
			myHead = myHead->next;

		delete tempptr; // node being removed
		mySize--;
		return true;   // delete successful

	}
}

bool LinkedList::removeFromEnd()
{
	if (size() == 0)			// List is empty
		return false;		// delete unsuccessful
	else
	{
		Node *tempptr = myTail;
		if (myHead == myTail)
			myHead = myTail = 0;
		else
		{
			Node *currentptr = myHead;
			//// locate second-to-last element
			while (currentptr->next != myTail)
				currentptr = currentptr->next;

			myTail = currentptr;
			currentptr->next = 0;
		}
		delete tempptr;
		mySize--;
		return true;
	}
}

void LinkedList::removeNodeFromList(int number)
{
	if (size() == 0) //if list is empty
	{
		return;
	}
	Node *previous = NULL, *del = NULL;
	if (myHead->itemNo == number)
	{
		// point to the node to be deleted
		del = myHead;
		// update head of the list
		myHead = del->next;
		delete del;
		mySize--;
		return;
	}

	previous = myHead;
	del = myHead->next;

	//  check the value of each node in full list
	while (del != NULL)
	{
		if (del->itemNo == number)
		{
			// Update the list
			previous->next = del->next;
			// If it is the last node, update the tail
			if (del == myTail)
			{
				myTail = previous;
			}
			delete del;
			mySize--;
			break; // break and return
		}

		previous = del;
		del = del->next;
	}
	//If the item is not found
	if (del == NULL)
		std::cout << "\n The item cannot be found \n";

}

void LinkedList::removeNodeFromList(string item_name)
{
	if (size() == 0)//list is empty
	{
		return;
	}
	Node *previous = NULL, *del = NULL;
	if (myHead->itemName == item_name)
	{
		// point to the node to be deleted
		del = myHead;
		// update the head of the list
		myHead = del->next;
		delete del;
		mySize--;
		return;
	}

	previous = myHead;
	del = myHead->next;

	// check the value of each node in full list
	while (del != NULL)
	{
		if (del->itemName == item_name)
		{
			// Update the list
			previous->next = del->next;
			// If it is the last node, update the tail
			if (del == myTail)
			{
				myTail = previous;
			}
			delete del;
			mySize--;
			break; // break and return
		}

		previous = del;
		del = del->next;
	}
	//If the item is not found
	if (del == NULL)
		std::cout << "\n The item cannot be found \n";
}
