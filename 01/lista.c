#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* criar_lista(){
  return NULL;
}

void destruir_lista(No **L) {
  No *q;
  while(*L!=NULL){
    q=*L;
    *L=(*L)->prox;
    free(q);
  }
}

void imprimir_lista(No *L){
  No *q=L;
  while(q!=NULL){
    printf("%c",q->dado);
    q=q->prox;
  }
}

int lista_esta_vazia(No **L){
  No* q=*L;
  if(q==NULL)return 1;
  return 0;
}

void inverter_lista(No **L){
  No* ant=NULL;
  No* atual=*L;
  No* prox=NULL;
  while(atual!=NULL) {
    prox=atual->prox;
    atual->prox=ant;
    ant=atual;
    atual=prox;
  }
  *L=ant;
}

void adicionar_final(No **L,int x) {// p recebe &L
  No *aux,*q;
  q=(No*)malloc(sizeof(No));
  q->dado=x;
  q->prox=NULL;
  if(*L==NULL)*L=q;
  else{
    aux=*L;
    while(aux->prox!=NULL)aux=aux->prox;
    aux->prox = q;
  }
}

void adicionar_inicio(No **L,int x) {// p recebe &L
  No *q;
  q=(No*)malloc(sizeof(No));
  q->dado=x;
  q->prox=*L;
  *L=q;
}

int obter_inicio(No **p){
  No* q=*p;
  if(q==NULL)return -1;
  return q->dado;
}

void remover_inicio(No **p) {// p recebe &L
  No* q=*p;
  if(q==NULL) return;
  *p = q->prox;
  free(q);
}
