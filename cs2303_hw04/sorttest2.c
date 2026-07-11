#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

#define VALUE_RANGE (10000)

/* Program which reads numbers from the command line,
 * outputs them, sorts them in descending order, and outputs the sorted list.
 *
 * Usage:
 *         ./sorttest some_number another_number ...
 * Example:
 *         ./sorttest 2014 15 7000
 *
 */

/** Main program
 * @param argc Number of words on the command line
 * @param argv[] Array of character strings, the words from the command line.
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

int main (int argc, const char* argv[]) {

  int *nums; // A place where numbers entered via the command line can be stored.
  int count; // The number of characters that were actually typed into the command line.
  int i; // Lopp multiplier
  char flag; // Order type flag


  if (argc < 2) {
    printf("Must enter a number of values to process. Exiting.\n");
    return 1; // Indicate failure
  }

  // Put the value from the command line into the count variable.
  count = atoi(argv[1]);

  // Give the character entered on the command line the flag variable's value.
  flag = argv[2][0];

  // If reseeding the RNG is indicated, do it.
  if (argc == 4 && argv[3][0] == 's') {
    srand(time(0));
  }
  printf("Flag character is %c\n", flag);

  // Set aside a large enough array to accommodate the numbers.
  nums = (int*) calloc(count, sizeof(int));
  if (nums == NULL) {
    fprintf(stderr, "Unable to allocate enougn memory to hold the numbers.\n");
  }

  /* For every index in the array, produce a random value. */
  for (i = 0; i < count; i++) {
    nums[i] = randomNumber(VALUE_RANGE);
  }

  // Print the array once more after sorting it, then time how long it took to sort it.
  // Determine if the application should use an array or a pointer sort.
  if (flag == 'a') {
    timesort(nums, count, 0);
  }
  else {
    timesort(nums, count, 1);
  }

  return 0; // Indicate success!
}
