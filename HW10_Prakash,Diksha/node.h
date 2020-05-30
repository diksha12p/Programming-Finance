/*  Name: Diksha Prakash
Date: 11/16/2018
Homework 10
node.h : Node declaration	*/

#ifndef NODE_H
#define NODE_H 
#include<iostream>
#include<string>

using namespace std;
//declaration of class node
class Node {
	friend class LinkedList; //make linkedlist a friend
public:
	Node(string &name, int no) //constructor
		:itemName(name), itemNo(no)  //initialisation
	{
		this->next = NULL;       //next node null
	}
private:
	string itemName; //to store item name
	int itemNo; // to store item no
	Node *next; //next node in the list
};
#endif
