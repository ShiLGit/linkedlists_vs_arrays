
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
  int f;
  ds_init_array();
  ds_swap(0, 12);
  ds_finish_array();
  printf("\nf = %d",f);

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
