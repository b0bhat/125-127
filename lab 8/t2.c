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

void point_array_reset( point_array_t* pa ){
	for (int i = 0;i < pa->len;i++) {
		pa->points[i].x = 0;
		pa->points[i].y = 0;
		pa->points[i].z = 0;
	}
	pa->len = 0;
	pa->reserved = 0;
	pa->points = realloc(pa->points,0);
}

int point_array_append( point_array_t* pa, point_t* p ) {
	if (pa == NULL || p == NULL ) return 1;
	if (pa->len == 0) {
		pa->len=1;
		pa->points = realloc(pa->points,sizeof(point_t)*pa->len*2);
		pa->reserved = 2;
		pa->points[pa->len].x = p->x;
		pa->points[pa->len].y = p->y;
		pa->points[pa->len].z = p->z;
	} else {
		pa->points[pa->len].x = p->x;
		pa->points[pa->len].y = p->y;
		pa->points[pa->len].z = p->z;
		pa->len = pa->len+1;
	} if (pa->reserved == pa->len ) {
		pa->reserved = pa->reserved * 2;
		pa->points = realloc(pa->points,sizeof(point_t)*pa->reserved);
	}	return 0;
}

int point_array_remove( point_array_t* pa, unsigned int i ) {
	if (pa->len == 0 || i >= pa->len) return 1;
	pa->points[i].x = pa->points[pa->len-1].x ;
	pa->points[i].y = pa->points[pa->len-1].y ;
	pa->points[i].z = pa->points[pa->len-1].z ;
	pa->points[pa->len-1].x = 0;
	pa->points[pa->len-1].y =0;
	pa->points[pa->len-1].z =0;
	pa->len = pa->len-1;
	return 0;
}
