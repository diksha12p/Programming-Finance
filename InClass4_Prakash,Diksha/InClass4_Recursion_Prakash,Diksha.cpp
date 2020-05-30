/*
Name : Diksha Prakash
RUID : 186001757
Date of Submission : 10/06/18
In-Class 4 :  Program to recursively count the number of binary strings of length n that do not have two consecutive 0's
*/

#include<iostream>
#include<string>

using std::cout;
using std::cin;

// Function declaration
//FUnction to recursively count the number of binary strings of length n that do not have two consecutive 0's
int countBinStr(int n)
{
    if(n==0)  //Base condition 1 definition
        return (n);
    else if (n == 1)  //Base condition 2 definition
      return 2;
    else if (n == 2)  //Base condition 3 definition
      return 3;
    else  //General case definition
    {
        return(countBinStr(n-1)+countBinStr(n-2));  //Recursive call of the function
    }
} //End of function definition

//Definition of main()
int main()
{
    int n, DD, i=0; //Variable declaration
    cout<<"\n Input the value of n : \n"; //Asking user input
    cin >> n; //Storing user input in 'n' variable
    DD = countBinStr(n);  //Storing the result of the function call to the variable 'DD'
    cout<<"\n The answer is :" + std::to_string(DD)+ "\n";  //Printing out the result to the user

    // Holds output window in Visual C++
  	cin.clear();
  	cin.ignore();
  	cin.get();

    return 0;
} //End of main()
