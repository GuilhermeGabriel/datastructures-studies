// GUILHERME GABRIEL FERREIRA SOUZA
// 11921ECP001

// Biblioteca para entrada e saida de dados
#include <stdio.h>

// Interface para incluir tipo Pilha
// (Acaba incluindo tambem o tipo Lista, suas definicoes e implementacoes)
// e implementar as funcoes desta
#include "pilha.h"

// Biblioteca para manipulacao de strings
#include <string.h>

// Implementacao de uma funcao que cria uma pilha
void pilha_criar(Pilha** p){
  // Criar uma pilha é o mesmo que criar um tipo de lista
  cria_lista(p);
}

// Implementacao de uma funcao que insere no topo de uma pilha
void pilha_inserir(Pilha* p, char* valor){
  // Insere no comeco da lista
  insere_comeco(p, valor);
}

// Implementacao da funcao que retorna o valor que esta
// no topo da pilha
char* pilha_valor_topo(Pilha* p){
  // Topo da pilha eh igual ao proximo
  // elemento apos o no cabeca da lista
  Pilha *aux = p->prox;

  // Se ele nao for nulo retorna seu valor, caso contrario
  // retorna "cabeca", para indicar que so ha o noh cabeca 
  if(aux!=NULL) return aux->v;
  else return "cabeca";
}

// Implementacao da funcao que remove o topo da pilha
void pilha_remover(Pilha* p){
  // Remover topo da pilha eh o mesmo que remover o 
  // comeco da lista apos o no cabeca
  remove_comeco(p);
}

// Implementacao da funcao que retorna se a lista esta vazia ou nao
int pilha_vazia(Pilha* p){
  // Pega o primeiro elemento apos o noh cabeca
  Pilha *aux = p->prox;

  // Se ele for nulo, retorna 1 (lista vazia), caso contrario
  // retorna 0, (lista nao vazia)
  if(aux!=NULL) return 0;
  else return 1;
}

// Implementacao de uma funcao que imprime os noh's
// de uma pilha na ordem em que estao naturalmente
void pilha_imprimir_ordem_natural(Pilha* p){
  // Cria uma pilha auxiliar
  Pilha *Aux;pilha_criar(&Aux);

  // Remove elemento a elemento do topo da pilha
  // e adicionando-o em uma pilha auxiliar para no futuro
  // restaurar a pilha original

  // Enquanto houver elementos na pilha original
  while(!pilha_vazia(p)){
    // Printa o valor do topo da pilha original
    printf("%s\n",pilha_valor_topo(p));
    // Insere o topo da pilha original em uma pilha auxiliar
    pilha_inserir(Aux,pilha_valor_topo(p));
    // Remove o topo do pilha original
    pilha_remover(p);
  }

  // Enquanto houver elementos na pilha auxiliar
  while(!pilha_vazia(Aux)){
    // Insere o topo da pilha auxiliar na pilha original
    pilha_inserir(p,pilha_valor_topo(Aux));

    // Remove o topo da pilha auxiliar
    pilha_remover(Aux);
  }

  // Libera a pila auxiliar da memorias
  pilha_liberar(&Aux);
}

// Implementacao de uma funcao que imprime os noh's
// de uma pilha na ordem que foram inseridos
void pilha_imprimir_ordem_inserida(Pilha* p){
  // Cria uma pilha auxiliar
  Pilha *Aux;pilha_criar(&Aux);

  // Variavel para saber se estamos no ultimo elemento
  int elem=0;

  // Remove elemento a elemento do topo da pilha
  // e adicionando-o em uma pilha auxiliar para no futuro
  // restaurar a pilha original

  // Enquanto houver elementos na pilha original
  while(!pilha_vazia(p)){
    // Insere na pilha auxiliar o topo da pilha original
    pilha_inserir(Aux,pilha_valor_topo(p));

    // Remove o topo da pilha original e soma 1 no atual elemento
    pilha_remover(p);elem++;
  }

  // Enquanto houver elementos na pilha auxiliar
  while(!pilha_vazia(Aux)){
    // Se for o ultimo elemento, printa uma seta
    if(--elem==0)printf("--> ");
    // Printa o topo da auxiliar
    printf("%s\n",pilha_valor_topo(Aux));
    // Insere o elemento do topo da pilha auxiliar na pilha original
    pilha_inserir(p,pilha_valor_topo(Aux));

    // Remove o topo da pilha auxiliar
    pilha_remover(Aux);
  }
  // Libera a pilha auxiliar da memoria
  pilha_liberar(&Aux);
}

// Implementacao da funcao libera todos elementos da pilha da memoria
void pilha_liberar(Pilha** p){
  // Liberar todos elementos da pilha eh 
  // o mesmo que liberar todos elementos da lista
  libera_lista(p);
}
