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
No* remover_da_lista(No* p, int x);

int buscar_valor(No *p, int x);
int imprimir_lista(No *p);
  

#endif
