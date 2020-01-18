/*
	Name:		     Pedro Zelada Souza
	Student#:	   116427188
	E-mail:      pzelada-souza@myseneca.ca
	Sect:		     SHH

	Milestone:   5
*/

// Necessary headers
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>

#include "Date.h"
#include "Product.h"
#include "Perishable.h"

using namespace std;

namespace ama{

  // **************************************************************************
  // *                          PRIVATE FUNCTIONS                             *
  // **************************************************************************


  // **************************************************************************
  // *                          PUBLIC FUNCTIONS                              *
  // **************************************************************************

  // ######################
  // #    CONSTRUCTORS    #
  // ######################

  // Default constructor. Initialize a Product as 'P' in a safe empty state.
  Perishable::Perishable() : Product ('P'){
    //p_expiry_date = Date(0, 0, 0);
  } // end Persishable::Perishable()

  // ######################
  // #     DESTRUCTOR     #
  // ######################


  // ######################
  // # OPERATORS OVERLOAD #
  // ######################


  // ################################
  // # MODIFIER AND QUERY FUNCTIONS #
  // ################################

  // Function that extracts the product data from the stream. If second parameter is true, it interacts with the user instead.
  istream& Perishable::read(istream& is, bool is_interactive) {

    // Call the base class Product read function
    Product::read(is, is_interactive);

    // Check if there was any error extracting the data for the base class.
    if( is ){
      // If no errors, proceed to extract the expiry date from the input stream.
      // Temporary Date object to receive a date from the input stream.
      Date tmp_date;

      // Checks if the stream input is interactive or not
      if( is_interactive == false){
        // If false, extract the date from the input stream.

        is.ignore(2000, ',');
        tmp_date.read(is);

      } else {
        // If the input is interactive, prompt the user for the date.
        // Prompt the user to enter a SKU.

        if( is ){
          cout << setw(max_length_label) << right << "Expiry date (YYYY/MM/DD): ";
          is >> tmp_date;
        } // end if

      } // end else

      // Check if the inputted data was not valid.
      if( !tmp_date.isGood() ) {
        // If true, set the product's error state according with the error.

        is.setstate(ios::failbit);

        switch ( tmp_date.status() ) {
          case 1:
            message("Invalid Year in Date Entry");
          break;
          case 2:
            message("Invalid Month in Date Entry");
          break;
          case 3:
            message("Invalid Day in Date Entry");
          break;
          default:
            message("Invalid Date Entry");
          break;
        } // end switch(status)

      } else {

        // If false, the date is valid. Store it.
        p_expiry_date = tmp_date;

      } // end else
    } // end if

    // Return the stream object.
    return is;

  } // end Product::read(istream&, bool)

   // Query function that inserts the current object info in the received stream parameter.
   // This functions does nothing if the object is in a safe empty state.
  ostream& Perishable::write(ostream& os, int write_type) const{

    // Call the base Product class write function
    Product::write(os, write_type);

    // Check if the object is in a safe empty state or in error state. If it is, this functions does nothing further.
    if( isClear() && !isEmpty() ){

      // Check which type of display is chosen.
      switch (write_type) {

        // If condensed
        case write_condensed:

          os << "," << p_expiry_date;

        break;

        // If human readable
        case write_human:

          os << setw(max_length_label) << right << "Expiry Date: " << left << p_expiry_date << endl;

        break;

        // If table
        case write_table:

          os << " " << p_expiry_date << " |";

        break;
      } // end switch(write_type)

    } // end if

    // Return the stream object.
    return os;
  } // end Product::write(ostream&, int) const
} // end namespace
