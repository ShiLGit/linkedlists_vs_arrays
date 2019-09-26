#include "ds_array.h"
#include "ds_memory.h"
#include <stdlib.h>
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

int ds_init_array(){
  int flag;
  void *flag2;
  void *val = malloc(sizeof(long));

  flag = ds_init("array.bin");
  if(flag != 0){
      return flag;
  }

  flag2 = ds_read(val, 0, sizeof(long));
  if(flag2 == NULL){
    printf("\nds_init: ds_read() failed!");
    return 1;
  }
  elements = *(long*)val;
  free(val);

  return 0;
}



int ds_finish_array(){
  int flag;
  void *ptr = &elements;

  flag = ds_write(0, ptr, sizeof(long));
  if(flag ==-1){
    return flag;
  }

  flag = ds_finish();
  if(flag != 1){
    return 1;
  }
  return 0;
}

int ds_insert(int value, long index){
  int temp;
  void *flag;
  long flag2;
  void *ptrRead = malloc(sizeof(int));
  void *ptrWrite;

  /*preliminary errorechgkinc*/
  if(index >255){/**index out of bounds*/
    return 1;
  }else if(elements == MAX_ELEMENTS){/*can't insert more eleemenest*/
    return 1;
  }else if(index > elements){/*tryna insert element at phat index when array is too small*/
    return 1;
  }

  /*edge case: insert eleemnt at end of araiyayaIAYA*/
  if(index == elements){
    ptrWrite = &value;
    flag2 = ds_write(sizeof(int)*index +sizeof(long), ptrWrite, sizeof(int));
    if(flag2 == -1){
      return flag2;
    }else{
      elements++;
      return 0;
    }

  }

  /*read current RESIDENT OF INDEX into temp */
  flag = ds_read(ptrRead, sizeof(int)*index + sizeof(long), sizeof(int)); /*+sizeof long to account for element -tracking long at "beginning" of .bin*/
  if(flag == NULL){
    printf("\nds_insert: ds_read failed");
    return 1;
  }
  temp = *(int*)ptrRead;

  /*write value into ele at index*/
  ptrWrite = &value;
  flag2 = ds_write(sizeof(int)*index + sizeof(long), ptrWrite, sizeof(int));

  /*
  WHAT IF THERE'S AN ERROR LATER? (E>G> EXCEEDED ELE 256)
  -FCLOSE TO DISCARD CHANGES TO FILE
  */  printf("\nele = %ld", elements);
  elements++;
  printf("\nele = %ld", elements);

  free(ptrRead);
  return 0;
}







void ds_print_array(){
  int i;
  void *val = malloc(sizeof(int));

  /*ds_init_array();*/
  ds_print(10);
  printf("\nds_print_array: Elements = %ld", elements);
  for(i = 0; i<elements; i++){
    ds_read(val, sizeof(long) + i * sizeof(int), sizeof(int));
    printf("\narray[%d] = %d", i , *(int*)val);
  }

  free(val);
}
