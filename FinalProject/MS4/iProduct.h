/*
	Name:		     Pedro Zelada Souza
	Student#:	   116427188
	E-mail:      pzelada-souza@myseneca.ca
	Sect:		     SHH

	Milestone:   4
*/

// Necessary headers
#include <iostream>
#include <string>

using namespace std;

// Header safeguards
#ifndef SICT_IPRODUCT_H
#define SICT_IPRODUCT_H

namespace ama{

  // Necessary constants
  const int max_length_label  = 30;   // Used when trading information with the user.
  const int max_length_sku    = 7;    // Defines the maximum size of the SKU.
  const int max_length_name   = 75;   // Defines the maximum size of the product name.
  const int max_length_unit   = 10;   // Defines the maximum size in the product descriptor.

  const int write_condensed   = 0;    // Indicates that the output must be condensed.
  const int write_table       = 1;    // Indicates that the output must be in a table form.
  const int write_human       = 2;    // Indicates that the output must be human readable.

  // An abstract class to serve as the interface for the main program
	class iProduct {

  protected:

    // Protected members
    void message(const char *); // Function that receives an error message and stores it into the p_error_state member.

    bool isClear() const; // Query functions that returns true if the product contains no Errors or false otherwise.

	public:

    // Operators overload
    virtual bool operator==(const char *) const = 0; // Is equal to operator overload. Returns true if the stored SKU is equal to the received paramter. Returns false otherwise.

    virtual int operator+=(int) = 0; // Sum and assign operator overload. Increase the product's in_stock value if the received amount is positive.

    virtual bool operator>(const iProduct&) const = 0; // Greater than operator overl// One or zero parameter constructor. Store the received value as the product type and sets the object to a safe empty state.oad. Returns true if the stored SKU is greater than the received paramter. Return false otherwise.

    // Modifier and Query functions
    virtual ostream& write(ostream&, int) const = 0; // Query function that inserts the current object info in the received stream parameter.
    virtual istream& read(istream&, bool) = 0; // Function that extracts the product data from the stream. If second parameter is true, it interacts with the user instead.

    virtual double total_cost() const = 0; // Query function that returns the total cost of all units of product, including taxes.

    virtual int qtyNeeded() const = 0; // Query function that returns how many Product units are needed.
    virtual int qtyAvailable() const = 0; // Query function that returns how many Product units are available in stock.

    virtual const char * name() const = 0; // Query function that returns the address of the string storing the Product's name.

    // Destructors
    virtual ~iProduct() {}; // Default destructor

	}; // end Class Product

} // end namespace
#endif
