/**
 * @purpose Stack implementation support functions. Every component of the stack is a * pointer to void. This makes it possible to store any kind of item on the stack.
 *
 * @author Alexander Lap
 */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

/** 
 * @purpose Function for building stacks at a certain height. Each stack action requires the returned Stack structure to specify the stack and its state.
 *
 * @return Stack structure pointer, or NULL on error.
 */
Stack * create ( int max_elements ) {
  Stack * stack = NULL;

  // Set aside memory for the stack's identification structure and its current state.
  // In case of a faulty allocation, check and return NULL.
  stack = (Stack *) calloc (1, sizeof(Stack) + sizeof(void *) * max_elements);
  if (stack == NULL) {
    return stack;
  }

  // Initialize top and base to start of ELEMENTS.
  stack->top = stack->base = (void*)stack->elements;

  stack->max_elements = max_elements;

  return stack;
}

/** 
 * @purpose Stack destruction and heap resource return functions. Notice that while the memory for the stack struct, which is used to keep track of the configuration of the stack, is returned to the heap, the memory for any potential elements that may already be present in the stack is not released.
 *
 * @param A pointer to the stack struct is called stack. Upon function return, invalid.
 * @return none.
 */
void destroy (Stack *stack) {
  free (stack);
  return;
}

/** 
 * @purpose Determines whether the stack is empty using a function. Returns non-zero if empty.
 *
 * @param A pointer to the stack is a stack.
 * @return Non-zero is true if false (zero) or not empty.
 */
int isempty(Stack *stack) {
  // The stack cannot be empty if there are elements in it.
  return (!numelements(stack));
}

/** 
 * @purpose Function that gives the amount of elements in the stack at the moment
 *
 * @param A pointer to the stack is called stack.
 * @return The number of pieces in the stack at this time.
 */
int numelements(Stack *stack) {
  return stack->num_elements;
}

/** 
 * @purpose Function that calculates how many elements the stack may hold in total
 *
 * @param A pointer to the stack is called stack.
 * @return The most items a stack can accommodate.
 */
int maxelements (Stack *stack) {
  // We presume stack is not bigger than what a signed int can represent.
  return stack->max_elements;
}

/** 
 * @purpose Function to support peeking at the current top of stack. This function
 * will return the top element of the stack without removing it from the stack.
 * the state of the stack will not be changed by this function.
 *
 * @param A pointer to the stack is called stack
 * @return The stack's topmost element, or null if the stack is empty.
 */
void * peek (Stack *stack) {
  // If stack is empty, nothing will be returned.
  if (stack->num_elements == 0) {
    return (void *) NULL;
  }

  // Not empty, the stack. the top element is at the previous address since the top pointer points to the following empty slot.
  void **top_element;
  top_element = stack->top;
  top_element--;
  return (*top_element);
}

/**
 * @purpose Pop the top stack element using this function, then return to the caller. By doing this, the stack's state will change and the top element will be removed. Modified top of stack pointer (moved) For simplicity of debugging, the top element of the stack is deleted, and the top slot (where the element was) is set to NULL. The number of elements in the stack is then decreased by one.
 *
 * @param A pointer to the stack is called stack
 * @return The stack's top element, or null if the stack is empty.
 */
void * pop (Stack *stack) {
  // If stack is empty, nothing will be returned.
  if (stack->num_elements == 0) {
    return (void *) NULL;
  }

  // Not empty, the stack. the top element is at the previous address since the top pointer points to the following empty slot.
  void *top_element;
  stack->top--;
  top_element = *(stack->top);
  *(stack->top) = (void *) NULL;
  stack->num_elements--;
  
  return (top_element);
}

/** 
 * @purpose Function to stack an element. Upon success, a pointer to the top element of the stack is given. The element won't be added to the stack if it is already full; instead, NULL will be returned. a new element is added to the stack at the top position (pointer to by top) modified top of stack pointer (moved to next position)
The number of stack elements is increased by one.
 *
 * @param A pointer to the stack is called stack.
 * @param Element points to the element that should be pushed into the stack, which is a pointer to void.
 * @return A NULL value in case of failure, or a pointer to the element pushed into the stack.
 */
void * push (Stack *stack, void *element) {
  // We cannot add more items to the stack if it is full size_t maxelements = sizeof(stack->elements) / sizeof(void *);

  if (stack->max_elements == stack->num_elements) {
    return (void *) NULL;
  }

  // Space is available on the stack. Adjust the top pointer and the element count by pushing the element.
  *(stack->top) = element;
  stack->top++;
  stack->num_elements++;

  return element;
}
