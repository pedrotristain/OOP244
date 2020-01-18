/*
	Name:		     Pedro Zelada Souza
	Student#:	   116427188
	E-mail:      pzelada-souza@myseneca.ca
	Sect:		     SHHL

	Milestone:   2
*/

// Headers
#include <iostream>
#include <cstring>
#include "ErrorState.h"

using namespace std; // Namespace for the cout object.

namespace ama{

  // Default constructor. May receive one or no arguments.
  ErrorState::ErrorState(const char* par_error_message){
      *this = par_error_message;
  } // end explicit ErrorState::ErrorState(const char*)

  // Destructor to de-allocate any memory dynamically allocated.
  ErrorState::~ErrorState(){
    delete [] error_message; // Deallocate the dynamic memory.
    error_message = nullptr; // Set the pointer to a null value to avoid errors.
  } // end ErrorState::~ErrorState()

  // Query function that return true if the current object is storing a valid message (not in a safe empty state).
  ErrorState::operator bool() const{
    bool is_valid = true; // Control variable that tells if the object is holding a valid message.

    // Check if the object is storing a valid message. If not, set the control variable to false.
    if( error_message == nullptr || strcmp(error_message, "") == 0){
      is_valid = false;
    } // end if

    return is_valid; // Return true if valid or false otherwise.
  } // end operator bool() const

  // Stores a copy of the text received as parameter.
  ErrorState& ErrorState::operator=(const char* par_text){
    message(par_text);
    return *this;
  } // end ErrorState& ErrorState::operator=(const char*)

  // Stores a copy of the text received as parameter.
  void ErrorState::message(const char * par_text){

    // If the received parameter is a null pointer or an empty string, set the object to a safe empty state.
    if(par_text == nullptr || strcmp(par_text, "") == 0){
      error_message = nullptr;
    } else {

      // If the received parameter is valid, store a copy of it in the object.
      int size_text = strlen(par_text); // Calculate the size of the received message.

      error_message = new char[size_text + 1]; // Assign dynamic memory to the object to store the received message.
      strncpy(error_message, par_text, size_text); // Copy the received message to the object.

      error_message[size_text + 1] = '\0'; // Add the null pointer to finish the string.
    } // end else
  } // end void ErrorState::message(const char*)

  // Query function that returns the address of the message stored or a nullptr in case the object is in a safe empty state.
  const char* ErrorState::message() const{
      return error_message;
  } // end const char* ErrorState::message() const

  // Input operator overload.
  ostream& operator<<(ostream& os, const ErrorState& par_error_message){
    // If the ErrorState object is in a safe empty state, this function does nothing.
    if(par_error_message){
      os << par_error_message.message();
    } // end if

    return os; // Return the ostream object.
  } // end operator<<(ostream&, const ErrorState&)
} // end namespace
