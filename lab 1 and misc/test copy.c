#include <stdio.h>

int main( void )
{
  int input;
  while (1) {
    if (scanf("%d", &input) != 0) {
      for (int i = 0; i < input; ++i) {
        printf("#");
      } printf("\n");
    }
  }
  return 0;
}
