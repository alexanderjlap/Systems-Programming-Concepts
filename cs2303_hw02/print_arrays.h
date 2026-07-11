/** File print_arrays.c
 * @author Alexander Lap 
 *
 * Header file for functions that print arrays.
 */

#ifndef PRINT_ARRAYS_H
#define PRINT_ARRAYS_H
#include <stdio.h>
#include <stdlib.h>

// function prototypes:

void print_int_array(int a[], int size);
void print_double_array(double a[], int size);
int ingest_array(const char* args[], size_t size, int dest[]);

#endif
