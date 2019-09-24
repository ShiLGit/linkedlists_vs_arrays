
#include <stdio.h>
#include <stdlib.h>
#include "ds_memory.h"

int main(){
  printf("\nds_create  = %d\n", ds_create("test.bin", 11234));
  ds_init("test.bin");
  long fuk = ds_malloc(1110);
  printf("\n%ld,", fuk);
  ds_print(10);

  ds_free(fuk);
  ds_print(10);

  return 0;
}
