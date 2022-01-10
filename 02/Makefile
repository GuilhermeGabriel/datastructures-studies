all: 02

02: 02.o lista.o pilha.o
	gcc 02.o lista.o pilha.o -lm -o 02

02.o: 02.c lista.h pilha.h
	gcc -Wall -Werror -c 02.c

lista.o: lista.c lista.h
	gcc -Wall -Werror -c lista.c

%.o: %.c %.h
	gcc -Wall -Werror -c $<