/** Program demonstrating parsing and linked lists. This program 
 * supports zip code lookup for any town in Massachusetts
 *
 * @author Alexander Lap
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <forward_list>
#include <readline/readline.h>
#include <readline/history.h>
#include <vector>
#include <iostream>
#include "zipfed.hpp"

// Length of the file name or fully qualified path with a null terminating.
#define SZ_FILENAME (129)

// Maximum input line buffer size.
#define MAXLINE (4096)


/** 
 * @purpose The fed2cs2303 zip line reading function returns a pointer to the data line as a C-String (i.e. NULL terminated string) 
 *
 * @return Read number of bytes (chars) or -1 on error.
 */
ssize_t readln_fedcs2303(char **lineptr, size_t *n, FILE *stream) {
  ssize_t bytes_read = -1;  // -1 will signify error reading line
  const int delim = '\n';   // each line terminated with \n

  // Check that the file is open. 
  if (stream == NULL) {
    return (ssize_t) -1;
  }

  // The FED ZIP CSV file terminates each line with an n, thus we read the complete line up to and including the n.
  bytes_read = getdelim (lineptr, n, delim, stream);

  // Replace the n at the line's end with a NULL terminator to remove it. 
  // The n at the end of a line should be at least 2 characters long. 
  for (int i = bytes_read - 1; i >= 0; i--) {
    if ((*lineptr)[i] == '\n') {
      (*lineptr)[i] = '\0';
    }
  }
    
  return bytes_read;
}

/** 
 * @purpose Forward list custom comparator based on zipfed city attr. 
 * @param pZip1 first zipfed object pointed to.
 * @param pZip2 the second zipfed object pointed to.
 * @return true if pZip1.city lex. Less than pZip2.city is false.
 **/
bool comparator_function(Zipfed* pZip1, Zipfed* pZip2) { 
 // If pZip1's city is smaller than pZip2's city, return true; otherwise, return false. 
    return pZip1->get_city().compare(pZip2->get_city()) < 0;
} 

/**
 * @purpose A program to locate the zip code for any Massachusetts town. 
 *
 * @param argc should be 1 if is the number of fields on the command line. 
 * @param argv is an array of strings entered on the command line with the program name.
 * @return Zero for success. One for failing.
 */
int main (int argc, char *argv[]) {
    char infile[SZ_FILENAME];  // Name/path of the input file 
    FILE *fdIn;
    
    ssize_t chars_read;        // Amount of characters read for one input line. 
    char *inbuf = NULL;        // Buffering input file with one record per line.
    size_t sz_inbuf = 0;       // Size of the input record at this time. 

    std::forward_list<Zipfed *> llist; // Single-linked list of Zipfed instance references 

    /* Open the command-line arguments and output files. Using common sense to validate the parameters on a command line 
    */
    if (argc != 2) {
        fprintf(stderr, "usage: %s input_file\n", argv[0]);
        return -1;
    }

    strncpy(infile, argv[1], SZ_FILENAME-1);

    /* Open the input and output files and send an error if necessary. Input used in reading. Producing writing.
    */
    fdIn = fopen(infile, "r");
    if (fdIn == NULL) {
        fprintf(stderr, "cannot open %s for input - exiting\n", infile);
        return -2;
    }

    std::vector<std::string> queries; 
    // This vector includes the cities the user enters. 
    char * buffer = (char *) calloc(1, MAXLINE); 
    // line buffer space allocated dyn. 

    printf("Enter city names line by line: (CTRL+D to stop)\n");

    size_t buff_idx; // Loop with counter.
    // When either of the following occurs: a) getline is null b) the maximum number of elements in the stack.
    for(buff_idx = 0; (buffer = readline("_ ")) != NULL ; buff_idx++){
        queries.push_back(buffer); // Push the city search into the vector.
    }
    printf("\n");
    

    // Process each line of the zip code data in CSV format using a loop now. 
    while ((chars_read = readln_fedcs2303(&inbuf, &sz_inbuf, fdIn)) != EOF) {
        if (chars_read == 0) {  // But nothing to process, nor EOF.
          continue;
        }

        // For debugging, write the buffer to stdout. 
        #ifdef DEBUG
            printf("inbuf: %s\n", inbuf);
        #endif
        
        // We create a new Zipfed object instance for each input line and have the object.
        // Parse the input record, then initialize it with the result of the parsing. 
        // Parsing error is indicated by a nonzero return. 
        Zipfed *pZipfed = new Zipfed();
        if(pZipfed->parse_zip_cs2303(inbuf) != 0) {
          fprintf (stderr, "failed to process input record - exiting\n");
          fclose (fdIn);
          return -4;
        }
        
        // When developing, output the structure to stdout to check for processing.
        /* printf ("DEBUG: "); */
        /* pZipfed->print(); */

        // Whenever a string from the queries vector matches an item, add the city to the linked list.
        if(pZipfed->is_from(queries))
            llist.push_front(pZipfed);
    }

    // Sort the list alphabetically by city name. 
    llist.sort(comparator_function);

    printf("All items from %s were processed successfully!\n\n", infile);

    // Check the list one more time to ensure that everything is present. 
    // Zipprint will output stream the struct. 
    for(std::forward_list<Zipfed *>::iterator it = llist.begin(); it != llist.end(); it++) {
        Zipfed * pTmpZipfed = *it;
        pTmpZipfed->print();
    }


    /* Before leaving, free up any memory. Delete the head repeatedly until the list is empty. This code is in charge of releasing the zip code data from the linked list, which will release the node from the list. 
   */
    while (!llist.empty()) {
        llist.pop_front();
    }

    free(buffer);

    return 0;
}
