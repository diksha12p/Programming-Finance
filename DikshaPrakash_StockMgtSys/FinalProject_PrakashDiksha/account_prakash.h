/*
NAME : DIKSHA PRAKASH
DATE : 12/17/2018
PROJECT : ACCOUNT MANAGEMENT SYSTEM
FILE : BASE CLASS .H FILE
*/

#pragma once
#ifndef ACCOUNT_PRAKASH
#define ACCOUNT_PRAKASH

class Account	// abstract base class - Account
{
protected:
	double cashbalance;	// cashbalance = cash balance, accessible to derived classes

public:
	virtual double getBalance() = 0;	// get cash balance
	virtual void setBalance() = 0;		// set cash balance
	virtual void historyPrint() = 0;	// Print history of transaction	
};

#endif