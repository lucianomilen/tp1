flow: main.o graph.o queue.o
	gcc -Wall -Wextra -Werror -std=c99 main.o graph.o queue.o -o flow -pedantic
main.o: main.c graph.h queue.h
	gcc -g -c main.c
flow.o: queue.h graph.h graph.c queue.c
	    gcc -g -c graph.c queue.c
clean:
	rm *.o
	rm flow
