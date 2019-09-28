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
  reset_file();
  ds_init_list();

   ds_insert( 100, 0 );



  ds_init_list();
  ds_print_list();
  ds_finish();




   return 0;

  return 69;
}
