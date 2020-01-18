/*
	Name:		     Pedro Zelada Souza
	Student#:	   116427188
	E-mail:      pzelada-souza@myseneca.ca
	Sect:		     SHH

	Milestone:   4
*/

// Necessary headers
#include "Product.h"
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

  iProduct * createInstance(char tag) {

    iProduct * temp = nullptr;

    if( tag == 'n' || tag == 'N'){
      temp = new Product();
    } // end if

    return temp;

  } // end iProduct * createInstance(char)

} // end namespace
