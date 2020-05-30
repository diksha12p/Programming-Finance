/* Submitted by : Diksha Prakash
RUID: 186001757
InClass Assignment-2
Submission Date : 09/15/2018 */

#include <iostream>
using namespace std;

int main()
{
    int rows;
    //Asking user input for the number of rows
    cout << "Enter number of rows: ";
    cin >> rows;
    // Printing the right angled half pyramid
    for(int i = 1; i <= rows; ++i) // Loop to keep a track of the number of rows
    {
        for(int j = 1; j <= i; ++j) //Loop to print the number of astricks correctly
        {
            cout << "*";
        }
        cout << "\n"; //Entering new line after every successful completion of the sub-loop
    }
    system("pause");
    return 0;
}
