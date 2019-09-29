#include <stdio.h>
#include "ds_memory.h"
#include "ds_array.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
/*
CAUTION: THIS SHIT INCREMENTS THE READWRITE COUNT
*/
void reset_array_file(){
  ds_create("array.bin", 2048);
  ds_create_array();
  ds_init_array();
  ds_read_elements("elements.txt");
  ds_finish_array();
  ds_reset_counter();
}

int main2(){
  reset_array_file();
  ds_init_array();
  ds_insert(700, 1);
  printf("\n......%d", ds_get_reads());
  ds_finish_array();
  return 0;
}

int main(){
  int numEle = 90, numIterations;
  FILE* fp = fopen("data_arrays_replace.txt", "w");
  time_t seed = time(0);
  int i;
  int r_max, r_min, r_avg;
  int w_max, w_min, w_avg;
  int reads, writes;
  long index;

  r_min = 101;
  r_max = -1;

  w_min = 101;
  w_max = -1;

  r_avg = 0;
  w_avg = 0;

  srand(seed);

  fprintf(fp, "10 ELEMENTS\n");
  for(i = 0; i < numEle; i++){
    index = rand() % numEle;

    printf("\n%d", i);
    printf("\n index = %ld", index);

    ds_init_array();

    /*actual function00*/
    ds_replace(0, index);
    reads = ds_get_reads();
    writes = ds_get_writes();
    printf("\nwriting reads %d writes %d", reads, writes);

    fprintf(fp, "%d,%d\n", reads, writes);


    ds_finish_array();

    /*file SHIT*/


    /*set vars to plot*/
    if(reads > r_max){
      r_max = reads;
    }
    if(reads < r_min){
      r_min = reads;
    }

    if(writes > w_max){
      w_max = writes;
    }
    if(writes <w_min){
      w_min = writes;
    }
    r_avg+=reads;
    w_avg+=writes;


    reset_array_file();
  }
  fprintf(fp, "MAX_R: %d MIN_R: %d AVG_R: %d\nMAX_W: %d MIN_W:%d AVG_W: %d", r_max, r_min, r_avg/numEle, w_max, w_min, w_avg/numEle);


  fclose(fp);

  return 0;
}
