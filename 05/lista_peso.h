#ifndef LISTA_PESO_H
#define LISTA_PESO_H

//Dados
typedef struct No {
  int v;
  int peso;
  struct No *prox;
} No;

No* criar_lista();

void destruir_lista(No* p);
No* inserir_na_lista(No *p, int x, int w);

#endif
