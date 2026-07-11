/**
 * @purpose Calculates the overall class average
 * @param grades: Array of grades
 * @param numGrades: Number of grades stored in array
 *
 * @return class average as an integer
 */

#include "calcGrades.h"
#include <stdio.h>

int calcGrades(int grades[], int numGrades) {

  int i;
  double gpa = 0;
  int max = 0;
  int min = 100;
  for (i = 0; i < numGrades; i++) {
    (grades[i] < min) ? min = grades[i] : 1;
    (grades[i] > max) ? max = grades[i] : 1;
    gpa += grades[i];
  }
  gpa = (double)gpa / (double)numGrades;
  printf("GPA: %f\nMax: %d\nMin: %d\n", gpa, max, min);
  return 0;
}
