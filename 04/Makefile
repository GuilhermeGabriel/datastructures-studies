CFLAGS= -Wall -Werror -g

all: 04

04: 04.c arvore.o
	gcc $^ -g -o $@

$.o: %.c %.h
	gcc ${CFLAGS} -c -g $<