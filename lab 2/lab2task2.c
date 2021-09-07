#include <stdio.h>

int identical( int arr1[], int arr2[], unsigned int len ) {
  int yes = 1;
  for(int i=0; i<len; i++ ) {
    if (arr1[i] != arr2[i]) {
    yes = 0;
    }
  }
  return yes;
}

int main( void )
{
   int arr1[20] = {98};
   int arr2[20] = {5};

   if( identical( arr1, arr2, 1 ) == 1 )
   {
      printf( "arr1 and arr2 are identical\n" );
   }  else {
      printf( "arr1 and arr2 are NOT identical\n" );
   }

   return 0;
}
