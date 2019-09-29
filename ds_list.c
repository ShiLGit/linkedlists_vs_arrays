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
  int i;
  long newHead, head_loc, next_loc, new_loc, prev_loc;;

  /*preliminary errorcheckgin*/
  if(index < 0){
    return -1;
  }

  /*get first number in file */
  ds_read(headBuffer, 0, sizeof(long));
  head_loc = *(long*)headBuffer;

  /*edge case: the list is empty - create furst NOAD!*/
  if(head_loc== -1){
    if(index != 0){
      printf("\nbad index jackass (init)");
      return -1;
    }
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
  new_loc = ds_malloc(sizeof(ds_list_item));

  /*read "next" of node at index-1*/
  for ( i =0; i < index; i++){
    ds_read(&dummy, next_loc, sizeof(ds_list_item));

    if(dummy.next == -1 && i != index - 1){
      if(i == index -1){
        printf("\nNew element added!!!!!!");
      }
      printf("\nbad index jackass");
      return -1;
    }

    if(i == index - 2){/*set prev_loc to point to location of node[index-1]*/
      prev_loc = dummy.next;
    }
    if(i == index - 1){/*we're on last loop iteration*/
      prev.item = dummy.item;
      prev.next = new_loc;
      printf("\npre-node item = %d, next = %ld", prev.item, prev.next);

      ds_write(prev_loc, (void*)&prev, sizeof(ds_list_item));
    }

    next_loc = dummy.next;
  }

  /*set and write the new node intfo ile */
  new.item = value;
  new.next = next_loc;
  ds_write(new_loc, (void*)&new, sizeof(ds_list_item));

  /*update head if inserting at start of list*/
  if(index == 0){
      ds_write(0, (void*)&new_loc, sizeof(long));
  }

  return 0;
}

int ds_replace(int value, long index){
  ds_list_item replacement, dummy;
  int i;
  long next, write_loc;

  /*prelim errorchecl*/
  if(index < 0){
    return -1;
  }
  ds_read(&next, 0, sizeof(long));

  /*edge case: replace first element*/
  if(index == 0){
    write_loc = next; /*writeloc = head*/
    ds_read(&dummy, next, sizeof(ds_list_item));
    replacement.next = dummy.next;
  }

  /*traverse linkedlist to set write location and .next of replacement node*/
  for(i = 0; i<= index; i++){
    ds_read(&dummy, next, sizeof(ds_list_item));
    if(i == index -1){
      /*printf("\n pre node reached: item = %d next = %ld", dummy.item, dummy.next);
      */write_loc = dummy.next;
    }
    if(i == index){
      replacement.next = dummy.next;
    }
    next = dummy.next;
  }
  replacement.item = value;
  ds_write(write_loc, &replacement, sizeof(ds_list_item));

  return 0;

}

int ds_swap(long index1, long index2){
    long next, addr1, addr2;
    int temp, i;
    ds_list_item dummy, node1, node2;

    /*preliminary errchekc */
    if(index1 < 0 || index2 < 0){
      return -1;
    }else if (index1 == index2){
      return 0;
    }

    /*make index2 > index1*/
    if(index2<index1){
      temp = index2;
      index2 = index1;
      index1=temp;
    }
    printf("\ni1 = %ld, i2 = %ld", index1, index2);

    ds_read(&next, 0, sizeof(long));
    printf("\nnext = %ld", next);

    /*set add1 = head in case index1 = 0?*/
    addr1 = next;

    /*traverse list findng locations and nodees to write in*/
    for(i = 0; i <= index2; i++){
      ds_read(&dummy, next, sizeof(ds_list_item));
      if(dummy.next == -1 && i < index2){
        printf("\ninvalid index ");
        return -1;
      }

      if(i == index1 -1 ){
        addr1 = dummy.next;
      }else if (i == index2-1){
        addr2 = dummy.next;
      }

      if(i == index1){
        node1 = dummy;
        printf("\nnode1 found - item = %d next = %ld", node1.item, node1.next);
      }else if (i == index2){
        node2  = dummy;
        printf("\nnode2 found - item = %d next = %ld", node2.item, node2.next);
      }
      next = dummy.next;
    }

    /*swap values*/
    temp = node1.item;
    node1.item = node2.item;
    node2.item = temp;

    /*write values in*/
    ds_write(addr1, &node1, sizeof(ds_list_item));
    ds_write(addr2, &node2, sizeof(ds_list_item));
    return 0;
}


int ds_read_elements(char* filename){
  FILE *fp = fopen(filename, "r");
  int print, index, flag;
  flag = 0;

  if(fp == NULL)
    return -1;

  index = 0;
  while(!feof(fp) && flag == 0){
    fscanf(fp, "%d\n", &print);

    flag = ds_insert(print, index);
    index++;
  }
  if(flag !=0)
    return -1;

  return 0;
}

int ds_finish_list(){
  return ds_finish();
}

void ds_print_list(){
  void* buffer = malloc(sizeof(long));
  void* nodeBuffer = malloc(sizeof(ds_list_item));
  ds_list_item read;
  int i = 0;
  long nextLoc;

  ds_read(buffer, 0, sizeof(long));
  nextLoc = *(long*)buffer;
  printf("\nhead = %ld", *(long*)buffer);

  do{
    ds_read(nodeBuffer, nextLoc, sizeof(ds_list_item));
    read = *(ds_list_item*)nodeBuffer;
    printf("\nIndex %d: item = %d\tnext = %ld", i, read.item, read.next );
    nextLoc = read.next;
    i++;
  }while (read.next != -1 );

}
