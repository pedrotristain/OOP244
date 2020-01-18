/*
	Name:		     Pedro Zelada Souza
	Student#:	   116427188
	E-mail:      pzelada-souza@myseneca.ca
	Sect:		     SHH

	Milestone:   5
*/

// Header safeguards
#ifndef SICT_SORT_H
#define SICT_SORT_H

namespace sict{

  // Template function that sorts an array received as parameter in ascending order.
  template<typename T>
  void sort(T* list, int size){

    int i, j;
    T temp;

    // Iterate through the list array
    for (i = size - 1; i > 0; i--) {
      for (j = 0; j < i; j++) {

        // If the left operando is greater than the right, change their positions.
        if (*list[j] > *list[j+1]) {

          temp      = list[j];
          list[j]   = list[j+1];
          list[j+1] = temp;

        } // end if
      } // end for
    } // end for

  } // end sort(T*, int)

} // end namespace
#endif
