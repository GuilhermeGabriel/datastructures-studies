#ifndef LISTA_H
#define LISTA_H

typedef struct no {
  int dado;
  struct no *prox;
} No;

No* criar_lista();

void inverter_lista(No **p);
void imprimir_lista(No *L);
void destruir_lista(No **L);
int lista_esta_vazia(No **L);
void adicionar_noh_final(No **L,int x);
void adicionar_noh_inicio(No **L,int x);
int obter_inicio(No **p);
void remover_inicio(No **p);
void concatenar_lista_final(No **A, No **B);
void concatenar_lista_inicio(No **A, No **B);
void substituir_elemento_na_lista(No *L, int a, int b);

#endif
