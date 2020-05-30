/*
Name : Diksha Prakash
RUID : 186001757
Date of Submission : 10/02/18
Program to perform matrix operations
*/

#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
#include<iomanip>

using std::setw;
unsigned int choice;
const int a = 10;     //maximum row and column size which is going to be constat to initialize matrix

void matrixInput(void);   //function prototype for inputting the matrix
void printMatrix(double [a][a], int, int);    //function prototype for printing the matrix
void matAdd(double [a][a], double [a][a], int, int, int, int);    //function prototype for performing the matrix addition
void matSub(double [a][a], double [a][a], int, int, int, int);    //function prototype for performing the matrix subtraction
void matMul(double [a][a], double [a][a], int, int, int, int);    //function prototype for performing the matrix multiplication
int matDet(double[a][a], int, int);    //function prototype for calculating the determinant of the matrix
void matTranspose(double [a][a], int, int);   //function prototype for calculating the transpose of the matrix
void matInverse(double [a][a], int, int);   //function prototype for calculating the inverse of the matrix

int main()
{
  cout << "\n NOTE : The program accepts only (3 X 3) for Determinant and Inverse operations & (10 X 10) matrix for other operations !! \n" ;
  cout << "\n Available Matrix Operations : \n";    // Informing the users of the available matrix operations
	cout << "\n Choice 1 : Addition";
	cout << "\n Choice 2 : Subtraction";
	cout << "\n Choice 3 : Multiplication";
	cout << "\n Choice 4 : Determinant";
	cout << "\n Choice 5 : Transpose";
	cout << "\n Choice 6 : Inverse";
	cout << "\n Choice 7 : Quit";
	cout << "\n Enter your choice of operation : \n ";   //Asking the user for the input
	cin >> choice;   //The user input is stored in the varibale 'choice'
  if(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6)
    matrixInput(); //If the user input is valid, then the function to enter the elements of the matrix is called
  else if (choice == 7)
    goto jmp; //If the user has asked to 'Quit', end the programme
  else
    cout<< "\n Please enter a valid choice number !! \n"; //If the user input doesn't belong to [1,7], ask for a valid input
    main();   //Recalling the main() function after prompting to enter a valid input

  jmp:
	return 0;

}

void matrixInput(void)    //Function to take user input for the elements of the matrix
{
  int row1 ;    //Variable declaration to calculate the number of rows
  int col1 ;    //Variable declaration to calculate the number of columns
  cout << "\n Enter the number of rows : \n" ;    //Asking the user to input the number of desired rows
  cin >> row1 ;   //User input is stored in the variable 'row1' declared above
  cout << "\n Enter the number of columns : \n" ;   //Asking the user to input the number of desired columns
  cin >> col1 ;   //User input is stored in the variable 'col1' declared above
  cout << "\n Please enter elements of matrix : \n";    //Asking the user to enter the elements of the matrix one by one
  double mat1[a][a];    //Declaration of the matrix i.e. a 2D array
    for (int i=0; i < row1; i++){   //'i' is the counter variable for the number of rows
      for (int j=0; j < col1; j++){   //'j' is the counter variable for number of columns
        cin >> mat1[i][j];    //The user input is stored in the matrix 'mat1' for a specific value of 'i' and 'j'
      }
    }
  cout << "\n The input matrix is : \n";    //Prompting the user that the input matrix is now going to be displayed
  printMatrix(mat1, row1, col1);    //Calling the function for printing the matrix


  double mat3[a][a];    //Declaration of the matrix i.e. 2D array
  int col2;   //Variable declaration to calculate the number of rows
  int row2;   //Variable declaration to calculate the number of columns
  if (choice == 1 || choice == 2 || choice == 3)    //Since two matrices are needed for the opeartions involving choices 1, 2 and 3; the user is asked to enter the second matrix
  {
    cout << "\n Please enter elements of second matrix : \n";   //User is prompted that he will be asked to enter the second matrix
    cout<< "\n Please enter the number of rows : \n";   //The number of desired rows are asked from the user
    cin >> row2;    //User input is stored in the variable 'row2' declared above
    cout << "\n Please enter the number of columns : \n";   //The number of desired columns are asked from the user
    cin >> col2;    //User input is stored in the variable 'col2' declared above
    cout << "\n Please enter elements of matrix : \n";    //Asking the user to enter the elements of the matrix one by one
    for (int i = 0; i < row2; i++){   //'i' is the counter variable for the number of rows
        for (int j = 0; j < col2; j++){   //'j' is the counter variable for the number of columns
          cin >> mat3[i][j];    //The user input is stored in the matrix 'mat3' for a specific value of 'i' and 'j'
        }
      }
    cout << "\n The input matrix is : \n";    //Prompting the user that the input matrix is now going to be displayed
    printMatrix(mat3, row2, col2);    //Calling the function for printing the matrix
  }
	int DD;    //variable declaration of the type 'int' and name 'DD'
	switch (choice){   //Operating switch cases on the choice entered by the user
    case 1 :    //Case 1 calls the addition function named 'matAdd' on the matrices
      cout << "\n The result of Matrix Addition is : \n";
      matAdd(mat1, mat3, row1, col1, row2, col2);
      main();   //Transfer the control back to the main function so that the user can perform another opeartion
      break;    //Breaking out of 'switch' statement

    case 2 :    //Case 2 calls the subtraction function named 'matSub' on the matrices
      cout << "\n The result of Matrix Subtraction is : \n";
      matSub(mat1, mat3, row1, col1, row2, col2);
      main();   //Transfer the control back to the main function so that the user can perform another opeartion
      break;    //Breaking out of 'switch' statement

    case 3 :    //Case 3 calls the multiplication function named 'matMul' on the matrices
      cout << "\n The result of Matrix Multiplication is : \n";
      matMul(mat1, mat3, row1, col1, row2, col2);
      main();   //Transfer the control back to the main function so that the user can perform another opeartion
      break;    //Breaking out of 'switch' statement

    case 4:   //Case 4 calls the determinant calculation function named 'matDet' on the matrices
			DD = matDet(mat1, row1, col1);
			cout << "\n The Matrix determinant is :  " + std::to_string(DD)+ " \n";
      main();   //Transfer the control back to the main function so that the user can perform another opeartion
      break;    //Breaking out of 'switch' statement

    case 5:   //Case 5 calls the transpose calculation function named 'matTranspose' on the matrices
      cout << "\n The Transpose of the matrix is : \n";
      matTranspose(mat1, row1, col1);
      main();   //Transfer the control back to the main function so that the user can perform another opeartion
      break;    //Breaking out of 'switch' statement

    case 6:   //Case 6 calls the inverse function named 'matInverse' on the matrices
      cout << "\n The Inverse of the matrix is : \n";
      matInverse(mat1, row1, col1);
      main();   //Transfer the control back to the main function so that the user can perform another opeartion
      break;    //Breaking out of 'switch' statement
  }
}

void printMatrix(double matrix[a][a], int num_row, int num_col)   //Function to print the matrix which is input by the user
{
  for (int i=0 ; i < num_row; i++){   //'i' is the counter variable for the number of rows
    for (int j=0 ; j < num_col; j++){   //'j' is the counter variable for the number of columns
      cout << setw(7) << matrix[i][j];    //Every element for a specific value of 'i' and 'j' is printed
    }
    cout << endl;
  }
}

void matAdd (double matrix1[a][a], double matrix3[a][a], int n_row, int n_col, int n_row2, int n_col2)    //Function to add the elemnts of the two matrices which are input by the user
{
  double AddResult[a][a];   //Declaring a matrix named 'AddResult' to store the results post the addition
  if (n_row == n_row2 && n_col == n_col2){    //Matrix addition can only be performed if both the matrices have the same number of rows and columns
    for (int i=0; i < n_row; i++){    //'i' is the counter variable for the number of rows
      for (int j=0; j < n_col; j++){    //'j' is the counter variable for the number of columns
        AddResult[i][j] = matrix1[i][j] + matrix3[i][j];    //Post addition of elements for a specific 'i' and 'j', store the result in 'AddResult' matrix declared above
      }
    }
    printMatrix(AddResult, n_row, n_col);   //Post computation, 'printMatrix' function is called to print the result to the user
    cout << "\n ----------------------------~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~------------------------------- \n";
  }
  else
    cout << "\n This operation isn't supported !! \n";    //If the number of rows and columns aren't identical for the two matrices, the user is intimated taht the opeartion can't be performed
}

void matSub(double matrix1[a][a], double matrix3[a][a], int n_row, int n_col, int n_row2, int n_col2)   //Function to subtract the elemnts of the two matrices which are input by the user
{
  double SubResult[a][a];   //Declaring a matrix named 'SubResult' to store the results post the subtraction
  if (n_row == n_row2 && n_col == n_col2){    //Matrix subtraction can only be performed if both the matrices have the same number of rows and columns
    for (int i=0; i < n_row; i++){    //'i' is the counter variable for the number of rows
      for (int j=0; j < n_col; j++){    //'j' is the counter variable for the number of columns
        SubResult[i][j] = matrix1[i][j] - matrix3[i][j];    //Post subtraction of elements for a specific 'i' and 'j', store the result in 'SubResult' matrix declared above
      }
    }
    printMatrix(SubResult, n_row, n_col);   //Post computation, 'printMatrix' function is called to print the result to the user
    cout << "\n ----------------------------~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~------------------------------- \n";
  }
  else
    cout << "\n This operation isn't supported !! \n";    //If the number of rows and columns aren't identical for the two matrices, the user is intimated taht the opeartion can't be performed
}

void matMul(double matrix1[a][a], double matrix3[a][a], int n_row, int n_col, int n_row2, int n_col2)   //Function to multiply the elemnts of the two matrices which are input by the user
{
  double MulResult[a][a];   //Declaring a matrix named 'MulResult' to store the results post the multiplication
  if (n_col == n_row2){   //Matrix multiplication can only be performed if the number of columns of the first matrix is equal to the number of rows of the second matrix
    for (int i=0; i < n_row; i++){    //'i' is the counter variable for the number of rows of the first matrix
      for (int j=0; j < n_col2; j++){   //'j' is the counter variable for the number of columns of the second matrix
        for (int k=0; k < n_col; k++){    //'k' is the counter variable for the number of columns of the first matrix
          MulResult[i][j] += matrix1[i][k] * matrix3[k][j];   //Post multiplication of elements for a specific 'i' and 'j', store the result in 'MulResult' matrix declared above
        }
      }
    }
    printMatrix(MulResult, n_row, n_col2);     //Post computation, 'printMatrix' function is called to print the result to the user
    cout << "\n ----------------------------~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~------------------------------- \n";
  }
  else
    cout << "\n This operation isn't supported !! \n";    //If the number of columns of the first matrix and number of columns of the second matrix aren't identical, the user is intimated taht the opeartion can't be performed
}

int matDet(double matrix1[a][a], int n_row, int n_col)    //Function to calculate the determinant of the matrix which are input by the user
{
  int DetResult;    //Variable declaration of the type 'int' to store the results of computation
  if (n_row == 3 && n_col == 3)   //The requirement is that the Determinant can only be calculated for a (3 X 3) matrix
  {
    DetResult = matrix1[0][0] * matrix1[1][1] * matrix1[2][2]   //The results of computation are stored in 'DetResult'
			- matrix1[0][0] * matrix1[1][2] * matrix1[2][1]
			- matrix1[0][1] * matrix1[1][0] * matrix1[2][2]
			+ matrix1[0][1] * matrix1[1][2] * matrix1[2][0]
			+ matrix1[0][2] * matrix1[1][0] * matrix1[2][1]
			- matrix1[0][2] * matrix1[1][1] * matrix1[2][0];
	cout << "\n ----------------------------~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~------------------------------- \n";
	    //This function returns 'DetResult' variable containing the value post determinant computation
  }
  else
    cout << "\n This operation isn't supported !! \n";    //If the matrix isn't (3 X 3), prompt the user that the opeartion can't be performed
  return DetResult;
}


void matTranspose(double matrix1[a][a], int n_row, int n_col)   //Function to calculate the transpose of the matrix which are input by the user
{
  double InvResult[a][a];   //Declaring a matrix named 'InvResult' to store the results post the transpose calculation
  for (int i=0; i < n_row; i++){    //'i' is the counter variable for the number of rows of the matrix
    for (int j=0; j < n_col; j++){    //'j' is the counter variable for the number of columns of the matrix
      InvResult[j][i] = matrix1[i][j];    //the 'i' and 'j' locations are flipped in the result matrix
    }
  }
  printMatrix(InvResult, n_row, n_col);   //Post computation, 'printMatrix' function is called to print the result to the user
  // cout << "\n ----------------------------~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~------------------------------- \n";
}

void matInverse(double matrix1[a][a], int n_row, int n_col)   //Function to calculate the inverse of the matrix which are input by the user
{
  int det;    //Variable declaration of the type 'int' to store the results of computation
  det = matDet(matrix1, n_row, n_col);    //Calling the function 'matDet' to calculate the determinant of the matrix and storing it in the variable 'det'
  double result[a][a] = { 0 };    //Declaring a matrix named 'result' to store the results of computation
  if (n_row == 3 && n_col == 3 && det != 0){    //Determinant calculation requirement here s that the matrix should be of (3 X 3) and the value of the determinant shouldn't be equal to zero
    result[0][0] = (1 / det)*(matrix1[1][1] * matrix1[2][2] - matrix1[2][1] * matrix1[1][2]);
    result[0][1] = (1 / det)*(-(matrix1[1][0] * matrix1[2][2] - matrix1[1][2] * matrix1[2][0]));
    result[0][2] = (1 / det)*(matrix1[1][0] * matrix1[2][1] - matrix1[2][0] * matrix1[1][1]);
    result[1][0] = (1 / det)*(-(matrix1[0][1] * matrix1[2][2] - matrix1[0][2] * matrix1[2][1]));
    result[1][1] = (1 / det)*(matrix1[0][0] * matrix1[2][2] - matrix1[0][2] * matrix1[2][0]);
    result[1][2] = (1 / det)*(-(matrix1[0][0] * matrix1[2][1] - matrix1[2][0] * matrix1[0][1]));
    result[2][0] = (1 / det)*(matrix1[0][1] * matrix1[1][2] - matrix1[0][2] * matrix1[1][1]);
    result[2][1] = (1 / det)*(-(matrix1[0][0] * matrix1[1][2] - matrix1[1][0] * matrix1[0][2]));
    result[2][2] = (1 / det)*(matrix1[0][0] * matrix1[1][1] - matrix1[1][0] * matrix1[0][1]);

    matTranspose(result, n_row, n_col);   //Calculating the function 'matTranspose' to calculate the transpose of the resultant matrix
    cout << "\n ----------------------------~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~------------------------------- \n";
  }
  else
    cout << "\n This operation isn't supported !! \n";    //If the matrix isn't (3 X 3) or the value of the determinant is zero, prompt the user that the operation isn't supported
}
