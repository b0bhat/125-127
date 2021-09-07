#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "list.h"

int main( int argc, char* argv[] ) {
  // test the create function
  list_t* list = list_create();

  // check to see if the create function did everything it was supposed to
  if( list == NULL ) {
      printf( "create: create failed to malloc\n" );
      return 1;
    } if( list->head != NULL ) {
      printf( "create: head is not null!\n" );
      return 1;
    } if( list->tail != NULL ) {
      printf( "create: tail is not null!\n" );
      return 1;
    }

    int i = 0;
    for (i = 0; i < 5; i++) list_append(list, i);
    element_t *el15 = list_index(list, i+2);
    if (el15 != NULL) return 1;
    list_t * list1 = list_create();
    element_t * element1 = list_index(list1, 20);
    if (element1 != NULL) return 1;

    list_t * list2 = list_create();
    for(int i = 0; i < 500; i++) {
      list_append(list2, i+5);
    }list_destroy(list2);
    list_t * list3 = list_create();
    element_t *t1 = element_create(10);
    element_t *t2 = element_create(20);

    t2->next = t1;
    free(t2);

    list_append(list3, 10);
    if(list3->tail->next != NULL) {
      return 1;
      assert(list->tail->next == NULL);
    }
     list_t * list4 = list_create();
     for(int i = 0; i<5; i++) list_append(list4, i);
     element_t * t3 = list_index(list4, 0);
     if (t3->val != 0) return 1;

     list_t * list5 = list_create();
     list_prepend(list5, 40);
     if(list5->tail != list5->head) return 1;
     return 0;
}
