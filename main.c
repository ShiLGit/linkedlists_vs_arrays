
#include <stdio.h>
#include <stdlib.h>
#include "ds_memory.h"

int main(){
  //printf("\nds_create  = %d\n", ds_create("test.bin", 1234));

  ds_init("test.bin");
  long fuk = ds_malloc(110);
  ds_print(30);

  //ds_free(0);
  //ds_print(30);
  printf("\ndsfinish = %d", ds_finish());

  return 0;
}
