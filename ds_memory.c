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

//size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)

int ds_create(char *filename, long size){
  FILE* fp = fopen(filename, "wb");
  int checker;

  if(fp == NULL){
    return 1;
  }

  //set values in block array
  ds_file.block[0].start = 0;
  ds_file.block[0].length = size;
  ds_file.block[0].alloced = '0';

  for(int i = 1; i < 4096; i++){
    ds_file.block[i].start = 0;
    ds_file.block[i].length = 0;
    ds_file.block[i].alloced = '0';
  }

  //write block into file "heder"
  checker = fwrite(ds_file.block, sizeof(struct ds_blocks_struct), 4096, fp);
  if(checker != 4096){
    return 1;
  }

  //write bytes after file header
  char byte = '\0';
  for(int i = 0; i < size; i++){
    fwrite(&byte, sizeof(byte), 1, fp);
  }
 
  if(fclose(fp) != 0){
    return 1;
  }

  return 0;
}

int ds_init(char *filename){
  //load fp into global var
  ds_file.fp = fopen(filename, "rb+");
  if(ds_file.fp == NULL){
    return 1;
  }

  //loda header into global varaibiel!
  fread(ds_file.block, sizeof(struct ds_blocks_struct), 4096, ds_file.fp);
  ds_init_TEST();
  printf("\nblock[0].length = %lu\n", ds_file.block[4095].length);
  return 0;
}

void ds_init_TEST(){
  for(int i = 0; i < 4095; i+= 1){
    printf("\nblock[%d]: length = %lu, start = %lu, alloced = '%c'", i, ds_file.block[i].length, ds_file.block[i].start, ds_file.block[i].alloced);
  }
}
