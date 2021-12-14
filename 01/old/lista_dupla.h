#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

typedef struct no {
  char dado;
  struct no *prox, *ant;
} No;

No* criar_lista();
void destruir_lista(No **L);
void imprimir_lista(No *L);
void adicionar_inicio(No **L, char c);
void adicionar_final(No **L, char c);
int buscar_valor(No *L, char c);
int tamanho_lista(No *L);

#endif
