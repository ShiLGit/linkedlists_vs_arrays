#include "ds_memory.h"
#include "ds_list.h"

void ds_create_list(){
  long toWrite = -1;

  ds_create("list.bin", 2048);
  ds_init("list.bin");

  ds_malloc(sizeof(long));
  ds_write(0, (void*)(&toWrite), sizeof(long));
  ds_finish();
}

int ds_init_list(){
  return ds_init("list.bin");
}

int ds_insert(int value, long index){
  ds_list_item test;
  void *ffs = malloc(sizeof(long));
  int i;

/*
  ds_read(ffs, 0, sizeof(long));
  test.next = *(int*)ffs;
*/
  test.next = -1;
  test.item = value;

  ds_write(sizeof(long), (void*)&test, sizeof(test));
  ds_finish();

  ds_init_list();
  for( i = 0; i < 20; i++){
    ds_read(ffs, index*(sizeof(test)) + i, sizeof(long));
    printf("\nim so sad %d\n", *(int*)ffs);

  }
  return 0;
}
