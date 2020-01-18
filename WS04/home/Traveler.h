// TODO: add file header comments here
/*
	Name:			Pedro Zelada Souza
	Student#:	116427188
	E-mail:		pzelada-souza@myseneca.ca
	Sect:			SHH

	Workshop:	04
*/

// Headers
#include <iostream>

// Header safeguards
#ifndef SICT_TRAVELER_H
#define SICT_TRAVELER_H

namespace sict {

  const int max_destination_size = 32; // A constant integer that specify the maximum length of a destination name.
  const int max_name_size = 16; // A constant integer that specify the maximum length of a Traveler's name.

  const char empty_string[1] = ""; // An empty string that is used in the name() function.

    // Traveler class that will hold a travelers information and methods.
    class Traveler {

    private: // The object's private members that will hold the object's data.

      char first_name[max_name_size]; // A string variable that will hold the traveler's first name.
      char last_name[max_name_size]; // A string variable that will hold the traveler's last name.
      char destination[max_destination_size]; // A string variable that will hold the traveler's destination.

      int departure_year; // An intenger that will hold the year portion of the departure date.
      int departure_month; // An intenger that will hold the month portion of the departure date.
      int departure_day; // An intenger that will hold the day portion of the departure date.

    public: // The object's public member functions that will manipulate the private data.

      Traveler(); // Default constructor that sets the object in an empty safe state.
      Traveler( const char[], const char[], const char[] ); // Constructor that validates inputted data and sets the object's members accordingly.

      Traveler( const char[], const char[], const char[], const int, const int, const int ); // Constructs the object with validated first name, last name, destination, year, month and day of departure.

      bool isEmpty() const; // Query function that returns true in case the object is in an empty safe state or false otherwise.
      void display() const; // Query function to display the object's stored data or a warning in case it is empty.

      const char* name() const; // Query function that returns the first name of a traveler or an empty string if the object is in a safe empty space.
      bool canTravelWith(const Traveler &companion) const; // Query function that verifies if the current Traveler can travel with a second traveler. It returns true if both have the same destination and departure date. Returns false otherwise.
    };
}

#endif
