CC=gcc
CFLAGS=-Wall -ANSI -Pedantic

matrix: main.o
	$(CC) main.o -o$@

main.o: main.c matrix.h
	$(CC) $(CFLAGS) -c main.c -o$@

run:
	./matrix

clean:
	rm ./*.o ./matrix
