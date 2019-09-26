#include "ds_array.h"
#include "ds_memory.h"
#define MAX_ELEMENTS 256

long elements;

int ds_create_array(){
  int flag;
  long toWrite = 0;
  flag = ds_create("array.bin", 2048);
  if(flag != 0){ /*ds create failed*/
    printf("\nFrom ds_create_array(): ds_create() failed");
    return flag;
  }

  flag = ds_init("array.bin");
  if(flag != 0){/*ds_init failed*/
    printf("\nFrom ds_create_array(): ds_init() failed");
    return flag;
  }

  flag = ds_malloc(sizeof(long)); /*malloc for long at start of .bin*/
  if(flag == -1){
    printf("\nFrom ds_create_array(): ds_malloc failed");
    return flag;
  }

  flag = ds_write(0, &toWrite, sizeof(long));/*set value of first long to 0*/
  if(flag == -1){
    printf("\nFrom ds_create_array(): ds_malloc failed");
    return flag;
  }

  flag = ds_malloc(MAX_ELEMENTS * sizeof(int)); /**malloc for entire array*/
  if(flag == -1){
    printf("\nFrom ds_create_array(): ds_malloc failed");
    return flag;
  }

  return 0;
}
