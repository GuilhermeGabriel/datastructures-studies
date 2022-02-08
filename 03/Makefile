

all: 03

03: 03.c arvore.o
	gcc $^ -o $@

$.o: %.c %.h
	gcc ${CFLAGS} -c $<