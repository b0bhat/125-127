#include <stdio.h>

int scrambled( unsigned int arr1[], unsigned int arr2[], unsigned int len ) {
  int cur1 = 0;
  int cur2 = 0;
  int same1 = 0;
  int same2 = 0;
  for(int i=0; i<len; i++ ) {
    for(int j=0; j<len; j++ ) {
      if (arr1[i] == arr2[j]) {
        cur1 = 1;
        same1++;
      } if (arr2[i] == arr1[j]) {
        cur2 = 1;
        same2++;
      }
    } if ((cur1 != 1) | (cur2 != 1)) {
      return 0;
      break;
    } cur1 = 0;
    cur2 = 0;
  } if (same1 != same2) return 0;
  return 1;
}

int main( void )
{
  unsigned int arr1[13] = {44, 14, 44, 43};
  unsigned int arr2[13] = {44, 14, 14, 43};

  if( scrambled( arr1, arr2, 13 ) == 1 )
  {
     printf( "arr2 is a scrambled version of arr1\n" );
  } else {
     printf( "arr2 has different contents to arr1\n" );
  }

  return 0;
}
