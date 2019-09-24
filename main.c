
#include <stdio.h>
#include <stdlib.h>
#include "ds_memory.h"

int main(){
  printf("\nds_create  = %d\n", ds_create("test.bin", 11234));
  ds_init("test.bin");
  printf("\n%lu,", ds_malloc(11));
  ds_malloc(22000);
  return 0;
}
