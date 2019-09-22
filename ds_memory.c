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

  if(fp == null){
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
  fwrite(ds_file.block, sizeof(struct ds_blocks_struct), 4096, fp);

  int byte = 0;
  fseek(fp, size, SEEK_CUR);
  fwrite(&byte, sizeof(byte), 1, fp);

  fclose(fp);

  return 0;
}
