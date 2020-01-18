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

		/* ---- Extended at-home code ---- */

		/*
			Validation of the ISBN number must:
			- Set aside last digit (13th) as a checking digit.
			- Get the remaining 12 digits and divide them in odd positioned and even positioned.
			- Sum all odd positioned digits (Indexes 0, 2, 4, 6, 8, 10).
			- Sum all even_positioned digits (Indexes 1, 3, 5, 7, 9, 11) and multiply the sum by 3.
			- Sum both sumsto get a Total Sum.
			- Find the next multiplier of 10 that is closer to the Total Sum (E.g: 45 -> 50. 31 -> 40).
			- Subtract the Total Sum from the next 10 multiplier and compare it to the checking digit.
			- If there is a match, the ISBN number is valid. If not, it is invalid.
		*/

		// If the ISBN number is exactly 13 digits long, proceed with the validation. Otherwise, flag it as invalid.
		if( valid) {

	    int check_digit = par_isbn % 10; // The checking digit to be used on the validation of the ISBN number.
			long long calc_isbn = par_isbn / 10; // The 12 digits to calculate the validation of the ISBN number.
			long long ary_isbn[12] = { 0 }; // Temporary array to hold all the 12 validation digits.
			long long divider = min_isbn_value / 10; // Variable to get the digits of the validation digits.

			// Variables to validate the ISBN number.
			int sum_odds = 0;
			int sum_evens = 0;
			int sum_total = 0;

			//cout << "ISBN [ " << par_isbn << "] ISBN - CHECK [" << calc_isbn << "]" << endl;

			// Iterate through all digits and add them to a temporary array.
			for(int a = 0; a < 12; a++){
				ary_isbn[a] = calc_isbn / divider; // Store the digit in the temporary array, from left most to right most.

				calc_isbn -= (calc_isbn / divider) * divider; // Math formula to find the next digit (Remove the left most digit from the number).
				divider /= 10; // Diminish the divider so we can get the next digit (Remove the right most zero).
			}

			// Iterate through all digits and sum all the odd positioned ones and all even positioned ones. Store the results in the respective variables.
			for(int a = 0; a < 12; a++){
				if( a % 2 == 0){ // If (a % 2 == 0), an odd positioned digit is currently being processed.
					sum_odds += ary_isbn[a]; // Sum all odd position digits.

				} else { // Otherwise, an even positioned digit is currently being processed.
					sum_evens += ary_isbn[a]; // Sum all even position numbers
				} // end else
			} // end for()

			sum_evens *= 3; // Needed for the validation.

			sum_total = sum_evens + sum_odds; // Add both sums together.

			int next_decimal = ((sum_total / 10) + 1) * 10; // Get the next multiple of 10.

			valid = ( next_decimal - sum_total == check_digit ); // If the subtraction matches, the isbn number is valid. Set the valid variable to true, or false otherwise.

			/* Debugging purposes
			cout << par_isbn << endl;
			cout << ary_isbn[0] << " + " <<  ary_isbn[2] << " + " << ary_isbn[4] << " + " << ary_isbn[6] << " + " <<  ary_isbn[8] << " + " <<  ary_isbn[10] << " = " <<  sum_odds << endl;
			cout << ary_isbn[1] << " + " <<  ary_isbn[3] << " + " << ary_isbn[5] << " + " << ary_isbn[7] << " + " <<  ary_isbn[9] << " + " <<  ary_isbn[11] << " = " <<  sum_evens << endl;
			cout << next_decimal << " - " << sum_total << " = " << (next_decimal - sum_total) << " = [" << check_digit << "]" << endl;
			*/

		} else { // ISBN number is not 13 digits long.

			valid = false; // Set the flag varbiable to false.

		} // end else

		/* ---- End at-home extended code ---- */

		// Store the data in the object according to the validation of the isbn number
		if ( valid ) { // If the isbn number is valid...

			// Store the received data in the object
			strncpy(given_name, first_name, max_name_size + 1); // Store the first name and make sure it does not overflow.
			given_name[max_name_size] = '\0';

			strncpy(family_name, last_name, max_name_size + 1); // Store the last name and make sure it does not overflow.
			family_name[max_name_size] = '\0';

			strncpy(title, book_title, max_title_size + 1); // Store the book name and make sure it does not overflow.
			title[max_title_size] = '\0';

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
	void Book::display(bool single_line) {


		if ( isEmpty() == true ) { // Object is empty

			if( single_line == false ) { // Parameter single_line is false

				cout.width(92);
				cout.setf(ios::left);

				cout << "The book object is empty! " << endl; // Display a message to the user alerting that the object is empty.

				cout.unsetf(ios::left);
			} else { // Parameter single_line is true

				cout << "|"; // Display a border line for aesthetics purposes.

				// Display a message that the object is empty with the format:
				// Width : 92
				// Aligned : Left
				cout.width(92);
				cout.setf(ios::left);

				cout << "The book object is empty!";  // Display a message to the user alerting that the object is empty.
				cout << "|" << endl;

				// Unset the cout settings
				cout.unsetf(ios::left);

			} // end else

		} else { // Object is not empty.

			if( single_line == false ) { // Parameter single_line is false

				cout << "Author: " << family_name << ", " << given_name << endl; // Display the author name
				cout << "Title: " << title << endl; // Display the book's title
				cout << "ISBN-13: " << isbn << endl; // Display the book's ISBN number
				cout << "Publication Year: " << pub_year << endl; // Display the book's publication year
				cout << "Price: " << price << endl; // Display the book's price

			} else { // Parameter single_line is true

				cout << "|"; // Display a border line for aesthetics purposes.
				// Cout settings: Size : max_name_size , Alignment : Right.
				cout.width(max_name_size);
				cout.setf(ios::right);

				cout << family_name << "|"; // Display the author's family name.

				// Cout settings: Size : max_name_size.
				cout.width(max_name_size);

				cout << given_name << "|"; // Display the author's given name.

				// Cout settings: Size : max_title_size , Alignment : Left.
				cout.unsetf(ios::right);
				cout.setf(ios::left);
				cout.width(max_title_size);

				cout << title << "|"; // Display the book's title.

				// Cout settings: Size : 13 , Alignment : Right.
				cout.unsetf(ios::left);
				cout.setf(ios::right);
				cout.width(13);

				cout << isbn << "|"; // Display the book's ISBN number.

				// Cout settings: Size : 4.
				cout.width(4);

				cout << pub_year << "|"; // Display the book's publication year.

				// Cout settings: Size : 6 , Precision : 2.
				cout.setf(ios::fixed);
				cout.width(6);
				cout.precision(2);

				cout << price << "|"; // Display the book's price.

				 // Reset the cout settings to their default values.
				cout.unsetf(ios::right);
				cout.unsetf(ios::fixed);
				cout.precision(6);

				cout << endl; // Output a line break for aesthetics.

			} // end else (single_line)
		} // end else (isEmpty())

	} // end Book::display()

  void Book::set(int par_year, double par_price){
		if( !isEmpty() ){

			pub_year = par_year; // Set the book publication year.
			price = par_price; // Set the book price.

		}// end if()
  } // end Book::set()
}
