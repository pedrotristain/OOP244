/*
	Name:		     Pedro Zelada Souza
	Student#:	   116427188
	E-mail:      pzelada-souza@myseneca.ca
	Sect:		     SHHL

	Milestone:   3
*/

#define _CRT_SECURE_NO_WARNINGS

// Necessary headers
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>

#include "ErrorState.h"
#include "Product.h"

using namespace std;

namespace ama{

  // **************************************************************************
  // *                          PRIVATE FUNCTIONS                             *
  // **************************************************************************

  // Modifier function that sets the current object's member variables to the received object member's variables values
  void Product::set(const Product& par_product){
    set(par_product.p_sku, par_product.p_name, par_product.p_unit, par_product.p_price, par_product.p_needed, par_product.p_in_stock, par_product.p_is_taxable);
  } // end Product::set(const Product&)

  // Modifier function that sets the current object's member variables to the received parameters.
  void Product::set(const char * par_sku, const char * par_name, const char * par_unit, double par_price, int par_needed, int par_stock, bool par_tax){
    // Initialize the string pointer members to a null pointer to avoid errors.
    p_name = nullptr;

    // Calculate the received NAME string size and store it in a size control variable.
    int size = strlen(par_name);
    // If the size is greater than the max allowed, change the size control variable value to the max allowed name size.
    size = (size > max_length_name) ? max_length_name : size;

    // Assign dynamic memory for the object name.
    p_name = new char[size];
    // Copy the received NAME up until the defined size control variable.
    strncpy(p_name, par_name, size);
    // Add the string-end null pointer manually.
    p_name[size] = '\0';

    // Copy the received SKU up to the defined size control variable.
    strncpy(p_sku, par_sku, max_length_sku);
    // Add the string-end null pointer manually.
    p_sku[size + 1] = '\0';

    // Copy the received UNIT up to the defined size control variable.
    strncpy(p_unit, par_unit, max_length_unit);
    // Add the string-end null pointer manually.
    p_unit[max_length_unit + 1] = '\0';

    // Set the non-string members
    p_price = (double) par_price;
    p_needed = par_needed;
    p_in_stock = par_stock;
    p_is_taxable = par_tax;
  } // end Product::set(...)

  // Query function that returns the price per unity.
  // Fator in the tax value if the attribute is_taxable is true.
  double Product::unit_price_with_taxes() const{
    // Control variable that will tell the total price per unit.
    double price = p_price;

    // Check if the product is taxable.
    if(p_is_taxable){
      // If true, calculate the taxes and increase the total price accordingly.
      price += (p_price * tax_rate);
    } // end if

    // Return the total price per unit
    return price;
  } // end Product::unit_price_with_taxes() const

  // Query function that concatenates the product name and return it.
  string Product::concatenate_name() const{
    string name = p_name;

    if(strlen(p_name) > 16){
      name = name.substr(0, 13);
      name += "...";
    } else {
      name = name.substr(0, 16);
    } // end else

    return name;
  }

  // **************************************************************************
  // *                         PROTECTED FUNCTIONS                            *
  // **************************************************************************

  // Modifier function that receives an error message and stores it into the p_error_state member.
  void Product::message(const char * par_message){
    p_error_state = par_message;
  } // end message(const char *)

  // Query functions that returns true if the product contains no Errors or false otherwise.
  bool Product::isClear() const{
    // Control variable that tells if the object has no error message.
    bool is_clear = true;

    // If the member p_error_state is not a null pointer or an empty string, change the control variable to false.
    if(p_error_state){
      is_clear = false;
    } // end if

    // Return false if there is an error message, or true otherwise.
    return is_clear;
  } // end Product::isClear() const

  // **************************************************************************
  // *                          PUBLIC FUNCTIONS                              *
  // **************************************************************************

  // ######################
  // #    CONSTRUCTORS    #
  // ######################

  // One or zero parameter constructor. Store the received value as the product type and sets the object to a safe empty state.
  Product::Product(char par_type) : p_type(par_type){
    p_in_stock = -1; // Safe empty state.
  } // end Product::Product(char)

  // 7 parameter constructor.
  // If the received name parameter is not valid, the object will remain in a safe empty state, as it was initialized.
  Product::Product(const char * par_sku, const char * par_name, const char * par_unit, double par_price, int par_needed, int par_stock, bool par_tax) : p_type('N'){
    // Initialize the object to a safe empty state.
    *this = Product();

    // Check if the received name is valid.
    if(par_name != nullptr or strcmp(par_name, "") != 0){

      // If true, set the objects attributes to the received values.
      set(par_sku, par_name, par_unit, par_price, par_needed, par_stock, par_tax);

    } // end if
  } // end Product::Product(const char *, const char *, const char *, double, int, int, bool)

  // Copy constructor
  Product::Product(const Product& old_product) : p_type('N'){
    // Copy the received Product object's member values to the new Product object.
    set(old_product.p_sku, old_product.p_name, old_product.p_unit, old_product.p_price, old_product.p_needed, old_product.p_in_stock, old_product.p_is_taxable);
  } // end Product::Product(const Product&)

  // ######################
  // #     DESTRUCTOR     #
  // ######################

  // Default destructor. Deallocate any dynamic generated memory for the object.
  Product::~Product(){
    //delete [] p_name;
  } // end Product::~Product()

  // ######################
  // # OPERATORS OVERLOAD #
  // ######################

  // Copy assignment operator overload.
  Product& Product::operator=(const Product& right_operand){
    set(right_operand);

    return *this;
  } // end Product::operator=(const Product&)

  // Sum and assign operator overload. Increase the product's in_stock value if the received amount is positive.
  // Return the updated quantity if the amount received is positive, or the current quantity otherwise.
  int Product::operator+=(int right_operand){
    // Check if the right operand is positive.
    if(right_operand > 0){
      // If true, add its value to the current Product in stock amount.
      p_in_stock += right_operand;
    } // end if

    // Return the in stock value.
    return qtyAvailable();
  } // end Product::operator+=(int)

  // Is equal to operator overload. Returns true if the stored SKU is equal to the received paramter. Returns false otherwise.
  bool Product::operator==(const char * right_operand) const{
    // Control variable that will tell if the right operand is equal to the left operand's sku value.
    bool is_equal = false;

    // Check if the right operand is equal to the current object sku
    if( strcmp(p_sku, right_operand) == 0 ){
      // If true, change the control variable to true.
      is_equal = true;
    } // end if

    // Return true if the sku is equal to the right operand. Returns false otherwise.
    return is_equal;
  } // end Product::operator==(const char *) const

  // Greater than operator overload. Returns true if the stored SKU is greater than the received parameter. Return false otherwise.
  bool Product::operator>(const char * right_operand) const{
    // Control variable that will tell if the left operand is greater than the right operand's sku value.
    bool is_greater = false;

    // Check if the left operand sku value is greater than the right operand.
    if( strcmp(p_sku, right_operand) > 0 ){
      // If true, change the control variable to true.
      is_greater = true;
    } // end if

    // Return true if the left operand sku value is greater than the right operand.
    return is_greater;
  } // end Product::operator>(const char *) const

  // Greater than operator overload 2. Returns true if the name of the current object is greater than the name of the received object.
  bool Product::operator>(const Product& right_operand) const{
    // Control variable that will tell if the left operand's name is greater than the right operand's name.
    bool is_greater = false;

    // Check if the left operand's name is greater than the right operand's name.
    if( strcmp(p_name, right_operand.p_name) > 0 ){
      // If true, change the control variable to true.
      is_greater = true;
    } // end if

    // Return true if the left's operand name is greater than the right operand's name.
    return is_greater;
  } // end Product::operator>(const Product&) const

  // ################################
  // # MODIFIER AND QUERY FUNCTIONS #
  // ################################

  // Query function that returns how many Product units are available in stock.
  int Product::qtyAvailable() const{
    return p_in_stock;
  } // end Product::qtyAvailable() const

  // Query function that returns how many Product units are needed.
  int Product::qtyNeeded() const{
    return p_needed;
  } //end Product::qtyNeeded() const

  // Query function that returns the total cost of all units of product, including taxes.
  double Product::total_cost() const{
    // Control variable that will tell the product total price.
    double total = p_price;

    // Calculate the total price including taxes
    total = unit_price_with_taxes() * qtyAvailable();

    // Return the total price.
    return total;
  } // end Product::total_cost() const

  // Query function that returns true if the object is in a safe empty state, or false otherwise.
  bool Product::isEmpty() const{
    // Control variable that will tell if the object is in a safe empty state.
    bool is_empty = false;

    // Check if the number of items in stock is negative.
    if(p_in_stock == -1){
      // If true, the object is in a safe empty state. Change the control variable to reflect this.
      is_empty = true;
    } // end if

    // Return true if the object is in a safe empty state, or false otherwise.
    return is_empty;
  } //end Product::isEmpty() const

  // Function that extracts the product data from the stream. If second parameter is true, it interacts with the user instead.
  istream& Product::read(istream& is, bool is_interactive){
    // Checks if the stream input is interactive or not

    // Declare temporary variables to hold the extracted information
    char tmp_sku[max_length_sku + 1];
    char tmp_name[max_length_name + 1];
    char tmp_unit[max_length_unit + 1];

    double tmp_price = 0.0;
    double tmp_tax = 0.0;

    int tmp_stock = 0;
    int tmp_needed = 0;

    if( is_interactive == false){
      // If false, extract all the information from the received stream object.

      // Extract the info from the input stream
      is.get(tmp_sku, max_length_sku, ',');
      is.ignore();

      is.get(tmp_name, max_length_name, ',');
      is.ignore();

      is.get(tmp_unit, max_length_unit, ',');
      is.ignore();

      is >> tmp_price;
      is.ignore();

      is >> tmp_tax;
      is.ignore();

      is >> tmp_stock;
      is.ignore();

      is >> tmp_needed;
      is.ignore(1024, '\n');

      set(tmp_sku, tmp_name, tmp_unit, tmp_price, tmp_needed, tmp_stock, tmp_tax);

    } else {
      // If the input is interactive, prompt the user for all the fields.

      // Prompt the user to enter a SKU.
      cout.width(max_length_label);
      cout.setf(ios::right);
      cout << "Sku: ";
      // Extract the SKU from the user input.
      is >> tmp_sku;

      // Prompt the user to enter a Product name.
      cout.width(max_length_label);
      cout << "Name (no spaces): ";
      // Extract the Product name from the user input.
      is >> tmp_name;

      // Prompt the user to enter a Product unit.
      cout.width(max_length_label);
      cout << "Unit: ";
      // Extract the Product unit from the user input.
      is >> tmp_unit;

      // Prompt the user to enter yes or no for the tax.
      cout.width(max_length_label);
      cout << "Taxed? (y/n): ";

      // Extract the answer from the user input.
      char is_taxed;
      is >> is_taxed;

      // Check if the extraction was successful.
      if(is){
        // Validate the user input
        switch (is_taxed) {
          // If the user inputted y or Y, set the tax to true.
          case 'y': case 'Y':
            tmp_tax = true;
          break;
          // If the user inputted n or N, set the tax to false.
          case 'n': case 'N':
            tmp_tax = false;
          break;
          // If the user inputted anything else, throw an error.
          default:
            is.setstate(ios::failbit);
            message("Only (Y)es or (N)o are acceptable!");
          break;
        } // end switch(is_taxed)
      } else {
        // If an error occurred, create an error message.
        message("Only (Y)es or (N)o are acceptable!");
      } // end else

      // Check if the extraction was successful.
      if(is){
        // Prompt the user to enter the product price before taxes.
        cout.width(max_length_label);
        cout << "Price: ";
        // Extract the Product price from the user input.
        is >> tmp_price;

        // If an error occur, create an error message
        if(!is){
          message("Invalid Price Entry!");
        } // end if
      } // end if

      // Check if the extraction was successful.
      if(is){
        cout.width(max_length_label);
        cout << "Quantity on hand: ";
        is >> tmp_stock;

        // If an error occur, create an error message.
        if(!is){
          message("Invalid Quantity Available Entry!");
        } // end if
      } // end if

      // Check if the extraction was successful.
      if(is){
        cout.width(max_length_label);
        cout << "Quantity needed: ";
        is >> tmp_needed;

        // If an error occur, create an error message.
        if(!is){
          message("Invalid Quantity Needed Entry!");
          return is;
        } // end if
      } // end if

      // Check if the extraction was successful.
      if(is){
        // If true, insert the received data into the object.
        set(tmp_sku, tmp_name, tmp_unit, tmp_price, tmp_needed, tmp_stock, tmp_tax);
      } // end if

      // Reset the cout object settings.
      cout.unsetf(ios::right);
    } // end else

    // Return the stream object.
    return is;
  } // end Product::read(istream&, bool)

   // Query function that inserts the current object info in the received stream parameter.
   // This functions does nothing if the object is in a safe empty state.
  ostream& Product::write(ostream& os, int write_type) const{

    // Configure the output stream object
    os << setprecision(2) << fixed;

    // Check if there is no error message in the object
    if(!isClear()){
      // If true, display the error message and quit the function.
      os << p_error_state;

    // If no error message, check if the object is not in a safe empty state
    } else if( !isEmpty() ) {
      // If not in a safe empty state, display the objects information on the screen.

      // Check which type of display is chosen.
      switch (write_type) {

        // If condensed, display all information in a single line, separated by COMMAS.
        case write_condensed:

          os
          << p_type       << ','
          << p_sku        << ','
          << p_name       << ','
          << p_unit       << ','
          << p_price      << ','
          << p_is_taxable << ','
          << p_in_stock   << ','
          << p_needed;

        break;

        // If human readable, display all information on a easy to read format.
        case write_human:

          os << setw(max_length_label) << right << "Sku: " << left << p_sku << endl;
          os << setw(max_length_label) << right << "Name: " << left << p_name << endl;
          os << setw(max_length_label) << right << "Price: " << left << p_price << endl;
          os << setw(max_length_label) << right << "Price after Tax: " << left << unit_price_with_taxes() << endl;
          os << setw(max_length_label) << right << "Quantity Available: " << left << qtyAvailable() << " " << p_unit << endl;
          os << setw(max_length_label) << right << "Quantity Needed: " << left << qtyNeeded() << " " << p_unit << endl;

        break;

        // If table, display every information in a cell, like a table.
        case write_table:

          os << " " << setw(max_length_sku) << right << p_sku << left << " ";
          os << "|";
          os << " " << setw(16) << concatenate_name() << " ";
          os << "|";
          os << " " << setw(10) << p_unit << " ";
          os << "|";
          os << " " << setw(7) << right << setprecision(2) << p_price << left << " ";
          os << "|";
          os << " " << setw(3) << right << ((p_is_taxable) ? "yes" : "no") << left << " ";
          os << "|";
          os << " " << setw(6) << right << p_in_stock << left << " ";
          os << "|";
          os << " " << setw(6) << right << p_needed << left << " ";
          os << "|";

        break;
      } // end switch(write_type)
    } // end else

    // Return the stream object.
    return os;
  } // end Product::write(ostream&, int) const
} // end namespace
