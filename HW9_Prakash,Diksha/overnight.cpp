/*	Name : Diksha Prakash
Date : 11/8/2018
CPP file for derived class overnightpackage definition
*/

#include "overnight.h"

// constructor
overnightpackage::overnightpackage(const string &sName, const string &sAddress, const string &sCity, const string &sState, int sZIP, const string &rName, const string &rAddress, const string &rCity, const string &rState, int rZIP, double w, double cost, double fee)
	: package(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, w, cost)
{
	setFlatFee(fee); // store overnight fee
}

// set overnight flat fee
void overnightpackage::setFlatFee(double overnightFee)
{
	FlatFee = (overnightFee < 0.0) ? 0.0 : overnightFee; // Check if value is positive
}

// return overnight fee
double overnightpackage::getFlatFee() const
{
	return FlatFee;
}

// calculate shipping cost for package
double overnightpackage::calculateCost() const
{
	return getWeight() * (getCost() + getFlatFee());
}
