FLAGS=-Wextra -Wall -Werror -pedantic -std=c99

all: start

start: main.o queue.o
	gcc $(FLAGS) -o lab26 main.o queue.o

main.o: main.c
	gcc -c $(FLAGS) main.c

queue.o: queue.h queue.c
	gcc -c $(FLAGS) queue.h queue.c

clean:
	-rm -f *.o *.gch lab26

lib: queue.o
	ar rc lib/libqueue.a queue.o
	ranlib lib/libqueue.a