/** file at.c
 * @author Alexander Lap
 *
 * Program to demonstrate fixed-size arrays in C.
 */

#include "print_arrays.h"
#include "sort_arrays.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 *@purpose Main purpose of at3 is to produce and print a set of 
 *pseudo-random integers in an array in a given range. It constructs an 
 *array of them with 30 values between the predetermined range of -10 to  *100 inclusive.
 *
 *@return 0 if it works, 1 if it doesn't work
 */

int main(void) {

  srand((int)time(0));
  int test[20];
  generate_rand_array(test, -10, 100, 20);
  printf("Unsorted array:\n");
  print_int_array(test, 20);
  printf("Sorted array:\n");
  bubble_sort(test, 20);
  print_int_array(test, 20);
  return 0; // Success!
}
