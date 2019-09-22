CC = gcc
CFLAGS = -Wall -ansi -pedantic

all: main

main: main.c
	$(CC) $(CFLAGS) main.c -o a1

	CC = gcc
	CFLAGS = -ansi -Wall -I$(IDIR)

	IDIR = ./includes/
	SRCDIR = ./src/
	BINDIR = ./bin/

	SOURCES = $(SRCDIR)*.c

	all: contactList

	contactList: $(BINDIR)main.o $(BINDIR)contacts.o
		 $(CC) $(BINDIR)main.o $(BINDIR)contacts.o -o $(BINDIR)$@

	$(BINDIR)main.o: $(SRCDIR)main.c
		$(CC) $(CFLAGS) -c $(SRCDIR)main.c -o $@

	$(BINDIR)contacts.o: $(SRCDIR)contacts.c
		$(CC) $(CFLAGS) -c $(SRCDIR)contacts.c -o $@
	run:
		./contactList

	clean:
		rm ./bin/*.o ./contactList
