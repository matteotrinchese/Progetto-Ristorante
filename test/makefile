

test: ordine.o queue.o PQueue.o utili.o test.o
	gcc ordine.o queue.o PQueue.o utili.o test.o -o test


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


clean:
	rm -f *.o

