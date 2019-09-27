#ifndef __DS_LIST__
#define __DS_LIST__

struct ds_list_item_struct{
  int item;
  long next;
};
typedef struct ds_list_item_struct ds_list_item;

void ds_create_list();
int ds_init_list();
int ds_replace(int, long);
int ds_insert(int, long);
int ds_delete(long);
int ds_swap(long, long);
int ds_read_elements(char*);
int ds_finish();

#endif
