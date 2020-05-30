/*
NAME : DIKSHA PRAKASH
DATE : 12/17/2018
PROJECT : ACCOUNT MANAGEMENT SYSTEM
FILE : DERIVED CLASS .H FILE
*/

#pragma once
#include<iostream>				// Standard I/O library	
#include<fstream>				// File I/O library
#include<string>				// Standard string operations library
#include<time.h>				// Library for time stamp
#include<sstream>				// string stream library
#include<map>					// Standard template map for storing key and contents

// include base class and node class 
#include "account_prakash.h"
#include "node_prakash.h"

using namespace std;


#ifndef STOCK_ACCOUNT_PRAKASH_H
#define STOCK_ACCOUNT_PRAKASH_H

class Node;	// Forward declaration of Class Node

class StockAccount : public Account
{
public:
	StockAccount();					  // constructor for the class
	~StockAccount();				  // destructor for the class

	//Function prototypes
	void stockDisplay();			  // display the stock price to the users
	void portfolioDisplay();         // display current portfolio to the users
	void shareBuy(Node *);		  // buy the shares
	void shareSell();				  // sell the shares
	bool listSort();				 // sort the linked list
	void portfolioSave();			 // save portfolio
	void portfolioGet();		     // get portfolio
	virtual double getBalance();		 // get cash balance
	virtual void setBalance();			 // setting cash balance
	void portfolioValueSave();			 // save portfolio value and timestamp.
	void portfolioValueGet();			 // get portfolio value.
	//void plot_graph();				 // view portfolio value graph
	virtual void historyPrint();    // print stock history

private:
	string stock_symbol;	// Stock ticker at the text files
	int size;				// Size of the list
	int fileNum;			// For random selection between two text files
	int count;				// size of portfolio value array

	// Linked list nodes 
	Node *prev = NULL;
	Node *firstPtr;
	Node *secondPtr;

	double portfolioValue, port_array[100];		// Portfolio value and array of portfolio values
	string time_stamp[100];					// Array for time values
	int shares;								// Number of shares
	double maximum, minimum;				// Maximum and minimum amount user willing to pay for share
	ifstream balance_file, port_file, portval_file;	// Instances to access portfolio text files
	ifstream file1, file2;							// Instances to access stock info files
	// Temporary variables to store the different parts of the line read from files
	string temp1;
	int share_temp;
	// Containers to hold values
	//Class: Template
	//Behavioural Design Pattern
	map<string, double> result1, result2;
	map<string, int> portfolio;
	// Variables to store streams of strings from file
	stringstream stream1;
	stringstream stream2;
	stringstream stream3;
	// string holders for different parameters from the line 
	string line1, line2, symb1, date1;
	double price1;
	// output file instances 
	ofstream writebalance_file, write_bank_history, write_portfolio;
};

#endif


