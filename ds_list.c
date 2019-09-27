#include "ds_memory.h"
#include "ds_list.h"

void ds_create_list(){
  long toWrite = -1;
  void* wtf = malloc(sizeof(long));
  void* flag;
  int flag2;

  ds_create("list.bin", sizeof(long));
  ds_malloc(sizeof(long));

  flag2 =ds_write(0, (void*)(&toWrite), sizeof(long));
  flag = ds_read(wtf, 0, sizeof(long));
  printf("\n%d : %d", *(int*)wtf, flag2);
}
