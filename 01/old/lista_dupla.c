#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"

No* criar_lista(){
  return NULL;
}

void destruir_lista(No **p){
  if(*p==NULL)return; // lista vazia
  No *q=(*p)->prox,*aux;
  while(q!=*p){
    aux=q;
    q=q->prox;
    free(aux);
  }
  free(*p);
  *p=NULL;
}

void imprimir_lista(No *p){ // p recebe L
  No *q;
  if(p!=NULL){
    No *aux=p->ant;
    for(q=p;q!=aux;q=q->prox)printf("%d -> ",q->dado);
    printf("%d -> ",q->dado);
  }
  printf("NULL\n");
}

void adicionar_inicio(No **p, char c){ //p recebe &L
  No *q=(No*)malloc(sizeof(No));
  q->dado=c;
  if(*p==NULL){ //lista vazia
    *p=q;
    q->prox=q->ant = q;
  }else{
    No *aux=*p;
    q->ant=aux->ant;
    q->prox=aux;
    (aux->ant)->prox=q;
    aux->ant=q;
    *p=q;
  }
}

void adicionar_final(No **p, char c){ // p recebe L
  No *q=(No*)malloc(sizeof(No));
  q->dado=c;
  if(*p==NULL){ //lista vazia
    *p=q;
    q->prox=q->ant=q;
  }else{
    No *aux=(*p)->ant;
    (*p)->ant=q;
    q->prox=*p;
    aux->prox=q;
    q->ant=aux;
  }
}

int buscar_valor(No *p, char c){ // q recebe L
  if(p==NULL)return -1; //lista vazia
  No *q=p->ant;
  while(p!=q){
    if(p->dado == c)return 1; //true!
    p=p->prox;
  }
  if(p->dado==c)return 1; //true!
  return 0;//false == nao encontrou
}

int tamanho_lista(No *p){
  if (p==NULL)return 0; //lista vazia
  No *q;int tam=1;
  for(q=p;q!=p->ant;q=q->prox)tam++;
  return tam;
}
