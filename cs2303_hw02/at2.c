/** file at.c
 * @author Alexander Lap
 *
 * Program to demonstrate fixed-size arrays in C.
 */

#include "print_arrays.h"
#include "sort_arrays.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *@purpose At2 accepts an array of integers of any size, primes them, and *then arranges them. Next, the sorted array is printed.
 *
 *@param argc Counts arguments
 *@param argv[] Makes arguments
 *
 *@return 0 if it works, 1 if it doesn't work
 */

int main(int argc, const char* argv[]) {
  if (argc < 2) {
    printf("You need to enter a number on the command line!\n");
    return 1;
  }

  int out[argc - 1];
  ingest_array(argv, argc - 1, out);
  printf("Unsorted array:\n");
  print_int_array(out, argc - 1);
  bubble_sort(out, argc - 1);
  printf("Sorted array:\n");
  print_int_array(out, argc - 1);
  return 0; // Success!
}

