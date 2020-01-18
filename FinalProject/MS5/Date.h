/*
	Name:		     Pedro Zelada Souza
	Student#:	   116427188
	E-mail:      pzelada-souza@myseneca.ca
	Sect:		     SHH

	Milestone:   5
*/

#include <iostream>

using namespace std;

// Header safeguards
#ifndef AMA_DATE_H
#define AMA_DATE_H

namespace ama{

  // Year range constants
  const int min_year = 2019;
  const int max_year = 2028;

  // Error code constants
  const int no_error = 0; // Safe state OR valid date
  const int error_year = 1; // Invalid year
  const int error_mon = 2; // Invalid month
  const int error_day = 3; // Invalid error_day
  const int error_invalid_operation = 4; // Invalid operation
  const int error_input = 5; // Invalid input stream format

	// A class to store and manipulate Date objects
	class Date {

    // Date members
    int year; // Year part
    int month; // Month part
    int day; // Day part
    int err_status; // Status to determine if date is valid.

    void status(int); // Sets the status to one of the constants.
    int mdays(int, int) const; // Returns number of days in a given month.

    // Custom private functions
    void set(int, int, int); // Sets the objects member values
    void setSafe(); // Sets the object to a safe empty state
    bool isSafe() const; // Returns true if the object is in a safe empty state or false otherwise.

	public:

    Date(); // Default constructor. Sets the object to a safe empty state.
    Date(int, int, int); // Three parameter constructor. Initiate the object to the received parameters in case they are valid.

		int status() const; // Query that returns the state of the object.
    void clearError(); // Resets the status of the object to 'no_error'.
    bool isGood() const; // Query that returns true if the object stores a valid date.

    Date& operator+=(int days); // Adds the inputted days to the ojbect date.
    Date& operator++(); // Adds one day to the date object.
    Date operator++(int); // Adds one day to the date object and returns a copy of the object before the sum.
    Date operator+(int) const; // Adds the inputted days to the the object

    bool operator==(const Date&) const; // A query that returns true if two date objects store the same date.
    bool operator!=(const Date&) const; // A query that returns true if two date objects store different dates.
    bool operator<(const Date&) const; // A query that returns true if the current object stores a date that is before the matching object.
    bool operator>(const Date&) const; // A query that returns true if the current object stores a date that comes after the matching object.
    bool operator<=(const Date&) const; // A query that returns true if the current object stores a date that is either before or equal to the matching object.
    bool operator>=(const Date&) const; // A query that returns true if the current object stores a date that is either after or equal to the matching object.

    istream& read(istream&); // Reads from input stream in a date format.
    ostream& write(ostream&) const; // Writes the date to the output stream.

	}; // end Class Date

  istream& operator>>(istream&, Date&);
  ostream& operator<<(ostream&, const Date&);

} // end namespace
#endif
