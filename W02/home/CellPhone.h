/*
	Name:		Pedro Zelada Souza
	Student#:	116427188
	E-mail:		pzelada-souza@myseneca.ca
	Sect:		SHH
*/

// Header safeguards
#ifndef SICT_CELLPHONE_H
#define SICT_CELLPHONE_H

// Declare the namespace that will be used in the program
namespace sict {

	// CellPhone Structure declaration.
	struct CellPhone {
		char m_model[32]; // The model name of the CellPhone
		double m_price; // The price of the CellPhone
	};

	// Prototype of the function that will display the model and price of the CellPhone.
	void display(const CellPhone&);
	void display(const CellPhone*, int);

} // end namespace sict

#endif // !1