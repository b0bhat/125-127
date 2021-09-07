#include <stdio.h>
#include <math.h>

int main( void ) {
  int input;
  int count;
  int rval;
  while ((rval = scanf("%d", &input)) != EOF) {
    if (rval == 0) {
      break;
    }
    for(count = 0; count < input; count++) {
      printf("#");
    }
    if (count == input) {
    printf("\n");
    }
  }
}
