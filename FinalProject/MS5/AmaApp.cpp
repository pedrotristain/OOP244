/*
	Name:		     Pedro Zelada Souza
	Student#:	   116427188
	E-mail:      pzelada-souza@myseneca.ca
	Sect:		     SHH

	Milestone:   5
*/

// Necessary headers
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>

#include "AmaApp.h"
#include "iProduct.h"
#include "Utilities.h"
#include "Sort.h"

using namespace std;

namespace ama{

  // **************************************************************************
  // *                          PRIVATE FUNCTIONS                             *
  // **************************************************************************

  // Stop the program and prompt the user to continue
  void AmaApp::pause() const {

    // Prompt the user to press Enter to continue
    cout << "Press Enter to continue..." << endl;
    cin.get();

    clearBuffer();

  } // end AmaApp::pause() const

  // Display a numeric menu and return the selected option.
  int AmaApp::menu() const {

    // Display the numeric menu
    cout << "Disaster Aid Supply Management Program" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1- List products" << endl;
    cout << "2- Search product" << endl;
    cout << "3- Add non-perishable product" << endl;
    cout << "4- Add perishable product" << endl;
    cout << "5- Add to product quantity" << endl;
    cout << "6- Delete product" << endl;
    cout << "7- Sort products" << endl;
    cout << "0- Exit program" << endl;
    cout << "> ";

    // Receive the selected option.
    int option = -1;
    cin >> option;

    // Check if the selected option is valid. If not, set it to -1.
    option = (option >= 0 && option <= 7) ? option : -1;

    if( cin.fail() ){
      option = -1;
      clearBuffer();
    } // end if

    // Return the selected option or -1
    return option;

  } // end AmaApp::menu() const

  // Opens a product file and store the records in the products array.
  // If the does not exist, create a new empty file and exit the function.
  void AmaApp::loadProductRecords(){

    // Clear the products array.
    deleteProductsArray();

    // Open the file for reading
    fstream f_product(m_filename, ios::in);

    // Check if the file exists and there was no problem reading it.
    if ( f_product.is_open() ){

      // Control variable that will define the tipe of product to be created.
      char tag;
      // Control variable that will tell the current index of the product array.
      int index = 0;

      // If the file is open, read all the records of the file untill the end of the file.
      while( f_product && !f_product.eof() ){
        // Extract the product tag from the stream
        f_product.get(tag);

        // Create a new dynamic product.
        m_products[index] = ama::createInstance(tag);

        // Ignore the first comma
        f_product.ignore(2000, ',');

        // Read the products info from the stream and add it to the current product object.
        m_products[index]->read(f_product, false);

        f_product.ignore(2000, '\n');

        // Increment the product index.
        index++;
      } // end while

      // Set the size of the product array to the current index.
      m_noOfProducts = index - 1;

    } else {

      // If the file does not exist, create a new empty file.
      f_product.open(m_filename, ios::out);

      // cout << "\t\t Called f_product.open(m_filename, ios::out)" << endl;

    } // end else

    // Close the file
    f_product.close();

  } // end AmaApp::loadProductRecords()

  // Save the products array into the file
  void AmaApp::saveProductRecords() const {

    // Open the file to write
    fstream f_product(m_filename, ios::out);

    int x;
    // Iterate through the product array writting each record to the file
    for( x = 0; x < m_noOfProducts; x++){

      // Write the current product to the file
      m_products[x]->write(f_product, write_condensed);

      // Add a new line.
      f_product << endl;

    } // end for

    // Close the file.
    f_product.close();

  } // end saveProductRecords() const

  // Display the product array in a table view
  void AmaApp::listProducts() const {

    // Display the table header
    // Top Border
    cout << setw(96) << setfill('-') << '-' << setfill(' ') << endl;

    // Column names
    cout
    << "|" << setw(5)  << left  << " Row "            << "|"
    << setw(9)  << right << " SKU "            << "|"
    << setw(18) << left  << " Product Name "   << "|"
    << setw(12) << left  << " Unit "           << "|"
    << setw(9)  << right << " Price "          << "|"
    << setw(5)  << left  << " Tax "            << "|"
    << setw(8)  << right  << " QtyA "           << "|"
    << setw(8)  << right  << " QtyN "           << "|"
    << setw(12) << left  << " Expiry "         << "|"
    << endl;

    // Bottom border
    cout << setfill('-')
    << "|" << setw(5)   << "-" << "|"
    << setw(9)   << "-" << "|"
    << setw(18)  << "-" << "|"
    << setw(12)  << "-" << "|"
    << setw(9)   << "-" << "|"
    << setw(5)   << "-" << "|"
    << setw(8)   << "-" << "|"
    << setw(8)   << "-" << "|"
    << setw(12)  << "-" << "|"
    << setfill(' ') << endl;

    // Control variable that will tell the total cost of all products.
    double total_cost = 0.0;

    int x;
    // Iterate through the products array and display the info of each product
    for(x = 0; x < m_noOfProducts; x++){

      // Display the row number
      cout << "|" << setw(4) << right << (x + 1) << " |";

      // Call the write function to display the rest of the data.
      m_products[x]->write(cout, write_table);

      cout << endl;

      // Increment the total price.
      total_cost += *m_products[x];
    } // end for

    // Display the table footer
    // Top border
    cout << setw(96) << setfill('-') << '-' << setfill(' ') << endl;

    // Total cost
    cout << "|" << setw(82) << right << " Total cost of support ($): |"
    << setw(11) << right << fixed << setprecision(2) << total_cost << " |"
    << endl;

    // Bottom border
    cout << setw(96) << setfill('-') << '-' << setfill(' ') << endl << endl;

  } // end AmaApp::listProducts() const

  // Look for the receveid SKU in the products array and return a match or a nullptr.
  iProduct* AmaApp::find(const char* par_sku) const {

    // Create a pointer to hold the address of the found product
    iProduct * temp = nullptr;

    int x;
    // Iterate through the products array and look for the received SKU parameter.
    for(x = 0; x < m_noOfProducts - 1; x++){

      // Check if the current product SKU is the same as the parameter SKU
      if( *m_products[x] == par_sku ){

        // If true, change the control pointer variable to the current object.
        temp = m_products[x];

        // End the loop prematurely
        x = m_noOfProducts;
      } // end if

    } // end for

    // Return the address of the found object or nullptr.
    return temp;
  } // end AmaApp::find(const char*) const

  // Update the quantity on hand of a product
  void AmaApp::addQty(iProduct* par_product) {

    // Control variable that will tell how many units were bought.
    int qty_bought = 0;

    // Display the received product parameter in human readable format.
    par_product->write(cout, write_human);

    // Promt the user to enter the number of purchased items.
    cout << endl << endl << "Please enter the number of purchased items: ";
    cin >> qty_bought;

    // Check if the input had any errors.
    if( !cin ){

      //If true, display an error message.
      cout << "Invalid quantity value!" << endl;

      clearBuffer();

    } else {

      // Needed Quantity
      int qty_to_full = par_product->qtyNeeded() - par_product->qtyAvailable();

      // If reading the number from the stream succeeded, check if the amount is less than quantity needed.
      if( qty_bought <= qty_to_full ){

        // If needed amount is more or equal to amount bought, increase the amount on hand by the amount bought.
        *par_product += qty_bought;

      } else {
        // If needed amount is less than amount bought, display an error message and increase quantity on hand by amount needed only.

        // Surplus
        int qty_surplus = qty_bought - qty_to_full;

        cout << "Too many items; only " << qty_to_full << " is needed. Please return the extra " << qty_surplus << " items." << endl;
        *par_product += qty_to_full;

      } // end else

      // Save the changes to the file.
      saveProductRecords();

      // Display a message stating the update was successful.
      cout << endl << "Updated!" << endl;

    } // end else

  } // end AmaApp::addQty(iProduct*)

  // Add a new product at the end of the array
  void AmaApp::addProduct(char par_tag) {

    // Create a new product at the end of the product array.
    iProduct * new_product = nullptr;
    new_product = createInstance(par_tag);

    // Check if the product was created successfully.
    if( new_product != nullptr ){

      // If successful, prompt the user for the data of the new product.
      cin >> *new_product;

      // Display a new line.
      cout << endl;

      // Check if the data extraction from the user failed.
      if( !cin ) {
        cin.clear();

        // If true, display the error message associated with the failure.
        cout << *new_product;

      } else {
        // If the data extraction was successful, add the new product to the end of the array, to the file and display a message stating so.
        m_products[m_noOfProducts] = new_product;
        m_noOfProducts++;

        // Rewrite the product file.
        saveProductRecords();

        // Display the success message.
        cout << "Success!";
      } // end else

      // Display 2 new lines.
      cout << endl << endl;

    } // end if

  } // end AmaApp::addProduct(char)



  // ====================
  //  OPTIONAL FUNCTIONS
  // ====================

  // Remove the received program from the file
  void AmaApp::deleteProductRecord(iProduct* par_product){

    // Open the file to write
    fstream f_product(m_filename, ios::out);

    int x;
    // Iterate through the product array writting each record to the file
    for( x = 0; x < m_noOfProducts; x++){

      // If the current product is equal to the parameter product, skip it.
      if(! (m_products[x] == par_product) ){

        // Write the current product to the file
        m_products[x]->write(f_product, write_condensed);

        // Add a new line.
        f_product << endl;

      } // end if

    } // end for

    // Close the file.
    f_product.close();

  } // end AmaApp::deleteProductRecord(iProduct* product)

  // Sort the product array
  void AmaApp::sort() {
    // Pass the array and its size to the template sorting function.
    sict::sort(m_products, m_noOfProducts);

  } // end AmaApp::sort()

  // ==================
  //  CUSTOM FUNCTIONS
  // ==================

  void AmaApp::deleteProductsArray(){

    // Deallocate all dynamic memory
    int x;
    for(x = 0; x < 100; x++){

      delete m_products[x];
      m_products[x] = nullptr;

    } // end for

  } // end AmaApp::deleteProductsArray()

  iProduct * AmaApp::findProductBySku() {

    // Variable to hold the inputted SKU
    char find_sku[max_length_sku];
    // Control variable that will tell if the product was found or not.
    iProduct * found_product = nullptr;

    // Promt
    cout << "Please enter the product SKU: ";
    cin >> find_sku;

    found_product = find( find_sku );

    //cin.ignore(2000, '\n');

    return found_product;

  } // end AmaApp::promptProductSku()

  // **************************************************************************
  // *                         PROTECTED FUNCTIONS                            *
  // **************************************************************************


  // **************************************************************************
  // *                          PUBLIC FUNCTIONS                              *
  // **************************************************************************

  // ######################
  // #    CONSTRUCTORS    #
  // ######################

  // 1 Parameter Constructor. Initialize the program.
  AmaApp::AmaApp(const char * file_name) {

    // Check if received filename is valid. If true, store it in the member m_filename.
    if(file_name != nullptr or strcmp(file_name, "") != 0){

      strncpy(m_filename, file_name, strlen(file_name));
      m_filename[strlen(file_name)] = '\0';

    } //end if

    // Set all elements of the products array to null.
    int x;
    for(x = 0; x < 100; x++){
      m_products[x] = nullptr;
    } // end for

    // Set the size of the product array to 0.
    m_noOfProducts = 0;

    // Load all records from the file.
    loadProductRecords();

  } // end AmaApp::AmaApp(const char *)

  // ######################
  // #     DESTRUCTOR     #
  // ######################

  AmaApp::~AmaApp(){

    deleteProductsArray();

  } // end AmaApp::~AmaApp()

  // ################################
  // # MODIFIER AND QUERY FUNCTIONS #
  // ################################

  // Execute the program. Display the menu and executed selected option until 0 is selected.
  int AmaApp::run() {

    // Control variable that will hold the menu option chosen by the user.
    int menu_option = 0;

    // Control variable that will tell if the product was found or not.
    iProduct * found_product = nullptr;

    do {

      // Display the menu and receive the selected option
      menu_option = menu();

      switch ( menu_option ) {
        case 0: // Quit the program.

          cout << "Goodbye!" << endl;

        break;

        case 1: // List products

          listProducts();

          pause();

        break;

        case 2: // Find a product by it's SKU and display it.

          // Try to find the product in the product array.
          found_product = findProductBySku();

          // Check if the product was found.
          if( found_product != nullptr ) {
            // If true, display the product data in a human readable form.
            cout << endl << *found_product << endl;
          } else {
            // If false, display a message stating that no product was found.
            cout << endl << "No such product!" << endl;

          } // end else

          pause();

        break;

        case 3: // Add a new non-perishable product and load all records from the file.

         addProduct('N');

         loadProductRecords();

         cin.get();

        break;

        case 4: // Add a new perishable product and load all records from the file.

          addProduct('P');

          loadProductRecords();

        break;

        case 5: // Ask for a SKU, find a product that matches it and increase it's quantity on hand.

          // Try to find the product in the product array.
          found_product = findProductBySku();

          cout << endl;

          // Check if the product was found.
          if( found_product != nullptr ) {
            // If true, prompt the user for the amount to be increasd.
            addQty( found_product );
          } else {
            // If false, display a message stating that no product was found.
            cout << "No such product!" << endl;

            cin.get();
          } // end else

          // Display a new line
          cout << endl;


        break;

        case 6: // Ask for a SKU, find a product that matches it and delete the product.

          // Try to find the product in the product array.
          found_product = findProductBySku();

          cout << endl;

          // Check if the product was found.
          if( found_product != nullptr ) {
            // If true, delete the product from the file.
            deleteProductRecord( found_product );

            // Reload all products from the file.
            loadProductRecords();

            cout << "Deleted!" << endl;
          } else {
            // If false, display a message stating that no product was found.
            cout << "No such product!" << endl;

          } // end else

        break;

        case 7: // Sort the products array, save it and display a message stating it was sorted.

          sort();

          //saveProductRecords();

          cout << "Sorted!" << endl << endl;

        break;

        default: // Display a message stating the chosen option is invalid.

          cout << "~~~Invalid selection, try again!~~~" << endl;
          pause();

        break;

      } //end switch(menu_option)

    } while ( menu_option != 0 );

    // Return 0 when the program ends.
    return menu_option;

  } // end AmaApp::run()

} // end namespace
