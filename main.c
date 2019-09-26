
#include "ds_memory.h"
#include "stdio.h"
#include "ds_array.h"
void ds_show_array(){
  ds_print_array();
  ds_finish_array();
}
int main()
{
  ds_create_array();
//  ds_show_array();

  ds_init_array();
  ds_insert(999, 0);
  ds_insert(998, 1);
  ds_insert(996, 2);
  ds_insert(997, 2);
  ds_insert(1000,0);
  ds_print_array();
  return 0;
}
