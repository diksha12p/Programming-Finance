// HomeWork 1
// Diksha Prakash (RUID : 186001757)
// Date of Submission : 09/13/2018

#include <iostream>

using namespace std;

int
main()
{
	// Variable declaration
	int n1, n2, n3, n4, n5, Min, Max;
	cout << "Enter five nubers to be compared, one after the other \n";
	cin >> n1 >> n2 >> n3 >> n4 >> n5;

	// Initializing the variables 'Max' and 'Min' as the value of first number i.e. 'n1'
	Max = Min = n1;

	// Comparing the numbers to obtain Maximum
	if (Max < n2)
	{
		Max = n2;
	}
	if (Max < n3)
	{
		Max = n3;
	}
	if (Max < n4)
	{
		Max = n4;
	}
	if (Max < n5)
	{
		Max = n5;
	}

	// Comparing the numbers to obtain the Minimum
	if (Min > n2)
	{
		Min = n2;
	}
	if (Min > n3)
	{
		Min = n3;
	}
	if (Min > n4)
	{
		Min = n4;
	}
	if (Min > n5)
	{
		Min = n5;
	}
	// Printing out the final result
	cout << "The smallest number is " << Min << "\n" << "The largest number is " << Max << endl;
	// To  hold the screen so that the answer can be verified 
	system("pause");
	return 0;
}
