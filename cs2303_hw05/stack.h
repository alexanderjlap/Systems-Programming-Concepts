/**
 * @purpose Header file for the implementation of the stack data structure
 *
 * @author Alexander Lap
 *
 */
#ifndef STACK_H
#define STACK_H

/**
 * @purpose A struct to make a dynamic size stack
 * @note Because this struct utilizes FAM, sizeof(stack) won't give the real size of the stack. 
 * */
typedef struct stack {
  int num_elements;         /**< When the stack is empty, there are 0 elements. */
  int max_elements;         /**< Array's size of items */
  void **top;               /**< Ptr to empty slot at top of stack at this time */
  void **base;              /**< Ptr to base (bottom) of stack*/
  void *elements[];          /**< These are the things that are kept in the stack. */
} Stack;

/** Prototypes of functions for stack operations.
 */
void * peek (Stack *stack);
void * pop (Stack *stack);
void * push (Stack *stack, void *element);
int isempty (Stack *stack);
int numelements (Stack *stack);
int maxelements (Stack *stack);
Stack * create (int max_elements);
void destroy (Stack *stack);


#endif
