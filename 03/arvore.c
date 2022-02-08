// GUILHERME GABRIEL FERREIRA SOUZA
// 11921ECP001

// Biblioteca para entrada e saida de dados
#include <stdio.h>

// Biblioteca para manipulacao de memoria
#include <stdlib.h>

// Interface para manipular arvores
#include "arvore.h"

// Definicao de uma funcao mais simples de usar para criar a arvore
// ela recebe o percurso (array de char) em pre-ordem e em in-ordem, o tamanho
// do percurso e chama uma funcao recursiva que gera os filhos a partir dos dados
No* criaArvore(char *pre, char *in, int tam){
  return gera_filhos(pre,in,0,tam-1,tam);
}

// Definicao de uma funcao mais complexa de chamar para criar a arvore
// ela recebe o percurso (array de char) em pre-ordem e em in-ordem, o tamanho
// do percurso e chama uma funcao recursiva que gera os filhos
No* gera_filhos(char *pre, char *in, int i_index_in, int j_index_in, int tam){
  if(i_index_in>j_index_in)return NULL;

  int novo_index_in=0,c=1;
  for(int m=0;m<=tam&&c;m++){
    for(int n=i_index_in;n<=j_index_in&&c;n++){
      if(pre[m]==in[n]){
        novo_index_in=n;
        c=0;
      }
    }
  }

  No* no = criar_no(in[novo_index_in], NULL, NULL);
  if(i_index_in==j_index_in)return no;

  no->esq=gera_filhos(pre,in,i_index_in,novo_index_in-1,tam);
  no->dir=gera_filhos(pre,in,novo_index_in+1,j_index_in,tam);

  return no;
}

No* criar_no(int x, No *l, No *r) {
  No *no = (No*) malloc(sizeof(No));
  no->dado = x;
  no->esq = l;
  no->dir = r;
 return no;
}

void pos_ordem(No *raiz) {
  if (raiz != NULL) {
    pos_ordem(raiz->esq);
    pos_ordem(raiz->dir);
    printf("%c", raiz->dado); /* visita raiz */
  }
}

void destruir_arvore(No **raiz){//func¸˜ao recursiva
  if (*raiz == NULL) return;
  destruir_arvore(&((*raiz)->esq));
  destruir_arvore(&((*raiz)->dir));
  free(*raiz);
  *raiz = NULL;
}
