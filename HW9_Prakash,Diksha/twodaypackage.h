/*	Name : Diksha Prakash
Date : 11/8/2018
H file for derived class twodaypackage
*/

#ifndef TWOPACKAGE_H
#define TWOPACKAGE_H

#include "package.h" // include H file

class twodaypackage : public package	// publicly inherit base class package
{
public:
	twodaypackage(const string &, const string &, const string &, const string &, int, const string &, const string &, const string &, const string &, int, double, double, double);
	void setFlatFee(double); // set flat fee for two-day-delivery service
	double getFlatFee() const; // return flat fee
	virtual double calculateCost() const; // calculate shipping cost

private:
	double FlatFee; // flat fee for two-day-delivery service
};
#endif
