CC=gcc
CFLAGS=-Wall -ANSI -Pedantic

all: exe
	$(CC) $(CFLAGS) -c main.c -o

exe: main.o
	$(CC) main.o -oexe

main.o: main.c ds_memory.h ds_memory.c	
	$(CC) $(CFLAGS) -c main.c -oexe

clean:
	rm -i exe
