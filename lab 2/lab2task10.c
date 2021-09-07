#include <stdio.h>

int InRectangle( float pt[2], float rect[4] ) {
  if (((rect[0] <= pt[0]) && (rect[2] >= pt[0])) || ((rect[2] <= pt[0]) && (rect[0] >= pt[0]))) {
    if (((rect[1] <= pt[1]) && (rect[3] >= pt[1])) || ((rect[3] <= pt[1]) && (rect[1] >= pt[1]))) return 1;
  } return 0;
}

//if (((rect[0] <= pt[0]) && ((rect[2]) >= pt[0])) && ((rect[1] <= pt[1]) && ((rect[3]) >= pt[1]))) return 1;
//if (((rect[2] <= pt[0]) && ((rect[0]) >= pt[0])) && ((rect[3] <= pt[1]) && ((rect[1]) >= pt[1]))) return 1;
//if (((rect[0] <= pt[0]) && ((rect[2]) >= pt[0])) && ((rect[3] <= pt[1]) && ((rect[1]) >= pt[1]))) return 1;
//if (((rect[2] <= pt[0]) && ((rect[0]) >= pt[0])) && ((rect[1] <= pt[1]) && ((rect[3]) >= pt[1]))) return 1;


int main( int argc, char* argv[] )
{
  // define a rectangle from (1,1) to (2,2)
  float rect[4] = {11.22,89.833618,53.41,96.22};

  // define a point that is inside the rectangle
  float p[2] = {26.35,90.611922};


  // InRectangle() should return 0 (false) for points that are NOT in
  // the rectangle, and non-zero (true) for points that are in the
  // rectangle. Points on the edge are considered *in* the rectangle.

  // test 1
  if( InRectangle( p, rect ) == 1 )
  {
    puts( "true\n" );
    return 1; // indicate error
  } else {
    puts( "false\n");
  }

  return 0; // all tests passed
}
