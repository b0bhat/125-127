#include <stdio.h>

int main( void )
{
  int x;
  int y;
  scanf("%d %d", &y, &x);
  for(int i = 0; i<x; i++) {
      for(int j = 0; j<y; j++) {
        if (((j != 0) && (j != y-1)) && ((i != 0) && (i != x-1))) {
          printf(".");
        } else {
          printf("#");
        }
      } printf("\n");
  }

}
