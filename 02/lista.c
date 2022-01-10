// GUILHERME GABRIEL FERREIRA SOUZA
// 11921ECP001

// Biblioteca para entrada e saida de dados
#include <stdio.h>

// Biblioteca para manipulacao de memoria
#include <stdlib.h>

// Biblioteca para manipulacao de strings
#include <string.h>

// Interface para incluir tipo Lista
// e implementar as funcoes desta
#include "lista.h"

// Implementacao de uma funcao que cria uma lista ligada
void cria_lista(Lista **l){
  // Alocacao de memoria para armzenar o primeiro no (Cabeca)
  Lista *q = (Lista*) malloc(sizeof(Lista));

  // Seta o valor igual a "cabeca", para saber q eh o primeiro noh
  strcpy(q->v,"cabeca");

  // Aponta o proximo igual null
  q->prox = NULL;

  // Seta o noh criado como primeiro elemento
  *l = q;
}

// Implementacao de uma funcao que insere no comeco da lista
void insere_comeco(Lista *l, char* valor){
  // Alocacao de memoria para armazenar o item
  Lista *q = (Lista*) malloc(sizeof(Lista));

  // Seta o valor recebido no valor do elemento
  strcpy(q->v,valor);

  // Seta o proximo do que entrou igual ao proximo da cabeca
  q->prox = l->prox;

  // Seta o proximo da cabeca igual ao que entrou
  l->prox = q;
}

// Implementacao de uma funcao que remove o comeco da lista
void remove_comeco(Lista *l){
  // Cria um ponteiro auxiliar q
  Lista *q;

  // Se a lista nao estivar sem elementos depois da cabeca
  if (l->prox != NULL){
    // Seta o auxilixar igual ao primeiro
    // elemento apos o no cabeca
    q = l->prox;

    // No cabeca aponta para o proximo do auxiliar
    l->prox = q->prox;

    // Libera o ponteiro auxiliar
    free(q);
  }
}

// Implementacao de uma funcao que libera a lista
void libera_lista(Lista **l){
  // Cria um ponteiro auxiliar q
  Lista *q;

  // Enquanto o noh cabeca nao for nulo
  while (*l != NULL) {
    // Seta o no auxiliar como o primeiro da lista
    q = *l;

    // Aponta o primeiro da lista para o proximo
    *l = (*l)->prox;

    // Libera o no auxiliar
    free(q);
  }
}