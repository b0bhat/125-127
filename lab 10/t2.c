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

int Image::save( const char* filename ){
 	if (filename == NULL) return 1;
 	fstream fp;
	fp.open(filename, fstream::out);
 	if (!fp.is_open()) return 1;
 	if ((rows == 0 && cols > 0) || (rows > 0 && cols == 0)) return 1;
 	if (cols == 0 && rows == 0){
 		fp.close();
 		return 0;
 	} int i,j;
 	for (i = 0; i < rows; i++){
 		j=0;
 		for(j = 0; j <c ols; j++) fp<< (int)pixels[i*cols+j]<< " ";
 		fp << endl;
 	} fp.close();
 	return 0;
}

int Image::load( const char* filename ){
 	if (filename == NULL){
		return 1;
	}
	fstream fp;
	fp.open(filename,ios::in);
	if(!fp.is_open()) return 1;
	fp.seekg (0, fp.end);
    int length = fp.tellg();
    fp.seekg (0, fp.beg);
    if (length == 0) {
 		cols = 0;
 		rows = 0;
 		pixels = NULL;
 		fp.close();
    return 0;
 	} int pix;
	int i,total_num=0,cline=0,ccol;
	char line[1000];
	while (!fp.eof()){
		fp >> pix;
		total_num++;
	} total_num = total_num -1;
	fp.clear();
	fp.seekg (0, fp.beg);
	while (!fp.eof()){
		fp.getline(line,1000,'\n');
		cline ++;
	} cline--;
	fp.clear();
	fp.seekg (0, fp.beg);
	if (cline == 0){
		ccol = 0;
		cols = ccol;
		rows = 0;
		if(pixels != NULL){
			delete[] pixels;
			pixels = NULL;
		} fp.close();
		return 0;
	} else{
		ccol = total_num/cline;
		cols = ccol;
		rows = cline;
	} if(pixels != NULL) delete[] pixels;
	pixels = new uint8_t[cols*rows];
	for (i=0; i<total_num; i++){
		fp >> pix;
		pixels[i] = pix;
	} fp.close();
	return 0;

 }
