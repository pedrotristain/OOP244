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
#include "Account.h"
using namespace sict;

// 1 Parameter constructor. Sets the object to the received balance if it is positive or to 0.0 otherwise.
Account::Account(double par_balance = 0.0) {
	
	// Check if the received balance is positive.
	if (par_balance > 0.0) {
		// If positive, initialize the object with balance equal to received value.
		a_balance = par_balance;

	} else {
		// If not positive, initialize the object with balance equal to 0.
		a_balance = 0.0;
	} // end else

} // end Account::Account(double)

// Destructor.
Account::~Account() {
	a_balance = 0.0;
} // end ~Account()

// Function that increases the account balance by the received value if it is positive.
// This function does nothing if the received value is not positive.
bool Account::credit(double amount) {

	bool is_successful = false; // Control variable that tells if the function was successful.

	// If the received amount is positive, add it to the current balance and change the control variable to true.
	if (amount > 0.0) {
		a_balance += amount;
		is_successful = true;
	} // end if

	return is_successful; // Return true if the current balance was modified or false otherwise.

} // end Account::credit(double)

// Function that decreases the account balance by the received value if it is positive and if it is smaller than the current balance.
// This function does nothing otherwise.
bool Account::debit(double amount) {

	bool is_successful = false; // Control variable that tells if the function was successful.

	// If the received amount is positive and smaller than current balance, subtract it from the current balance and change the control variable to true.
	if (amount > 0.0 && amount < balance()) {
		a_balance -= amount;
		is_successful = true;
	} // end if

	return is_successful; // Return true if the current balance was modified or false otherwise.

} // end Account::debit(double)

// Query function that returns the current balance of the account.
double Account::balance() const {
	return a_balance;
} // end Account::balance() const
