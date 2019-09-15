
/*
Name: Lilian Shi
Stu#: 1048355
Email: lshi02@uoguelph.ca
*/
#include <stdlib.h>
const int MAX_BLOCKS = 4096;

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
}
