#ifndef __DS_ARRAY__
#define __DS_ARRAY__
#include <stdio.h>

int ds_create_array();
int ds_init_array();
void ds_print_array();
int ds_finish_array();

int ds_insert(int, long);
int ds_replace(int, long);
int ds_read_elements(char*);

int ds_delete(long);
int ds_swap(long, long);
int ds_find(int);
#endif
