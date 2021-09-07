#include "image.hpp"
#include <iostream>
#include <stdint.h> // for uint8_t
#include <stdlib.h>
#include <stdio.h>
using namespace std;
Image::Image() {
	cols = 0;
	rows = 0;
	pixels = NULL;//
}

 Image::~Image() {
 	if( pixels != NULL )delete[] pixels;
 }

int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolor ){
 	delete[] pixels;
 	uint8_t pixels[width*height];
 	if (pixels == NULL) return 1;
 	int i;
 	for (i=0;i<width*height;i++) pixels[i]=fillcolor;
 	return 0;
 }

int Image::set_pixel( unsigned int x, unsigned int y, uint8_t color ){
 	if (x >= cols || y >= rows ) return 1;
 	pixels[y*cols+x] = color;
 	return 0;
 }

int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp ){
 	if (x >= cols || y >= rows ) return 1;
 	*colorp = pixels[y*cols+x];
 	return 0;
 }
