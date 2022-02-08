#include "arvore.h"

#include <stdio.h>
#include <stdlib.h>

No* criaArvore(char *pre, char *in, int tam){
  return gera_filhos(pre,in,0,tam-1,tam);
}

No* gera_filhos(char *pre, char *in, int i_index_in, int j_index_in, int tam){
  if(i_index_in>j_index_in)return NULL;

  int novo_index_raiz,novo_index_in,c=1;
  for(int m=0;m<=tam&&c;m++){
    for(int n=i_index_in;n<=j_index_in&&c;n++){
      if(pre[m]==in[n]){
        novo_index_raiz=m;
        novo_index_in=n;
        c=0;
      }
    }
  }

  No* no = criar_no(pre[novo_index_raiz], NULL, NULL);
  if(i_index_in==j_index_in)return no;

  no->esq=gera_filhos(pre,in,i_index_in,novo_index_in-1,tam);
  no->dir=gera_filhos(pre,in,novo_index_in+1,j_index_in,tam);

  return no;
}

No* criar_no(int x, No *l, No *r) {
  No *no = (No*) malloc(sizeof(No));
  no->dado = x;
  no->esq = l;
  no->dir = r;
 return no;
}

void destruir_arvore(No **raiz){//func¸˜ao recursiva
  if (*raiz == NULL) return;
  destruir_arvore(&((*raiz)->esq));
  destruir_arvore(&((*raiz)->dir));
  free(*raiz);
  *raiz = NULL;
}

void pre_ordem(No *raiz) {
  if (raiz != NULL) {
    printf("%c ", raiz->dado); /* visita raiz */
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
  }
}

void inordem(No *raiz) {
  if (raiz != NULL) {
    inordem(raiz->esq);
    printf("%c ", raiz->dado); /* visita raiz */
    inordem(raiz->dir);
  }
}

void pos_ordem(No *raiz) {
  if (raiz != NULL) {
    pos_ordem(raiz->esq);
    pos_ordem(raiz->dir);
    printf("%c", raiz->dado); /* visita raiz */
  }
}


void printnode(int x, int h) {
  int i;
  for (i = 0; i < h; i++) printf("-");
  printf("%2c\n", x);
}

void print(No *p, int h) {
  if (p == NULL)
  return;
  print(p->dir, h+1);
  printnode(p->dado, h);
  print(p->esq, h+1);
}

void imprimir_arvore(No *raiz){
  print(raiz, 0);
}

No* procurar_no(No *raiz, int x) {
  if (raiz == NULL || raiz->dado == x)
  return raiz;
  No *esq = procurar_no(raiz->esq, x);
  if (esq != NULL)
  return esq;
  return procurar_no(raiz->dir, x);
}

int numero_nos(No *raiz) {
  if (raiz == NULL)
  return 0;
  return numero_nos(raiz->esq) + numero_nos(raiz->dir) + 1;
}

int altura(No *raiz) {
  int h_esq, h_dir;
  if (raiz == NULL)
  return 0;
  h_esq = altura(raiz->esq);
  h_dir = altura(raiz->dir);
  return (h_esq > h_dir ? h_esq : h_dir) + 1;
}
