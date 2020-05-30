/*
NAME : DIKSHA PRAKASH
DATE : 12/17/2018
PROJECT : ACCOUNT MANAGEMENT SYSTEM
FILE : DERIVED CLASS .CPP FILE
*/

// Library files for linking to MATLAB 
//#pragma comment( lib, "libmx.lib" )	
//#pragma comment( lib, "libmex.lib" )
//#pragma comment( lib, "libeng.lib" )
//#include <yvals.h>
//#if (_MSC_VER >= 1600)
//#define __STDC_UTF_16__
//#endif
//#include "mex.h"
//// end

//#include<engine.h>			// library for MATLAB
#include<cmath>				// math operations library
#include<time.h>			// time stamp library
#include<iostream>			// standard console I/O library
#include<iomanip>			// standard I/O manipulation library
#include<map>				// container map library
#include<sstream>			// string stream library
#include<fstream>			// file streaminimumg library
#include<string>			// string library
#include<stdlib.h>			// standard library

using namespace std;
// include other class files
#include "stock_account_prakash.h"
#include "node_prakash.h"

// constructor
StockAccount::StockAccount()	// Default constructor
{
	firstPtr = NULL;				// Assign NULL to head pointer of linked list
	secondPtr = NULL;				// Assign NULL to tail pointer of linked list

								//Initialising all portfolio variables
	port_array[20] = { 0 };
	count = 0;
	portfolioValue = 0;

	setBalance();					// Set value for cash balance

	srand((unsigned int)time(NULL));	// Generate random seeds for random function using time

	// Access the given two stock text files 
	file1.open("Result_1.txt");
	file2.open("Result_2.txt");

	if (file1.is_open() && file2.is_open())		// Check if the files are open
	{
		while (!file1.eof() && !file2.eof())	// Check if end of file reached
		{
			getline(file1, line1);				// Read line from the file
			stream1 << line1;					// store in the stream 
			stream1 >> symb1 >> price1;			// Store into different parts for Ticker and price
			result1.insert(pair<string, double>(symb1, price1));	// Store pair into container
			stream1.str("");					// allocate string object
			stream1.clear();					// clear stream

			getline(file2, line1);				// Read line from the file
			stream1 << line1;					// store in the stream 
			stream1 >> symb1 >> price1;			// Store into different parts for Ticker and price
			result2.insert(pair<string, double>(symb1, price1));	// Store pair into container
			stream1.str("");					// allocate string object
			stream1.clear();					// clear stream
		}
	}
	// close the files after usage
	file1.close();
	file2.close();

	// getting the size of previously stored portfolio (doubly linked list)
	file1.open("list_size.txt", ios_base::in); // open file for reading
	file1 >> size;
	file1.close();
	if (size != 0)
		this->portfolioGet(); 	// retrieing the previously stored portfolio in a double linked list
	this->portfolioGet(); // retrieve portflio value in double array for plotting
}

// Get cash balance
double StockAccount::getBalance()
{
	return cashbalance;
}

// Set cash balance
void StockAccount::setBalance()
{
	streampos len;
	ifstream file1;
	file1.open("balance_file.txt", ios::binary);    // open the file
	if (file1.is_open())
	{
		file1.seekg(0, ios::end);              // Putting the console at the end of file
		len = file1.tellg();                   // Finding the position of the console
		file1.close();                         // Closes the  file
	}

	if (!len) // if len isn't found, create the file and put $500 cash balance into it.
	{
		double depositCash = 500.00;

		ofstream file2; // output file
		file2.open("balance_file.txt", ios_base::out);
		file2 << depositCash;				//Deposit the cash in the passbook record
		file2.close();						// Closes the  file

		//Update the cash balance as 500
		ifstream file3("balance_file.txt", ios_base::in);
		file3 >> cashbalance;
		file3.close();
	}
	else
	{
		// Else, update balance from existing cash balance file.
		ifstream file4("balance_file.txt", ios_base::in);
		file4 >> cashbalance;
		file4.close();
	}
}

//display stock price 
void StockAccount::stockDisplay()
{
	bool flag = false;		// temporary indicator
	cout << "\nPlease Enter the Stock Symbol : ";
	cin >> stock_symbol;
	fileNum = rand() % 2;    // generate random numbers for selecting between two text files

	if (fileNum == 0)		// Access Result_1.txt
	{
		// iterating through
		for (map<string, double>::iterator i = result1.begin(); i != result1.end(); i++)
		{
			// if symbol is found then display its stock price
			if (stock_symbol == (*i).first)		// compare the first stored value
			{	// print all the parameters
				cout << left << setw(10) << "Symbol";
				cout << left << setw(10) << "Price/Share" << endl;
				cout << left << setw(10) << (*i).first;
				cout << left << setw(10) << (*i).second << endl;
				flag = true;
			}
		}
		if (flag == false)
			cout << "\nERROR! Symbol not found at database !\n";
		return;
	}

	else if (fileNum == 1)	// Access Result_2.txt
	{
		// iterating through container
		for (map<string, double>::iterator i = result2.begin(); i != result2.end(); i++)
		{
			// if symbol is found then display its stock price
			if (stock_symbol == (*i).first)	// compare the first stored value
			{
				cout << left << setw(10) << "Symbol";
				cout << left << setw(10) << "Price/Share" << endl;
				cout << left << setw(10) << (*i).first;
				cout << left << setw(10) << (*i).second << endl;
				flag = true;
			}
		}
		if (flag == false)	// if symbol not found
			cout << "\nERROR! Symbol not found!\n";
		return;
	}
}

// display the portfolio
void StockAccount::portfolioDisplay()
{
	Node *current = firstPtr;	// new temporary pointer for accessing linked list
	setBalance();				// set value for cash balance
	double stockval = 0, cashbalance = getBalance();	// initialise cash and stock values

	while (current != NULL)
	{
		fileNum = rand() % 2;
		// for file 1 assign temporary stock price to corresponding symbol in portfolio 
		if (fileNum == 0)
		{
			for (map<string, double>::iterator i = result1.begin(); i != result1.end(); i++)
			{
				if (current->symb == (*i).first)	// compare the symbol from the node
				{
					current->priceTemp = (*i).second;				 // assign price per share
					current->currentPortfolioVal = current->share_num*current->priceTemp; // calculate temporary node value of portfolio
				}
			}
		}

		// Repeat above steps for file 2
		else if (fileNum == 1)
		{
			for (map<string, double>::iterator i = result2.begin(); i != result2.end(); i++)
			{
				if (current->symb == (*i).first)
				{
					current->priceTemp = (*i).second;
					current->currentPortfolioVal = current->share_num*current->priceTemp;
				}
			}
		}
		current = current->nextptr; // access next node
	}

	this->listSort(); // sort the stock values using the linked list nodes

	if (size > 0)
	{
		cout << endl << left << setw(15) << "Symbol";
		cout << left << setw(15) << "Shares";
		cout << left << setw(15) << "Price/Share($)";
		cout << left << setw(15) << "Total Value($)" << endl;
		current = firstPtr;  // temp pointer for iterations

		while (current != NULL)
		{
			cout << left << setw(15) << current->symb;						// print the symbol
			cout << left << setw(15) << current->share_num;					// print the number of shares
			cout << left << setw(15) << current->priceTemp;				// print the price per share
			cout << left << setw(15) << current->currentPortfolioVal << endl;		// print the stock value

			stockval = stockval + current->currentPortfolioVal;		// update the stock value
			current = current->nextptr;							// traverse to the next node
		}
		portfolioValue = cashbalance + stockval;			// Calculate the portfolio value
		cout << "\nThe Cash Balance is  : $" << cashbalance;
		cout << "\nThe Stock Balance is : $" << stockval;
		cout << "\nThe Total Portfolio value is : $" << portfolioValue << endl; // print total portfolio value

		port_array[count] = portfolioValue; // store portfolio value changes in double type array.
		count++;
	}

	else if (size == 0) // if no values present in shares
	{
		portfolioValue = cashbalance;
		cout << "\nERROR! No shares are available in portfolio! Please Buy some!\n";
	}
}

//sorting the linked list using nodes
bool StockAccount::listSort()
{
	Node *tempPtr = firstPtr; // create a head pointer temporary
	int counter = 0;	// temporary counter

	while (tempPtr != NULL)	// check if head pointer is NULL
	{
		fileNum = rand() % 2;	// Choose a random file

		if (fileNum == 0)		// for Result_1.txt
		{
			for (map<string, double>::iterator i = result1.begin(); i != result1.end(); i++)
			{
				if (tempPtr->symb == (*i).first)
				{
					tempPtr->priceTemp = (*i).second;
					tempPtr->currentPortfolioVal = tempPtr->share_num*tempPtr->priceTemp;
				}
			}
		}

		else if (fileNum == 1)	// for Result_2.txt
		{
			for (map<string, double>::iterator i = result2.begin(); i != result2.end(); i++)
			{
				if (tempPtr->symb == (*i).first)
				{
					tempPtr->priceTemp = (*i).second;
					tempPtr->currentPortfolioVal = tempPtr->share_num*tempPtr->priceTemp;
				}
			}
		}

		tempPtr = tempPtr->nextptr; // go to next node
	}

	Node *c2 = firstPtr;	// create another temporary head pointer

	if (firstPtr != NULL) // check if list not empty.
	{
		Node *prev = 0;			// assign previous pointer as zero
		Node *temp_ptr = NULL;	// temporary pointer
		int swap = 0;			// flag to check if swapped

		// Implementing bubble sorting using the same nodes of doubly linked list
		for (int i = 0; i < size; i++)
		{
			while (c2->nextptr != 0) // checking if tail pointer
			{
				temp_ptr = c2->nextptr;	//assign next pointer to a temporary pointer
				if (c2->currentPortfolioVal < temp_ptr->currentPortfolioVal) // if the portfolio values are smaller than consequent,then swap.
				{
					temp_ptr->prevptr = c2->prevptr;
					c2->prevptr = temp_ptr;
					swap = 1;
					c2->nextptr = temp_ptr->nextptr;

					if (c2->nextptr != NULL) // checking for tail pointer to be NULL
						c2->nextptr->prevptr = c2;
					temp_ptr->nextptr = c2;   // after swapping temptr's next pointer should be current.
					if (prev != 0)				  // if previous pointer to the current is not NULL
						prev->nextptr = temp_ptr;  // then previous's next pointer should be temptr after swapping.
					prev = temp_ptr;               // and for next iteration previous should be temptr.
					if (firstPtr == c2)       // if firstPtr is current, then after swapping, firstPtr should be temptr.
						firstPtr = temp_ptr;
					if (c2->nextptr == 0)    // if current's next pointer is tailpointer then after swapping, tailpointer should be current.
						secondPtr = c2;
				}
				else
				{
					prev = c2;               // if no swapping, then for next iteration, previous pointer should be c2.
					c2 = c2->nextptr;   // increment the node.
				}
			}
			if (swap == 0) // list already sorted, no swapping.
				break;
			else               // start again from head pointer.
			{
				prev = 0;
				c2 = firstPtr;
				swap = 0;
			}
		}
	}
	else // list is empty
	{
		cout << "\nList is Empty! Can't Sort!\n";
		return false;
	}
	return true;
}

// BUY shares
void StockAccount::shareBuy(Node *n)
{
	setBalance();
	bool flag2 = true, flag3 = true, flag4 = true, flag5 = true;
	double sval1, sval2;
	cashbalance = getBalance();
	double total_amount;
	cout << "\nPlease Enter the stock symbol : ";
	cin >> stock_symbol;

	for (map<string, double>::iterator i = result1.begin(); i != result1.end(); i++) // check in container if symbol present
	{
		if (stock_symbol == (*i).first)
		{
			flag4 = false;
		}
	}

	if (flag4 == true)	// if symbol absent
	{
		cout << "\nERROR! Symbol Not found in the database!\n";
		return;
	}

	// if the symbol is found, continue
	cout << "\nPlease Enter the Number of shares to buy : ";
	cin >> shares;
	cout << "\nPlease Enter the maximum limit you're willing to pay per share : ";
	cin >> maximum;

	for (map<string, double>::iterator i = result1.begin(); i != result1.end(); i++)
	{
		if (stock_symbol == (*i).first)
		{
			sval1 = (*i).second;
		}
	}

	for (map<string, double>::iterator i = result2.begin(); i != result2.end(); i++)
	{
		if (stock_symbol == (*i).first)
		{
			sval2 = (*i).second;
		}
	}

	fileNum = rand() % 2; // randomly select one of the two files

	if (fileNum == 0)
	{
		if (maximum >= sval1) // check if value entered is more than expected
		{
			total_amount = shares * sval1;
			price1 = sval1;
		}
		else	// otherwise, print error
		{
			cout << "\ERROR! The minimum limit entered is less than current Share value! Can't buy stock! \n";
			return;
		}
	}

	// for the other file -
	else if (fileNum == 1)
	{
		if (maximum >= sval2)
		{
			total_amount = shares * sval2;
			price1 = sval2;
		}
		else
		{
			cout << "\Maximum limit entered is less than current Share value! Can't buy stock.\n";
			return;
		}
	}

	// compare amount with current cash balance.
	if (total_amount > cashbalance)
	{
		cout << "\n ERROR! Insufficient Cash Balance!\a\n";
		return;
	}

	// else update cash balance.
	else
	{
		cashbalance = cashbalance - total_amount;

		cout << "\nYou purchased " << shares << " shares of " << stock_symbol << " for a total of $" << total_amount;

		// write back to a balance file.
		writebalance_file.open("balance_file.txt", std::ios_base::out);
		writebalance_file << cashbalance;
		writebalance_file.close();

		// generate the current timestamp using time.h
		time_t raw;
		struct tm space;
		char buffer[80];
		time(&raw);
		localtime_s(&space, &raw);
		strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", &space);
		std::string str(buffer);

		// write deposit transaction to bank_transaction_history.txt file
		write_bank_history.open("bank_transaction_history.txt", ios::app);
		write_bank_history << endl << left << setw(30) << "Debited to Stock Account.";
		write_bank_history << left << setw(1) << "$";
		write_bank_history << left << setw(15) << total_amount;
		write_bank_history << right << setw(15) << str;
		write_bank_history << right << setw(5) << "$" << cashbalance;
		write_bank_history.close();

		// write transaction to stock_transaction_history.txt file
		write_bank_history.open("stock_transaction_history.txt", ios::app);
		write_bank_history << endl << left << setw(7) << "Buy";
		write_bank_history << left << setw(14) << stock_symbol;
		write_bank_history << left << setw(7) << shares;
		write_bank_history << left << setw(14) << price1;
		write_bank_history << left << setw(10) << total_amount;
		write_bank_history << left << setw(15) << str;
		write_bank_history.close();

		//Updating doubly linked list
		if (secondPtr == NULL && firstPtr == NULL) // start from a new node
		{
			// point head and tail to same node
			secondPtr = n;
			firstPtr = n;
			n->symb = stock_symbol;
			n->share_num = shares;
			n->price = price1;
		}

		// else update the existing nodes
		else
		{
			Node *cur = firstPtr;
			while (cur != NULL)
			{
				// if already present, update share number 
				if (stock_symbol == cur->symb)
				{
					cur->share_num = cur->share_num + shares;
					return;
				}
				cur = cur->nextptr;
			}

			// add new node at the end with new values
			Node *copy = secondPtr;
			secondPtr->nextptr = n;
			secondPtr = n;
			secondPtr->prevptr = copy;
			n->symb = stock_symbol;
			n->share_num = shares;
			n->price = price1;
		}
		size++; // update size of list.
	}
}

// SELL shares
void StockAccount::shareSell()
{
	bool flag3 = false, flag4 = true, flag6 = false;
	setBalance();
	cashbalance = getBalance();

	cout << "\nEnter the Symbol of stock to sell : ";
	cin >> stock_symbol;

	Node *curtemp = firstPtr;

	// chec if symbol present in the portfolio
	while (curtemp != NULL)
	{
		if (stock_symbol == curtemp->symb)
		{
			flag6 = true;
		}
		curtemp = curtemp->nextptr;
	}

	// if not present
	if (flag6 == false)
	{
		cout << "\nERROR! Symbol not found in portfolio!\n";
		return;
	}

	// else continue
	cout << "\nPlease Enter the no. of shares to sell : ";
	cin >> shares;

	cout << "\nPlease Enter the mimimum limit willing to pay per share : ";
	cin >> minimum;

	fileNum = rand() % 2; // choose from random files 

	if (size > 0)
	{
		Node *cur = firstPtr;  // temporary pointer for iteration

		while (cur != NULL)
		{
			if (stock_symbol == cur->symb && shares <= cur->share_num) // if entered limit is correct
			{
				flag3 = true;
				cur->share_num = cur->share_num - shares;

				// for file 1
				if (fileNum == 0)
				{
					// get current price for the symbol 
					for (map<string, double>::iterator i = result1.begin(); i != result1.end(); i++)
					{
						if (stock_symbol == (*i).first)
						{
							// if minimum. limit entered is greater than current share value 
							if (minimum > ((*i).second))
							{
								cout << "\nERROR! Minimum limit entered is greater than current Share value! Can't sell shares.\n";
								return;
							}
							price1 = (*i).second; // update price
						}
					}
				}
				// repeat for file 2
				else if (fileNum == 1)
				{
					for (map<string, double>::iterator i = result2.begin(); i != result2.end(); i++)
					{

						if (stock_symbol == (*i).first)
						{

							if (minimum > ((*i).second))
							{
								cout << "\ERROR! Minimum limit entered is greater than current Share value! Can't sell shares.\n";
								return;
							}
							price1 = (*i).second;
						}
					}
				}

				//update balance after selling
				cashbalance = cashbalance + (shares*price1);

				// print the statement 
				cout << "\nYou sold " << shares << " shares of " << stock_symbol << " at rate of " << price1 << " per share\n";

				//generating the current date and timestamp
				time_t raw;
				struct tm space;
				char buffer[80];
				time(&raw);
				localtime_s(&space, &raw);
				strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", &space);
				std::string str(buffer);

				// write deposit transaction to bank_transaction_history.txt file
				write_bank_history.open("bank_transaction_history.txt", ios::app);
				write_bank_history << endl << left << setw(30) << "Credited from Stock Account.";
				write_bank_history << left << setw(1) << "$";
				write_bank_history << left << setw(15) << shares * price1;
				write_bank_history << right << setw(15) << str;
				write_bank_history << right << setw(5) << "$" << cashbalance;
				write_bank_history.close();

				// write transaction to stock_transaction_history.txt file
				write_bank_history.open("stock_transaction_history.txt", ios::app);
				write_bank_history << endl << left << setw(7) << "Sell";
				write_bank_history << left << setw(14) << stock_symbol;
				write_bank_history << left << setw(7) << shares;
				write_bank_history << left << setw(14) << price1;
				write_bank_history << left << setw(10) << shares * price1;
				write_bank_history << left << setw(15) << str;
				write_bank_history.close();

				//update current balance 
				writebalance_file.open("balance_file.txt", std::ios_base::out);
				writebalance_file << cashbalance;
				writebalance_file.close();

				// delete node if shares zero
				if (cur->share_num == 0)
				{
					//if current node is firstPtr
					if (cur == firstPtr)
					{
						if (cur == secondPtr)
						{
							firstPtr = NULL;
							secondPtr = NULL;
							delete cur;
							size--;
							return;
						}
						Node *temp = cur->nextptr;
						firstPtr = cur->nextptr;
						temp->prevptr = NULL;
						delete cur; // delete the node.
						size--;     // update the size.
						return;
					}
					//if current node is secondPtr
					else if (cur == secondPtr)
					{
						if (cur == firstPtr)
						{
							firstPtr = NULL;
							secondPtr = NULL;
							delete cur;
							size--;
							return;
						}
						Node *temp2 = cur->prevptr;
						secondPtr = cur->prevptr;
						temp2->nextptr = NULL;
						delete cur;    // delete the node
						size--;        // reduce the size.
						return;
					}
					// if the node is on the middle
					else
					{
						Node *temp3 = cur->prevptr;
						Node *temp4 = cur->nextptr;
						temp3->nextptr = cur->nextptr;
						temp4->prevptr = cur->prevptr;
						delete cur;                     // delete current node.
						size--;                         // update the size.
						return;
					}
				}
				return;
			}
			cur = cur->nextptr; // move to next pointer
		}
	}
	if (flag3 == false)
		cout << "\n ERROR! The number of shares is out of range!\n";
}

// Save portfolio to a temporary text file
void StockAccount::portfolioSave()
{
	Node *tem = firstPtr; // temporary instance of linked list node
	write_portfolio.open("portfolio_file.txt", std::ios_base::out);
	while (tem != NULL)
	{
		write_portfolio << tem->symb << "\t" << tem->share_num << "\n";
		tem = tem->nextptr;
	}
	write_portfolio.close();
	// update size of the doubly llist_sizeinked list.
	write_portfolio.open(".txt");
	write_portfolio << size;
	write_portfolio.close();
}

// Get values from portfolio in a doubly linked list 
void StockAccount::portfolioGet()
{

	port_file.open("portfolio_file.txt", ios_base::in);
	if (port_file.is_open())
	{
		while (!port_file.eof())
		{ // read from the text file line by line and store in separate parts
			getline(port_file, line1);
			stream2 << line1;
			stream2 >> temp1 >> share_temp;
			portfolio.insert(pair<string, int>(temp1, share_temp));
			stream2.clear();
		}
	}
	port_file.close();

	for (map<string, int>::iterator i = portfolio.begin(); i != portfolio.end(); ++i) // iterating through the container
	{
		Node *current = new Node();
		current->symb = (*i).first;
		current->share_num = (*i).second;

		// first new node
		if (prev == NULL)
		{
			current->prevptr = NULL;
			current->nextptr = NULL;
			firstPtr = current;
			secondPtr = current;
		}
		//update list at the end
		else
		{
			current->prevptr = prev;
			prev->nextptr = current;
		}
		prev = current;
		secondPtr = prev;
	}
	Node *cur = firstPtr;

	while (cur != NULL)
	{
		fileNum = rand() % 2;
		// for file 1
		if (fileNum == 0)
		{
			for (map<string, double>::iterator i = result1.begin(); i != result1.end(); i++)
			{
				if (cur->symb == (*i).first) // compare the symbol name 
				{
					cur->priceTemp = (*i).second;                // update price per share
					cur->currentPortfolioVal = cur->share_num*cur->priceTemp; // calculate temp node portfolio value
				}
			}
		}
		// repeat these steps for file 2
		else if (fileNum == 1)
		{
			for (map<string, double>::iterator i = result2.begin(); i != result2.end(); i++)
			{
				if (cur->symb == (*i).first)
				{
					cur->priceTemp = (*i).second;
					cur->currentPortfolioVal = cur->share_num*cur->priceTemp;
				}
			}
		}
		portfolioValue = portfolioValue + cur->currentPortfolioVal; // update potfolio value
		cur = cur->nextptr; // move to next node
	}
	portfolioValue += cashbalance; // update portfolio value

}

// Get portfolio value
void StockAccount::portfolioValueGet()
{
	string line2, temp;
	//open port_value text file and get the historical data from it and save it in two arrays.
	portval_file.open("port_value.txt", ios_base::in);
	if (portval_file.is_open())
	{
		while (!portval_file.eof())
		{
			getline(portval_file, line2);
			stream3 << line2;
			stream3 >> port_array[count] >> time_stamp[count] >> temp; // storing porfolio values in port_array.
			if (time_stamp[count] == "") // retrieve corresponding date in time_stamp
				continue;
			else
			{
				time_stamp[count].append(" ");
				time_stamp[count].append(temp); // append time to it.
			}
			count++; // increment counter for both arrays.
			stream3.clear();
		}
	}
	portval_file.close();
}

// Update portfolio value and timestamp
void StockAccount::portfolioValueSave()
{
	//generating the current date and timestamp
	time_t raw;
	struct tm space;
	char buffer[80];
	time(&raw);
	localtime_s(&space, &raw);
	strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", &space);
	std::string str(buffer);

	if (size == 0)
		portfolioValue = cashbalance; // update cash balance if portfolio empty.
	write_portfolio.open("port_value.txt.", ios::app);
	write_portfolio << portfolioValue << "  " << str << endl;
	write_portfolio.close();
}

// Plot MATLAB graph for portfolio value variation
/*void StockAccount::plot_graph()
{
	// pointer to the engine
	Engine *N;
	N = engOpen(NULL);
	// if matlab engine is not opened.
	if (N == NULL)
	{
		cout << "Error." << endl;
		exit(1);
	}
	/*cout << "Potfolio Value" << setw(15) << "Date & Time" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << port_array[i] << setw(30) << time_stamp[i] << endl;
	}*/
	// create mxArray and copy your c++ double array of portfolio value into it.
	/*cout << "\n Plotting MATLAB graph. Please wait...";
	mxArray *M;
	M = mxCreateDoubleMatrix(1, count, mxREAL); // creat a matrix
	memcpy((void *)mxGetPr(M), (void *)port_array, count * sizeof(double)); // allocate memory space
	engPutVariable(N, "set", M);
	engEvalString(N, "plot(set);"); // plot the value
	engEvalString(N, "title('Change In Portfolio Value');");
	mxDestroyArray(M);// deallocate		 M
}*/

// Print transaction history
void StockAccount::historyPrint()
{
	cout << endl << left << setw(7) << "Transaction";
	cout << left << setw(14) << "Symbol";
	cout << left << setw(7) << "Shares";
	cout << left << setw(14) << "Price per Share($)";
	cout << left << setw(10) << "Value($)";
	cout << left << setw(15) << "Timestamp" << endl;

	file1.open("stock_transaction_history.txt", ios::app); // open history file

	if (file1.is_open())
	{
		while (!file1.eof())
		{
			while (getline(file1, line2))
				cout << line2 << "\n";
		}
	}
	file1.close();  // close the file
}

// destructor 
StockAccount::~StockAccount()
{
	cout << "\n Account System Has Been Exited. ";
}