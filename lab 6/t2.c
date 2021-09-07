#include "intarr.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/*
  Save the entire array ia into a file called 'filename' in a JSON
  text file array file format that can be loaded by
  intarr_load_json(). Returns zero on success, or a non-zero error
  code on failure. Arrays of length 0 should produce an output file
  containing an empty array.

  Make sure you validate the parameters before you use them.

  The JSON output should be human-readable.

  Examples:

  The following line is a valid JSON array:
  [ 100, 200, 300 ]

  The following lines are a valid JSON array:
  [
   100,
   200,
   300
  ]
*/
int intarr_save_json( intarr_t* ia, const char* filename ) {
  if ((ia == NULL) || (filename == NULL)) return -1;
  FILE *fp;
  fp = fopen(filename, "a");
  if (fp == NULL) {
    fclose(fp);
    return -1;
  } fprintf(fp,"[");
  for (int i=0;i<ia->len;i++) {
    fprintf(fp," %d",ia->data[i]);
    if (i!=ia->len-1) fprintf(fp,",");
  } fprintf(fp," ]");
  fclose(fp);
  return 0;
}


/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.

  Make sure you validate the parameter before you use it.
*/
intarr_t*  intarr_load_json( const char* filename ) {
  if (filename == NULL) return NULL;
  FILE *fp;
  fp = fopen(filename, "r");
  if (fp == NULL) return NULL;
  int count=0;
  char ch;
  int k,i=0;
  intarr_t *output = malloc(sizeof(intarr_t));
  while (!feof(fp)) {
    ch = getc(fp);
    if (ch == ',') count ++;
  } fseek(fp,0,SEEK_SET);
  if (count==0) {
    output->len = 0;
    output->data = NULL;
    return output;
  } output->len=count+1;
  output->data=malloc(sizeof(int)*output->len);
  while(i<output->len) {
    while (fscanf(fp, "%d",&k)!=1) fseek(fp, 1, SEEK_CUR);
    output->data[i]=k;
    i++;
  } fseek(fp,0,SEEK_END);
  fclose(fp);
  return output;
}
