#ifndef USER_H
#define USER_H

/* define the struct User */
typedef struct {
  char username[20]; /* field for username, set to max size of 20 */
  int join_year; /* field for the user's join year */
  int num_posts; /* field for the user's number of posts */
} User;


/* function prototypes */

User* make_user( char* username, int join_year, int num_posts );

void print_struct( User* user );

User* rand_struct();

User** count_array( int count );

void print_array( User** uArr, int count );

User** dup_array( User** dupArr, int count );

void free_array( User** freeArr, int count );

#endif
