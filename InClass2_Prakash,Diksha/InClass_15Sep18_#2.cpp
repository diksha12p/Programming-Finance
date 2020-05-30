/* Submitted by : Diksha Prakash
RUID: 186001757
InClass Assignment-2
Submission Date : 09/15/2018 */

#include <iostream>
using namespace std;

int main()
{
  int i,j,r,n;
  cout<<"Enter the maximum number of odd spaces \n";
  cin>>n;
  if (n%2 == 0)
    {
      cout<<"Invalid input! please enter ODD number of spaces \n";
    }
  else {
    //Calculating the number of rows from the user entered maximum number of spaces
    r=n+2;
    //First loop to keep a track of the number of the row being dealt with
    for(i=0; i<r; i++)
      {
        //Second loop to print the astrick once the condition is met
        for(j=0; j<r; j++)
          {
            // Condition description using logical 'OR' operator
            if(i+j== r/2 || i+j == (r-1)+r/2 || j-i == r/2 || i-j == r/2)
              cout<<"*";
            else
              cout<<" ";
          }
        cout<<"\n";
      }
  }
  system("pause");
  return 0;

}
