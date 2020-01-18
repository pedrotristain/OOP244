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

    // Traveler class that will hold a travelers information and methods.
    class Traveler {

    private: // The object's private members that will hold the object's data.

      char first_name[max_name_size]; // A string variable that will hold the traveler's first name.
      char last_name[max_name_size]; // A string variable that will hold the traveler's last name.
      char destination[max_destination_size]; // A string variable that will hold the traveler's destination.

    public: // The object's public member functions that will manipulate the private data.

      Traveler(); // Default constructor that sets the object in an empty safe state.
      Traveler( const char[], const char[], const char[] ); // Constructor that validates inputted data and sets the object's members accordingly.
      bool isEmpty() const; // Query function that returns true in case the object is in an empty safe state or false otherwise.
      void display() const; // Query function to display the object's stored data or a warning in case it is empty.
    };
}

#endif
