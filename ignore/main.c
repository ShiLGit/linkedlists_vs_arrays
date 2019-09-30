#include "ds_memory.h"
#include <stdio.h>
#include "ds_list.h"

void reset_file(){
  ds_create("list.bin", 2048);
  ds_create_list();
  ds_init_list();
  ds_finish();
  printf("\nFILE RESET!");
  ds_print(10);

}

int main(){
/*
  reset_file();
  ds_init_list();
  ds_read_elements("elements.txt");
  ds_finish_list();
*/
  ds_init_list();

  ds_find(3);
  ds_insert(99, 4);
  ds_print_list();
  ds_finish_list();




   return 0;

  return 69;
}
