CFLAGS= -Wall -Werror

all: 01

01: 01.c lista_dupla.o
	gcc $^ -o $@

%.o: %.c %.h
	gcc $(CFLAGS) -c $<