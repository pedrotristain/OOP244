/*
	Name:		     Pedro Zelada Souza
	Student#:	   116427188
	E-mail:      pzelada-souza@myseneca.ca
	Sect:		     SHHL

	Milestone:   3
*/

// Necessary headers
#include <iostream>
#include <string>
#include "ErrorState.h"

using namespace std;

// Header safeguards
#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H

namespace ama{

  // Necessary constants
  const int max_length_label  = 30;   // Used when trading information with the user.
  const int max_length_sku    = 7;    // Defines the maximum size of the SKU.
  const int max_length_name   = 75;   // Defines the maximum size of the product name.
  const int max_length_unit   = 10;   // Defines the maximum size in the product descriptor.

  const int write_condensed   = 0;    // Indicates that the output must be condensed.
  const int write_table       = 1;    // Indicates that the output must be in a table form.
  const int write_human       = 2;    // Indicates that the output must be human readable.

  const double tax_rate       = 0.13;  // Current tax rate.

  // A class to store and manipulate Product objects.
	class Product {

    // Private members

    const char p_type; // Indicates the type of the product.

    char p_sku[max_length_sku]; // Holds the value of the product sku.
    char p_unit[max_length_unit]; // Holds the product's unit.
    char * p_name; // Holds the product name.

    int p_in_stock; // Holds the quantity of the product currently available.
    int p_needed; // Tells how many of the product are needed.

    double p_price; // Holds the value of the product before applying taxes.

    bool p_is_taxable; // Tells if the product is taxable or not.

    ErrorState p_error_state; // Tells the errors state of the product object.

    // Private functions

    void set(const Product&); // Set the current object info to be equal to the received object's info.
    void set(const char *, const char *, const char *, double, int, int, bool); // Set the current objects attributes to the received parameters.
    bool input_successful(istream&, const char *); // Returns true if the input stream is not in error state. Returns false otherwise.
    double unit_price_with_taxes() const; // Query function that return the total price of a single product unit. Inclues taxes when needed.
    string concatenate_name() const; // Query function that returns the product name in 13 characters or less.
  protected:

    // Protected members

    void message(const char *); // Function that receives an error message and stores it into the p_error_state member.

    bool isClear() const; // Query functions that returns true if the product contains no Errors or false otherwise.

	public:

    // Public members

    // Constructors
    Product(char = 'N'); // One or zero parameter constructor. Store the received value as the product type and sets the object to a safe empty state.
    Product(const char *, const char *, const char *, double = 0.0, int = 0, int = 0, bool = true); // 7 parameter constructor.
    Product(const Product&); // Copy constructor

    // Destructors
    ~Product(); // Default destructor

    // Operators overload
    Product& operator=(const Product&); // Copy assignment operator overload.
    int operator+=(int); // Sum and assign operator overload. Increase the product's in_stock value if the received amount is positive.
    bool operator==(const char *) const; // Is equal to operator overload. Returns true if the stored SKU is equal to the received paramter. Returns false otherwise.
    bool operator>(const char *) const; // Greater than operator overl// One or zero parameter constructor. Store the received value as the product type and sets the object to a safe empty state.oad. Returns true if the stored SKU is greater than the received paramter. Return false otherwise.
    bool operator>(const Product&) const; // Greater than operator overload. Returns true if the name of the current object is greater than the name of the received object.

    // Modifier and Query functions
    int qtyAvailable() const; // Query function that returns how many Product units are available in stock.
    int qtyNeeded() const; // Query function that returns how many Product units are needed.

    double total_cost() const; // Query function that returns the total cost of all units of product, including taxes.

    bool isEmpty() const; // Query function that returns true if the object is in a safe empty state, or false otherwise.

    istream& read(istream&, bool); // Function that extracts the product data from the stream. If second parameter is true, it interacts with the user instead.
    ostream& write(ostream&, int) const; // Query function that inserts the current object info in the received stream parameter.
	}; // end Class Product

  //ostream& operator<<(ostream&, const ErrorState&);

} // end namespace
#endif
