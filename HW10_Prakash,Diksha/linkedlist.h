/*  Name: Diksha Prakash
Date: 11/16/2018
Homework 10
linkedlist.h : Class declaration	*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include"node.h"   //node class definition
#include<string>
#include <iostream>
using namespace std;

//declaration of class linkedlist
class LinkedList {
public:
	LinkedList(); //constructor
	~LinkedList();//destructor
	int size() const;
	void addToStart(Node *);
	void addToEnd(Node *);
	void printList();
	bool removeFromStart();
	bool removeFromEnd();
	void removeNodeFromList(int);
	void removeNodeFromList(string);
private:
	Node *myHead; //pointer to first node
	Node *myTail;//pointer to last node
	int mySize;//to store size of list
};
#endif

