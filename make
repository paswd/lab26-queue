FLAGS=-Wextra -Wall -Werror -pedantic -std=c99 -lm

all: start

start: main.o queue.o
	gcc $(FLAGS) -o lab26 -lm main.o queue.o
	rm main.o queue.o
	rm queue.h.gch

main.o: main.c
	gcc -c $(FLAGS) main.c

queue.o: queue.h queue.c
	gcc -c $(FLAGS) queue.h queue.c
