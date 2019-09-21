CC = gcc
CFLAGS = -Wall -ansi -pedantic

all: main

main: main.c ds_memory.c
	$(CC) $(CFLAGS) ds_memory.c
	$(CC) $(CFLAGS) main.c -o a1
