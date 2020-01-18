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

using namespace sict;
using namespace std;

// Modular function that creates an object dynamically and return it.
iAccount * sict::CreateAccount(const char * par_type, double par_balance)
{
	// Create a pointer
	iAccount* acc = nullptr;
	int size = strlen(par_type);

	const double interest = 5.00;

	// Create new object by assigning dynamic memory to it and store its address on the pointers.
	if (strncmp(par_type, "Savings", size) == 0) {
		acc = new SavingsAccount(par_balance, interest);
	} // end if

	// Return the new object address
	return acc;
} // end CreateAccount(const char *, double)
