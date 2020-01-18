/*
	Name:		     Pedro Zelada Souza
	Student#:	   116427188
	E-mail:      pzelada-souza@myseneca.ca
	Sect:		     SHH

	Milestone:   5
*/

// Necessary headers
#include "Product.h"
#include "Perishable.h"
#include "Utilities.h"

#include <iostream>
#include <iomanip>      // std::setprecision

using namespace std;
using namespace ama;

namespace ama{

  double& operator+=(double& total, const iProduct& right_operand){
    return total += right_operand.total_cost();
  } // end double& operator+=(double&, const Product&)

  ostream& operator<<(ostream& os, const iProduct& right_operand){
    return right_operand.write(os, write_human);
  } // end ostream& operator<<(ostream&, const Product&)

  istream& operator>>(istream& is, iProduct& right_operand){
    return right_operand.read(is, true);
  } // end istream& operator>>(istream&, Product&)

  // Create a new object based on the received tag parameter
  iProduct * createInstance(char tag) {

    // Create a new dynamic pointer to hold the address of the newly created object.
    iProduct * temp = nullptr;

    // If the tag is 'n' or 'N', create a new Product.
    if( tag == 'n' || tag == 'N' ){
      temp = new Product();
    } else if( tag == 'p' || tag == 'P' ) {
      // If it is 'p' or 'P', create a new Perishable
      temp = new Perishable();
    } // end else

    // Return the address of the new object.
    return temp;

  } // end iProduct * createInstance(char)

  // Helper function that clear the input buffer;
  void clearBuffer() {

    cin.clear();
    cin.ignore(2000, '\n');

  } // end clearBuffer()

} // end namespace
