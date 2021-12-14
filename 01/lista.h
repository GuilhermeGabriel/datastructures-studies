#ifndef LISTA_H
#define LISTA_H

typedef struct no {
  int dado;
  struct no *prox;
} No;

No* criar_lista();
void destruir_lista(No **L);
void imprimir_lista(No *L);
void adicionar_final(No **L,int x);
void adicionar_inicio(No **L,int x);
void inverter_lista(No **p);
int lista_esta_vazia(No **L);
int obter_inicio(No **p);
void remover_inicio(No **p);
int tamanho_lista(No *L);
#endif
