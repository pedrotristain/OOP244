/*
	Name:		Pedro Zelada Souza
	Student#:	116427188
	E-mail:		pzelada-souza@myseneca.ca
	Sect:		SHH

	Workshop:	08
*/

// Necessary headers
#include <iostream>
using namespace std;

// Header safeguards
#ifndef SICT_IACCOUNT_H
#define SICT_IACCOUNT_H

namespace sict {

	// Interface class iAccount
	class iAccount {
	
	public:
		virtual ~iAccount() {};

		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;

		virtual void monthEnd() = 0;
		virtual void display(ostream&) const = 0;
	}; // end class iAccount

	iAccount* CreateAccount(const char*, double);
} // end namespace
#endif