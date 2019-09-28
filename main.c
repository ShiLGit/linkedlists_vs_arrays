#include "ds_memory.h"
#include <stdio.h>
#include "ds_list.h"

void ds_print_list(){

}
void reset_file(){
  ds_create("list.bin", 2048);
  ds_create_list();
  printf("\nFILE RESET!");
  ds_print(10);
}
int main(){
  /*ds_init("list.bin");
  */
  void* buffer = malloc(sizeof(long));

    ds_init_list();

    ds_insert(999, 0);
    ds_read(buffer, 0, sizeof(long));
    printf("\nNEW HEAD: %ld", *(long*)buffer);
    ds_print(10);

    ds_finish();

  return 69;
}
