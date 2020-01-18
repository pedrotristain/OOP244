/*
	Name:		     Pedro Zelada Souza
	Student#:	   116427188
	E-mail:      pzelada-souza@myseneca.ca
	Sect:		     SHH

	Milestone:   5
*/

// Header inclusions
#include <iostream>
#include "Date.h"

using namespace std; // Namespace for the COUT object.

namespace ama{

  // Sets the member 'status' to the value of 'new_status'
  void Date::status(int new_status){
    err_status = new_status;
  } // end Date::status

  // Returns the number of days in a given month, for a given year.
  int Date::mdays(int year, int mon) const{
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int month = mon >= 1 && mon <= 12 ? mon : 13;
    month--;
    return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
  } // end Date::mdays

  // Function that sets the object to a safe empty state
  void Date::setSafe(){
    set(0, 0, 0);
  } // end Date::setSafe

  // Function to set the objects member values
  void Date::set(int p_year, int p_month, int p_day){
    year = p_year;
    month = p_month;
    day = p_day;
  } // end Date::set

  // Default constructor. Set the object to a safe empty state and no error.
  Date::Date(){
    setSafe(); // Set the object to an safe empty state.
    clearError(); // Set the status of the object to 'no_error'
  } // Date::Date()

  // 3 Parameters constructor. Initiate the object with data for member year, month and day.
  Date::Date(int par_year, int par_month, int par_day){
    status(no_error); // Initiate the object with the status set to no error.

    // If inputted day is not in a valid range (min_year and max_year), set the object status error code to 'error_year'
    if( par_year > max_year || par_year < min_year ){
      // cout << " ERROR YEAR ";
      status(error_year);
    } else if(par_month < 1 || par_month > 12){
      // cout << " ERROR MONTH ";
      status(error_mon);
    } else if(par_day < 1 || par_day > mdays(par_year, par_month) ){
      // cout << " ERROR DAY ";
      status(error_day);
    } // end if

    if( status() != no_error ){
      setSafe();
    } else { // If the values are valid, set them to the member variables.
      set(par_year, par_month, par_day);
    } // end else

  } // end Date(int, int, int)

  // A query that returns the status of the current object
  int Date::status() const{
    return err_status;
  } //end Date::status()

  // Resets the status of the current object to 'no_error'. Does not alter the data in the object.
  void Date::clearError(){
    status(no_error);
  } // end Date::clearError()

  // A query that returns if the object stores a valid date and is not in error mode
  bool Date::isGood() const{

    bool is_good = false; // Control variable that will return if the object is valid.

    if(status() == no_error){ // Check if the object status is not an error status.
      if(year >= min_year && year <= max_year){ // If object's status is not error, check if year is in range.
        if(month >= 1 && month <= 12){ // If year is in range, check if month is in range.
          if(day >= 1 && day <= mdays(year, month) ){ // If month is in range, check if day is in range.
            is_good = true; // If every member is valid, set the control variable to 'true'.
          } // end if(day)
        } // end if(month)
      } // end if(year)
    } // end if(status)

    return is_good; // Return the control variable's value. True if the object is valid or false otherwise.
  } // end Date::isGood()

  // Sum and assign operator overload
  Date& Date::operator+=(int par_days) {

    // Control variables
    Date temp_date = *this; // Temporary object to hold the sum

    int temp_day = 0; // Holds the sum of the current object day with the parameter days to be added.
    bool valid = false; // Tells if the object is valid and not in a safe empty state.
    bool in_range = false; // Tells if the sum of the days is in valid range.

    // Add up the current object day to the inputted parameter days.
    temp_day = temp_date.day + par_days;

    // Check if the temp_day is in valid range for the month and year
    if(temp_day > 1 && temp_day <= mdays( year, month ) ){
      in_range = true; // If in range, change the control variable 'in_range' to true.
    } // end if

    // Check if the current object is valid and not in a safe empty state
    if(isGood()){
      valid = true;
    } // end if

    // Check if the object is valid and the temp_day is in range
    if( valid == true && in_range == true){
       temp_date.day = temp_day; // If true, set the sum of days to the current object 'day' member.
    } else {
      // If either the sum of days is out of range or the current object is in a safe empty state or holds invalid data, set the status to 'error_invalid_operation'.
      temp_date.status(error_invalid_operation);
    } // end else

    *this = temp_date;

    return *this; // Return the altered object reference
  } // end Date::operator+=(int)

  // Pre-increment operator overload
  Date& Date::operator++() {
    *this += 1;

    return *this;
  } // end Date::opeartor++

  // Post-increment operator overload
  Date Date::operator++(int) {
    Date temp = *this;

    *this += 1;

    return temp;
  } // end Date::opeartor++

  // Sum operator overload
  Date Date::operator+(int right_day) const {
    Date temp = *this; // Temporary object to hold the sum.

    temp += right_day; // Add the days by using the overloaded += operator, which checks for safe empty state and valid ranges.

    return temp; // Return the temmporary object with the added days.
  } // end Date::opeartor++

  // Equal comparisson operator overload
  bool Date::operator==(const Date& rhs) const {

    // Control variables
    bool is_equal = false; // Tells if both objects are storing the same date
    Date temp = *this;

    // If both dates day, month and year are equal, change control variable 'is_equal' to 'true'
    if( temp.day == rhs.day && temp.month == rhs.month && temp.year == rhs.year ){
      is_equal = true;
    } // end if

    return is_equal; // Return true if equal or false otherwise
  } // end Date::opeartor==

  // Different comparisson operator overload
  bool Date::operator!=(const Date& rhs) const {

    // Check if both objects are equal and store the oposite value.
    bool is_different = (*this == rhs) ? false : true;

    return is_different; // Return true if both objects are different or true otherwise
  } // end Date::opeartor!=

  // Lesser than operator overload
  bool Date::operator<(const Date& rhs) const {

    // Control variables
    bool is_lesser = false; // Boolean variable that will tell if the current object is lesser than the matching object
    Date current_date = *this; // Temporary object that will hold the current object's values.

    // If current date year is lesser than the matching year, change the control variable is_lesser to true.
    if( current_date.year < rhs.year ){
      is_lesser = true;
    } else if ( current_date.year == rhs.year && current_date.month < rhs.month) {
      // If current year is equal to rhs year and current month is lesser than rhs month
      // Change control variable is_lesser to true.
      is_lesser = true;
    } else if ( current_date.month == rhs.month && current_date.day < rhs.day) {
      // If current month is equal to rhs month and current day is lesser than rhs day
      // Change control variable is_lesser to true.
      is_lesser = true;
    } //end else

    // If no condition was met, the current date is greater than rhs. In that case, the control variable will hold false.
    return is_lesser; // Return true if current date is lesser than rhs date or false otherwise.

  } // end Date::opeartor<

  // Greater than operator overload
  bool Date::operator>(const Date& rhs) const {

    // Control variables
    Date current_date = *this;
    bool is_greater = false; // Tells if the current object stored date is greater than the rhs date

    // Check if both objects store the same date.
    if(current_date != rhs){ // If both dates are not the same, check if current date is lesser than rhs date.
      is_greater = (*this < rhs) ? false : true; // Store the opposite boolean value of the comparisson in the control variable.
    } // end if

    return is_greater; // Return true if current date is greater than rhs date, and false otherwise
  } // end Date::opeartor>

  // Lesser than or equal comparison operator overload
  bool Date::operator<=(const Date& rhs) const {

    bool is_lesser_or_equal = false; // Tells if the current date is lesser or equal to rhs date

    // Checks if both dates are equal or if current date is lesser than rhs date.
    if(*this < rhs || *this == rhs){
      is_lesser_or_equal = true; // If equal or lesser, change the control variable to true.
    } // end if

    return is_lesser_or_equal; // Return true if both dates are equal or if current date is lesser than rhs date. Returns false otherwise.
  } // end Date::opeartor<=

  // Greater than or equal comparison operator overload
  bool Date::operator>=(const Date& rhs) const {

    bool is_greater_or_equal = false; // Tells if the current date is greater or equal to rhs date

    // Checks if both dates are equal or if current date is greater than rhs date.
    if(*this > rhs || *this == rhs){
      is_greater_or_equal = true; // If equal or greater, change the control variable to true.
    } // end if

    return is_greater_or_equal; // Return true if both dates are equal or if current date is greater than rhs date. Returns false otherwise.
  } // end Date::opeartor>=

  // Function that reads a formatted date from the input stream.
  istream& Date::read(istream& is){

    // Control variables that will hold the inputted values from the input stream
    int temp_year = 0;
    int temp_month = 0;
    int temp_day = 0;

    // Reads the input buffer
    is >> temp_year;

    if( is.fail() == false ){
      is.ignore();
      is >> temp_month;
    } else {
      is.ignore(2000, '\n');
      setSafe();
      status(error_input);
    } // end else

    if( is.fail() == false ){
      is.ignore();
      is >> temp_day;
    } else {
      is.ignore(2000, '\n');
      setSafe();
      status(error_input);
    } // end else

    // If the reading is successfull, set the object member values accordingly and the error status to 'no_error'
    if( is.fail() == false ){
      *this = Date(temp_year, temp_month, temp_day);
    } else {
      is.clear();
      is.ignore(2000, '\n');
      setSafe();
      status(error_input);
    } // end else

    return is; // Return the istream object reference
  }

  // Function to write a formatted date as YYYY/MM/DD
  ostream& Date::write(ostream& os) const{

    os.width(4);
    os.fill('0');
    os << year;

    os.fill(' ');
    os << "/";

    os.width(2);
    os.fill('0');
    os.setf(ios::right);
    os << month;

    os.fill(' ');
    os << "/";

    os.width(2);
    os.fill('0');
    os << day;

    os.fill(' ');
    os.unsetf(ios::right);
    return os;
  }

  // Input operator overload
  istream& operator>>(istream& is, Date& dt){
    dt.read(is);
    return is;
  }

  // Output operator overload
  ostream& operator<<(ostream& os, const Date& dt){
    dt.write(os);
    return os;
  }

} // end namespace
