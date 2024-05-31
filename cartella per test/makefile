main.exe: ordine.o queue.o PQueue.o utili.o main.o
	gcc ordine.o queue.o PQueue.o utili.o main.o -o main.exe

ordine.o: ordine.c 
	gcc -c ordine.c

queue.o: ordine.h queue.c 
	gcc -c queue.c

PQueue.o: ordine.h PQueue.c
	gcc -c PQueue.c

utili.o: utili.c
	gcc -c utili.c

main.o: queue.h ordine.h main.c 
	gcc -c main.c