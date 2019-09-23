
#include <stdio.h>
#include <stdlib.h>
#include "ds_memory.h"

int main(){
  printf("\nds_create  = %d\n", ds_create("test.bin", 10));
  ds_init("test.bin");
  return 0;
}
