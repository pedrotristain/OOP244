// TODO: add file header comments here
/*
	Name:			Pedro Zelada Souza
	Student#:	116427188
	E-mail:		pzelada-souza@myseneca.ca
	Sect:			SHH

	Workshop:	04
*/

// Headers
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "Traveler.h"

using namespace std; // Namespace for the COUT object.

namespace sict {

    // Sets the object to a safe empty state.
    Traveler::Traveler(){

      first_name[0] = '\0';
      last_name[0] = '\0';
      destination[0] = '\0';

    }

    // Construct the object with valid inputted data. If the data is invalid, call the default constructor instead.
    Traveler::Traveler(const char par_first_name[], const char par_last_name[], const char par_destination[]){

      bool valid = true; // Control variable that will tell if the received data is valid.

      // Validate the received first name data. If empty, set the control valid to invalid.
      if(par_first_name == nullptr || strcmp(par_first_name, "") == 0){
        valid = false;
      }

      // Validate the received last name data. If empty, set the control valid to invalid.
      if(par_last_name == nullptr || strcmp(par_last_name, "") == 0){
        valid = false;
      }

      // Validate the received destination data. If empty, set the control valid to invalid.
      if(par_destination == nullptr || strcmp(par_destination, "") == 0){
        valid = false;
      }


      // If the data is valid, copy the received data into the object's members.
      if( valid == true ){
        /* Debugging
        cout << "############################################" << endl;
        cout << par_first_name << " - " << par_last_name << " - " << par_destination << endl;
        cout << "############################################" << endl << endl;
        */
        // Set the first name
        strncpy(first_name, par_first_name, max_name_size);
        first_name[max_name_size] = '\0';

        // Set the last name
        strncpy(last_name, par_last_name, max_name_size);
        last_name[max_name_size] = '\0';

        // Set the destination
        strncpy(destination, par_destination, max_destination_size);
        destination[max_destination_size] = '\0';

      } else { // If the received data is invalid, construct the object in an empty safe state

        first_name[0] = '\0';
        last_name[0] = '\0';
        destination[0] = '\0';

      }

    }
    // Returns true if the object is in an empty safe state or false otherwise.
    bool Traveler::isEmpty() const {


      return (first_name[0] == '\0'); // If the first character of the first_name is a null pointer, return true. Return false otherwise.
    }

    // Outputs the traveler data or a warning message if the object is in an empty safe state.
    void Traveler::display() const {

      // If the object is not empty, display the data to the screen.
      if( isEmpty() == false ) {
        cout << first_name << " " << last_name << " goes to " << destination << endl;

      } else { // If the object is empty, display a warning message instead.
        cout << "--> Not a valid traveler! <--" << endl;

      } // end else
    } // end display()
}
