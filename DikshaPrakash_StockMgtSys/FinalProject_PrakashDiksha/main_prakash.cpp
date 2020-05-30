/*
NAME : DIKSHA PRAKASH
DATE : 12/17/2018
PROJECT : ACCOUNT MANAGEMENT SYSTEM
FILE : MAIN FUNCTION FILE
*/


#include <iostream>			// standard console I/O library
#include <string>			// string library
#include <fstream>			// file streaming library
#include <sstream>			// string stream library

// include other class files
#include "account_prakash.h"
#include "bank_account_prakash.h"
#include "stock_account_prakash.h"
#include "node_prakash.h"
using namespace std;

//	1.Object of class BankAccount
//	2.Global access
//	3.Singleton design pattern
BankAccount BA;

int main()
{
	int choice1 = 0, choice2 = 0, choice3 = 0;  // Menu choice variables
	double deposit = 0, withdraw = 0;			// deposit and withdraw variables

	StockAccount *stockAccPtr = new StockAccount();	// Pointer object to class StockAccount

	Node *node = NULL;						// New node created for linked list

	cout << "			Welcome To 'ACMIS' : The Personalized Account Management System			"<<endl;;
	cout << "										 MAIN MENU :			     ";

	bool flag1 = true;	// temporary flag

	while (choice1 != 3)
	{
		// MAIN MENU
		cout << "=========================================================================================" << endl;
		cout << "\n   Choice # 1. Stock Portfolio Account"
			<< "\n    Choice # 2. Bank Account"
			<< "\n    Choice # 3. Quit";
		cout << endl;
		cout << "=========================================================================================" << endl;
		cout << "Please enter your choice"<<endl;
		cin >> choice1;

		switch (choice1)
		{
		case 1:
			// Stock Account Menu
			while (choice2 != 8)
			{
				cout << "\n";
				cout << "=========================================================================================" << endl;
				cout << "\n				STOCK PORTFOLIO ACCOUNT						";
				cout << "\n Choice #1. Display the Stock Symbol's price"
					<< "\n Choice #2. Display the Current Portfolio"
					<< "\n Choice #3. Buy the Shares"
					<< "\n Choice #4. Sell the Shares"
					<< "\n Choice #5. View the Graph for the Portfolio Value Variation"
					<< "\n Choice #6. View the Transaction History"
					<< "\n Choice #7. Sort the Stock List"
					<< "\n Choice #8. Previous Menu"<<endl;
				cout << "=========================================================================================" << endl;
				cout << "\nPlease Enter Your Choice : ";
				cin >> choice2;
				switch (choice2)
				{
				case 1:
					stockAccPtr->stockDisplay();	// display stock prices
					break;
				case 2:
					stockAccPtr->portfolioDisplay();	// display portfolio
					break;
				case 3:
					node = new Node();
					stockAccPtr->shareBuy(node);	// Buy shares
					break;
				case 4:
					stockAccPtr->shareSell();		// sell shares
					break;
				case 5:
					//stockAccPtr->plot_graph();		// Plot MATLAB graph
					break;
				case 6:
					stockAccPtr->historyPrint();	// Print transaction history
					break;
				case 7:
					flag1 = stockAccPtr->listSort();	// Sort the linked list
					if (flag1 == false)
						cout << "\nERROR! Empty list."<<endl;
					else
						cout << "\nSuccess! Stock list is now sorted!"<<endl;
					break;
				case 8:
					break;
				default:
					cout <<endl;
				}
			}
			choice2 = 0;
			break;

		case 2:
			// Bank account Menu
			while (choice3 != 5)
			{
				cout << "\n";
				cout << "=========================================================================================" << endl;
				cout << "\n				BANK ACCOUNT				";
				cout << "\n Choice #1. View the Account Cash Balance"
					<< "\n Choice #2. Deposit Money"
					<< "\n Choice #3. Withdraw Money"
					<< "\n Choice #4. Print the History"
					<< "\n Choice #5. Previous Menu";
				cout << "\n";
				cout << "=========================================================================================" << endl;
				cout << "\nPlease Enter Your Choice : ";
				cin >> choice3;
				switch (choice3)
				{
				case 1:
					BA.balanceDisplay();		// display bank balance
					break;
				case 2:
					cout << "\nPlease Enter the Amount to Deposit ($) : ";
					cin >> deposit;				// temporary amount variable
					BA.depositCash(deposit);	// call deposit function
					break;
				case 3:
					cout << "\nEnter Amount to Withdraw ($): ";
					cin >> withdraw;			// temporary amount variable
					BA.withdrawCash(withdraw); // call withdraw function
					break;
				case 4:
					BA.historyPrint();		// call function to print transaction history
					break;
				case 5:
					break;		// go back to previous menu
				default:
					cout << "\n ERROR! Invalid choice!";
				}
			}
			choice3 = 0;
			break;
		case 3: // if user exits from main menu, save all data
			stockAccPtr->portfolioSave();    // save portfolio.
			stockAccPtr->portfolioValueSave();    // save portfolio value and timestamp
			cout << "\nSystem has been exited!";
			break;
		default:
			cout << "\nERROR! Invalid choice!";
		}
	}
} // End of main function
