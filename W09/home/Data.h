/*
	Name:		Pedro Zelada Souza
	Student#:	116427188
	E-mail:		pzelada-souza@myseneca.ca
	Sect:		SHH

	Workshop:	09
*/

// OOP244 Workshop 9: Function Templates
// File: Data.h
// Version: 2.0
// Date: 2017/12/15
// Author: Chris Szalwinski, based on previous work by Hasan Murtaza
// Description:
// This file defines the templated functions and the answers prototype
///////////////////////////////////////////////////

// Necessary headers
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>

using namespace std;

// Header safeguards
#ifndef SICT_DATA_H
#define SICT_DATA_H

namespace sict {
	// These number defines the output column width for a single data field

	const int COLUMN_WIDTH    = 15;

	// max returns the largest item in data
	// Returns the smallest element in the received array.
	template<typename T>
	T max(const T* data, int n){
		int x;
		T greater = data[0];

		for(x = 0; x < n; x++){
			greater = (data[x] > greater) ? data[x] : greater;
		} // end for

		return greater;
	} // end T max(const T*, int)

	// min returns the smallest item in data
	// Returns the largest element in the received array.
	template<typename T>
	T min(const T* data, int n){
		int x;
		T smaller = data[0];

		for(x = 0; x < n; x++){
			smaller = (data[x] < smaller) ? data[x] : smaller;
		} // end for

		return smaller;
	} // end T min(const T*, int)

	// sum returns the sum of n items in data
	// Calculates and return the sum of all elements in the received array.
	template<typename T>
	T sum(const T* data, int n){

		int x;
		T sum = data[0];

		for(x = 1; x < n; x++){
			sum += data[x];
		} // end for

		return sum;
	} // end T sum(const T*, int)

	// average returns the average of n items in data
	// Calculates and return the average of all elements in the received array.
	template<typename T>
	double average(const T* data, int n){
		T total = sum(data, n);
		T average = total / n;

		average = static_cast<double>(average);

		return average;
	} // end double average(const T*, int)

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	template<typename T>
	bool read(istream& is, T* data, int n){
		int x;
		bool success = true;

		for(x = 0; x < n; x++){

			is.ignore(2000, ',');
			is >> data[x];

			if(is.fail())
				success = false;

		} // end for

		return success;
	} // end bool read()

	// display inserts n items of data into std::cout
	template<typename T>
	void display(const char * name, const T* data, int n){

		cout << setw(20) << right << name;

		int x;
		for(x = 0; x < n; x++){
			cout << fixed << setw(COLUMN_WIDTH) << setprecision(1) << right << data[x];
		} //end for

		cout << endl;

	} // end void display()

	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	template<typename T>
	bool readRow(std::istream& input, const char* name, T* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	} // end bool readRow()

	void answers(const int*, const int*, const int*, const double*, const int*, const int n);

} // end namespace sict
#endif
