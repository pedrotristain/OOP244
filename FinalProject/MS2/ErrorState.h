/*
	Name:		     Pedro Zelada Souza
	Student#:	   116427188
	E-mail:      pzelada-souza@myseneca.ca
	Sect:		     SHHL

	Milestone:   2
*/

#include <iostream>

using namespace std;

// Header safeguards
#ifndef SICT_ERRORSTATE_H
#define SICT_ERRORSTATE_H

namespace ama{

  // A class to store and manipulate ErrorState objects
	class ErrorState {

    // ErrorState message
    char * error_message;

	public:
    explicit ErrorState(const char* = nullptr); // Default constructor. May receive one or no arguments.
    ErrorState(const ErrorState&) = delete; // Disable the copying constructor.

    ~ErrorState(); // Destructor to de-allocate any memory dynamically allocated.

    ErrorState& operator=(const ErrorState&) = delete; // Disable the copying operator.
    operator bool() const; // Query function that return true if the current object is storing a valid message (not in a safe empty state).
    ErrorState& operator=(const char*); // Stores a copy of the text received as parameter.

    void message(const char*); // Stores a copy of the text received as parameter.
    const char* message() const; // Query function that returns the address of the message stored or a nullptr in case the object is in a safe empty state.
	}; // end Class ErrorState

  ostream& operator<<(ostream&, const ErrorState&);

} // end namespace
#endif
