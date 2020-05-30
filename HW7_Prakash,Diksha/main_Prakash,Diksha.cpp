/*
Name : Diksha Prakash
RUID : 186001757
Date of Submission : 10/26/18
Driver Program for class Polynomial.
*/

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

#include"Polynomial_Prakash,Diksha.h"

int main()
{
	polynomial t, w, x, y, z;


	cout << "\nENTER THE FIRST POLYNOMIAL\n";//Getting the data from the user
	t.getData();
	cout << "\nENTER THE SECOND POLYNOMIAL\n";
	w.getData();


	cout << "\n The First Polynomial: ";  //Demostrating the << operator overloading
	cout << t << endl;
	cout << "\n The Second Polynomial: ";
	cout << w << endl;


	cout << "\n The Polynomial sum is : ";  //Demostrating the + operator overloading
	cout << t + w << endl;


	cout << "\n The Polynomial difference is : ";   	//Demostrating the - operator overloading
	cout << t - w << endl;


	cout << "\n The Polynomial product is : ";	//Demostrating the * operator overloading
	cout << t * w << endl;


	x = t;//Demostrating the = operator overloading


	cout << "\n The operator += yields : ";//Demostrating the += operator overloading
	cout << (x += w) << endl;

	y = t;

	cout << "\n The operator -= yields : ";  //Demostrating the -= operator overloading
	cout << (y -= w) << endl;

	z = t;

	cout << "\n The operator *= yields : ";//Demostrating the *= operator overloading
	cout << (z *= w) << endl;

	//Hold the screen
	cin.clear();
	cin.ignore();
	cin.get();


	return(0);
}
