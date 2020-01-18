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

#include "Allocator.h"
#include "iAccount.h"
#include "Account.h"
#include "SavingsAccount.h"

using namespace sict;
using namespace std;

iAccount * sict::CreateAccount(const char * par_type, double par_balance)
{
	iAccount* acc = nullptr;
	int size = strlen(par_type);

	const double interest = 0.05;

	if (strncmp(par_type, "Savings", size) == 0) {
		acc = new SavingsAccount(par_balance, interest);
	}

	return acc;
}
