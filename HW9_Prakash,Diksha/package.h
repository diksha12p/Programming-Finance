/*	Name : Diksha Prakash
	Date : 11/8/2018
	H file for base class package
*/

#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
using std::string;

class package
{
public:
	package(const string &, const string &, const string &, const string &, int, const string &, const string &, const string &, const string &, int, double, double);

	void setSenderName(const string &); // set sender's name
	string getSenderName() const; // return sender's name

	void setSenderAddress(const string &); // set sender's address
	string getSenderAddress() const; // return sender's address

	void setSenderCity(const string &); // set sender's city
	string getSenderCity() const; // return sender's city

	void setSenderState(const string &); // set sender's state
	string getSenderState() const; // return sender's state

	void setSenderZIP(int); // set sender's ZIP code
	int getSenderZIP() const; // return sender's ZIP code

	void setRecipientName(const string &); // set recipient's name
	string getRecipientName() const; // return recipient's name

	void setRecipientAddress(const string &); // set recipient's address
	string getRecipientAddress() const; // return recipient's address

	void setRecipientCity(const string &); // set recipient's city
	string getRecipientCity() const; // return recipient's city

	void setRecipientState(const string &); // set recipient's state
	string getRecipientState() const; // return recipient's state

	void setRecipientZIP(int); // set recipient's ZIP code
	int getRecipientZIP() const; // return recipient's ZIP code

	void setWeight(double); // validate and store weight
	double getWeight() const; // return weight of package

	void setCost(double); // validate and store cost per ounce
	double getCost() const; // return cost per ounce

	virtual double calculateCost() const; // calculate shipping cost
private:
	// data members to store sender and recipient's address information
	string SenderName, SenderAddress, SenderCity, SenderState;
	int SenderZIP;
	string RecipientName, RecipientAddress, RecipientCity, RecipientState;
	int RecipientZIP;
	double weight; // weight of the package
	double cost; // cost per ounce to ship the package
};
#endif
