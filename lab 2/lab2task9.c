#include <stdio.h>

int main(void) {
  int input;
  int output[80] = {0};
  int count = 0;
  int largest = 0;
  int prev = 0;
  while ( (input = getchar()) != EOF ) {
    if ((input != 32) && (input != '\n')) {
      input = input - '0';
      if ((prev != 32) && (prev != '\n') && (count != 0)) {
        input = (prev*10) + input;
        count--;
      } if (input > largest) largest = input;
      output[count] = input;
      count++;
    } prev = input;
  } int n = largest;
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < count; k++) {
      if (output[k] >= largest) {
        printf("#");
      } else { printf(" ");}
    } largest--;
    printf("%c", 10);
  }
}
