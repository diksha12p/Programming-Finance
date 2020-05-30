/*	Name : Diksha Prakash
Date : 11/8/2018
H file for derived class overnightpackage
*/

#ifndef OVERNIGHT_H
#define OVERNIGHT_H
#include "package.h" // Include H file

class overnightpackage : public package	// publicly inherit base class package
{
public:
	overnightpackage(const string &, const string &, const string &, const string &, int, const string &, const string &, const string &, const string &, int, double, double, double);
	void setFlatFee(double); // set overnight flat fee
	double getFlatFee() const; // return overnight flat fee
	virtual double calculateCost() const; // calculate shipping cost

private:
	double FlatFee; // flat fee per ounce for overnight
};
#endif
