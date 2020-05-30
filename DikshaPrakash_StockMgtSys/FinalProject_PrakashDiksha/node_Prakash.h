/*
NAME : DIKSHA PRAKASH
DATE : 12/17/2018
PROJECT : ACCOUNT MANAGEMENT SYSTEM
FILE : NODE CLASS .H FILE FOR LINKED LIST
*/
#pragma once

#include<iostream>	// Standard I/O library
#include<string>	// Standard string operations library
//Including other classes
#include "account_prakash.h"
#include "stock_account_prakash.h"

using namespace std;

#ifndef NODE_PRAKASH_H
#define NODE_PRAKASH_H

class Node
{
	friend class StockAccount;		//Declaring 'StockAccount' as a friend class of 'Node'
public:
	Node()	//Constructor
	{
		this->nextptr = NULL;
		this->prevptr = NULL;
	}
private:

	string symb;		// stock symbol
	int share_num;		// number of shares
	double price;      // Price per share 
	double priceTemp; // Temporary price per share for sorting purpose
	double currentPortfolioVal;         //Current value of a portfolio node 
// Parameters for Double Linked List 
	Node *nextptr;	// Next pointer of the node
	Node *prevptr;	// Previous pointer of the node
};

#endif

