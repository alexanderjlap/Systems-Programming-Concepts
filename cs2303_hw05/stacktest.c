/**
 * @purpose A quick program that stacks strings and pops them off
 *
 * @author Alexander Lap
 */

#include <stdio.h>
#include <stdlib.h>
#include <readline/history.h>
#include <readline/readline.h>
#include "stack.h"


#define MAXLINE (4096)

/** 
 * @purpose How to use a stack.
 * @return On success, output 0.
 * @return 1 for invalid stack size or arguments.
 */
int main (int argc, char *argv[]) {
  if(argc != 2){
    printf ("Just one parameter should be entered into the command line.\n");
    return 1;
  }

  int user_size = atoi(argv[1]); // Get user size from the first input arg.

  if(user_size < 0){
    printf ("You have entered %d but max_elements must be >= 0!\n", user_size);
    return 1;
  }

  Stack *the_stack; // Make a stack to house the test results.
  the_stack = create( user_size ); // Set stack size to a user-defined value.

  if(the_stack == NULL){
      printf("Lack of room to build a stack!\n");
      return 1;
  }

  #ifdef DEBUG_TEST
    printf("Add strings in lines to the stack. To stop, press CTRL + D.\n");
  #endif

  ssize_t buff_size = MAXLINE; // Maximum line length in a Unix terminal.
  char ** buffers = calloc(user_size, MAXLINE); 
    // Allocated array of strings in the array with dyn in it.

  if(buffers == NULL){
      printf("Not enough room to set up an array of buffers.\n");
      return 1;
    }

  size_t buff_idx; // Loop with counter.

  // When the maximum number of elements in the stack is reached or when getline is null, this loop ends.
  for(buff_idx = 0; 
    getline(&buffers[buff_idx], &buff_size, stdin) != -1 
    && buff_idx < user_size; buff_idx++){
   
    #ifdef DEBUG_TEST
      printf("Pushing elements \"%s\"\n", buffers[buff_idx]);
    #endif

    push(the_stack, buffers[buff_idx]); //push line into stack

    #ifdef DEBUG_TEST
      printf("Currently at the top of the stack \"%s\"\n", (char *) peek(the_stack));
    #endif
  }

  // Now remove the components from the stack.
  while (!isempty(the_stack)) {
    char *element = (char *) pop(the_stack);
    #ifdef DEBUG_TEST
      printf("Popped element \"%s\"\n", element);
    #endif
    
    printf("%s", element);
  }
 
  destroy(the_stack); // Free up space on the stack.
  free(buffers);      // Free up space in the buffer array.

  return 0;
}
