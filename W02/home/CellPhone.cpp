/*
	Name:		Pedro Zelada Souza
	Student#:	116427188
	E-mail:		pzelada-souza@myseneca.ca
	Sect:		SHH
*/

// Header inclusions
#include <iostream>
#include "CellPhone.h"

using namespace std; // Declare a namespace for the cout object used in the display function

// Declare the namespace we will use in the program
namespace sict {

	// A function for printing the model and price of a phone. Returns no value.
	void display(const struct CellPhone &thePhone) {

		// Outputs the model and the price of the phone to the user.
		cout << "Phone " << thePhone.m_model << " costs $" << thePhone.m_price << "!" << endl;

	} // end display()

	/*
		A function that:
		- Display all phone models and prices.
		- Highlight the cheapest phone number.
		- Returns no value.
	*/
	void display(const struct CellPhone* phone_list, int size) {

		// Outputs the header:
		cout << "------------------------------" << endl;
		cout << "Phones available at the mall:" << endl;
		cout << "------------------------------" << endl;

		// Outputs all phone models and prices

		int i; // Control variable for the loop
		double smallest_price = 500000; // Control variable to hold the smallest price. Initiate it so it won't hold garbage value.

		// Iterate through all phones in the object thePhone.
		for (i = 0; i < size; i++) {

			cout << (i + 1) << ". "; // Outputs the index of the phone in the list.
			display(phone_list[i]); // Outputs the current phone model and price.

			// Check if the price is smaller than the current smallest price.
			if (phone_list[i].m_price < smallest_price)
				smallest_price = phone_list[i].m_price; // If true, change the control variable with the new smallest price.

		} // end for()

		// Outputs the cheapest phone's price:
		cout << "------------------------------" << endl;
		cout << "The cheapest phone costs $" << smallest_price << "." << endl;
		cout << "------------------------------" << endl;

	}// end display() [2]

} // end namespace sict