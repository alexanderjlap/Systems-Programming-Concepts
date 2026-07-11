#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "user.h"

#define INT_MAX (3000)
#define ARR_MAX (10)


/** Generates pseudo-random integers 
 * within the range specified.
 *
 * @return value The random integer generated.
 */

int randInt() {

  int value; /* stores randomly generated integer */
 
  /* generates a random integer corresponding to uppercase ASCII chars, inclusive */
  value = ( rand() % (INT_MAX + 1));

  return value; /* returns the random integer */

} /* end function randInt */


/** Generates pseudo-random integers 
 * within the range of uppercase ASCII chars.
 * Generator is seeded in randFill,
 * in order to produce more random integers.
 *
 * @return letter The randomly generated integer for uppercase ASCII chars.
 */

int randCharInt() {

  int letter; /* stores randomly generated integer */
 
  /* generates a random integer corresponding to uppercase ASCII chars, inclusive */
  letter = (65 + rand() % (26));

  return letter; /* returns the random integer */

} /* end function randInt */


/** Takes in an array, the size of the array, and a specified maximum,
 * and fills the array with randomly generated integers, produced
 * by randInt function. When the array  is full, the array is printed,
 * then sorted, then printed again.
 *
 * @param r Array to be filled with random integers.
 * @param array_size The defined size of the array.
 * @param max The specified maximum value in the random generator's range.
 *
 * @return a The character array filled with random chars.
 */

char *randFill() {

  int j = 0; /* loop counter */
  char* a = (char*) malloc(ARR_MAX + 1);
  char* p1 = a;
  
  /* loop until the max number of elements is reached */
  while( j < ARR_MAX ) {
    j++; /* advance to next element in array */
    *(p1++) = (char) randCharInt(); /* fill array with randomly gen. chars */
  }
  *p1 = '\0'; /* add the null terminator */

  return a;

} /* end function randFill */
