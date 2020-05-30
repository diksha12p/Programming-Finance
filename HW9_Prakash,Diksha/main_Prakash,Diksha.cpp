/*	Name : Diksha Prakash
Date : 11/8/2018
Main file
*/

#include <iostream>			// I/O header library
#include <iomanip>			// I/O manipulation library
#include <vector>			// Header for vector

using std::setprecision;	// Set precision
using std::fixed;			// Fixed width
using namespace::std;		// Standard cout and cin
using std::vector;

#include "package.h"	// Include base class
#include "twodaypackage.h" // Derived class twodaypackage
#include "overnight.h"	// Derived class overnightpackage

int main()
{
	vector < package * > packs(3); // Vector for three objects

	cout << "\n The cost per ounce for package is $2/ounce ";
	cout << "\n The additional cost for two day delivery is $2.5/ounce";
	cout << "\n The additional cost for overnight delivery is $5/ounce" << endl << endl;

	// initialize vectors
	packs[0] = new package("Diksha Prakash", "D, Phelps Ave", "NB", "NJ", 123456, "Shreya Prakash", "A, Phelps Ave", "NB", "NJ", 98901, 20, 5);
	packs[1] = new twodaypackage("Diksha Prakash", "D, Phelps Ave", "NB", "NJ", 89011, "Ayush Bansal", "4H, Mehrauli", "Delhi", "ND", 800001, 5, 2, 2.5);
	packs[2] = new overnightpackage("Shaashwat Bharadwaj", "Sector 5", "Faridabad", "HR", 801234, "Jatin Khanna", "Janakpuri East", "Delhi", "ND", 468527, 2, 2, 5);

	double totalcost = 0;	// Initialise cost variable to zero
	cout << fixed << setprecision(2);

	// Print the final output
	for (size_t i = 0; i < packs.size(); i++)
	{
		cout << "					PACKAGE NUMBER	" << i + 1 << " \n \nSENDER :\n" << packs[i]->getSenderName() << '\n' << packs[i]->getSenderAddress() << ',' << packs[i]->getSenderCity() << ", " << packs[i]->getSenderState() << ',' << packs[i]->getSenderZIP();
		cout << "\n \nRECIPIENT :\n" << packs[i]->getRecipientName() << '\n' << packs[i]->getRecipientAddress() << ',' << packs[i]->getRecipientCity() << ", " << packs[i]->getRecipientState() << ',' << packs[i]->getRecipientZIP();
		double cost = packs[i]->calculateCost();
		cout << "\n \n Weight:" << packs[i]->getWeight();
		cout << "\n Rate Per Ounce :" << packs[i]->getCost();
		cout << "\n Cost: $" << cost ;

		if (i == 0)
		{
			cout << "\n The type of Delivery is \"Regular Delivery\" \n" << endl;
		}
		else if (i == 1)
		{
			cout << "\n The type of Delivery is \"Two Day Delivery\" \n " << endl;
		}
		else
		{
			cout << "\n The type of Delivery is \"Overnight Delivery\" \n  " << endl;
		}
		totalcost += cost; // add to total
	}
	cout << "\n \n Hence, TOTAL SHIPPING COST is:	$" << totalcost << " . " << endl;
	
	//Hold the screen
	cin.clear();
	cin.ignore();
	cin.get();


	return 0;
} // end of main function
