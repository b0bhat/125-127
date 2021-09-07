#include <stdio.h>

int main(void) {
  int input;
  float count = 0;
  int output[26] = {0};
  while ( (input = getchar()) != EOF ) {
    if (input >='A' && input<='Z') output[(input)-65]++;
    if (input >='a' && input<='z') output[(input)-97]++;
    if ((input >='a' && input<='z') || (input >='A' && input<='Z')) count++;
  } for (int i = 0; i < 26; i++) {
    if (output[i] != 0) printf("%c %0.4f\n",i+97, output[i]/count);
  }
}
