#include <stdio.h>
#include <stdlib.h>

int* transposeMatrix(int arr[],  unsigned int h, unsigned int w){
    int* output = malloc(h * w * sizeof(unsigned int));
    int i, j;
    for(i = 0; i < h; ++i) {
      for(j = 0; j < w; ++j) {
        output[i * w + j] = arr[j * h + i];
      }
    }
    return output;
}
