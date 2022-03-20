// GUILHERME GABRIEL FERREIRA SOUZA
// 11921ECP001

// Biblioteca para entrada e saida de dados
#include <stdio.h>

// Biblioteca para manipulacao de memoria
#include <stdlib.h>

// Interface para manipular lista ligado com peso
#include "lista_peso.h"

// Implementacao de uma funcao que cria a lista ligada
No* criar_lista(){
  return NULL;
}

// Implementacao de uma funcao que remove todos
// os elementos da lista ligada da memoria
void destruir_lista(No* p) {
  // Enquanto o noh n for nulo, 
  // chama destruir para o seu sucessor
  if (p != NULL) {
    destruir_lista(p->prox);
    // remove o no da memoria
    free(p);
  }
}

// Implementacao de uma funcao que 
// insere um elemento (vertice) na lista ligada recebendo
// o valor e o peso ate ele
No* inserir_na_lista(No *p, int x, int w) {
  // aloca memoria para ele
  No *novo = malloc(sizeof(No));
  // Seta o valor do seu vertice
  novo->v = x;
  // Seta seu peso
  novo->peso = w;
  // insere o novo elemento na lista
  novo->prox = p;
  // retorna o noh criado
  return novo;
}

