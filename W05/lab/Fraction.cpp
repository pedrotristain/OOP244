/*
	Name:		Pedro Zelada Souza
	Student#:	116427188
	E-mail:		pzelada-souza@myseneca.ca
	Sect:		SHH

	Workshop:	05
*/

// TODO: insert header files
#include <iostream>
#include <cstring>

#include "Fraction.h"

using namespace std; // Namespace for the COUT object.

namespace sict {

	// TODO: implement the default constructor
	Fraction::Fraction() {

		// Set the members to a safe empty state.
		numerator = 0;
		denominator = 0;

	} // end Fraction::Fraction()
	
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int par_numerator, int par_denominator) {
		
		bool valid = true; // Initiate a control variable that will tell if the inputted data is valid.

		// If the received numerator is negative or if the received denominator is 0 or negative, change the control variable to false.
		if (par_numerator < 0 || par_denominator < 1)
			valid = false;

		// If inputted valid is invalid, call the default constructor (safe empty state).
		if( valid == false ){

			*this = Fraction();

		} else { // If inputted data is valid, assign the values to the members.

			numerator = par_numerator; // Set the numerator
			denominator = par_denominator; // Set the denominator

			reduce(); // Reduce the fraction

		} // end else

	} // end Fraction::Fraction(int, int)

	// TODO: implement the max query
	int Fraction::max() const {

		// Compare the numerator and denominator and set the bigger value to the control variable 'greater'.
		int greater = (numerator > denominator) ? numerator : denominator;

		return greater; // Return the greater value.
	} // end bool Fraction::max()

	// TODO: implement the min query
	int Fraction::min() const {

		// Compare the numerator and denominator and set the smaller value to the control variable 'lesser'.
		int lesser = (numerator < denominator) ? numerator : denominator;

		return lesser; // Return the lesser value.
	} // end bool Fraction::min()

	// gcd returns the greatest common divisor of num and denom
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}

		return g_c_d;
	} // end bool Fraction::gcd()

	// TODO: implement the reduce modifier
	void Fraction::reduce() {

		int temp = gcd();

		numerator /= temp; // Divide the numerator by the GCD and assign the new value to the member 'numerator'
		denominator /= temp; // Divide the denominator by the GCD and assign the new value to the member 'denominator'

	} // end bool Fraction::reduce()

	// TODO: implement the display query
	void Fraction::display() const{

		// Checks if the object is empty. If true, display a warning message.
		if (isEmpty() == true) {
			
			cout << "no fraction stored"; // Display a warning message.

		} else if( denominator == 1 ) { // If object is not empty, check if the denominator is equal to 1. If true, display the fraction as an integer.

			cout << numerator; // Display the fraction as an integer (also know as only the numerator).

		} else { // If the object is not empty AND the denominator is not 1, display the fraction as NUMERATOR/DENOMINATOR.

			cout << numerator << "/" << denominator;

		}

	}// end bool Fraction::isEmpty()

	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {

		return (denominator == 0); // If the member 'denominator' is equal to zero, return true. Return false otherwise.

	} // end bool Fraction::isEmpty()

	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& right_operand) const {

		// Temporary variable to hold the values for calculation.
		// Initialize it in a safe empty state.
		Fraction temp; 

		// If neither the left operand (current object) nor the right operand (right_operand) are empty, add them up.
		// If either operand is empty, the temporary fraction will remand in a safe empty state.
		if (isEmpty() == false && right_operand.isEmpty() == false) {

			// Adding the numerators
			temp.numerator = numerator * right_operand.denominator;
			temp.numerator += denominator * right_operand.numerator;

			// Adding the denominators
			temp.denominator = denominator * right_operand.denominator;
			
			// Reduce the fraction after the sum.
			temp.reduce();

		} // end if

		return temp; // Return the temporary fraction.

	}
} // end namespace sict