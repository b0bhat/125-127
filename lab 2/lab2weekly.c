#include <stdio.h>

int countEven(int arr[],int size) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 == 0) count++;
  } return count;
}


int main() {
  int intArray[8] = {2, 4, 6, 1, 7, 8, 5, 3};
  int numberOfEven = countEven(intArray, 8);
  printf("The number of even numbers in the int array is: %d\n", numberOfEven);
  return 0;
}
