/*
Name : Diksha Prakash
RUID : 186001757
Date of Submission : 10/08/18
Program to perform operations on entered ISBNs list
*/

#include<iostream>
#include<iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::setw;

const int size = 20;
int bookArray_ISBN[size];
int numBooks;
int choice;
int unsorted = 0;

void insert(int [size], int , int );									//protoype of insert function
void insert_at(int [size], int , int , int );							////protoype of insert at position function
int find_linear(int [size], int , int );								////protoype of function for finding element by linear search
int find_binary(int [size], int , int );								//protoype of function for finding element by binary search
void delete_item_position(int [size], int, int);						//protoype of deleting element function
void delete_item_isbn(int [size], int , int);							//protoype of function for deleting element by ISBN
void sort_list_selection(int [size], int );								////protoype of sorting function
void sort_list_bubble(int [size], int);									//protoype of soriting function by bubblesort
void print(int [size], int );											////protoype of printint the array function

int main(){   //Declaration of main function
  int new_entry;  //Variable Declaration
  int output;
  int pos;
  if (numBooks == 0){   //If the list is empty, the user is asked to enter values of ISBN
    cout << "Your list is empty, please input some ISBNs !! \n";
    cin >> new_entry;   //Storing the entered value in the varu=iable
    insert (bookArray_ISBN, numBooks, new_entry);   //Calling the function to insert the user input in the list
    numBooks++;   //Incrementing the counter of the number of ISBNs in the list
    print(bookArray_ISBN, numBooks);    //Calling the function to print the list to the user
  }
  cout << "What operation would you like to perform ? \n";  //Asking the uer for an input corresponding to the choice of operation to be performed
  cout << "  " << " 1. Add an element to end of list\n";
	cout << "  " << " 2. Add an element at a location\n";
	cout << "  " << " 3. Find an element by ISBN number (linear search)\n";
	cout << "  " << " 4. Find an element by ISBN number (binary search)\n";
	cout << "  " << " 5. Delete an element at position\n";
	cout << "  " << " 6. Delete an element by ISBN number\n";
	cout << "  " << " 7. Sort the list using selection sort\n";
	cout << "  " << " 8. Sort the list using bubble sort\n";
	cout << "  " << " 9. Print the list\n";
	cout << "  " << " 0. Exit\n";
  cout << "\n" << "\n" << "Enter your choice : \n";
  cin >> choice;    //Recording the choice of the user

  switch(choice)    //Implementing 'switch' cases on the user input
  {
   case 1:  //When the user wants to add an element to the end of the list
  		if (numBooks < size)											//checks if no. of numBooks in library list are less than 20
  		{
  			cout << "\n Please type in the element\n";				//prompts to type new element
  			cin >> new_entry;										//reads new element
  			if (find_linear(bookArray_ISBN, numBooks, new_entry) != -1)   //checks if the new element entered already exist
  			{
  				delete_item_isbn(bookArray_ISBN, numBooks,new_entry);   // delete that element if it exists
  				numBooks--;											//decrease the list size
  			}
  			insert(bookArray_ISBN, numBooks, new_entry);					//function call to insert element in list
  			numBooks++;											//decrease the list size
  			print(bookArray_ISBN, numBooks);					//prints the list
  			unsorted = 0;												//indicates the list is unsorted since new element added

  		}
  		else
  			cout << "\n List is full\n";					// prompts list is full if no. of numBooks greater than or equal to 20
  		main();												//shows the menu again
  		break;

    case 2:   //When the user wants to add an input at a given location in the list
      if (numBooks < size){   //Checking if the entered location falls within the array bounds
        cout << "Enter the element to be inserted : \n";
        cin >> new_entry; //Storing the user input in the variable
        if (find_linear(bookArray_ISBN, numBooks, new_entry) != -1){  //Checking the the entered ISBN is a part of the list
          cout << "Oops! The Element was already present at a location !! \n"; //If the condition holds true, the user is prompted that the old element got deleted
          cout << "The old element is now getting deleted !! \n";
          delete_item_isbn(bookArray_ISBN, numBooks, new_entry);    //function used to delete the existing element
          numBooks -- ;   //Decrementing the counter indicating the number of current ISBNs in the list
          print(bookArray_ISBN, numBooks);    //Printing out the new list to the user
        }
        cout << "Please enter the position at which insertion will happen \n";  //Asking the user for the location where the insertion is to happen
        cin >> pos;   //Storing the user input in a variable
        if (pos <= numBooks){   //Checking if the entered position lies within the array index range
          insert_at(bookArray_ISBN, numBooks, pos, new_entry);    //Function call to insert the elements at the requested position
          numBooks ++ ;   //Incrementing the counter indicating the number of current ISBNs in the list
          print(bookArray_ISBN, numBooks);    //Printing out the new list to the user
          unsorted = 0;   //Setting the 'unsorted' flag to 0 since elements have been added to the list
        }
        else
          cout << "Oops! Entered position is out of array bounds !! \n";    //If the entered position doesn't lie within the array range, error is prompted to the user

      main();   //Passing the control back to main() function to display the menu
      break;    //Breaking out of case 2
      }

    case 3:   //When the user wants to find an element using linear search
      cout << "Please enter the element to be searched ! \n";   //User input for the ISBN to be searched
      cin >> new_entry;   //Storing the user input
      output = find_linear(bookArray_ISBN, numBooks, new_entry);    //Storing the result of find_linear() function in 'output' variable
      if (output != -1)   //If the output's value isn't equal to -1 i.e. the ISBN is present in the list, print out the location to the user
        cout << "The entered ISBN  " << new_entry << "  is at location  "<< output <<"\n";
      else
        cout << "The entered ISBN couldn't be found !! \n"; //If the value of output is -1, prompt the user that the entered ISBN doesn't exixt in the list
      main(); //Passing the control back to main() function to display the menu
      break;    //Breaking out of case 3

    case 4:   //When the user wants to performs a binary search of an ISBN
      if (unsorted == 1){   //The condition for binary search to work is that the list should be sorted
        cout << "Please enter the element to be searched ! \n"; //Asking user input for the ISBN to be searched
        cin >> new_entry;   //Storing the user input in a variable
        output = find_binary(bookArray_ISBN, numBooks, new_entry);    //Checking if the value exists in the list
        if (output != -1)   //If the value of the ISBN exists in the list, return the position of the same to the user
          cout << "The entered ISBN "<< new_entry << "  is at location  "<< output <<"\n";
        else
          cout << "Element not found !! \n";  //If the value of the ISBN doesn't exist in the list, prompt error to the user
      }
      else
        cout << "\n List is not sorted, Please sort the list before performing binary search\n"; //if list not sorted, prompt the suer of the error
      main();   //Passing the control back to main() function to display the menu
      break;    //Breaking out of case 4

    case 5:   //When the user wants to delete the lement at a particular specified position
      if (numBooks > 0){    //Checking if the list isn't empty
        cout << "Please enter the position whose element you want to delete : \n";    //Asking the user for the position where deletion is to be performed
        cin >> pos ;    //Storing user input in 'pos' variable
        while (pos > size || pos < 0){    //COndition to check if an invalid integer value is entered by the user
          cout << "Please enter a valid position ! \n";   //If invalid position is entered by the user, prompt the error to the user
          cin >> pos ;    //Storing the new value in the 'pos' variable
        }
        delete_item_position(bookArray_ISBN, numBooks, pos);   //function call to delete specified position element
  			numBooks--;									//decrease the list size
  			print(bookArray_ISBN, numBooks);						//print the list
      }
      main();   //Passing the control back to main() function to display the menu
      break;    //Breaking out of case 5

    case 6:   //When the user wants to delete an element by providing the ISBN
      cout << "Enter the ISBN to be deleted : \n";    //Asking the ISBN value from the user
      cin >> new_entry;   //Storing the user response in 'new_entry' variable
      if (find_binary(bookArray_ISBN, numBooks, new_entry) != -1){    //Checking if the ISBN is present in the list
        delete_item_isbn(bookArray_ISBN, numBooks, new_entry);    //If present, deleting the element
        numBooks--;										//decrease the list size
				print(bookArray_ISBN, numBooks);						//print the list
      }
      main();   //Passing the control back to main() function to display the menu
      break;    //Breaking out of case 6

   case 7:
    	if (numBooks > 1){
    		cout << "\n The sorted list is as under : \n";
    		sort_list_selection(bookArray_ISBN, numBooks);   //sorts the list
    		print(bookArray_ISBN, numBooks);						//print the list
    	}
    	unsorted = 1;										//indicates the list is sorted
    	main();			//Passing the control back to main() function to display the menu
      break;    //Breaking out of case 7

   case 8:
     if (numBooks > 1)									//checks if no. of numBooks in library list are more than 1
     {
       cout << "\n The sorted list is as under : \n";
       sort_list_bubble(bookArray_ISBN, numBooks);  //sorts the list by bubble sort
       print(bookArray_ISBN, numBooks);									//print the list
     }
     unsorted = 1;										//indicates the list is sorted
     main();			//Passing the control back to main() function to display the menu
     break;    //Breaking out of case 8

   case 9:
   		print(bookArray_ISBN, numBooks);                    //print the list
   		main();		 //Passing the control back to main() function to display the menu
      break;    //Breaking out of case 9

   case 0:
   		return 0;									//successfull termination of program
   		break;

      }

// Holds output window in Visual C++
  cin.clear();
  cin.ignore();
  cin.get();
  }

void insert(int array[size], int num_in_list, int new_element) //function defined to insert new element
  {
  	array[num_in_list] = new_element;						//inserts new element at end of the list
  }


void insert_at(int array[size], int num_in_list, int position, int new_element)//function defined to insert new element at speicific position
  {
  	for (int i = num_in_list - 1; i >= position - 1; i--)
  		array[i + 1] = array[i];							//shifts the elements to right side after specidfied postion
  	array[position - 1] = new_element;					//inserts new element at specified position
  }

int find_linear(int array[size], int num_in_list, int element) //function defined to find element by linear search
  {
  	for (int i = 0; i < num_in_list; i++)
  		if (array[i] == element)				//compares each element by entered element
  			return i+1;							//returns position if found

  	return -1;									//returns -1 if not found
  }

int find_binary(int array[size], int num_in_list, int element)//function defined to find element by binary search
  {
  	int low = 0;								//initialize low as 0
  	int high = num_in_list - 1;					//initialize high as highest index no. of array
  	int middle;									//initialize middle to store fouund element
  	if (unsorted == 1)								//if list is sorted
  	{
  		while (low <= high)                   //will execute all statements only till low is less than high
  		{
  			middle = (low + high) / 2;
  			if (element == array[middle])     //if element matches middle, middle is returned
  				return middle+1;

  			else if (element < array[middle])
  				high = middle - 1;			//if element is less than middle element high value is reduced to given
  			else
  				low = middle + 1;				//if element is more than middle element low value is increases to given

  		}
  		return -1;
  	}
  }//end of main function

void delete_item_position(int array [size], int num_in_list, int position)//function defined to delete element by position
  {
  	for (int i = position ; i <num_in_list; i++)
  		array[i - 1] = array[i];         // shifts the elements to the left and overlap the element which is to be deleted

  }

void delete_item_isbn(int array[size], int num_in_list, int element)//function defined to delete specified element
  {
  	int position;                                    //initialize the position
  	position = find_linear(array, num_in_list, element);	//element is found sotre the position
  	if (position != -1)
  		delete_item_position(array, num_in_list, position); //call the above function
  	else
  		cout << "\n Element not found\n";
  }


void sort_list_selection(int array[size], int num_in_list)//function defined to sort list
  {
  	int swap_index;							//initialize
  	int smallest;							//initialize to store smaller no.
  	int temp;								//variable for swapiing
  	int k;
  	for (int i = 0; i < num_in_list - 1; i++)    //till all small elements are swapped
  	{
  		smallest = *(array + i);
  		swap_index = i;
  		for (k = i + 1; k < num_in_list; k++)
  		{
  			if (*(array + k) < smallest)     //checks every element
  			{
  				smallest = *(array + k);
  				swap_index = k;
  			}
  		}
  		temp = *(array + i);					//swaps the smallest no. and brings on left side
  		*(array + i) = smallest;
  		*(array + swap_index) = temp;
  	}
  }

void sort_list_bubble(int array[size], int num_in_list)//function defined to sort by bubble sort
  {
  	int hold;									// temporary location used to swap array elements

  	for (int i=0; i<num_in_list-1; i++)					// loop to control number of total swapping loop
  		for (int j=0; j<num_in_list-1-i; j++)   // compare side-by-side elements and swap them if
  			if (*(array + j) > *(array + (j + 1))) //previous no. is greater than next no.
  			{
  				hold = *(array+j);
  				*(array + j) = *(array + (j + 1));
  				*(array + (j + 1)) = hold;
  			}

  }


void print(int array[size], int num_in_list)//function defined to print list
  {
  	cout << "\n Your list is now\n\n";         //prompts
  	for (int i = 0; i < num_in_list; i++)
  		cout <<"  "<< i + 1 << ". " << array[i] << endl;			//prints each element and takes cursor to next line
  }
