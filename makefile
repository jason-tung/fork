all: main.o
	gcc -o fun main.o
main.o: main.c
	gcc -c main.c
clean:
	rm *.o
run:
	./fun