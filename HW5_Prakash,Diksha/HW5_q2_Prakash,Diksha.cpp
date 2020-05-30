/*
Name : Diksha Prakash
RUID : 186001757
Date of Submission : 10/12/18
Program to solve a puzzle
*/

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include<iomanip>
using std::setw;

//Variable Declaration
int size;   //Variable to define the array size
const int max = 50;   //Variable to contain the maxium size of the array which is a constant
int arr[max];   //Defining an array with maximum size as 50
int indexValue;   //Variable to define the value stored at a particular index
int pos = 0;    //Initializing the initial value of the 'pos' variable as zero
int visited = -1;   //Variable used to set the value of the visited index as -1

int solve(int[max], int);   //Pseudo function

int main(){

  int i,j;    //Variable declaration
  do {
    cout << "Enter the number of elements in the row : \n";   //Asking the user for entering the number of elements
    cin >> size;    //Storing the enteed value in the variable 'size'
  }
  while (size <= 0);    //Repeat this if the entered size is a non-positive number

  cout << "The last element of the row is automatically set to be zero !! \n";    //Prompting the user that the last element will be automatically set to zero
  cout << "Enter the positive integer values for the first " << (size-1) <<" elements of the row : \n";   //Asking the user for input for all the other elements than the last element

  for (i=0; i < size-1; i++)
    cin >> arr[i];    //Taking the user input
  arr[size-1] = 0;    //Setting the last element as zero

  cout << "Printing the value of elements in the row entered by user : \n";   //Printing out the results to the user
  for (j = 0; j < size; j++)    //Looping through all the elements
    cout << arr[j] << "   ";    //Printing out the row elements to the user

  cout << "\n \n";

  if (solve( arr, indexValue) == 1)   //Putting a condition on the output of the solve function
    cout << "TRUE \n";    //If the return value of the function is 1, return 'TRUE' to the user that the puzzle has been solved
  else
    cout << "FALSE \n";   //If the return value of the function is not 1, return 'FALSE' to the user that the puzzle hasn't been solved

  return 0;   //Indicating the end of the main function

}


//Function Declaration
int solve(int a[max], int start ) {
  int flag = 0;										//initialize flag
	int result = 0;										//initialize result to visited if puzzle is solved or not
	if (start < (size-pos)||(pos-a[pos])>=0)			//Checking if the element with peg is not out of bonds either from left side or right side
	{
		if (flag==0)									//Checking if flag is zero
			pos = pos + start;							//Changing the position value to next position
		if (pos < size)									//position should not be out of bonds
			if (a[pos] != visited && ((a[pos] + pos) < size || a[pos] <= pos))	//Checking if the next element hasn't been visited before and it is not out of bonds from left or right side
			{
				a[pos - start] = visited;					//previous element is made -1 i.e it is visited
				start = a[pos];							//peg is shifted to next position if all conditions are satisfied
				flag = 1;								//flag is set
				if (start == 0)							//visited if it is reached at end position
				{
					result = 1;							//result is set
				}
				else
					solve(a, start);					//if not again function is called
			}
			else
				pos = pos - start;                     //if element is visited or out of bounds then postion value is reset to previous one
		else
			pos = pos - start;
		if (flag==0)                              //Checking if the previous condition was not done
			pos = pos - start;					//set pos value to left side pos value
		if (pos > 0)							//visited position is not out of bonds on left side of row
			if (a[pos] != visited && ((a[pos] + pos) < size || a[pos] <= pos) && result == 0)	 ////visited the next element is not visited one and it is not out of bonds from left or right side
			{
				a[pos + start] = visited;   // previous element is made -1 i.e it is visited
				start = a[pos];					//peg is shifted to left if all conditions are satisfied
				flag = 1;						//flag is set
				if (start == 0)					//visited if it is reached end position
				{
					result = 1;					//return result one
				}
				else
					solve(a, start);			//else call function again
			}
			else
				pos = pos + start;			//if condition not satisfied postion value is made same again
		else
			pos = pos + start;				//if condition not satisfied postion value is made same again
	}
	return result;								//at the end return result value
}
