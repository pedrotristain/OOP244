/*
	Name:		     Pedro Zelada Souza
	Student#:	   116427188
	E-mail:      pzelada-souza@myseneca.ca
	Sect:		     SHH

	Milestone:   4
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

  double& operator+=(double&, const iProduct&);

  ostream& operator<<(ostream&, const iProduct&);

  istream& operator>>(istream&, iProduct&);

  iProduct * createInstance(char);

} // end namespace
#endif
