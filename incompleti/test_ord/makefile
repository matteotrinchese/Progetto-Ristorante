main.exe: ordine.o queue.o list.o main.o
	gcc ordine.o queue.o list.o main.o -o main.exe

ordine.o: ordine.c 
	gcc -c ordine.c

queue.o: ordine.h queue.c 
	gcc -c queue.c

list.o: ordine.h list.c
	gcc -c list.c

main.o: queue.h ordine.h main.c 
	gcc -c main.c
