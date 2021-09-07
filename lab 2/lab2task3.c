l#include <stdio.h>

void* reverse( int arr[], unsigned int len ) {
  int tmp[len];
  for(int i = 0; i < len; i++ ) tmp[len-i-1] = arr[i];
  for(int i = 0; i < len; i++ ) arr[i] = tmp[i];
  return arr;
}

int main( void )
{
  int intArray[] = {11, 12, 13};
  unsigned int len = 3;

  reverse( intArray, len );

  for( unsigned int i = 0; i < len; i++ )
  {
     printf( "%d ", intArray[i] );
  }
  printf( "\n" );

  return 0;
}
