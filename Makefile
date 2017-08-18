CC = gcc

all: clear compile run

clear:
	rm -f main
	rm -f main.o
	rm -f note.o
	rm -f queue.o
	clear

compile: main.o note.o queue.o
	$(CC) -o note main.o note.o queue.o

main.o:
	$(CC) -c main.c
note.o:
	$(CC) -c note.c
queue.o:
	$(CC) -c queue.c

run:
	
	./note list
	
