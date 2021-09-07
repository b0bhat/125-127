#include <stdio.h>

int main( void )
{
  int base = 0;
  int iter = 0;
  int res = scanf("%i", &base);
  if (base > 0) {
    for(int i = 0; i<(base*2)+1; i++) printf("+");
    for(int i = 0; i<base; i++) {
      printf("\n");
      for(int j = 0; j<base-iter; j++) printf("+");
      for(int j = 0; j<1+2*iter; j++) printf(" ");
      for(int j = 0; j<base-iter; j++) printf("+");
      iter++;
    }
    printf("\n");
    for(int i = 0; i<(base*2)+1; i++) printf("+");
  } else printf("Invalid base size: Has to be a positive integer.");
}
