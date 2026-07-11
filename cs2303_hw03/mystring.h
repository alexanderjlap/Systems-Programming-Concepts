/** mystring.h
 * @author Alexander Lap
*/
#include <stdlib.h>
#include <string.h>

char* mystrdup(const char* src);
char* mystrndup(const char *s, size_t n);

size_t mystrlen(const char* s);

char* mystrcpy(char* dst, const char * src);
char* mystrncpy(char* destination, const char* source, size_t num);

char* mystrncat(char* destination, const char* source, size_t num);
char* mystrcat(char* destination, const char* source);
