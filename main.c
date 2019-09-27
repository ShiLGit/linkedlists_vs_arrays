
#include "ds_memory.h"
#include "stdio.h"
#include "ds_array.h"

void ds_show_array(){
  ds_print_array();
  ds_finish_array();
}

void resetLoad(){

    ds_create_array();
    ds_finish_array();
    ds_init_array();

    ds_read_elements("elements.txt");


    ds_print_array();
    ds_finish_array();
}
int main()
{

  ds_init_array();

  ds_delete(0);
  ds_print_array();
  ds_finish_array();

  /* write new file that hasn't been fked
ds_create_array();
ds_finish();

ds_init_array();

printf("\ndsreplae = %d", ds_replace(-9000000, 2));

ds_finish_array();

ds_init_array();

ds_print_array();
*/


/*
//ds_finish_array();
ds_print_array();
  */return 0;
}
