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

  for(int i = 1; i < 4096; i++){//START AT 1 TO AVOID OVERWRITING FIRST BLOK
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
  return 0;
}

//METHOOOOOOOOOOOOOOOOOOOOOOOD!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
long ds_malloc(long amount){
  int indexOne, indexTwo;
  long returnVal;
  indexOne = indexTwo = -1;
  returnVal = -1;

  for(int i =0; i < 4096; i++){
    if(ds_file.block[i].length >= amount && ds_file.block[i].alloced == '0'){
      indexOne = i;
      returnVal = ds_file.block[i].start;
      break;
    }
  }
  if(indexOne == -1){
    printf("\nNo block1 fond.");
    return -1;
  }

  for(int i = 0; i < 4096; i++){
    if(ds_file.block[i].length ==0){
      indexTwo = i;
      printf("\nds_malloc: set index two to %d", i);
      break;
    }
  }
  if(indexTwo == -1){//unable to find blcok 2 >>set returnval from start of block1 to -1 to indicate errrrerus
    printf("\nNo block2 found.");
    returnVal = -1;
  }else{
    //set block 2 first if it exists
    ds_file.block[indexTwo].start = ds_file.block[indexOne].start + amount;
    ds_file.block[indexTwo].length = ds_file.block[indexOne].length - amount;
    ds_file.block[indexTwo].alloced = '0';
  }

  ds_file.block[indexOne].length = amount;
  ds_file.block[indexOne].alloced = '1';

  return returnVal;
}
//METHOOOOOOOOOOOOOOOOOOOOOOOD!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void ds_free(long start){
  for(int i = 0; i < 4096; i++){
    if(ds_file.block[i].start == start){
      printf("\nds_free: freed block at %d", i);
      ds_file.block[i].alloced = '0';
      break;
    }
  }
  return;
}
//print tha dumbass array!!!!!!!!!!!
void ds_print(int max){
  for(int i = 0; i < max; i++){
    printf("\nblock[%d]: length = %ld, start = %ld, alloced = '%c'", i, ds_file.block[i].length, ds_file.block[i].start, ds_file.block[i].alloced);
  }
  printf("\n");
}
