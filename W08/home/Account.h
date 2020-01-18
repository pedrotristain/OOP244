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

#include "iAccount.h"

// Header safeguards
#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H

namespace sict {

	// Abstract class Account
	class Account : public iAccount {
		
	public:
		Account(double); // 1 Parameter constructor.

		virtual bool credit(double); // Function that increases the account balance by received amount.
		virtual bool debit(double); // Function that decreases the account balance by received amount.
	
	protected:
		double a_balance; // Account monetary balance
		
		~Account(); // Destructor
		double balance() const; // Query function that returns the current balance of the account.

	}; // end class Account

} // end namespace
#endif
