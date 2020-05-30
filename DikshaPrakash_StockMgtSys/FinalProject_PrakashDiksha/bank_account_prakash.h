/*
NAME : DIKSHA PRAKASH
DATE : 12/17/2018
PROJECT : ACCOUNT MANAGEMENT SYSTEM
FILE : DERIVED CLASS .H FILE
*/
#pragma once

#include<iostream>	// Standard I/O library
#include<fstream>	// File I/O library
#include<string>	// Standard string operations library
#include<time.h>	// Library for time stamp

// include other class files
#include "account_prakash.h"

using namespace std;

#ifndef BANK_ACCOUNT_PRAKASH_H
#define BANK_ACCOUNT_PRAKASH_H

// Derived class BankAccount which inherits publicly from base class 'Account'
class BankAccount : public Account
{
public:
	BankAccount();             // consructor
	~BankAccount();            // destructor
	virtual double getBalance();	 // get cash balance
	virtual void setBalance();		 // set cash balance
	void balanceDisplay();         // view cash balance
	void depositCash(double);      // deposit cash
	void withdrawCash(double);     // withdraw cash
	virtual void historyPrint();   // print history

private:
	ofstream file;
	ifstream read_file;
	ifstream balance_file;
	ofstream writebalance_file;
	string line;
	double deposit;
	double withdraw;

};

#endif
#pragma once
