/** file at.c
 * @author Alexander Lap
 *
 * Program to demonstrate fixed-size arrays in C.
 */

#include "print_arrays.h"

#define SAMPLE_INT_ARRAY_SIZE (10)

/** Main program for demonstrating arrays. It fills them and prints them.
 * @return 0, Indicating success.
 */

int main() {
  int i; // Loop counter
  int a[SAMPLE_INT_ARRAY_SIZE]; // Initilize array for integers
  double b[SAMPLE_INT_ARRAY_SIZE]; /* Initialize array to be filled with doubles */

  // Fill the array with consecutive integers
  for (i = 0; i < SAMPLE_INT_ARRAY_SIZE; i++) {
    a[i] = i;
    b[i] = (double)i;
  }

  // Now print it out
  printf("Ten consecutive integers:\n");
  print_int_array(a, SAMPLE_INT_ARRAY_SIZE);
  
  /* Print the array with consecutive doubles */
  printf("Ten consecutive double:\n"); /* Label output */
  print_double_array(b, SAMPLE_INT_ARRAY_SIZE); /* Print func call */
  

  return 0; // Success!
}
