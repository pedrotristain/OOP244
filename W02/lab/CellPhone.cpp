/*
	Name:		Pedro Zelada Souza
	Student#:	116427188
	E-mail:		pzelada-souza@myseneca.ca
	Sect:		SHHL
*/

// Header inclusions
#include <iostream>
#include "CellPhone.h"

using namespace std; // Declare a namespace for the cout object used in the display function

// Declare the namespace we will use in the program
namespace sict {

	// A function for printing the model and price of a phone. Returns nothing.
	void display(const struct CellPhone &thePhone) {

		// Outputs the model and the price of the phone to the user.
		cout << "Phone " << thePhone.m_model << " costs $" << thePhone.m_price << "!" << endl;

	} // end display()
} // end namespace sict