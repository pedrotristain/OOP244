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
#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H

namespace sict {

	// Abstract class Account
	class ChequingAccount : public Account {
	protected:
		double a_transaction_fee; // Current account transaction fee
    double a_monthly_fee; // Current account monthly fee to be charged on the end of the month

	public:
		ChequingAccount(double, double, double); // 2 Parameter constructor.

    bool credit(double); // Modifier function that credits the current account balance by the received amount.
    bool debit(double); // Modifier function that debits the current account balance by the received amount.

    void monthEnd(); // Modifier function that debits the monthly fee from the current account balance.
		void display(ostream&) const; // Query function that displays the current account info on the screen.
	}; // end class Account

} // end namespace
#endif
