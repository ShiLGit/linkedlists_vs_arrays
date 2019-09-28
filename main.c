#include "ds_memory.h"
#include <stdio.h>
#include "ds_list.h"

int main(){
  void* fml = malloc(sizeof(long));

  ds_create_list();
  ds_init("list.bin");
  ds_read(fml, 0, 8);
  printf("\nfml = %d", *(int*)fml);
  ds_finish();

  ds_insert(9000, 0);
  return 69;
}
