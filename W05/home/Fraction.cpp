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

	// Default constructor
	Fraction::Fraction() {

		// Set the members to a safe empty state.
		numerator = 0;
		denominator = 0;

	} // end Fraction::Fraction()

	// Validated constructor
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

	// Function that compares the numerator and denominator and return whichever is greater
	int Fraction::max() const {

		// Compare the numerator and denominator and set the bigger value to the control variable 'greater'.
		int greater = (numerator > denominator) ? numerator : denominator;

		return greater; // Return the greater value.
	} // end bool Fraction::max()

	// Function that compares the numerator and denominator and return whichever is smaller
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

	// Function that compares reduces the fraction to their samaller version possible
	void Fraction::reduce() {

		int temp = gcd();

		numerator /= temp; // Divide the numerator by the GCD and assign the new value to the member 'numerator'
		denominator /= temp; // Divide the denominator by the GCD and assign the new value to the member 'denominator'

	} // end bool Fraction::reduce()

	// Function that display the fractions on the screen or a warning message in case the fraction is empty
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

	// Query function that returns true if the fraction is empty. Returns false otherwise
	bool Fraction::isEmpty() const {

		return (denominator == 0); // If the member 'denominator' is equal to zero, return true. Return false otherwise.

	} // end bool Fraction::isEmpty()

	// Sum operator overload
	Fraction Fraction::operator+(const Fraction& right_operand) const {

		// Temporary object to hold the values for calculation.
		// Initialize it in a safe empty state.
		Fraction temp;

		// If neither the left operand (current object) nor the right operand (right_operand) are empty, add them up.
		// If either operand is empty, the temporary fraction will remain in a safe empty state.
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

	} // end Fraction::operator+

	// Multiplication operator overload
	Fraction Fraction::operator*(const Fraction& right_operand) const {

		// Temporary variable to hold the values for calculation.
		// Initialize it in a safe empty state.
		Fraction temp;

		// If neither the left operand (current object) nor the right operand (right_operand) are empty, multiply them up.
		// If either operand is empty, the temporary fraction will remain in a safe empty state.
		if (isEmpty() == false && right_operand.isEmpty() == false) {

			// Multiplying the numerators
			temp.numerator = numerator * right_operand.numerator;

			// Multiplying the denominators
			temp.denominator = denominator * right_operand.denominator;

			// Reduce the fraction after the sum.
			temp.reduce();

		} // end if

		return temp; // Return the temporary fraction.

	} // end Fraction::operator*

	// Comparison (equal) operator overload
	bool Fraction::operator==(const Fraction& right_operand) const {

		// Temporary variable to hold the value of the comparison.
		// Initialize it as false by default.
		bool equal = false;

		// If neither the left operand (current object) nor the right operand (right_operand) are empty, compare them and change the control variable 'equal' to true if they are equal.
		// If either operand is empty, the control variable will still hold 'false'.
		if (isEmpty() == false && right_operand.isEmpty() == false) {

			// Compare both fractions numerators and denominators. If all are equal, change the control variable 'equal' to true.
			if( numerator == right_operand.numerator && denominator == right_operand.denominator ){

				equal = true; // Set the control variable to true.

			} // end if

		} // end if

		return equal; // Return the control variable 'equal' value.

	} // end Fraction::operator==

	// Comparison (not equal) operator overload
	bool Fraction::operator!=(const Fraction& right_operand) const {

		// Use the overload == operator to compare both fractions. Store the opposite value in the control variable 'not_equal'.
		bool not_equal = ( *this == right_operand ) ? false : true;

		// Check if either operand is in a safe empty state. If true for any, change the control variable 'not_equal' to false.
		if ( isEmpty() || right_operand.isEmpty() ){

			not_equal = false; // Set the control variable 'not_equal' to false.

		} // end if

		return not_equal;

	} // end Fraction::operator!=

	// Sum and assign operator overload
	Fraction& Fraction::operator+=(const Fraction& right_operand) {

		*this = *this + right_operand;

		return *this;

	} // end Fraction::operator+=

} // end namespace sict
