/*
	Name:		Pedro Zelada Souza
	Student#:	116427188
	E-mail:		pzelada-souza@myseneca.ca
	Sect:		SHH

	Workshop:	05
*/

// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

// TODO: create namespace
namespace sict {

	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables
		int numerator;
		int denominator;

		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;

	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int, int);

		bool isEmpty() const;
		void display() const;

		// Operators Overload
		Fraction operator+(const Fraction&) const;
		Fraction operator*(const Fraction&) const;
		bool operator==(const Fraction&) const;
		bool operator!=(const Fraction&) const;
		Fraction& operator+=(const Fraction&);
	};

} // end namespace sict
#endif

	// At part, overload += return type will be reference
	// Works like this: Fraction& operator+=( etc ).
