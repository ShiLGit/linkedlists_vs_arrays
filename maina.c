
#include "ds_memory.h"
#include <stdio.h>
#include "ds_array.h"
#include "ds_list.h"

void ds_show_array(){
  ds_print_array();
  ds_finish_array();
}

void resetLoad(){ /*doesn't fukin work anymore because ds_create_array doesn't call ds_create()*/

    ds_create_array();
    ds_finish_array();
    ds_init_array();

    ds_read_elements("elements.txt");


    ds_print_array();
    ds_finish_array();
}
int main()
{
  void* fml = malloc(sizeof(long));

  ds_create_array();
  ds_init_array();

  ds_print_array();
  ds_finish();

  printf("\nsizeof %ld", sizeof(ds_list_item));
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
