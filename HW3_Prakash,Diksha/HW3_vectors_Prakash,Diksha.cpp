/*
Name : Diksha Prakash
RUID : 186001757
Date of Submission : 10/02/18
Program to perform matrix operations using vectors
*/


#include<iostream>

using std::cout;
using std::cin;
using std::endl;

#include<iomanip>

using std::setw;

#include<vector>

using std::vector;

unsigned int choice;					//to take choice according to the user from the menu
const int a = 10;						// maximum row and column size which is going to be constat to initialize matrix
void MatrixInput(vector<vector<double> >&, int, int);						//function prototype for inputing the matrix
void MatrixPrint(vector<vector<double> >&, int, int);					//function prototype for displaying matrix
void MatrixAdd(vector<vector<double> >&, vector<vector<double> >&, int, int, int, int);	 //function prototype for MatrixAdd of 2 matrices
void MatrixSub(vector<vector<double> >&, vector<vector<double> >&, int, int, int, int);	 //function prototype for MatrixSub of matrices
void MatrixMul(vector<vector<double> >&, vector<vector<double> >&, int, int, int, int);	  //function prototype for MatrixMul
void MatrixTranspose(vector<vector<double> >&, int, int);					//function prototype for finding MatrixTranspose of matrix
int MatrixDet(vector<vector<double> >&, int, int);						//function prototype for finding MatrixDet
void MatrixInverse(vector<vector<double> >&, int, int);					//function prototype for finding MatrixInverse of matrix

int main()
{										//main function begins
	cout << "\nmenu";					//prompts menu
	cout << "\n Choice 1 : Addition";						//prompts all the choices w.r.t their choice no.
	cout << "\n Choice 2 : Subtraction";					// choice no. will be entered by user according to
	cout << "\n Choice 3 : Multiplication";					// the user's requirement
	cout << "\n Choice 4 : Determinant";
	cout << "\n Choice 5 : Transpose";
	cout << "\n Choice 6 : Inverse";
	cout << "\n Choice 7 : Quit";							//choice 7 should be entered if user wants to quit the program
	cout << "\n Enter your Choice : ";						//prompts user to enter choice
	cin >> choice;							// read an integer value of choice


	int row1 = 0;						//initialize no. of rows of matrix 1
	int row2 = 0;						//initialize no. of rows of matrix2
	int col1 = 0;						//initialize no. of columns of matrix 1
	int col2 = 0;						//initialize no. of columns of matrix 2
	vector<vector<double> >m1(a, vector<double>(a, 0));						//initialize matrix 1 with size 10x10
	vector<vector<double> >m2(a, vector<double>(a, 0));						//initialize matrix 2 with size 10x10
	if (choice < 7)								// checking the condition if choice enter is valid
	{
		cout << "\n Please Enter the number of rows : ";					// prompts to enter no. of rows
		cin >> row1;								//reads row1
		cout << "\n Please Enter number of columns : ";						//prompts to enter no. of columns
		cin >> col1;							//reads col1

	}
	switch (choice)								// checks choice value according selects the case
	{
	case 1:
		MatrixInput(m1, row1, col1);						//takes the elements of matrix1 from the user and stores them display them
		cout << "\n Please Enter the number of rows : ";				// prompts to enter no. of rows
		cin >> row2;								//reads row2
		cout << "\n Please Enter number of columns : ";						// prompts to enter no. of columns
		cin >> col2;								//reads col2
		if (row1 == row2 && col1 == col2)						//checks if MatrixAdd operation can be performed or not
		{
			MatrixInput(m2, row2, col2);					//takes the elements of matrix2 from the user and stores them and display them
			cout << "\n\n The result is : \n";						//prompts the result is
			MatrixAdd(m1, m2, row1, col1, row2, col2);						// function call:-add the 2 matrices and display them
		}
		else
			cout << "\n The operation is not supported";					//if MatrixAdd is not supported prompts this
		main();									// calls main function again shows the menu choices
		break;									//takes out of the switch case

	case 2:
		MatrixInput(m1, row1, col1);						//takes the elements of matrix1 from the user and stores them display them
		cout << "\n Please Enter the number of rows : ";					// prompts to enter no. of rows
		cin >> row2;								//reads row2
		cout << "\n Please Enter number of columns : ";						// prompts to enter no. of columns
		cin >> col2;								//reads col2
		if (row1 == row2 && col1 == col2)						//checks if MatrixSub operation can be performed or not
		{
			MatrixInput(m2, row2, col2);					//takes the elements of matrix2 from the user and stores them and display them
			cout << "\n\n The result is : \n";						//prompts the result is
			MatrixSub(m1, m2, row1, col1, row2, col2);					// function call :-subtracts the 2 matrices and display them
		}
		else
			cout << "\n The operation is not supported";					//if MatrixSub is not supported prompts this
		main();									// calls main function again shows the menu choices
		break;									//takes out of the switch case

	case 3:
		MatrixInput(m1, row1, col1);						//takes the elements of matrix1 from the user and stores them display them
		cout << "\n Please Enter the number of rows : ";					// prompts to enter no. of rows
		cin >> row2;								//reads row2
		cout << "\n Please Enter number of columns : ";						//prompts to enter no. of columns
		cin >> col2;								//reads col2
		if (col1 == row2)							//checks if MatrixMul operation can be performed or not
		{
			MatrixInput(m2, row2, col2);					//takes the elements of matrix2 from the user and stores them and display them
			cout << "\n\n The result is : \n";						//prompts the result is
			MatrixMul(m1, m2, row1, col1, row2, col2);					// function call :-multiplies the 2 matrices and display them
		}
		else
			cout << "\n The operation is not supported";					//if MatrixMul is not supported prompts this

		main();									// calls main function again shows the menu choices
		break;									//takes out of the switch case

	case 4:
		if (row1 == 3 && col1 == 3)					//checks if matrix is 3x3
		{
			MatrixInput(m1, row1, col1);					//takes the elements of matrix1 from the user and stores them display them
			cout << "\n\n The result is : \n\n";					//prompts the result is
			cout << MatrixDet(m1, row1, col1);						// function call :-find MatrixDet and display result
		}
		else
			cout << "\n The operation is not supported";					//if  matrix is not 3x3 prompts this
		main();									// calls main function again shows the menu choices
		break;									//takes out of the switch case

	case 5:
		MatrixInput(m1, row1, col1);						//takes the elements of matrix1 from the user and stores them display them
		cout << "\n\n The result is : \n";							//prompts the result is
		MatrixTranspose(m1, row1, col1);					// function call :-take MatrixTranspose of matrix and display them
		main();									// calls main function again shows the menu choices
		break;									//takes out of the switch case


	case 6:
		if (row1 == 3 && col1 == 3)						//checks if matrix is 3x3
		{
			MatrixInput(m1, row1, col1);					//takes the elements of matrix1 from the user and stores them display them
			if (MatrixDet(m1, row1, col1) != 0)						//checks if MatrixDet is 0 or not
			{
				cout << "\n\n The result is : \n";					//prompts the result is
				MatrixInverse(m1, row1, col1);					// function call :-find MatrixInverse of matrix and display result
			}
			else
				cout << "\n MatrixDet is 0, The operation is not supported";				//if  MatrixDet is not 0 prompts this
		}
		else
			cout << "\n The operation is not supported";					////if  matrix is not 3x3 prompts this
		main();									// calls main function again shows the menu choices
		break;									//takes out of the switch case

	case 7:
		return 0;								//successfull termination if choice is 7
		break;									//takes out of the switch case

	default:
		cout << "\n Wrong choice entered, Enter the choice again\n";		//if any other value is entered prompts this
		main();									// calls main function again shows the menu choices
		break;									//takes out of the switch case
	}
	return 0;									//successfull termination of program
}


void MatrixInput(vector<vector<double> >& m1, int row1, int col1)						//function to input matrix
{
	cout << "\n Please enter elements of matrix : \n";						//prompts to enter elements of matrix rowwise


	for (int i = 0; i < row1; i++)						//for loop for ith rows
		for (int j = 0; j < col1; j++)					//for loop for jth column in ith row
			cin >> m1[i][j];					//reads the element of matrix
	cout << "your input is : \n";						//prompts your input is
	MatrixPrint(m1, row1, col1);					//prints the matrix with elements entered by user

}												//ends input function

void MatrixPrint(vector<vector<double> >& matrix, int rows, int columns)			//function to display or print the matrix
{
	for (int i = 0; i < rows; i++)						//for loop for ith rows
	{
		for (int j = 0; j < columns; j++)							//for loop for jth column in ith row
			cout << setw(10) << matrix[i][j];						//prints the element at ith row and jth column
		cout << endl;
	}
}

void MatrixAdd(vector<vector<double> >& matrix1, vector<vector<double> >& matrix2, int rows1, int columns1, int rows2, int columns2)	//function to add 2 matrices
{

	vector<vector<double> >result(a, vector<double>(a, 0));						//initialize a matrix to store result
	for (int i = 0; i < rows1; i++)					//for loop for ith rows
		for (int j = 0; j < columns1; j++)					//for loop for jth column in ith row
		{
			result[i][j] = matrix1[i][j] + matrix2[i][j];						//adds the 2 elements of 2 input matrix and stores in result matrix
		}
	MatrixPrint(result, rows1, columns1);					//display the result matrix



}

void MatrixSub(vector<vector<double> >& matrix1, vector<vector<double> >& matrix2, int rows1, int columns1, int rows2, int columns2)//function to subtract 2 matrices
{

	vector<vector<double> >result(a, vector<double>(a, 0));							//initialize a matrix to store result
	for (int i = 0; i < rows1; i++)						//for loop for ith rows
		for (int j = 0; j < columns1; j++)						//for loop for jth column in ith row
		{
			result[i][j] = matrix1[i][j] - matrix2[i][j];					//subtracts the 2 elements of 2 input matrix and stores in result matrix
		}
	MatrixPrint(result, rows1, columns1);						//display the result matrix


}

void MatrixMul(vector<vector<double> >& matrix1, vector<vector<double> >& matrix2, int rows1, int columns1, int rows2, int columns2)//function to multiply 2 matrices
{

	vector<vector<double> >result(a, vector<double>(a, 0));					//initialize a matrix to store result
	for (int i = 0; i<rows1; i++)						//for loop for ith row of matrix 1
		for (int j = 0; j<columns2; j++)						//for loop for jth column in matrix 2
			for (int k = 0; k<columns1; k++)					//this for loops for kth column in matrix 1
			{
				result[i][j] += matrix1[i][k] * matrix2[k][j];						//multiplies the 2 elements and stroes the result in result
			}
	MatrixPrint(result, rows1, columns2);						//display the result matrix


}

void MatrixTranspose(vector<vector<double> >& matrix1, int rows1, int columns1)						//function to find MatrixTranspose of matrix
{
	vector<vector<double> >result(a, vector<double>(a, 0));					//initialize a matrix to store result
	for (int i = 0; i<rows1; ++i)						//for loop for ith rows
		for (int j = 0; j<columns1; ++j)						//for loop for jth column in ith row
		{
			result[j][i] = matrix1[i][j];						//interchange elemnts with rows and columns
		}
	MatrixPrint(result, columns1, rows1);						//Displays MatrixTranspose of matrix
}

int MatrixDet(vector<vector<double> >& matrix1, int rows1, int columns1)					//function to find MatrixDet of matrix
{
	int result;											//initialize to stroe result

	result = matrix1[0][0] * matrix1[1][1] * matrix1[2][2]					//logicto calculate MatrixDet
		- matrix1[0][0] * matrix1[1][2] * matrix1[2][1]
		- matrix1[0][1] * matrix1[1][0] * matrix1[2][2]
		+ matrix1[0][1] * matrix1[1][2] * matrix1[2][0]
		+ matrix1[0][2] * matrix1[1][0] * matrix1[2][1]
		- matrix1[0][2] * matrix1[1][1] * matrix1[2][0];
	return result;										//returns the value of result


}

void MatrixInverse(vector<vector<double> >& matrix1, int rows1, int columns1)				//function to find MatrixInverse of matrix
{
	double det;									//to store MatrixDet value
	det = MatrixDet(matrix1, rows1, columns1);					//finds the MatrixDet of matrix
	vector<vector<double> >result(a, vector<double>(a, 0));					//initialize matrix to store the result

	//logic to find inverese of matrix

	result[0][0] = (1 / det)*(matrix1[1][1] * matrix1[2][2] - matrix1[2][1] * matrix1[1][2]);
	result[0][1] = (1 / det)*(-(matrix1[1][0] * matrix1[2][2] - matrix1[1][2] * matrix1[2][0]));
	result[0][2] = (1 / det)*(matrix1[1][0] * matrix1[2][1] - matrix1[2][0] * matrix1[1][1]);
	result[1][0] = (1 / det)*(-(matrix1[0][1] * matrix1[2][2] - matrix1[0][2] * matrix1[2][1]));
	result[1][1] = (1 / det)*(matrix1[0][0] * matrix1[2][2] - matrix1[0][2] * matrix1[2][0]);
	result[1][2] = (1 / det)*(-(matrix1[0][0] * matrix1[2][1] - matrix1[2][0] * matrix1[0][1]));
	result[2][0] = (1 / det)*(matrix1[0][1] * matrix1[1][2] - matrix1[0][2] * matrix1[1][1]);
	result[2][1] = (1 / det)*(-(matrix1[0][0] * matrix1[1][2] - matrix1[1][0] * matrix1[0][2]));
	result[2][2] = (1 / det)*(matrix1[0][0] * matrix1[1][1] - matrix1[1][0] * matrix1[0][1]);
	MatrixTranspose(result, rows1, columns1);							//MatrixTranspose is found of result matrix and is displayed


}
