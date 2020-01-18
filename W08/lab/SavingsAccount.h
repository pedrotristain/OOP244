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

#include "Account.h"

// Header safeguards
#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H

namespace sict {

	// Abstract class Account
	class SavingsAccount : public Account {
	protected:
		double a_interest; // Current account interest rates
		~SavingsAccount(); // Destructor
	
	public:
		SavingsAccount(double, double = 0.0); // 2 Parameter constructor.

		void monthEnd();
		void display(ostream&) const;
	}; // end class Account

} // end namespace
#endif