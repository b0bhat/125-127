#include <stdio.h>

int main() {
  int ar[4] = {10, 20, 30};
  const int* ptr = ar;
  printf("%d ", *(ptr+1));

  ptr = ptr+1;
  printf("%d", *(ptr+1));

  return 0;
}
