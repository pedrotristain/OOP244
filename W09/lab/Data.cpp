/*
	Name:		Pedro Zelada Souza
	Student#:	116427188
	E-mail:		pzelada-souza@myseneca.ca
	Sect:		SHH

	Workshop:	09
*/

// OOP244 Workshop 9: Function Templates
// File: Data.cpp
// Version: 2.0.1
// Date: 2017/12/17
// Author: Chris Szalwinski, based on previous work by Hasan Murtaza
// Description:
// This file defines the answers and readRow functions
// Chris     2017.12.17 removed answers to Q1
///////////////////////////////////////////////////

// Necessary headers
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>

#include "Data.h"

using namespace std;

namespace sict {

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		int first = 0;
		int last = n - 1;

		int subtraction = population[last] - population[first];
		double variation = static_cast<double>(subtraction) / 1000000;

		cout << "Population change from " << year[first] << " to " << year[last] << " is ";
		cout << fixed << setprecision(2) << variation;
		cout << " million" << endl;

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005

		bool is_down = (violentCrime[last] < violentCrime[first]);
		cout << "Violent Crime trend is " << ((is_down) ? "down" : "up") << endl;

		// Q3 print the GTA number accurate to 0 decimal places

		cout << fixed << "There are " << setprecision(2) << (average(grandTheftAuto, n) / 1000000)
		<< " million Grand Theft Auto incidents on average a year" << endl;

		// Q4. Print the min and max violentCrime rates

		cout << "The Minimum Violent Crime rate was " << setprecision(0) << min(violentCrimeRate, n) << endl;
		cout << "The Maximum Violent Crime rate was " << setprecision(0) << max(violentCrimeRate, n) << endl;

	} // end answers()
}
