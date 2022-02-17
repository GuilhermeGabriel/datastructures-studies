// GUILHERME GABRIEL FERREIRA SOUZA
// 11921ECP001

// Biblioteca para entrada e saida de dados
#include <stdio.h>

// Biblioteca para manipulacao de memoria
#include <stdlib.h>

// Biblioteca importada para usar funcoes de operacoes de strings
#include <string.h>

// Interface para manipular arvores
#include "arvore.h"

int main(){
  // Criacao e leitura da quantidade de nos e de operacoes
  int n,m,a,b; scanf("%d %d", &n, &m);

  // Aloca um array de char dinamicamente para armazenar a operacao
  char *comando=(char*)malloc(5*sizeof(char));

  // Aloca uma array de No's dinamicamente com a quantidade
  // de arvores que terao na floresta inicial
  No** arvores=(No**)malloc((n+1)*sizeof(No*));
  for(int i=0;i<=n;i++)arvores[i]=criar_no(i);

  // Enquanto houver comandos
  while(m--){
    // Le o comando
    scanf("%s", comando);

    // Caso o comando seja o de lca
    if(strcmp(comando,"lca")==0){
      // Recebe os noh's que sao para encontrar o lca
      scanf("%d %d", &a, &b);
      // Printa o valor retornado pela funcao lca
      printf("%d\n",lca(arvores[a],arvores[b]));
    }

    // Caso o comando seja o de link
    if(strcmp(comando,"link")==0){
      // Recebe os nos que sao para fazer o link
      scanf("%d %d", &a, &b);

      // Se os noh's forem diferentes, chama a funcao
      // que faz o link dos mesmos
      if(a!=b)link(arvores[a],arvores[b]);
    }

    // Caso o comando seja o de cut
    if(strcmp(comando,"cut")==0){
      // Recebe o noh que eh para fazer o cut
      scanf("%d", &a);

      // Chama a funcao cut, passando o noh 
      // que eh para fazer o cut
      cut(arvores[a]);
    }
  }

  // Libera da memoria o array de No's alocado dinamicamente 
  // com a quantidade de arvores que terao na floresta inicial
  for(int i=0;i<=n;i++){
    free(arvores[i]);
  }
  free(arvores);

  // Libera o array de char que armazena cada comando
  free(comando);

  // Encerra o programa
  return 0;
}