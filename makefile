
test: ordine.o queue.o PQueue.o utili.o test.o
	gcc ordine.o queue.o PQueue.o utili.o test.o -o test


main: ordine.o queue.o PQueue.o utili.o main.o
	gcc ordine.o queue.o PQueue.o utili.o main.o -o main


ordine.o: ordine.c
	gcc -c ordine.c


queue.o: ordine.h queue.c
	gcc -c queue.c


PQueue.o: ordine.h PQueue.c
	gcc -c PQueue.c


utili.o: utili.c
	gcc -c utili.c


test.o: queue.h PQueue.h utili.h test.c
	gcc -c test.c


main.o: queue.h PQueue.h utili.h main.c
	gcc -c main.c


clean:
	rm -f *.o

