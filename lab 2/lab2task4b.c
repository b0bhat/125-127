#include <stdio.h>

int scrambled( unsigned int arr1[], unsigned int arr2[], unsigned int len ) {
  int test1[100] = {0};
  int test2[100] = {0};
  for(int i=0; i<len; i++ ) {
    test1[arr1[i]]++;
    test2[arr2[i]]++;
  } for(int j=0; j<100; j++ ) {
      if (test1[j] != test2[j]) return 0;
  } return 1;
}

int main( void )
{
  unsigned int arr1[2] = {48, 14};
  unsigned int arr2[2] = {48, 14};

  if( scrambled( arr1, arr2, 2 ) == 1 )
  {
     printf( "arr2 is a scrambled version of arr1\n" );
  } else {
     printf( "arr2 has different contents to arr1\n" );
  }

  return 0;
}
