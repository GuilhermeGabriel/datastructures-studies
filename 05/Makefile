CFLAGS= -Wall -Werror -g

05: 05.o digrafo_lista_peso.o lista_peso.o pq_heap.o
	gcc -o 05 05.o digrafo_lista_peso.o lista_peso.o pq_heap.o

05.o: 05.c digrafo_lista_peso.h
	gcc -c ${CFLAGS} 05.c

digrafo_lista_peso.o: digrafo_lista_peso.c digrafo_lista_peso.h
	gcc -c ${CFLAGS} digrafo_lista_peso.c

lista_peso.o: lista_peso.c lista_peso.h
	gcc -c ${CFLAGS} lista_peso.c

pq_heap.o: pq_heap.c pq_heap.h
	gcc -c ${CFLAGS} pq_heap.c

