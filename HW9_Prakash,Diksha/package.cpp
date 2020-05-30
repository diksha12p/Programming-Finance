/*	Name : Diksha Prakash
Date : 11/8/2018
CPP file for base class package
*/

#include "package.h" // include H file

// constructor to initiliaze
package::package(const string &sName, const string &sAddress, const string &sCity, const string &sState, int sZIP, const string &rName, const string &rAddress, const string &rCity, const string &rState, int rZIP, double w, double cost)
	: SenderName(sName), SenderAddress(sAddress), SenderCity(sCity), SenderState(sState), SenderZIP(sZIP), RecipientName(rName), RecipientAddress(rAddress), RecipientCity(rCity), RecipientState(rState), RecipientZIP(rZIP)
{
	setWeight(w);			// store weight
	setCost(cost);	// cost per ounce
}
// set sender's name
void package::setSenderName(const string &name)
{
	SenderName = name;
}
// return sender's name
string package::getSenderName() const
{
	return SenderName;
}
// set sender's address
void package::setSenderAddress(const string &address)
{
	SenderAddress = address;
}
// return sender's address
string package::getSenderAddress() const
{
	return SenderAddress;
}
// set sender's city
void package::setSenderCity(const string &city)
{
	SenderCity = city;
}
// return sender's city
string package::getSenderCity() const
{
	return SenderCity;
}
// set sender's state
void package::setSenderState(const string &state)
{
	SenderState = state;
}
// return sender's state
string package::getSenderState() const
{
	return SenderState;
}
// set sender's ZIP code
void package::setSenderZIP(int zip)
{
	SenderZIP = zip;
}
// return sender's ZIP code
int package::getSenderZIP() const
{
	return SenderZIP;
}
// set recipient's name
void package::setRecipientName(const string &name)
{
	RecipientName = name;
}
// return recipient's name
string package::getRecipientName() const
{
	return RecipientName;
}
// set recipient's address
void package::setRecipientAddress(const string &address)
{
	RecipientAddress = address;
}

// return recipient's address
string package::getRecipientAddress() const
{
	return RecipientAddress;
}

// set recipient's city
void package::setRecipientCity(const string &city)
{
	RecipientCity = city;
}
// return recipient's city
string package::getRecipientCity() const
{
	return RecipientCity;
}
// set recipient's state
void package::setRecipientState(const string &state)
{
	RecipientState = state;
}
// return recipient's state
string package::getRecipientState() const
{
	return RecipientState;
}
// set recipient's ZIP code
void package::setRecipientZIP(int zip)
{
	RecipientZIP = zip;
}
// return recipient's ZIP code
int package::getRecipientZIP() const
{
	return RecipientZIP;
}
// validate and store weight
void package::setWeight(double w)
{
	weight = (w < 0.0) ? 0.0 : w;
}
// return weight of package
double package::getWeight() const
{
	return weight;
}
// validate and store cost per ounce
void package::setCost(double cost1)
{
	cost = (cost1 < 0.0) ? 0.0 : cost1;
}
// return cost per ounce
double package::getCost()const
{
	return cost;
}
// calculate shipping cost for package
double package::calculateCost() const
{
	return getWeight() * getCost(); // return the cost
}
