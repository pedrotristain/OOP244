/*
	Name:		     Pedro Zelada Souza
	Student#:	   116427188
	E-mail:      pzelada-souza@myseneca.ca
	Sect:		     SHH

	Milestone:   5
*/

// Necessary headers
#include <iostream>
#include <string>
#include "iProduct.h"

using namespace std;

// Header safeguards
#ifndef AMA_AMAAPP_H
#define AMA_AMAAPP_H

namespace ama{

  // A class to store and manipulate Perishable Product objects.
  class AmaApp {

    // Private members
    char m_filename[256]; // Holds the name of the text file used to store product information.

    iProduct * m_products[100]; // An Array iProduct pointers.

    int m_noOfProducts; // Number of Products and Perishables pointed by the m_products array.

    // Private functions
    AmaApp(const AmaApp&) = delete; // Disable the copy constructor
    void operator=(const AmaApp&) = delete; // Disable the assignment operator

    void pause() const; // Query function that stops execution of the program and prompts the user to continue.

    int menu() const; // Query function that display the program menu. Returns a menu option selected by the user.

    void loadProductRecords(); // Open a file and store each record in the array of products.

    void saveProductRecords() const; // Save the array of products in a file.

    void listProducts() const; // Display all the products in a table view

    void deleteProductRecord(iProduct *); // Optional. Store the product array in a file, skipping the received parameter.

    void sort(); // Opitional. Sort the product array

    iProduct * find(const char *) const; // Looks for the received SKU parameter in the product array and return a match or nullptr.

    void addQty(iProduct *); // Upodate the quantity on hand for a product

    void addProduct(char); // Add a new product to the end of the product array.

    /* Custom Functions */

    void deleteProductsArray(); // Clear the products array, deallocating all the dynamic memory.

    iProduct * findProductBySku(); // Find a product by it's SKU and return it.

	public:

    // Constructors
    AmaApp(const char * = nullptr); // 1 Parameter construct.

    // Destructors
    ~AmaApp(); // Clear up dynamic memory of m_products.

    // Modifier and Query functions
    int run(); // Executes the program.

	}; // end Class Product

} // end namespace
#endif
