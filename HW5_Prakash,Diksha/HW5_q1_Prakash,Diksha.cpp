/*
Name : Diksha Prakash
RUID : 186001757
Date of Submission : 10/12/18
Program to compute squares upto a desired number and print in required format
*/

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

unsigned int a = 1;												//initialize global variable equal to 1
void compute_square(unsigned int);						//prototype of fucntion to fin square

const int max = 100;								//initialize max to declare size of array
unsigned int arr[max];								//inialize array
int main()											//main function starts
{
	unsigned int num;								//initialize n
	do
	{
		cout << "\n Please enter a number upto which the squares have to be printed : \n";  //ask for the number from the user
		cout << "CAUTION : The number should be less than 100 !! \n";
		cin >> num;									//read the number entered by the user
	}
	while (num >= max);							//check if n is greater than max)
	cout << "\n The square of numbers from 1 to " << num << "is as under : \n \n" << endl; //prompt
	compute_square(num);											//call function to find squares of 1 to n and display according to the need
	cout << "\n \n";

	return 0;
}   //end the function

void compute_square(unsigned int n1)							//define the function
{


	if (a <= n1)												//check if x less than or equal to n
	{
		arr[a] = a*a;											//store square in array
		a++;												//increase x
		compute_square(n1);										//call the same function again
	}
	else
	{
		for (unsigned int i = n1; i > 0; i--)				//for printing odd square values in descending order
		{
			if (i % 2 != 0)
			{
				cout << arr[i] << ", ";
			}
		}
		for (unsigned int j = 1; j <= n1; j++)      ////for printing even square values in ascending order
		{
			if (j % 2 == 0)
			{
				cout << arr[j];
				if (j < n1 && j <(n1 - 1))
					cout << ", ";
			}

		}
	}
}
