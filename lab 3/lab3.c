#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

uint8_t get_pixel( const uint8_t array[],
           unsigned int cols,
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}

void set_pixel( uint8_t array[],
        unsigned int cols,
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
}


void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{

  memset( array, 0, cols * rows * sizeof(array[0]) );
}

uint8_t* copy( const uint8_t array[],
           unsigned int cols,
           unsigned int rows )
{

  int i;
  uint8_t* a=malloc( sizeof(uint8_t)*cols*rows);
  if (a == NULL)
  {
    return NULL;
  }

  else
  {
    for (i=0;i<cols*rows;i++)
    {
      a[i]=array[i];
    }
    return a;
  }
}

uint8_t min( const uint8_t array[],
	     unsigned int cols,
	     unsigned int rows )
{
  int i;
  uint8_t minn=array[0];
  for (i=0;i<cols*rows;i++)
  {
    if (array[i]<=minn)
    {
      minn = array[i];
    }

  }
  return minn;

}

uint8_t max( const uint8_t array[],
		 unsigned int cols,
		 unsigned int rows )
{
  // your code here
  int i;
  uint8_t maxx=0;
  for (i=0;i<cols*rows;i++)
  {
    if (array[i]>=maxx)
    {
      maxx = array[i];
    }

  }
  return maxx;
}

void replace_color(  uint8_t array[],
		     unsigned int cols,
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color )
{
  int i;
  for (i=0;i<cols*rows;i++)
  {
    if (array[i]==pre_color)
    {
      array[i]=post_color;
    }
  }
}

void flip_horizontal( uint8_t array[],
              unsigned int cols,
              unsigned int rows )
{
  int i,j;
  uint8_t tmp;
  for (i=0;i<rows;i++)
  {
    if (cols%2==0)
    {
      for(j=0;j<cols/2;j++)
      {
        tmp=array[i*cols+j];
        array[i*cols+j]=array[(i+1)*cols-(j+1)];
        array[(i+1)*cols-(j+1)]=tmp;
      }
    }
    else
    {
      for(j=0;j<(cols-1)/2;j++)
      {
        tmp=array[i*cols+j];
        array[i*cols+j]=array[(i+1)*cols-(j+1)];
        array[(i+1)*cols-(j+1)]=tmp;
      }
    }
  }
}

void flip_vertical( uint8_t array[],
            unsigned int cols,
            unsigned int rows )
{
  int i,j;
  uint8_t tmp;
  for (i=0;i<cols;i++)
  {
    if (rows%2==0)
    {
      for(j=0;j<rows/2;j++)
      {
        tmp=array[j*cols+i];
        array[j*cols+i]=array[(rows-j-1)*cols+i];
        array[(rows-j-1)*cols+i]=tmp;
      }
    }
    else
    {
      for(j=0;j<(rows-1)/2;j++)
      {
        tmp=array[j*cols+i];
        array[j*cols+i]=array[(rows-j-1)*cols+i];
        array[(rows-j-1)*cols+i]=tmp;
      }
    }
  }
}

int locate_color(  const uint8_t array[],
		   unsigned int cols,
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
  int i,j;
  for (i=0;i<rows;i++)
  {
    for (j=0;j<cols;j++)
    {
      if (array[i*cols+j]==color)
      {
        *x=j;
        *y=i;
        return 1;
      }
    }
  }
  return 0;
}

void invert( uint8_t array[],
         unsigned int cols,
         unsigned int rows )
{
  int i,j;
  for (i=0;i<rows;i++)
  {
    for (j=0;j<cols;j++)
    {
      array[i*cols+j]=255-array[i*cols+j];
    }
  }
}

void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
  int k;
  for (int i=0;i<cols*rows;i++)
  {
    k=round(scale_factor*array[i]);
    if (k>=255)
    {
      array[i]=255;
    }
    else
    {
      array[i]=k;
    }

  }
}

void normalize( uint8_t array[],
        unsigned int cols,
        unsigned int rows )
{
  int i;
  unsigned int cc=cols;
  unsigned int rr=rows;

  uint8_t arr[rr*cc];
  for (i=0;i<rr*cc;i++)
  {
    arr[i]=array[i];
  }
  int x=max(arr,cc,rr);
  int n=min(arr,cc,rr);
  for (i=0;i<rows*cols;i++)
  {
    array[i]=array[i]-n;

  }

  for (i=0;i<rows*cols;i++)
  {
    array[i]=round(array[i]*255.0/(x-n));
  }

}

uint8_t* half( const uint8_t array[],
	       unsigned int cols,
	       unsigned int rows )
{
  int ncols,nrows;
  if (cols%2!=0)
  {
    ncols=cols-1;
  }
  else
  {
    ncols=cols;
  }
  if (rows%2!=0)
  {
    nrows=rows-1;
  }
  else
  {
    nrows=rows;
  }
  int i,j,a,b;
  int k=0,sum=0;

  uint8_t* new=malloc(sizeof(uint8_t)*(cols/2)*(rows/2));
  for (i=0;i<nrows-1;i+=2)
  {
    for (j=0;j<ncols-1;j+=2)
    {

      for (a=0;a<2;a++)
      {
        for (b=0;b<2;b++)
        {
          sum+=array[(i+a)*cols+j+b];
        }
      }
      new[k]=round(sum/4.0);
      k++;
      sum=0;
    }
  }
  return new;


}

void region_set( uint8_t array[],
         unsigned int cols,
         unsigned int rows,
         unsigned int left,
         unsigned int top,
         unsigned int right,
         unsigned int bottom,
         uint8_t color )
{
  int i,j;
  for (i=0;i<rows;i++)
  {
    if (left==right || top==bottom)
    {
      break;
    }
    for (j=0;j<cols;j++)
    {
      if (i>=top && i<=bottom-1)
      {
        if (j>=left && j<=right-1)
        {
          array[i*cols+j]=color;
        }
      }
    }
  }

}

unsigned long int region_integrate( const uint8_t array[],
                    unsigned int cols,
                    unsigned int rows,
                    unsigned int left,
                    unsigned int top,
                    unsigned int right,
                    unsigned int bottom )
{
  int i,j,sum=0;
  for (i=0;i<rows;i++)
  {
    if (left==right || top==bottom)
    {
      sum=0;
      break;
    }

    for (j=0;j<cols;j++)
    {
      if (i>=top && i<=bottom-1)
      {
        if (j>=left && j<=right-1)
        {
          sum+=array[i*cols+j];
        }
      }
    }
  }
  return sum;

}

uint8_t* region_copy( const uint8_t array[],
              unsigned int cols,
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{
  int i,j,k=0;
  uint8_t* regcopy=malloc( sizeof(uint8_t)*(right-left)*(bottom-top));
  if (left==right || top==bottom)
  {
    return NULL;
  }

  else
  {
    for (i=0;i<rows;i++)
    {
      for (j=0;j<cols;j++)
      {
        if (i>=top && i<=bottom-1 )
        {
          if (j>=left && j<=right-1 )
          {
            regcopy[k]=array[i*cols+j];
            k++;
          }
        }
      }
    }

    return regcopy;
  }



}
