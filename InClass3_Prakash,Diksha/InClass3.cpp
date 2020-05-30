/*
Name: Diksha Prakash
RUID: 186001757
In-class 3: Calculating the winner of RSC polls
Date of Submission: 22nd September 2018
*/

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

#include<iomanip>

using std::setw;

// Function definition for finding out the 'winner' for the array input
void winner(int candidates[], int votes[], int voters)
{
  int nCandidates = 5; // nCandidates is a variable representing the number of candidates
  // int voters = 20; //voters is a variable representing the number of students casting their vote
  int highestVote = 0; //highestVote is a variable representing the highest number of votes for a specific candidate
  int next_apprentice; //next_apprentice is a variable representing the next winner
  int error = 0; //error is a variable representing any tie in the number of highest votes

  // Objective 1 : Count the number of votes that each candidate has got
  for (int i = 1; i<= nCandidates; i++)
    candidates[i] = 0; //Generating the candidate numbers
  for (int j = 1; j <= voters; j++)
      ++candidates[votes[j]]; //Incrementing the number of votes as each candidate is encountered

  // Objective 2 : Print the number of votes for each candidates
  cout<<"RSC results for every Candidate \n";
  cout<<"Candidate Number  "<<setw(25)<<"No. of Votes   "<<"\n"; //Printing the header of the table
  for (int numCandidate = 1; numCandidate <= nCandidates; numCandidate++)
  {

    cout<<setw(6)<<numCandidate<<setw(30)<<candidates[numCandidate]<<"\n"<<endl; //Printing the number of votes taht each candidate has got

    // Objective 3 : Compare among all the candidates for declaring the winner

    if (candidates[numCandidate] > highestVote) //Comparing the highest obtained vote with the votes of the other candidates
      {
        highestVote = candidates[numCandidate]; //Assigning the value of the largest vote to the variable 'highestVote'
        next_apprentice = numCandidate; //Declaring the candidate with highest umber of votes as the winner

      }
  }
  // cout<<"Next Apprentice is"<<next_apprentice<<"\n"<<highestVote<<"\n";

  // Objective 4 : Checking if two candidates have the same number of Votes

  for (int s = 1; s <= nCandidates; s++){
    // cout<<candidates[numOfCandidates]<<"\n";
    if ( candidates[s] == highestVote ) //Checking if any other candidate has an equal number of highest vote
      error++; //If true, the error flag is incremented
  }
    if (error > 1)
      cout<<"There's no winner !! \n"; //In case two candidates have the same number of highest votes, decalare taht there is no winner
    else
      cout<<"Congratulations! The winner is    "<< next_apprentice << "   and has got  " << highestVote << " votes \n"; //If thre's no tie, print the winner and the number of votes won
}



int main()
{
  //Variable declaration
  const int voters = 20;
  int candidates[5];
  int votes[voters];

  cout<<"\n Start Voting! Record your responses now : \n ";
  cout<< "\n Note that the available choices are : 1, 2, 3, 4 and 5 \n";
   for(int k = 1; k <= voters; k++) //Looping through all the voters to register their responses
   {
     cout<<"Waiting response for Student "<<k<<"\n";
     cin>>votes[k]; //Recording the response for each voter
     while (votes[k]>5 || votes[k]<1 || cin.fail()) //Checking the condition when the user hasn't enteered a valid input
     {
       cin.clear(); //Clear the response
       cout<<"Please enter a valid input between 1 and 5 (inclusive) \n"; //Prompt the voter to enter a correct value
       cin>>votes[k]; //Register the response of the voter
     }
   }
  winner(candidates, votes, voters); //Call the function 'winner' to compute the winner after voting
  system("pause");
  return 0;
}
