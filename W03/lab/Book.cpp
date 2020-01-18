/*
	Name:		Pedro Zelada Souza
	Student#:	116427188
	E-mail:		pzelada-souza@myseneca.ca
	Sect:		SHHL

	Workshop:	03
*/

// Headers
#include <iostream>
#include <cstring>

#include "Book.h"

using namespace std; // Namespace for the COUT object.

namespace sict {

	/*
		Function to assign data to a Book object.
		- Receives:
			+ first_name : The authors given name.
			+ last_name  : The authors last name.
			+ book_title : The book title.
			+ isbn       : The book ISBN number for validation.
		- Validates: the ISBN number. If not valid, assign a 'empty state' to the object.
			+ empty state : 0.
		- Returns no value.
	*/
	void Book::set(const char* first_name, const char* last_name, const char* book_title, long long par_isbn) {
		/* 
			strncpy(given_name, famile_name, max_name_size + 1)
			given_name[max_name_size] = '\0'
		*/

		// Validate the isbn number.
		bool valid = (par_isbn >= min_isbn_value && par_isbn <= max_isbn_value) ? true : false;

		// Store the data in the object according to the validation of the isbn number
		if ( valid ) { // If the isbn number is valid...
			
			// Store the received data in the object
			strncpy(given_name, first_name, max_name_size + 1); // Store the first name and make sure it does not overflow.
			given_name[max_name_size] = '\0';

			strncpy(family_name, last_name, max_name_size + 1); // Store the last name and make sure it does not overflow.
			family_name[max_name_size] = '\0';

			strncpy(title, book_title, max_title_size + 1); // Store the book name and make sure it does not overflow.
			title[max_name_size] = '\0';

			isbn = par_isbn; // Store the isbn number.

		} else { // If the isbn number is not valid...

			// Store an 'empty state' in the object.
			
			family_name[0] = '\0';
			given_name[0] = '\0';
			title[0] = '\0';
			isbn = 0;

		} // end if else

	} // end Book::set()

	/*
		A function to verify if the object is in a empty safe state.
		- Returns 'true' if the object is empty.
		- Returns 'false' if the object is not empty.
	*/
	bool Book::isEmpty() {
		
		// Validate if the isbn number of the object is 0.
		// If true, the object is in an empty state. Otherwise, it is not.
		// Return true if empty state and false if not.
		return (isbn == 0);

	} // end Book::isEmpty()

	/*
		A function to display the data in the object on the default output
		- Display a warning message if the object is in empty state.
		- Display the object data if the object is not in empty state.
		- Returns no value.
	*/
	void Book::display() {
		
		// Validate if the object is in empty state.
		if (isEmpty()) { // If it is...
			
			cout << "The book object is empty!" << endl; // Display a message to the user alerting that the object is empty.

		} else { // Otherwise...

			cout << "Author: " << family_name << ", " << given_name << endl; // Display the author name
			cout << "Title: " << title << endl; // Display the book title
			cout << "ISBN-13: " << isbn << endl; // Display the ISBN number
		}

	} // end Book::display()
}