#include <stdio.h>
#include <stdlib.h>
#include "ds_memory.h"

int main(){
  printf("\ndscountes: %d\n", sizeof(struct ds_counts_struct));
  printf("\nblocks: %d\n", sizeof(long long));
  printf("\nfiles: %d\n", sizeof(struct ds_file_struct));

  return 0;
}
