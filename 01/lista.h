#ifndef LISTA_H
#define LISTA_H

typedef struct no {
  char dado;
  struct no *prox;
} No;

No* criar_lista();
void destruir_lista(No **L);
void imprimir_lista(No *L);
void adicionar_final(No **L, char c);

#endif
