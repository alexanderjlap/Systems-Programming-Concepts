/**
 * @purpose The stacktest2 program uses a stack to reorder the characters in a string.
 * @author Alexander Lap
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
		printf ("Just one parameter should be entered into the command line!\n");
		return 1;
	}
	int user_size = atoi(argv[1]);  // Get user_size from the first input arg
	if(user_size < 0){
		printf ("Max elements must be greater than 0 but entered %d!\n", user_size);
		return 1;
	}

	Stack *main_stack; // Make a stack that can accommodate several stacks.
  	main_stack = create( user_size ); // Set stack size to a user_def value.

  	if(main_stack == NULL){
      printf("Insufficient room exists to build main stack.\n");
      return 1;
 	}

  	#ifdef DEBUG_TEST
  		printf("Add strings in lines to the stack. To stop, press CTRL + D.\n");
  	#endif

  	ssize_t buff_size = MAXLINE; // Maximum line length in a Unix terminal.
  	char ** buffers = calloc(user_size, buff_size); 
	// Allocated array of strings in the array with dyn.

  	if(buffers == NULL){
  		printf("Not enough room to set up an array of buffers.\n");
  		return 1;
  	}

  	size_t buff_idx; // Loop with counter.
  	ssize_t buff_line_sz; // Contains the line's actual width.

  	Stack *sub_stack[user_size]; // Contains references to the stack's stacks.


  	// When either getline is null or the maximum number of elements in the stack is reached, this loop ends.
	for(buff_idx = 0; 
		(buff_line_sz = getline(&buffers[buff_idx], &buff_size, stdin)) != -1 
		&& buff_idx < user_size; buff_idx++){
		
		#ifdef DEBUG_TEST
		  printf("Pushing element \"%s\"\n", buffers[buff_idx]);
		#endif

		sub_stack[buff_idx] = create (buff_line_sz); // Make a sub_stack.

		if(sub_stack[buff_idx] == NULL){
			printf("Insufficient room to form a sub stack[%ld]\n", buff_idx);
  			return 1;
		}

		int i; // Counter for temp.
		// Except for "n" and "0," this loop pushes all characters to the sub_stack.
		for(i = 0; i < buff_line_sz; i++){
			if(buffers[buff_idx][i] != '\0' && buffers[buff_idx][i] != '\n'){
				push(sub_stack[buff_idx], &buffers[buff_idx][i]);
			}
		}
	
		push(main_stack, sub_stack[buff_idx]); // Put substack on top of stack.

		#ifdef DEBUG_TEST
		  printf("Currently at the top of the stack \"%s\"\n", (char *) peek(main_stack));
		#endif
	}

 	// Pull the substacks away from the stack now.
	while (!isempty(main_stack)) {
		Stack *sub = (Stack *) pop(main_stack);
		// Remove every character from every sub_stack.
		while(!isempty(sub)){
			char *element = (char *) pop(sub);
			printf("%c", *element);
		}
		printf("\n");
		destroy(sub); // No-cost sub_stack.
	}
	
	destroy(main_stack); // no cost main_stack.
	free(buffers);  // Available buffer array.
}
