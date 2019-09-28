#include "ds_memory.h"
#include "ds_list.h"

void ds_create_list(){
  long toWrite = -1;

  /*commented out because the instructions keep GOSH DARN CHANGING
  ds_create("list.bin", 2048);
  ds_init("list.bin");
  */
  ds_init("list.bin");

  ds_malloc(sizeof(long));
  ds_write(0, (void*)(&toWrite), sizeof(long));
  ds_finish();
}

int ds_init_list(){
  return ds_init("list.bin");
}

int ds_insert(int value, long index){
  ds_list_item new, dummy, prev;
  void *headBuffer = malloc(sizeof(long));
  void *nextBuffer = malloc(sizeof(long));
  int i;
  long newHead, head_loc, next_loc, new_loc, prev_loc;;

  /*preliminary errorcheckgin*/
  if(index < 0){
    return -1;
  }

  /*get first number in file */
  ds_read(headBuffer, 0, sizeof(long));
  head_loc = *(long*)headBuffer;
  printf("\nheadloc = %ld", head_loc);

  /*edge case: the list is empty - create furst NOAD!*/
  if(head_loc== -1){
    new.item = value;
    new.next = -1;
    newHead = sizeof(long);

    /*update head location; write new node in and allocate memory*/
    headBuffer = &newHead;
    ds_malloc(sizeof(new));
    ds_write(0, headBuffer, sizeof(long));
    if(ds_write(sizeof(long), (void*)&new, sizeof(new)) == -1){
        return -1;
    }
    return 0;
  }

  /*case other lmaoooo*/
  next_loc = head_loc;
  prev_loc = head_loc;
  new_loc = head_loc + sizeof(ds_list_item);

  /*read "next" of node at index-1*/
  for ( i =0; i < index; i++){
    ds_read(&dummy, next_loc, sizeof(ds_list_item));
    printf("\nnext: %ld", dummy.next);

    if(i == index - 2){/*set prev_loc to point to location of node[index-1]*/
      prev_loc = dummy.next;
    }
    if(i == index - 1){/*we're on last loop iteration*/
      prev.item = value;
      prev.next = new_loc;

      ds_write(prev_loc, (void*)&prev, sizeof(long));
    }
    if(dummy.next == -1){/*traversed to end of list without reaching node[index-1] because ur dumb ass input an invalid index*/
      return -1;
    }
    next_loc = dummy.next;
  }


  /*set and write the new node intfo ile */
  new.item = value;
  new.next = head_loc;
  ds_malloc(sizeof(ds_list_item));
  ds_write(new_loc, (void*)&new, sizeof(ds_list_item));

  /*update head*/
  ds_write(0, (void*)&new_loc, sizeof(long));
  free(nextBuffer);
  return 0;
}
