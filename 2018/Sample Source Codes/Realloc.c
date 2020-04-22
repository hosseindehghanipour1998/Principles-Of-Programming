#include <stdio.h>


void *update_size(void* p, size_t OldLength, size_t NewLength) {
  void *p2 = malloc(NewLength);
  if (p && p2) {
    memcpy(p2, p, OldLength < NewLength ? OldLength : NewLength);
  }
  if (p2 || (NewLength == 0)) {
    free(p);  // Note A
  }
  return p2;
}


void main(void){

    char * p = malloc(20);
    char * j = update_size ( p , 20 , 30);
}
