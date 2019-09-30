#include <stdio.h>
#include "ds_memory.h"
#include "ds_list.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
/*
CAUTION: THIS SHIT INCREMENTS THE READWRITE COUNT
*/
FILE* fp;

void reset_array_file(){
  ds_create("list.bin", 2048);
  ds_create_list();
  ds_init_list();
  ds_read_elements("elements.txt");
  ds_finish_list();
  ds_reset_counter();
}

void fillFile (int num){
  int rando, i;
  time_t seed = time(0);

  printf("\nnum = %d", num);
  FILE* fp = fopen("elements.txt", "w");


  srand(seed);
  for(i = 0; i < num; i++){
    rando = rand() % 101;
    fprintf(fp, "\n%d", rando);
  }
  fclose(fp);

}

void Iterate(int numEle){
  int numIterations= 30;

  time_t seed = time(0);
  int i;
  int r_max, r_min;
  int w_max, w_min;
  int reads, writes;
  long index, index2;
  double r_avg, w_avg;

  r_min = 101;
  r_max = -1;

  w_min = 101;
  w_max = -1;

  r_avg = 0;
  w_avg = 0;

  srand(seed);
  reset_array_file();

  fprintf(fp, "\n%d ELEMENTS\n\n", numEle);
  /*inner loop: repreated 30 imtes*/
  for(i = 0; i < numIterations; i++){
    index = rand() % numEle;
    do{
      index2 = rand() % numEle;
    }while(index2 == index);


    printf("\n%d", i);
    printf("\n index = %ld", index);

    ds_init_list();
    
    /*actual function00*/
    ds_delete(index);
    printf("\npost....");
    ds_finish_list();

    reads = ds_get_reads();
    writes = ds_get_writes();
    printf("\nwriting reads %d writes %d", reads, writes);
    ds_finish_list();

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
  fprintf(fp, "MAX_R: %d MIN_R: %d AVG_R: %lf\nMAX_W: %d MIN_W:%d AVG_W: %lf", r_max, r_min, r_avg/numIterations, w_max, w_min, w_avg/numIterations);

}
int main(){
  int i;
  fp  = fopen("LL_delete.txt", "w");
  reset_array_file();

  for(i = 1; i <= 10; i++){
    fillFile(i*10);
    Iterate(i * 10);
  }

  fclose(fp);
  return 0;
}

int main1(){
  ds_create("list.bin", 2048);
  ds_create_list();
  ds_init_list();
  ds_read_elements("elements.txt");
  ds_insert(9000, 4);
  printf("\ndelete status = %d", ds_delete(0));

  ds_finish_list();
  ds_print(10);
  return 0;
}
