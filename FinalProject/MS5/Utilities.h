/*
	Name:		     Pedro Zelada Souza
	Student#:	   116427188
	E-mail:      pzelada-souza@myseneca.ca
	Sect:		     SHH

	Milestone:   5
*/

// Necessary headers
#include "Product.h"

#include <iostream>

using namespace std;
using namespace ama;

// Header safeguards
#ifndef AMA_UTILITIES_H
#define AMA_UTILITIES_H

namespace ama{

  double& operator+=(double&, const iProduct&);

  ostream& operator<<(ostream&, const iProduct&);

  istream& operator>>(istream&, iProduct&);

  iProduct * createInstance(char);

  void clearBuffer();

} // end namespace
#endif
