#include <stdio.h>

int findMode(int* intArr, int n) {
  int temp[100] = {0};
  for(int i=0; i<n; i++ ) {
    temp[intArr[i]]++;
  }
  int largestnum = 0;
  int largestvalue = 0;
  for(int i=0; i<100; i++ ) {
    if (temp[i] >= largestnum) {
      if (i > largestvalue) {
        largestvalue = i;
        largestnum = temp[i];
      }
    }
  } return largestvalue;
}
