/*
Name : Diksha Prakash
RUID : 186001757
Date of Submission : 10/20/18
Header File definitions for class IntegerSet.
*/


#ifndef INTEGER_SET_H
#define INTEGER_SET_H

class IntegerSet
{
public:
	IntegerSet(); // constructor

	IntegerSet UnionOfSets(IntegerSet set2);		  /* Write a member funcion prototype for UnionOfSets */

	IntegerSet IntersectionOfSets(IntegerSet set2); //member function prototype for intersection of set

	void inputSet(); // read values from user

	void printSet() const;

private:
	int set[101]; // range of 0 - 100

				  // determines a valid entry to the set
	int validEntry(int x) const
	{
		return (x >= 0 && x <= 100);
	} // end function validEntry
};
#endif
