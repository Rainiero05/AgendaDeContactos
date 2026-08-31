agenda: main.o agenda.o
	gcc -Wall -Wextra -std=c99 -o agenda main.o agenda.o

clean:
	rm -f *.o agenda
