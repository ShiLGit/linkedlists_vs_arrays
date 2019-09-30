#include <stdio.h>
#include <stdlib.h>

int main(){
  struct fk{
    int val;
    
    long posn;
  };

  void* lol = malloc(sizeof(struct fk));
  struct fk fkk;
  int* imdumb = malloc(sizeof(int));

  lol = &fkk;
  fkk.posn = 10;
  fkk.val = 2000;

  printf("\n%ld", *(long*)lol);

  for(int i = 0; i < 20; i++){
    printf("\n%d: %ld",i, *(int*)(lol++));

  }
  return 0;
}
