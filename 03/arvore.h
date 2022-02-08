#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

typedef struct no {
  int dado;
  struct no *esq, *dir;
} No;

No* criaArvore(char *pre, char *in, int tam);
No* gera_filhos(char *pre, char *in, int i_index_in, int j_index_in, int tam);
No* criar_no(int x, No *l, No *r);
void pre_ordem(No *raiz);
void pos_ordem(No *raiz);
void inordem(No *raiz);
void destruir_arvore(No **raiz);
void imprimir_arvore(No *raiz);
No* procurar_no(No *raiz, int x);
int numero_nos(No *raiz);
int altura(No *raiz);

#endif