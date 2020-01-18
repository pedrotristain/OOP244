/*
	Name:		Pedro Zelada Souza
	Student#:	116427188
	E-mail:		pzelada-souza@myseneca.ca
	Sect:		SHH

	Workshop:	08
*/

// Necessary headers
#include <iostream>
#include <string>
#include <cstring>

#include "iAccount.h"
#include "Account.h"
#include "SavingsAccount.h"
#include "ChequingAccount.h"

//using namespace sict;
using namespace std;

namespace sict{

	const double interest = 5.00;
	const double transaction_fee = 0.50;
	const double monthly_fee = 2.00;

	// Modular function that creates an object dynamically and return it.
	iAccount * CreateAccount(const char * par_type, double par_balance)
	{
		// Create a pointer to hold the new dynamically created object.
		iAccount* acc = nullptr;
		int size = strlen(par_type); // Control variable to check the account type.

		// Create new account object by assigning dynamic memory to it according to the define type.
		if (strncmp(par_type, "Savings", size) == 0) {
			// If the defined type is Savings, create a new SavingsAccount object.
			acc = new SavingsAccount(par_balance, interest);
		} else {
			// If the defined type is Chequing, create a new ChequingAccount object.
			acc = new ChequingAccount(par_balance, transaction_fee, monthly_fee);
		} // else

		// Return the new object address
		return acc;
	} // end CreateAccount(const char *, double)
}
