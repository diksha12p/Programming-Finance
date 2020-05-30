/*
Name : Diksha Prakash
RUID : 186001757
Date of Submission : 10/26/18
Member-function definitions for class Polynomial.
*/

#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

#include"Polynomial_Prakash,Diksha.h"     //Include the header file

polynomial::polynomial()
{
	for (int i = 0; i <= 10; i++)
		Poly[i] = 0;    //Initializing the polynomial elements to zero
	nTerms = 0;       //Initializing the variable for the number of terms as zero
	coefficient = 0;    //Initializing the variable for coefficients as zero
	exponent = 0;     //Initializing the variable for exponents as zero
}

void polynomial::getData()
{
	cout << "\n Enter number of polynomial terms :  ";
	cin >> nTerms;	// Store the input in variable
	while (cin.fail() || nTerms < 0)		// If input is invalid
	{
		cout << "\n Invalid input. Try again: ";
		cin.clear();	// Clear console
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
		cin >> nTerms;	// Take input again
	}
	for (int i = 0; i < nTerms; i++)
	{
		cout << "\nPolynomial " << i + 1 << " - Enter the coefficient and the exponent : ";
		cin >> coefficient >> exponent;
		while (cin.fail() || coefficient < 0 || exponent < 0)		// If input is invalid
		{
			cout << "\n Invalid input. Try again: ";
			cin.clear();	// Clear console
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignore the input and wait for new input
			cin >> coefficient >> exponent;	// Take input again
		}
		setData(coefficient, exponent);  //Passing the data to setdata
	}
}

void polynomial::setData(int coefficient, int exponent)
{
	Poly[exponent] = coefficient;
}

// Friend function definition
ostream &operator<<(ostream &output, const polynomial p1)
{
	int count = 0;
	int flag = 0;

	//Counting the non-zero enteries among those made by the user
	for (int i = 0; i < 12; i++) {
		if (p1.Poly[i] != 0)
			count++;
	}

	//Printing the non-zero entries only
	for (int i = 0; i < 12; i++) {
		if (p1.Poly[i] != 0) {
			flag++;
			output << "( " << p1.Poly[i] <<" )" << " x^" << i;
			if (count != flag) {
				cout << "+";
			}
		}
	}
	return output;
}

polynomial polynomial::operator+(polynomial p1) //function definition for addition of the Polynomials
{
	polynomial result;   //Variable to store the output of the polynomial addition
	for (int i = 0; i <= 6; i++)   //Loopig through individual elements of the two polynomials
	{
		result.Poly[i] = Poly[i] + p1.Poly[i];   //Adding individual elements of the Polynomials
	}
	return result;   //Returning the reuslt of Polynomial addition to the user
}

polynomial polynomial::operator-(polynomial p1)//function defintion for overloading subtraction operator
{
	polynomial result;   //Variable to store the output of the polynomial subtraction
	for (int i = 0; i <= 6; i++)   //Loopig through individual elements of the two polynomials
	{
		result.Poly[i] = Poly[i] - p1.Poly[i];  //Subtracting the individual elements of the Poly
	}
	return result;     //Returning the reuslt of Polynomial subtraction to the user
}


polynomial polynomial::operator*(polynomial p1)//function definition to multiplication operator
{
	polynomial result;     //Variable to store the output of the polynomial multiplication
	int mat[13][13];     //Variable matrix to perform the operation
	for (int i = 0; i <= 12; i++)
		for (int j = 0; j <= 12; j++)
			mat[i][j] = 0;

	for (int i = 0; i <= 6; i++)
		for (int j = 0; j <= 6; j++)
			mat[i][i + j] = Poly[i] * p1.Poly[j];  //Multiplying and assigning values to a 13x13 matrix


	for (int i = 0; i <= 12; i++)
		for (int j = 0; j <= 12; j++)
			result.Poly[i] = result.Poly[i] + mat[j][i];  //Adding along the columns to get the result
	return result;
}

void polynomial::operator=(polynomial p1)     //assignment operator
{
	for (int i = 0; i < 12; i++)
		Poly[i] = p1.Poly[i];
}

polynomial polynomial::operator+=(polynomial p1)
{
	polynomial result;
	for (int i = 0; i <= 6; i++)
	{
		result.Poly[i] = Poly[i] + p1.Poly[i];  //Adding individual elements of the Poly
	}
	return result;
}


polynomial polynomial::operator-=(polynomial p1)
{
	polynomial result;
	for (int i = 0; i <= 6; i++)
	{
		result.Poly[i] = Poly[i] - p1.Poly[i];   //Subtracting  individual elements of the Poly
	}
	return result;
}

polynomial polynomial::operator*=(polynomial p1)
{
	polynomial result;
	int mat[13][13];
	for (int i = 0; i <= 12; i++)
		for (int j = 0; j <= 12; j++)
			mat[i][j] = 0;

	for (int i = 0; i <= 6; i++)
		for (int j = 0; j <= 6; j++)
			mat[i][i + j] = Poly[i] * p1.Poly[j];    //Multiplying and assigning values to a 13x13 matrix


	for (int i = 0; i <= 12; i++)
		for (int j = 0; j <= 12; j++)
			result.Poly[i] = result.Poly[i] + mat[j][i];     //Adding along the columns to get the result
	return result;
}

//Destructor definition
polynomial::~polynomial()
{
}
