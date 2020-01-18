/*
	Name:		     Pedro Zelada Souza
	Student#:	   116427188
	E-mail:      pzelada-souza@myseneca.ca
	Sect:		     SHH

	Milestone:   5
*/

// Necessary headers
#include <iostream>
#include <string>
#include "Date.h"
#include "Product.h"

using namespace std;

// Header safeguards
#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H

namespace ama{

  // A class to store and manipulate Perishable Product objects.
  class Perishable : public Product {

    // Private members
    Date p_expiry_date; // A Date that tells when the product will expire.

	public:

    // Constructors
    Perishable(); // Default constructor. Calls the Product base class constructor with a value of 'P'

    // Modifier and Query functions
    istream& read(istream&, bool); // Function that extracts the product data from the stream. If second parameter is true, it interacts with the user instead.
    ostream& write(ostream&, int) const; // Query function that inserts the current object info in the received stream parameter.
	}; // end Class Product

} // end namespace
#endif
