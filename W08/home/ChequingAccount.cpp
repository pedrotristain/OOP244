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

#include "ChequingAccount.h"
using namespace sict;

// 3 Parameter constructor. Sets the object's interest rate to the received value if it is positive or to 0.0 otherwise.
ChequingAccount::ChequingAccount(double par_balance, double par_trans_fee, double par_monthly_fee) : Account::Account(par_balance) {

	// Check if the received transaction fee is positive.
	if (par_trans_fee > 0.0) {
		// If positive, initialize the object with transaction fee equal to received value.
		a_transaction_fee = par_trans_fee;
	}
	else {
		// If not positive, initialize the object with transaction fee equal to 0.
		a_transaction_fee = 0.0;
	} // end else

  // Check if the received monthly fee is positive.
	if (par_monthly_fee > 0.0) {
		// If positive, initialize the object with monthly fee equal to received value.
		a_monthly_fee = par_monthly_fee;
	}
	else {
		// If not positive, initialize the object with monthly fee equal to 0.
		a_monthly_fee = 0.0;
	} // end else

} // end SavingsAccount::SavingsAccount(double, double)

// Modifier function that tries to credit the current account balance by the received amount.
// If successfull, the current account's transaction fee is debited from the current balance.
// Returns true if the transaction was successful or false otherwise.
bool ChequingAccount::credit(double par_credit){
  // Check if the credit transaction was successful.
  bool is_valid = Account::credit(par_credit);

  if( is_valid ){
    // If the transaction was successful, debit the transaction fee from the balance.
    Account::debit(a_transaction_fee);
  } // end if

  // Return true if the transaction was successful or false otherwise.
  return is_valid;
} // end CequingAccount::credit(double)

// Modifier function that tries to debit the current account balance by the received amount.
// If successfull, the current account's transaction fee is debited from the current balance.
// Returns true if the transaction was successful or false otherwise.
bool ChequingAccount::debit(double par_credit){
  // Check if the credit transaction was successful.
  bool is_valid = Account::debit(par_credit);

  if( is_valid ){
    // If the transaction was successful, debit the transaction fee from the balance.
    Account::debit(a_transaction_fee);
  } // end if

  // Return true if the transaction was successful or false otherwise.
  return is_valid;
} // end CequingAccount::credit(double)

// Modifier function that debits the monthly fee from the current account's balance.
void ChequingAccount::monthEnd() {

  // Debit the monthly fee from the current account.
	Account::debit(a_monthly_fee);

} // end ChequingAccount::monthEnd()

// Query function that inserts in the stream the current account information
void ChequingAccount::display(ostream& out) const {

	out << "Account type: Chequing" << endl;
	out << "Balance: $";

	int old = out.precision();
	out.setf(ios::fixed);
	out.precision(2);

	out << balance() << endl;
	out << "Per Transaction Fee: " << a_transaction_fee << endl;
  out << "Monthly Fee: " << a_monthly_fee << endl;

	out.unsetf(ios::fixed);
	out.precision(old);
} // end SavingsAccount::display()
