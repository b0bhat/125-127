#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/*
 * intarr.h
 *
 * Provides a bounds-checked, resizable array of integers with
 * random-access and stack interfaces, and several utility functions
 * that operate on them.
 *
 */

/* DO NOT CHANGE THIS FILE - YOUR CODE WILL BE COMPILED AGAINST THE
   ORIGINAL. NON-COMPILING CODE WILL FAIL ALL THE TASKS!

   FOR TASKS WITH MORE THAN ONE FUNCTION, YOU MUST IMPLEMENT ALL
   FUNCTIONS TO PASS THE TASK.
*/

/* Structure type that encapsulates our safe int array. */
typedef struct {
  int* data;
  unsigned int len;
} intarr_t;

/* A type for returning status codes */
typedef enum {
  INTARR_OK,
  INTARR_BADARRAY,
  INTARR_BADINDEX,
  INTARR_BADALLOC,
  INTARR_NOTFOUND
} intarr_result_t;

/* LAB 5 TASK 1 */

// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.
intarr_t* intarr_create( unsigned int len ) {
  intarr_t *arr=malloc(sizeof(intarr_t));
    if (arr == NULL) return NULL;
    arr->len=len;
    arr->data=malloc(sizeof(int)*arr->len);
    return arr;

}

// frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia ){
    if (ia != NULL) free(ia);
}

/* LAB 5 TASK 2 */

// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_set( intarr_t* ia, unsigned int index, int val ){
    if (ia == NULL) return INTARR_BADARRAY;
    else if (index < ia->len) {
        ia->data[index] = val;
        return INTARR_OK;
    } else return INTARR_BADINDEX;
}

// If index is valid and i is non-null, set *i to ia->data[index] and return
// INTARR_OK. Otherwise no not modify *i and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia, unsigned int index, int* i ) {
    if (ia == NULL) return INTARR_BADARRAY;
    else if (index<ia->len && i != NULL) {
        *i = ia->data[index];
        return INTARR_OK;
    } else return INTARR_BADINDEX;
}

/* LAB 5 TASK 3 */

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer.
intarr_t* intarr_copy( const intarr_t* ia ) {
    intarr_t *duplicate=malloc(sizeof(intarr_t));
    if (duplicate==NULL) return NULL;
    duplicate->len=ia->len;
    duplicate->data=malloc(sizeof(int)*duplicate->len);
    int i;
    for (i=0;i<ia->len;i++) duplicate->data[i]=ia->data[i];
    return duplicate;
}

/* LAB 5 TASK 4 */

// Sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_sort( intarr_t* ia ) {
    if (ia==NULL)return INTARR_BADARRAY;
    else {
      int i,k,min,minpos,tmp;
      min=ia->data[0];
      for (i=0;i<ia->len;i++) {
        min = ia->data[i];
        for (k=i;k<ia->len;k++) {
          if (ia->data[k]<=min) {
              min=ia->data[k];
              minpos=k;
            }
          }
        tmp=ia->data[i];
        ia->data[i]=min;
        ia->data[minpos]=tmp;
      }
    return INTARR_OK;
  }
}

/* LAB 5 TASK 5 */

// Find the first occurrence of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i ) {
    if (ia == NULL) return INTARR_BADARRAY;
    int k;
    for (k = 0;k < ia->len;k++) {
        if (ia->data[k] == target && i != NULL) {
            *i = k;
            return INTARR_OK;
        }
    } return INTARR_NOTFOUND;
}

/* LAB 5 TASK 6 */

// HINT: First, do TASK 7, since you will need to resize your array
//       by +1 in order to successfully push val.
// Append val to the end of ia (allocating space for it). If
// successful, return INTARR_OK, otherwise return
// INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_push( intarr_t* ia, int val ) {
    if (ia==NULL) return INTARR_BADARRAY;
    int tmp_len = ia->len+1;
    ia->len = tmp_len;
    int *new_data = realloc(ia->data, sizeof(int)*ia->len);
    if(new_data){
        new_data[tmp_len-1] = val;
        ia->data = new_data;
        return INTARR_OK;
    } else return INTARR_BADALLOC;
}

// HINT: You will need to decrement len so that it always represents
//       the number of int's stored in the array data.
// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK. If the array is empty, leave *i unmodified
// and return INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_pop( intarr_t* ia, int* i ) {
    if (ia == NULL) return INTARR_BADARRAY;
    if (ia->data[0] == 0 && ia->len == 0) return INTARR_BADINDEX;
    if (i!=NULL ){
        *i = ia->data[ia->len-1];
        ia->data[ia->len-1] = 0;
        ia->len = ia->len-1;
        return INTARR_OK;
    } return INTARR_BADINDEX;
}

/* LAB 5 TASK 7 */

// HINT: Do this task before doing TASK 6.
// Resize ia to contain newlen values. If newlen is less than the
// original array length, the end of the array is discarded.
// If newlen is greater than the original array length, the values
// of the new integers will be undefined
// (see https://en.cppreference.com/w/c/memory/realloc).
// If the allocation is successful, return INTARR_OK, otherwise
// return INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen ) {
    if (ia == NULL) return INTARR_BADARRAY;
    int i,original_len;
    original_len = ia->len;
    ia->len = newlen;
    ia->data = realloc(ia->data,sizeof(int)*ia->len);
    if (ia->data != NULL) {
      if (ia->len > original_len) {
        for (i = original_len; i < ia->len; i++) ia->data[i] = 0;
      } return INTARR_OK;
    }return INTARR_BADALLOC;
}

/* LAB 5 TASK 8 */

// Get a deep copy of a portion of ia from index 'first' to index 'last'
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specified section. If an error
// occurs, i.e. ia is null, 'first' or 'last' are out of bounds,
// 'last' < 'first', or memory allocation fails, return a null pointer.
intarr_t* intarr_copy_subarray( intarr_t* ia, unsigned int first, unsigned int last ) {
    if (ia == NULL || first > ia->len || last > ia->len || last < first) return NULL;
    intarr_t *duparray = malloc(sizeof(intarr_t));
    if (duparray == NULL) return NULL;
    if (first <= last && duparray != NULL ) {
        int i,k = 0,newlen = last-first+1;
        duparray->len = newlen;
        duparray->data = malloc(sizeof(int)*newlen);
        for (i = first;i <= last;i++) {
            duparray->data[k] = ia->data[i];
            k++;
        } return duparray;
    } return NULL;
}
