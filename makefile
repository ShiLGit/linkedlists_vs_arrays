CC = gcc
CFLAGS = -Wall -ansi -pedantic

all: main

main: main.c
	$(CC) $(CFLAGS) main.c -o a1
