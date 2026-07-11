/** Program to read in public zip code information and store as needed
 * for cs2303 assignment needs.
 *
 * @author Alexander Lap
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <forward_list>
#include "zipfed.hpp"

// Length of the file name or fully qualified path with a null terminating.
#define SZ_FILENAME (129)

/**
 * @purpose Reads a line of data from the US FED and returns a pointer to that line of data as a C-String (i.e. NULL terminated string).
 *
 * @return read number of bytes (chars) or -1 on error.
 */
ssize_t readln_fed (char **lineptr, size_t *n, FILE *stream) {
  ssize_t bytes_read = -1;  // -1 denotes a reading mistake on line.
  const int delim = '\n';   // Each line had a \r\n at the end. 

  // Check that the file is open. 
  if (stream == NULL) {
    return (ssize_t) -1;
  }

  // The FED ZIP CSV file terminates each line with the characters "n" and "r," therefore we read each line up to and including the latter character. 
  bytes_read = getdelim (lineptr, n, delim, stream);

  // Replace the \n\r at the line's end with a NULL terminator to remove it. 
  // The \n\r at the end of a line should be at least 2 characters long. 
  for (int i = bytes_read - 1; i >= 0; i--) {
    if (((*lineptr)[i] == '\n') || ((*lineptr)[i] == '\r')) {
      (*lineptr)[i] = '\0';
    }
  }
    
  return bytes_read;
}


/** 
 * @purpose The command line specifies the names of the input and output files. 
 *
 * @param The input string count (argc) will be 3.
 * @param Argv is an array of command-line arguments for the fed2cs2303 existing input file and output file to create.
 * @return 1 for failure, non-zero for mistakes 
 */
int main (int argc, char *argv[]) {
  char infile[SZ_FILENAME];  // Name/path of the input file.
  char outfile[SZ_FILENAME]; // Name/path of the output file.
  FILE *fdIn;
  FILE *fdOut;

  ssize_t chars_read;        // Amount of characters read for one input line. 
  char *inbuf = NULL;        // Buffering input file with one record per line.
  size_t sz_inbuf = 0;       // Size of the input record at this time.

  std::forward_list<Zipfed *> llist; // Single-linked list of Zipfed instance references.
  
  /* Open the command-line arguments and output files.
   * Using common sense to validate the parameters on a command line.
   */
  if (argc != 3) {
    fprintf(stderr, "usage: %s input_file output_file\n", argv[0]);
    return -1;
  }

  strncpy(infile, argv[1], SZ_FILENAME-1);
  strncpy(outfile, argv[2], SZ_FILENAME-1);

  /* Open the input and output files and send an error if necessary. Input used in reading. Producing writing.
   */
  fdIn = fopen(infile, "r");
  if (fdIn == NULL) {
    fprintf(stderr, "cannot open %s for input - exiting\n", infile);
    return -2;
  }
  fdOut = fopen(outfile, "w");
  if (fdOut == NULL) {
    fprintf(stderr, "cannot open %s for output - exiting\n", outfile);
    fclose(fdIn);
    return -3;
  }

  /* 
   * @purpose The input file has now been looped through to read each line in the format and structure downloaded from the US Government. Next, before writing to the output file, each line is fed into our zip code data structure. 
   */
  // Simply read the first line of input and ignore the column names. 
  chars_read = readln_fed (&inbuf, &sz_inbuf, fdIn);

  // Process each line of the zip code data in CSV format using a loop now. 
  while ((chars_read = readln_fed (&inbuf, &sz_inbuf, fdIn)) != EOF) {
    if (chars_read == 0) {  // not EOF, but nothing to process
      continue;
    }

    // For debugging, write the buffer to stdout. 
#ifdef DEBUG
    printf("inbuf: %s\n", inbuf);
#endif
    
    // We construct a new instance of the Zipfed object, have it parse the input record, and initialize it with the parse result for each input line. 
    // Parsing error is indicated by a nonzero return. 
    Zipfed *pZipfed = new Zipfed();
    if(pZipfed->parse_zip_federal(inbuf) != 0) {
      fprintf (stderr, "failed to process input record - exiting\n");
      fclose (fdIn);
      fclose(fdOut);
      return -4;
    }
    
    // When developing, output the structure to stdout to check for processing. 
    /* printf ("DEBUG: "); */
    /* pZipfed->print(); */

    // If from Massachusetts, add the zip code record to the linked list. 
    if(pZipfed->is_from_MA())
      llist.push_front(pZipfed);
  }

  // Ensure that everything is present by iterating through the list now. Zipprint will print the struct to the output stream. 
  for(std::forward_list<Zipfed *>::iterator it = llist.begin(); it != llist.end(); it++) {
    Zipfed * pTmpZipfed = *it;
    pTmpZipfed->print(fdOut);
  }


  /* Before leaving, free up any memory. Delete the head repeatedly until the list is empty. This code is in charge of releasing the zip code data from the linked list, which will release the node from the list. 
   */
  while (!llist.empty()) {
    llist.pop_front();
  }
    
  return 0;
}	
