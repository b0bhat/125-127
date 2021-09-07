#include <stdio.h>

int multiplyToArray(int arr[], int size, int num) {
  int output = 0;
  for (int i = 0; i < size; i++) {
    arr[i] = arr[i]*num;
    output += arr[i];
  }
  return output;
}

int main() {
  int intArray[8] = {2, 4, 6, 1};
  int sumOfElements = multiplyToArray(intArray, 4, 2);
  printf("The sum of all the elements in the updated int array is: %d\n", sumOfElements);
  return 0;
}
