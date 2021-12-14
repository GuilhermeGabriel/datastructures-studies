#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* criar_lista(){
  return NULL;
}

void destruir_lista(No **p) {
  No *q;
  while(*p!=NULL){
    q=*p;
    *p=(*p)->prox;
    free(q);
  }
}

void imprimir_lista(No *p){
  No *q=p;
  while(q!=NULL){
    printf("%c",q->dado);
    q=q->prox;
  }
}

void adicionar_final(No **p, char c) {// p recebe &L
  No *aux,*q;
  q=(No*)malloc(sizeof(No));
  q->dado=c;
  q->prox=NULL;
  if(*p==NULL)*p=q;
  else{
    aux=*p;
    while(aux->prox!=NULL)aux=aux->prox;
    aux->prox = q;
  }
}