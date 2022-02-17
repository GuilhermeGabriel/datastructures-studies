// GUILHERME GABRIEL FERREIRA SOUZA
// 11921ECP001

// Biblioteca para entrada e saida de dados
#include <stdio.h>

// Biblioteca para manipulacao de memoria
#include <stdlib.h>

// Interface para manipular arvores
#include "arvore.h"

#include <string.h>

// Implementacao de uma funcao de cria um noh da arvore
// recebendo o valor que o noh ira armazenar, 
// seu noh filho da esquerda e seu noh filho da direita
No* criar_no(int x, No *l, No *r) {
  // Alocacao de memoria para um novo no
  No *no = (No*) malloc(sizeof(No));

  // Seta o valor q o noh armazena
  no->dado = x;
  
  // Seta noh filho da esquerda
  no->esq = l;

  // Seta noh filho da direita
  no->dir = r;

  no->pai = NULL;

  // Retorna o noh
 return no;
}

// Implementacao de funcao recursiva que 
// elimina a arvore da memoria
void destruir_arvore(No **raiz){
  // Se a raiz for nula, esta vazia a arvore nao prossegue
  if (*raiz == NULL) return;

  // Chama destruir_arvore para o filho da esquerda
  destruir_arvore(&((*raiz)->esq));

  // Chama destruir_arvore para o filho da direita
  destruir_arvore(&((*raiz)->dir));

  // Libera o noh quando chega nas folhas da arvore
  free(*raiz);
  *raiz = NULL;
}

void link(No* filho, No* pai){
  if(pai->esq==NULL){
    pai->esq=filho;
    filho->pai=pai;
    return;
  }

  if(pai->dir==NULL){
    pai->dir=filho;
    filho->pai=pai;
    return;
  }
}

void cut(No* no){
  if(no->pai==NULL)return;
  No* pai=no->pai;
  if((pai->esq)!=NULL&&(pai->esq)->dado==no->dado)pai->esq=NULL;
  if((pai->dir)!=NULL&&(pai->dir)->dado==no->dado)pai->dir=NULL;
  no->pai=NULL;
}

void lca(No* a, No* b){
  int *caminho_ate_raiz_A=(int*)malloc(1005*sizeof(int));
  int *caminho_ate_raiz_B=(int*)malloc(1005*sizeof(int));
  int i=0,j=0;

  memset(caminho_ate_raiz_A,0,1005*sizeof(int));
  memset(caminho_ate_raiz_B,0,1005*sizeof(int));

  No *aux_a=a, *aux_b=b;

  // caminho do A ate raiz
  while(aux_a->pai!=NULL){
    caminho_ate_raiz_A[i++]=aux_a->dado;
    aux_a=aux_a->pai;
  }
  caminho_ate_raiz_A[i++]=aux_a->dado;
  
  // caminho do B ate raiz
  while(aux_b->pai!=NULL){
    caminho_ate_raiz_B[j++]=aux_b->dado;
    aux_b=aux_b->pai;
  }
  caminho_ate_raiz_B[j++]=aux_b->dado;

  /*
  printf("lca %d%d\n",a->dado,b->dado);
  for(int m=i-1;m>=0;m--)printf("%d",caminho_ate_raiz_A[m]);
  printf("\n");
  for(int m=j-1;m>=0;m--)printf("%d",caminho_ate_raiz_B[m]);
  printf("\n");*/

  while((i>=0&&j>=0)&&caminho_ate_raiz_A[i]==caminho_ate_raiz_B[j]){
    i--;j--;
  }
  
  //printf("\n\n");

  printf("%d\n",caminho_ate_raiz_A[i+1]);

  free(caminho_ate_raiz_A);
  free(caminho_ate_raiz_B);
  //printf("\n\n");
}

void printnode(int x, int h) {
  int i;
  for (i = 0; i < h; i++) printf("-");
  printf("%2d\n", x);
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
  if (raiz == NULL || raiz->dado == x) return raiz;
  No *esq = procurar_no(raiz->esq, x);
  if (esq != NULL) return esq;
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
