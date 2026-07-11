/** file print_arrays.c
 * @author Alexander Lap
 *
 * Functions for printing arrays.
 */

#include "print_arrays.h"
#include <stdio.h>

/** Print an array of ints, one per line.
    @param a Array to print
    @param num_entries Number of entries in the array
*/

void print_int_array(int a[], int num_entries) {
  int i; // Loop counter

  for (i = 0; i <= num_entries; i++) {
    printf("%d\n", a[i]);
  }
}

/**
 *@purpose An array of doubles is printed, one per line.
 *
 *@param a[] printed array
 *@param num_elements Number of elements in a[]
 */

void print_double_array(double a[], int num_entries) {
  int i;

  for (i = 0; i <= num_entries; i++) {
    printf("%f\n", a[i]);
  }
}

/** 
 *@purpose Takes in a command-line-provided array of integers. Ingestion  *of an array from argv into an input array is performed.
 *
 *@param args[] Array is created in argv in main loop
 *@param size Size of the input array
 *@param dest[] Array that will contain the new values
 *
 *return 0 if it works, 1 if it doesn't work
 */

int ingest_array(const char* args[], size_t size, int dest[]) {
  int i;
  for (i = 1; i <= size; i++) {
    dest[i - 1] = atoi(args[i]);
  }

  return 0;
}


