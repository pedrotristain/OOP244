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

#include "SavingsAccount.h"
using namespace sict;

// 2 Parameter constructor. Sets the object's interest rate to the received value if it is positive or to 0.0 otherwise.
SavingsAccount::SavingsAccount(double par_balance, double par_interest) : Account::Account(par_balance) {

	// Check if the received interest is positive.
	if (par_interest > 0.0) {
		// If positive, initialize the object with interest equal to received value.
		a_interest = par_interest;
	}
	else {
		// If not positive, initialize the object with interest equal to 0.
		a_interest = 0.0;
	} // end else

} // end SavingsAccount::SavingsAccount(double, double)

// Destructor.
SavingsAccount::~SavingsAccount() {
	a_balance = 0.0;
} // end ~SavingsAccount()

// Function that increases the current balance by the interest rate.
void SavingsAccount::monthEnd() {

	double interest = 0.0; // Control variable that will tell the interest amount to increase the balance.

	interest = a_balance * a_interest / 100; // Calculate the interest amount and store it on the control variable.

	a_balance += interest; // Increase the balance

} // end SavingsAccount::monthEnd()

// Query function that inserts in the stream the current account information
void SavingsAccount::display(ostream& out) const {

	out << "Account type: Savings" << endl;
	out << "Balance: $";

	int old = out.precision();
	out.setf(ios::fixed);
	out.precision(2);
	
	out << balance() << endl;
	out << "Interest Rate (%): " << a_interest << endl;

	out.unsetf(ios::fixed);
	out.precision(old);
} // end SavingsAccount::display()
