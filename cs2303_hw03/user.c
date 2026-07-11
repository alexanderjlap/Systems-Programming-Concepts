#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "rand_funcs.h"


/** Allocates a struct of type User and fills its
 * fields with data passed in as parameters.
 *
 * @param username The username of the user.
 * @param join_year The year in which the user joined.
 * @param num_posts The number of posts the user has made.
 *
 * @return new_u The newly created user struct.
 */

User* make_user( char* username, int join_year, int num_posts ) {
  
  User* new_u; /* define a pointer to the User struct */

  new_u = ( User* ) malloc(sizeof(User)); /* allocate memory for the struct */
  mystrcpy(new_u->username, username); /* set the username field */
  new_u->join_year = join_year; /* set the join_year field */
  new_u->num_posts = num_posts; /* set the num_posts field */

  return new_u; /* return the struct */
} /* end function make_user */


/** Prints a struct passed to the function.
 *
 *@param user The struct to be printed.
 */

void print_struct( User* user ) {

  /* print the three fields of the User struct */
  printf("Username: %s\n", user->username);
  printf("Join Year: %d\n", user->join_year);
  printf("Post Count: %d\n", user->num_posts);

} /* end function print_struct */


/** Creates a struct of type User and fills
 * the struct with random data. A random string,
 * and two random integers are generated in order
 * to fill the struct. The struct is then returned.
 *
 * @param username The randomly generated char array for the username.
 * @param year The randomly generated integer for the join year.
 * @param posts The randomly generated integer for the post count.
 *
 * @return rand_struct The User struct filled with random data.
 */

User* rand_struct() {

  User* rand_user; /* define a pointer to the User struct */

  /* call make_user to generate a struct using the randomly generated data */
  rand_user = make_user(randFill(), randInt(), randInt());

  return rand_user; /* return the pointer to the randomly generated struct */
} /* end function rand_struct */


/** Takes a count value and allocates an array
 * that can hold that many pointers to the struct
 * of type User. Fills each element of the array with
 * a pointer to a new, randomly generated struct.
 *
 * @param count The number of pointers to User struct that the array will hold.
 *
 * @return u1 The array of pointers to struct of type User.
 */

User** count_array( int count ) {

  int i = 0; /* loop counter */

  /* allocate memory w/ calloc to hold count number of ptrs to User structs */
  User** u1 = calloc(count, sizeof(User*));
  User** u2 = u1;

  /* fill array with pointers to User structs until count value is reached */
  while( i < count ) {
    *(u2++) = rand_struct();
    i++;
  } /* end while */

  return u1; /* return the array of pointers to struct of type User */
} /* end function count_array */


/** Takes an array of pointers and a count value
 * and prints out all the structs pointed to in
 * the array.
 *
 * @param uArr The array of pointers to struct of type User.
 */

void print_array(User** uArr, int count) {
  int j; /* counter for loop */

  /* prints each element of the array until last element is processed */
  for ( j = 0; j < count; j++ ) {
    print_struct( *uArr++ ); /* call print_struct to print each struct */
  } /* end for */

} /* end function print_array */


/** Duplicates an array fo pointers to struct
 * of type User. Must determine the # of elements in
 * the array, and size of ememory to be allocated.
 *
 * @param dupArr The array of pointers to struct to be duplicated.
 * @param num_ele The amount of pointers in the array being duplicated.
 */

User** dup_array( User** dupArr, int count ) {
  
  int i = 0;; /* loop counter */

  /* allocate memory for duplicate array using calloc */
  User** new_dup = calloc(count, sizeof(User*));

  User** dup = new_dup; /* assign the allocated array to dup for loop use */

  /* loop until the max number of elements in the array is reached */
  while( i < count) {
    *(dup++) = *(dupArr++);
    i++; /* move to next element in the array */
  } /* end while */

  return new_dup;
} /* end function dup_array */


/** Takes an array of pointers to struct of type User
 * and de-allocates (frees) all the structs pointed to.
 *
 * @param freeArr The array of pointers to struct to be freed.
 */

void free_array( User** freeArr, int count ) {

  /* loop until all the pointers (elements) in the array have been processed */
  while( count-- > 0 ) {
    free(*freeArr++); /* use free() to de-allocate the pointers */
  } /* end while */

} /* end function free_array */
