CC = gcc
CFLAGS = -Wall -ansi -pedantic

all: insert_array array

insert_array: insert_array.o ds_memory.o ds_array.o
	$(CC) $(CFLAGS) insert_array.o ds_memory.o ds_array.o -o insert_array

array: ds_memory.o ds_array.o arrays.o
	$(CC) $(CFLAGS) ds_memory.o ds_array.o arrays.o -oarray

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o $@

ds_memory.o: ds_memory.c
	$(CC) $(CFLAGS) -c ds_memory.c -o $@

ds_array.o: ds_array.c
	$(CC) $(CFLAGS) -c ds_array.c -o $@

insert_array.o: insert_array.c
	$(CC) $(CFLAGS) -c insert_array.c -o$@

ds_list.o: ds_list.c
	$(CC) $(CFLAGS) -c ds_list.c -o$@

maina.o: maina.c
	$(CC) $(CFLAGS) -c maina.c -o$@

arrays.o: arrays.c
	$(CC) $(CFLAGS) -c arrays.c -o$@
