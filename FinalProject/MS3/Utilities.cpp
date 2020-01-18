/*
	Name:		     Pedro Zelada Souza
	Student#:	   116427188
	E-mail:      pzelada-souza@myseneca.ca
	Sect:		     SHHL

	Milestone:   3
*/

// Necessary headers
#include "Product.h"
#include "Utilities.h"

#include <iostream>
#include <iomanip>      // std::setprecision

using namespace std;
using namespace ama;

namespace ama{

  double& operator+=(double& total, const Product& right_operand){
    return total += right_operand.total_cost();
  } // end double& operator+=(double&, const Product&)

  ostream& operator<<(ostream& os, const Product& right_operand){
    return right_operand.write(os, write_human);
  } // end ostream& operator<<(ostream&, const Product&)

  istream& operator>>(istream& is, Product& right_operand){
    return right_operand.read(is, true);
  } // end istream& operator>>(istream&, Product&)

} // end namespace
