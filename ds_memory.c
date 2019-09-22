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

  ds_file.block[0].start = 0;
  ds_file.block[0].length = size;
  ds_file.block[0].alloced = 0;

  return 0;
}

int wtf(){

  return 99;
}
