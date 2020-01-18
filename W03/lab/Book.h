/*
	Name:		Pedro Zelada Souza
	Student#:	116427188
	E-mail:		pzelada-souza@myseneca.ca
	Sect:		SHHL

	Workshop:	03
*/

#include <iostream>

// Header safeguards
#ifndef SICT_BOOK_H
#define SICT_BOOK_H

namespace sict{
	
	const int max_title_size = 32; // A constant that holds the maximum string length for a Book title.
	const int max_name_size = 16; // A constant that holds the maximum number of characters for the Book's author's name.

	const long long min_isbn_value = 1000000000000; // A constant that holds the min value for the ISBN number
	const long long max_isbn_value = 9999999999999; // A constant that holds the max value for the ISBN number

	// A class that will hold the data of a book in an object.
	class Book {
		// Author data
		char given_name[max_name_size]; // Author first / given name.
		char family_name[max_name_size]; // Author last / family name.
		
		// Book data
		char title[max_title_size]; // Book title.
		long long isbn; // Book ISBN number.

	public:
		void set(const char*, const char*, const char*, long long);
		bool isEmpty();
		void display();

	}; // end Class Book

} // end namespace
#endif