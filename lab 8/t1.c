#include "point_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

void point_array_init( point_array_t* pa ) {
	pa->len = 0;
	pa->reserved = 0;
	pa->points = realloc(pa->points,sizeof(point_t));
}
void point_array_reset( point_array_t* pa ) {
	int k;
	for (k = 0;k < pa->len;k ++){
		pa->points[k].x = 0;
		pa->points[k].y = 0;
		pa->points[k].z = 0;
	} pa->len = 0;
	pa->points = realloc(pa->points,0);
}

int point_array_append( point_array_t* pa, point_t* p ) {
	if (p == NULL) return 0;
	pa->len = pa->len + 1;
	pa->points = realloc(pa->points,sizeof(point_t)*pa->len);
	if (pa->points == NULL) return 1;
	pa->points[pa->len-1].x = p->x;
	pa->points[pa->len-1].y = p->y;
	pa->points[pa->len-1].z = p->z;
  return 0;
}

int point_array_remove( point_array_t* pa, unsigned int i ) {
	if (i >= pa->len) return 1;
	pa->points[i].x = pa->points[pa->len-1].x;
	pa->points[i].y = pa->points[pa->len-1].y;
	pa->points[i].z = pa->points[pa->len-1].z;
	pa->len = pa->len-1;
	pa->points = realloc(pa->points,sizeof(point_t)*pa->len);
	return 0;
}
