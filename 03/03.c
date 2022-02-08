// GUILHERME GABRIEL FERREIRA SOUZA
// 11921ECP001

// Biblioteca para entrada e saida de dados
#include <stdio.h>

// Biblioteca para manipulacao de memoria
#include <stdlib.h>

// Interface para manipular arvores
#include "arvore.h"

int main(){
  // Cria uma variavel para armazenar os casos de testes e
  // outra para armazenar o tamanho do percurso do caso de teste
  int c, n; 
  
  // Faz leitura da quantidade de casos de testes
  scanf("%d",&c);

  // Aloca dois arrays de char dinamicamente, um para
  // armazenar o percurso em pre-ordem e o outro em in-ordem
  char *pre=(char*)malloc(60*sizeof(char));
  char *in=(char*)malloc(60*sizeof(char));
  
  // Enquanto ainda houver casos de testes
  while(c--){
    // Faz leitura do tamanho do percurso do caso de teste
    // e os percursos em pre-ordem e em in-ordem
    scanf("%d %s %s",&n,pre,in);
    
    // Cria uma arvore passando o percurso em pre-ordem,
    // em in-ordem e o tamanho do percurso
    No* raiz = criaArvore(pre,in,n);

    // Printa o percuso em pos-ordem
    pos_ordem(raiz);
    printf("\n");

    // Limpa da memoria a arvore criada 
    destruir_arvore(&raiz);
  }

  // Limpa os dois arrays de char dinamicos, 
  // que armazenam o percurso
  free(pre);
  free(in);

  // Finaliza o programa
  return 0;
}