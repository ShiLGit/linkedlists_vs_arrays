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
  ds_file.block[0].alloced = 0;

  for(int i = 0; i < 4095; i++){
    ds_file.block[i].start = 0;
    ds_file.block[i].length = 0;
    ds_file.block[i].alloced = 0;
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

  
  /* if(size > 0){
    printf("\nwtf..");
    fseek(fp, size, SEEK_CUR);
    checker = fwrite(&byte, sizeof(byte), 1, fp);
    checker = checker < 1;
  }
*/
  if(checker == 1){
    printf("\nCHECKER = %d: SOMETHING WENT WRONG WITH FWRITE", checker);
    return 1;
  }

  if(fclose(fp) != 0){
    return 1;
  }

  return 0;
}
