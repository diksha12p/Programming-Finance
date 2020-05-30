/*
NAME : DIKSHA PRAKASH
DATE : 12/17/2018
PROJECT : ACCOUNT MANAGEMENT SYSTEM
FILE : DERIVED CLASS .CPP FILE
*/
#include<iostream>	// Standard I/O library
#include<iomanip>	// standard I/O manipulation library

#include<string>	// Standard string operations library
#include<stdlib.h>	// standard library
#include<time.h>	// Library for time stamp
#include<fstream>	// File I/O library


using namespace std;

// including the class files
#include "bank_account_prakash.h"

//constructor for the class
BankAccount::BankAccount()
{
	setBalance();
	deposit = 0;
	withdraw = 0;
}

// Get cash balance
double BankAccount::getBalance()
{
	return cashbalance;
}

// Set cash balance
void BankAccount::setBalance()
{
	streampos len;
	ifstream file1;
	file1.open("balance_file.txt", ios::binary);     // open balance file
	if (file1.is_open())
	{
		file1.seekg(0, ios::end);              // put console at end of file
		len = file1.tellg();				   // find the position of the cursor
		file1.close();                         // close file
	}

	if (!len) // put default cash balance of 10000
	{
		double cash = 10000.00;
		ofstream file2;
		file2.open("balance_file.txt", ios_base::out);
		file2 << cash;
		file2.close();

		ifstream file3("balance_file.txt", ios_base::in);
		file3 >> cashbalance;
		file3.close();
	}
	else
	{
		// else update balance from existing cash balance 
		ifstream file4("balance_file.txt", ios_base::in);
		file4 >> cashbalance;
		file4.close();
	}
}

//Deposit the cash
void BankAccount::depositCash(double amount)
{
	deposit = amount;
	cashbalance = getBalance();
	cashbalance = cashbalance + deposit;
	cout << "\nAmount $" << deposit << " is Deposited to the Account\n";

	// Generate the current date and timestamp for storage purpose
	time_t R;
	struct tm T;
	char buffer[80];
	time(&R);
    localtime_r(&T, &R);
	strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", &T);
	std::string str(buffer);

	// Writing the deposit transaction to bank_transaction_history.txt file
	file.open("bank_transaction_history.txt", ios::app);
	file << endl << left << setw(30) << "Deposit";
	file << left << setw(1) << "$";
	file << left << setw(15) << deposit;
	file << right << setw(15) << str;
	file << right << setw(5) << "$" << cashbalance;
	file.close();

	// Writing to the balance file for transaction log purpose
	writebalance_file.open("balance_file.txt", std::ios_base::out);
	writebalance_file << cashbalance;
	writebalance_file.close();
}

//Display cash balance
void BankAccount::balanceDisplay()
{
	setBalance();
	cout << "\nCurrent Cash Balance : " << getBalance() << "$" << endl;
}


//withdraw cash
void BankAccount::withdrawCash(double amount)
{
	withdraw = amount;
	setBalance();
	cashbalance = getBalance();

	if (cashbalance > 0)	//check if cash balance is greater than 0 
	{
		if (withdraw > cashbalance)
		{
			cout << "\nSorry! The Balance is insufficient! Withdrawal Denied!\n";
			return;
		}

		else
		{
			cashbalance = cashbalance - withdraw; // update cash balance after withdrawl
			cout << "\nAmount $" << withdraw << " is withdrwan from the Account\n";

			//generate the current date and timestamp
			time_t R;
			struct tm T;
			char buffer[80];
			time(&R);
			localtime_s(&T, &R);
			strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", &T);
			std::string str(buffer);

			// write withdrawal transaction to file
			file.open("bank_transaction_history.txt", ios::app);
			file << endl << left << setw(30) << "Withdrawal";
			file << left << setw(1) << "$";
			file << left << setw(15) << withdraw;
			file << right << setw(15) << str;
			file << right << setw(5) << "$" << cashbalance;
			file.close();

			// write to a balance file
			writebalance_file.open("balance_file.txt", std::ios_base::out);
			writebalance_file << cashbalance;
			writebalance_file.close();

			return;
		}
	}
	else
	{
		cout << "\nThe Account Balance is NILL, withdrawal denied!\n";
	}
}

//print history
void BankAccount::historyPrint()
{
	read_file.open("bank_transaction_history.txt", ios::app);
	cout << endl << left << setw(30) << "Transaction";
	cout << left << setw(16) << "Amount";
	cout << left << setw(23) << "Timestamp";
	cout << right << setw(5) << "Balance" << endl;
	if (read_file.is_open())
	{
		while (!read_file.eof())
		{
			while (getline(read_file, line))
				cout << line << "\n";
		}
	}
	read_file.close();
}

// destructor
BankAccount::~BankAccount()
{
	cout << "\nAccount Exited!";
}
