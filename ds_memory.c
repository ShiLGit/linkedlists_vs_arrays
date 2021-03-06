/*
Name: Lilian Shi
Stu#: 1048355
Email: lshi02@uoguelph.ca
*/

#include <stdio.h>
#include <stdlib.h>
#include "ds_memory.h"

struct ds_file_struct ds_file;
struct ds_counts_struct ds_counts;

/*
filename: name of file to create/write
size: length of first array entry
ds_create: create file of filename; write "header" (ds_file.block) into file
*/

int ds_create(char *filename, long size){
  FILE* fp = fopen(filename, "wb");
  int checker, i;
    char byte = '\0';

  if(fp == NULL){
    return 1;
  }

  /*set values in block array*/
  ds_file.block[0].start = 0;
  ds_file.block[0].length = size;
  ds_file.block[0].alloced = '0';

  for(i = 1; i < 4096; i++){/*START AT 1 TO AVOID OVERWRITING FIRST BLOK*/
    ds_file.block[i].start = 0;
    ds_file.block[i].length = 0;
    ds_file.block[i].alloced = '0';
  }

  /*write block into file "heder"*/
  checker = fwrite(ds_file.block, sizeof(struct ds_blocks_struct), 4096, fp);
  if(checker != 4096){
    return 1;
  }

  /*write bytes after file header*/
  for(i = 0; i < size; i++){
    fwrite(&byte, sizeof(byte), 1, fp);
  }

  if(fclose(fp) != 0){
    return 1;
  }

  return 0;
}

int ds_init(char *filename){
  /*load fp into global var*/
  ds_file.fp = fopen(filename, "rb+");
  if(ds_file.fp == NULL){
    return 1;
  }

  /*loda header into global varaibiel!*/
  fread(ds_file.block, sizeof(struct ds_blocks_struct), 4096, ds_file.fp);
  return 0;
}

/*METHOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOD*/
long ds_malloc(long amount){
  int indexOne, indexTwo, i;
  long returnVal;
  indexOne = indexTwo = -1;
  returnVal = -1;

  for(i =0; i < 4096; i++){
    if(ds_file.block[i].length >= amount && ds_file.block[i].alloced == '0'){
      indexOne = i;
      returnVal = ds_file.block[i].start;
      break;
    }
  }
  if(indexOne == -1){
    return -1;
  }

  for(i = 0; i < 4096; i++){
    if(ds_file.block[i].length ==0){
      indexTwo = i;
      break;
    }
  }
  if(indexTwo == -1){/*unable to find blcok 2 >>set returnval from start of block1 to -1 to indicate errrrerus*/

  }else{
    /*set block 2 first if it exists*/
    ds_file.block[indexTwo].start = ds_file.block[indexOne].start + amount;
    ds_file.block[indexTwo].length = ds_file.block[indexOne].length - amount;
    ds_file.block[indexTwo].alloced = '0';
  }

  ds_file.block[indexOne].length = amount;
  ds_file.block[indexOne].alloced = '1';

  return returnVal;
}
/*METHOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOD*/
void ds_free(long start){
  int i;
  for(i = 0; i < 4096; i++){
    if(ds_file.block[i].start == start){
      ds_file.block[i].alloced = '0';
      break;
    }
  }
  return;
}
/*METHOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOD*/
int ds_finish(){
  int flag;
  if(ds_file.fp == NULL){
    return 1;
  }

  flag = fseek(ds_file.fp, 0, SEEK_SET);
  if(flag != 0){ /*return error if fseek failed*/
    return 0;
  }
  /*write changed header into DISCK*/
  flag = fwrite(ds_file.block, sizeof(struct ds_blocks_struct), 4096, ds_file.fp);

  if(flag != 4096){ /*return error: didn't write all ele into file*/
    return 0;
  }
  printf("\nreads: %d\nwrites: %d\n", ds_counts.reads, ds_counts.writes);
  fclose(ds_file.fp);
  return 1;
}

/*METHOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOD*/
void *ds_read(void *ptr, long start, long bytes){ /*rCATUSION: reading fat values (byte = big number) is problematic..*/
  int flag;
  if(ds_file.fp == NULL){
    return NULL;
  }

  flag = fseek(ds_file.fp, sizeof(ds_file.block) + start, SEEK_SET);
  if(flag !=0 ){
    return NULL;
  }

  flag = fread(ptr, bytes, 1, ds_file.fp);
  if(flag != 1){
    return NULL;
  }

  ds_counts.reads++;
  return ptr;
}

long ds_write(long start, void *ptr, long bytes){
  int flag;



  if(ds_file.fp == NULL){
    return -1;
  }

  flag = fseek(ds_file.fp, sizeof(ds_file.block) + start, SEEK_SET);
  if(flag != 0){
    return -1;
  }

  flag = fwrite(ptr, bytes, 1, ds_file.fp);
  if(flag != 1){
    return -1;
  }

  ds_counts.writes++;
  return start;

}
/*print array*/
void ds_print(int max){
  int i;
  for(i = 0; i < max; i++){
    printf("\nblock[%d]: start = %ld, length = %ld, alloced = '%c'", i, ds_file.block[i].start, ds_file.block[i].length, ds_file.block[i].alloced);
  }
  for(i = 4093; i < 4096; i++){
    printf("\nblock[%d]: start = %ld, length = %ld, alloced = '%c'", i, ds_file.block[i].start, ds_file.block[i].length, ds_file.block[i].alloced);
  }
  printf("\n");
}

void ds_reset_counter(){
  ds_counts.reads = 0;
  ds_counts.writes = 0;
}

int ds_get_reads(){
  return ds_counts.reads;
}

int ds_get_writes(){
  return ds_counts.writes;
}
