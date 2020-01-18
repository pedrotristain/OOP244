/*
	Name:		     Pedro Zelada Souza
	Student#:	   116427188
	E-mail:      pzelada-souza@myseneca.ca
	Sect:		     SHHL

	Milestone:   3
*/

// Necessary headers
#include "Product.h"

#include <iostream>

using namespace std;
using namespace ama;

// Header safeguards
#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H

namespace ama{

  double& operator+=(double&, const Product&);

  ostream& operator<<(ostream&, const Product&);

  istream& operator>>(istream&, Product&);

} // end namespace
#endif
