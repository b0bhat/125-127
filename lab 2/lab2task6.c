#include <stdio.h>

int main( void ) {
  unsigned long int charcount = 0;
  unsigned long int wordcount = 0;
  unsigned long int linecount = 0;
  char input;
  char oldn = '\n';
  int oldw = 1;
  while ( (input = getchar()) != EOF ) {
      charcount++;
    if ((((input < 65) || ((input < 97) && (input > 90))) && (input != 39)) && (oldw != 1) && (oldn != '\n')) {
      wordcount++;
      oldw = 1;
    } else if ((((input > 65) && (input < 90)) || ((input > 97) && (input < 123))) || (input = 39)) {
      oldw = 0;
    }
    if ((input == '\n')) linecount++;
    oldn = input;
  } printf( "%lu %lu %lu\n", charcount, wordcount, linecount );
}
