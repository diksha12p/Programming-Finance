/*
Name: Diksha Prakash
RUID: 186001757
HomeWork 2: Calculating the value of Pi using Monte Carlo's Method
Date of Submission: 20th September 2018
*/

//Including the required header files
#include <iostream>
#include <fstream>
#include <cstdlib>      //defines rand(), srand(), RAND_MAX
#include <ctime>        //defines ctime() for random numbers
#include <cmath>        //defines math functions
#include <chrono>		//defines several clock types
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using namespace std::chrono;

//Function to calculate the location of the thrown dart w.r.t origin
double location(double x, double y)
{
	double throwLoc;	// Variable Declaration
	throwLoc = sqrt(x*x + y * y);  // Calculatin the Euclidean Distance w.r.t Origin(0,0)
	return throwLoc;	//Variable to be retured post the function execution
}

//Function to calculate 'pi' using number of darts thrown in the circle i.e. 'nHits' vs all darts thrown i.e. 'nThrown'
double pie(int numThrows, double a)
{
	double pieValue = 4 * (a / numThrows);	//Formula to calculate the value of 'pi'
	return pieValue;	//Variable to be returned post the function execution
}

int main()
{
	double x, y;	//Variable declaration
	srand(time(NULL));      //creates the seed time
	double throwLoc;       //Variable showing the distance from the origin
	double nHits = 0;       //Variable for the number of times a dart ends up inside the circle
	int nThrows;          //Variable for the number of times a dart is thrown
	cout << "Enter how many times to throw the dart: \n";
	cin >> nThrows;

	if (nThrows >= 1)
	{
		ofstream file;	//A stream class to write on files
		file.open("coordiates.txt");	//Command to open the text file for writing the co-ordinates into it

		//Getting start timepoint
		auto start = high_resolution_clock::now();

		//creates 2 random numbers 'n' times
		for (int i = 1; i <= nThrows; i++)
		{
			x = (double)rand() / (RAND_MAX);	//Generating a random number for 'x' co-ordinate such that it is lies between 0 and 1
			y = (double)rand() / (RAND_MAX);	//Generating a random number for 'y' co-ordinate such that it is lies between 0 and 1
			if(i<250)	//Condition to ensure that only a few entries are written into the text file
			{
				file << x << "	" << y << "\n";	//COmmand to write the values of x and y co-ordinates into the text file
			}
			throwLoc = location(x, y);	//Calculating the location of the dart thrown using the function 'location' based on 'Eucledian Distance'
			//counts how often the dart is thrown inside the circle
			if (throwLoc < 1)
			{
				nHits++;	//Increment the count of successful hits by 1 if the dart lies within the circle
			}
		}
		double pieCalc = pie(nThrows, nHits);	//Calculating the value of 'Pi' using the defined function 'pie'

		//Getting ending timepoint
		auto stop = high_resolution_clock::now();

		cout << "The value of PI is: " << pieCalc;	//Displaying the result

		cout << "\nThe first 250 x-y coordinates have been stored in text file coordinates.txt\n\n"; //Prompts the info about text file

		//Get the duration of the process in the desired time format
		auto duration = duration_cast<milliseconds>(stop - start);
		cout << "Time taken for the computation is " << duration.count() << " milliseconds" << endl;

	}
	else
		cout << "Please enter a valid positive number! \n" << endl;

	// Holds output window in Visual C++
	cin.clear();
	cin.ignore();
	cin.get();


	return 0;
}
