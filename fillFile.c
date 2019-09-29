#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[]){
  int num = atoi(argv[1]);
  int rando;
  time_t seed = time(0);

  printf("\nnum = %d", num);
  FILE* fp = fopen("elements.txt", "w");


  srand(seed);
  for(int i = 0; i < num; i++){
    rando = rand() % 101;
    fprintf(fp, "\n%d", rando);
  }

  return 0;

}
