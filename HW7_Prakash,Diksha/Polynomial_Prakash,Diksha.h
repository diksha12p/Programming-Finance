/*
Name : Diksha Prakash
RUID : 186001757
Date of Submission : 10/25/18
Header file definition for class Polynomial.
*/


#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>

using std::ostream;

class polynomial
{
	friend ostream &operator<<(ostream&, const polynomial p);

public:
	int nTerms;						//number of terms in polynomial
	int Poly[12];						//array

	int coefficient;							//coefficient
	int exponent;							//exponent
	polynomial();						//constructor declaration

	void getData();						//to print data
	void setData(int, int);

	//Operator overloading function declaration
	polynomial operator+(polynomial);
	polynomial operator-(polynomial);
	polynomial operator*(polynomial);
	void operator=(polynomial);
	polynomial operator+=(polynomial);
	polynomial operator-=(polynomial);
	polynomial operator*=(polynomial);

	//Destructor declaration
	~polynomial();
};
#endif
