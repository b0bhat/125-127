#include <stdio.h>

int main(void) {
  int input;
  int values[80] = {0};
  int output[2000];
  int count = 0;
  int largest = 0;
  int prev = 0;
  int n = 0;
  while ( (input = getchar()) != EOF ) {
    if ((input != 32) && (input != '\n')) {
      input = input - '0';
      if ((prev != 32) && (prev != '\n') && (count != 0)) {
        input = (prev*10) + input;
        count--;
      } if (input > largest) largest = input;
      values[count] = input;
      count++;
    } prev = input;
  } int m = largest;
  for (int i = 0; i < m; i++) {
    for (int k = 0; k < count; k++) {
      if (values[k] >= largest) {
        output[n] = 35;
      } else { output[n] = 32;}
      n++;
    } largest--;
    output[n] = 32;
    output[n+1] = 10;
    n += 2;
  } return output;
}
