#include <stdio.h>
#include <math.h>
#include <string.h>

int main( void )
{
  int x;
  int y;
  int z;
  int iter = 0;
  char line[1032] = "";
  char output[1032] = "";
  scanf("%i %i %i", &x, &y, &z);
  for(int j = 0; j<z; j++) {
    int left = floor( j * (x/(2.0*z)) );
    int right = ceil( (x-1) + -j * (x/(2.0*z)) );
      for(int k = 0; k<left; k++) strcat(line, " ");
      if (x != 1 && z != 1) strcat(line, "#");
    if (iter == 0 || iter == z-1) {
      for(int k = 0; k<(right-(left+1)); k++) strcat(line, "#");
    } else {
      for(int k = 0; k<(right-(left+1)); k++) {
        strcat(line, ".");
      }
    }strcat(line, "#\n");
    strcat(line, output);
    strcpy(output, line);
    //printf("%i %i %i\n", j, left, right);
    memset(line, 0, sizeof(line));
    iter++;
  }
  printf("%s", output);

}
