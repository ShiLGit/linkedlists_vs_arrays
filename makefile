CC = gcc
CFLAGS = -Wall -ansi -pedantic

all: main1

main1: main.o ds_memory.o ds_array.o
	$(CC) $(CFLAGS) main.o  ds_memory.o ds_array.o -o a1

main.o: main.c
	$(CC) $(FLAGS) -c main.c -o $@

ds_memory.o: ds_memory.c
	$(CC) $(FLAGS) -c ds_memory.c -o $@

ds_array.o: ds_array.c
	$(CC) $(CFLAGS) -c ds_array.c -o $@
