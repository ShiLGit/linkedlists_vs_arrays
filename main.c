
#include "ds_memory.h"
#include "stdio.h"
#include "ds_array.h"
int main()
{
  /*show array

  */
  int p = ds_create_array();
  printf("\n%d", p);
  ds_init_array();
  ds_finish();
  return 0;
}
