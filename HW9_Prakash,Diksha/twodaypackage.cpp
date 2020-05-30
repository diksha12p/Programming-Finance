/*	Name : Diksha Prakash
Date : 11/8/2018
CPP file for derived class twodaypackage
*/

#include "twodaypackage.h" // include H file
// constructor definition
twodaypackage::twodaypackage(const string &sName, const string &sAddress, const string &sCity, const string &sState, int sZIP, const string &rName, const string &rAddress, const string &rCity, const string &rState, int rZIP, double w, double cost, double fee)
	: package(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, w, cost)
{
	setFlatFee(fee);
}

// set flat fee
void twodaypackage::setFlatFee(double fee)
{
	FlatFee = (fee < 0.0) ? 0.0 : fee;	// check if positive
}

// get flat fee
double twodaypackage::getFlatFee() const
{
	return FlatFee;
}

// calculate shipping cost for package
double twodaypackage::calculateCost() const
{
	return package::calculateCost() + getFlatFee();
}
