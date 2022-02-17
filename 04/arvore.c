// GUILHERME GABRIEL FERREIRA SOUZA
// 11921ECP001

// Biblioteca para entrada e saida de dados
#include <stdio.h>

// Biblioteca para manipulacao de memoria
#include <stdlib.h>

// Interface para manipular arvores
#include "arvore.h"

// Biblioteca importada para usar a funcao memset
#include <string.h>

// Implementacao de uma funcao de cria um noh da arvore
// recebendo o valor que o noh ira armazenar.
No* criar_no(int x) {
  // Alocacao de memoria para um novo no
  No *no = (No*) malloc(sizeof(No));

  // Seta o valor q o noh armazena
  no->dado = x;

  // Seta o seu pai como nulo
  no->pai = NULL;

  // Retorna o noh
 return no;
}

// Implementacao de uma funcao link que recebe dois noh's: filho e pai
// e para conectar seta o apontador pai do noh filho como o noh pai recebido.
void link(No* filho, No* pai){
  filho->pai=pai;
}

// Implementacao de uma funcao cut que recebe um noh
// e corta sua ligacao com o seu pai, setando o apontador
// pai do noh como null
void cut(No* no){
  no->pai=NULL;
}

// Implementacao de uma funcao lca que recebe dois noh's e 
// retorna qual o menor ancestral comum entre eles.

// A ideia usada foi, como os dois noh's estao necessariamente
// na mesma arvore, para cada noh recebido percorrer o caminho
// ate a sua raiz armazenando em um vetor.
// Depois percorrendo os caminhos armazenados da raiz ate os noh's,
// verifa-se o momento (noh) em que os caminhos se diferenciarem, 
// um noh anterior sera o lca.  
int lca(No* a, No* b){
  // Aloca dois arrays de inteiros dinamicamente para armazenar os caminhos
  int *caminho_ate_raiz_A=(int*)malloc(1005*sizeof(int));
  int *caminho_ate_raiz_B=(int*)malloc(1005*sizeof(int));

  // Variaveis para controle de indice dos arrays e resultado do lca
  int i=0,j=0,resultado_lca;

  // Seta todos os valores dos arrays como 0 (noh's tem valor 1<=N)
  memset(caminho_ate_raiz_A,0,1005*sizeof(int));
  memset(caminho_ate_raiz_B,0,1005*sizeof(int));

  // Noh's auxiliares para ir percorrendo dos noh's ate a raiz
  No *aux_a=a, *aux_b=b;

  // Caminho do A ate raiz
  // Enquanto auxiliar nao estiver na raiz da arvore
  // adiciona o valor do noh no array do caminho e 
  // recebe auxiliar como o noh pai do noh auxiliar.
  while(aux_a->pai!=NULL){
    caminho_ate_raiz_A[i++]=aux_a->dado;
    aux_a=aux_a->pai;
  }
  caminho_ate_raiz_A[i++]=aux_a->dado;
  
  // Caminho do B ate raiz
  // Enquanto auxiliar nao estiver na raiz da arvore
  // adiciona o valor do noh no array do caminho e 
  // recebe auxiliar como o noh pai do noh auxiliar.
  while(aux_b->pai!=NULL){
    caminho_ate_raiz_B[j++]=aux_b->dado;
    aux_b=aux_b->pai;
  }
  caminho_ate_raiz_B[j++]=aux_b->dado;

  // Percorrendo os caminhos armazenados da raiz ate os noh's,
  // verifa-se o momento (noh) em que os caminhos se diferenciarem, 
  // um noh anterior sera o lca
  while((i>=0&&j>=0)&&caminho_ate_raiz_A[i]==caminho_ate_raiz_B[j]){
    i--;
    j--;
  }

  // Salva o resultado do lca antes de liberar a memoria do array
  // (O valor do noh anterior do momento em que
  // os caminhos (noh's) se diferenciaram)
  resultado_lca=caminho_ate_raiz_A[i+1];

  // Libera os arrays alocados para armazenar os caminhos
  free(caminho_ate_raiz_A);
  free(caminho_ate_raiz_B);
  
  // Retorna resultado do lca
  return resultado_lca;
}
