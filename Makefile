a.out: main.o vector.o converter.o stack.o interfejs.o
	$(CC) -o a.out main.o vector.o converter.o stack.o interfejs.o
vector.o: vector.c 
	$(CC) -c vector.c
converter.o: converter.c stack.h
	$(CC) -c converter.c
interfejs.o: interfejs.c  vector.h converter.h
	$(CC) -c interfejs.c
stack.o: stack.c
	$(CC) -c stack.c

.PHONY: clean

clean:
	-rm *.o a.out 

