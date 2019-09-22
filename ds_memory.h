
/*
Name: Lilian Shi
Stu#: 1048355
Email: lshi02@uoguelph.ca
*/

#ifndef DS_MEMORY
#define DS_MEMORY

#define MAX_BLOCKS 4096

struct ds_counts_struct{
  int reads;
  int writes;
};

struct ds_blocks_struct{
  long start;
  long length;
  char alloced;
};

struct ds_file_struct{
  FILE *fp;
  struct ds_blocks_struct block[MAX_BLOCKS];
};

int ds_create(char *filename, long size);


#endif
