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

      departure_year = 0;
      departure_month = 0;
      departure_day = 0;

    }

    // Construct the object with valid inputted data. If the data is invalid, initiate the object in a safe empty state.
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

        departure_year = 2019; // Set the departure year
        departure_month = 7; // Set the departure month
        departure_day = 1; // Set the departure day

      } else { // If the received data is invalid, construct the object in an empty safe state

        first_name[0] = '\0';
        last_name[0] = '\0';
        destination[0] = '\0';

        departure_year = 0;
        departure_month = 0;
        departure_day = 0;
      } // end else
    } // end Traveler::Traveler(char, char, char)

    // Construct the object with valid inputted data. If the data is invalid, initiate the object in a safe empty state.
    // This variation of the constructor has the year, month and day of departure.
    Traveler::Traveler(const char par_first_name[], const char par_last_name[], const char par_destination[], const int par_year, const int par_month, const int par_day ){

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

      // Validate the received departure year
      if( par_year < 2019 || par_year > 2022 ){
        valid = false;
      }

      // Validate the received departure month
      if( par_month < 1 || par_month > 12 ){
        valid = false;
      }

      // Validate the received departure day
      if( par_day < 1 || par_day > 31 ) {
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

        departure_year = par_year;
        departure_month = par_month;
        departure_day = par_day;

      } else { // If the received data is invalid, construct the object in an empty safe state

        first_name[0] = '\0';
        last_name[0] = '\0';
        destination[0] = '\0';

        departure_month = 0;
        departure_year = 0;
        departure_day = 0;

      } // end else
    } // end Traveler::Traveler(char, char, char, int, int, int)

    // Returns true if the object is in an empty safe state or false otherwise.
    bool Traveler::isEmpty() const {
      return (first_name[0] == '\0'); // If the first character of the first_name is a null pointer, return true. Return false otherwise.
    }

    // Outputs the traveler data or a warning message if the object is in an empty safe state.
    void Traveler::display() const {

      // If the object is not empty, display the data to the screen.
      if( isEmpty() == false ) {

        cout << last_name << ", " << first_name << " goes to " << destination << " on " << departure_year << "/";

        cout.fill('0'); // Set the cout object filling setting.
        cout.width(2); // Format the month as <01> if month is less than 10
        cout << departure_month << "/";

        cout.width(2); // Format the day as <01> if month is less than 10
        cout << departure_day << endl;

      } else { // If the object is empty, display a warning message instead.

        cout << "--> Not a valid traveler! <--" << endl;

      } // end else
    } // end display()

    // Function that returns the address of the first name of the current traveler or the address of an empty string empty string.
    const char* Traveler::name() const {

      // Validate if the object is in a safe empty state.
      // If true, set address of the sict::empty_string variable to the name_address pointer.
      // Set the address of the object first_name to the name_address pointer otherwise.
      const char * name_address = ( isEmpty() == true ) ? (const char *) &sict::empty_string : (const char *) &first_name;

      // Return the address.
      return name_address;
    } // end Traveler::name()

    // Function that returns if the received traveler can travel with the current traveler
    bool Traveler::canTravelWith(const Traveler& companion) const {

      bool can_travel = false; // Variable that will hold the return value of the function. Initialize it to false by default.

      // Verify if the destination, departure year, month and day of both objects match. If there is a match, change the return value to true.
      if(
        strcmp( companion.destination, destination ) == 0
        && companion.departure_year == departure_year
        && companion.departure_month == departure_month
        && companion.departure_day == departure_day
      ){
        can_travel = true; // Change the return variable to true.
      }

      // Return the return variable.
      return can_travel;
    } // end bool Traveler::canTravelWith()
}
