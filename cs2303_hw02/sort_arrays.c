#include "sort_arrays.h"

/**
 *@purpose Makes use of the bubble sort sorting 
 *technique to order an array of integers. This 
 *function performs the operation in place, which 
 *means that the input array will be replaced.
 *
 *@param unsorted[] Unsorted array
 *@param size Size of the input array
 */

void bubble_sort(int unsorted[], size_t size) {
  int i, j;
  int k = 0;
  for (j = size; j > 0; j--) {
    for (i = 1; i < j; i++) {
      if (unsorted[i] > unsorted[i - 1]) {
	k = 1;
	int tmp = unsorted[i - 1];
	unsorted[i - 1] = unsorted[i];
	unsorted[i] = tmp;
      }
    }

    if (k == 0) break; // Breaks the code if sorted
  }
}

/**
 *@purpose Creates an array of random numbers with the *length and range of your choosing (inclusive)
 *
 *@param dest[] Destination array for created random
 *array
 *@param min Minimum range for random numbers
 *@param max Maximum range for random numbers
 *@param size of chosen array
 */

void generate_rand_array(int dest[], int min, int max, size_t size) {
  int i;
  for (i = 0; i < size; i++) {
    dest[i] = generate_rand_int(min, max);
  }
}

/**
 *@purpose Creates a random number with a min-max
 *inclusive range.
 *
 *@param min Minimum of the random range
 *@param max Maximum of the random range
 */

int generate_rand_int(int min, int max) {
  return (rand() % (max + 1 - min)) + min;
}
