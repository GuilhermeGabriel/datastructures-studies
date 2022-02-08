// GUILHERME GABRIEL FERREIRA SOUZA
// 11921ECP001

// Biblioteca para entrada e saida de dados
#include <stdio.h>

// Biblioteca para manipulacao de memoria
#include <stdlib.h>

// Interface para manipular arvores
#include "arvore.h"

// Implementacao de uma funcao mais simples (com menos parametros) para criar a arvore,
// ela recebe o percurso (array de char) em pre-ordem e em in-ordem, o tamanho
// do percurso e chama uma funcao recursiva que gera os filhos a partir dos dados recebidos
No* criaArvore(char *pre, char *in, int tam){
  return gera_filhos(pre,in,0,tam-1,tam);
}

// Implementacao de uma funcao com mais parametros para criar a arvore.
// Ela recebe o percurso (array de char) em pre-ordem, in-ordem, indice de inicio e fim
// do atual subvetor da in_order, o tamanho
// do percurso e chama a funcao recursivamente gerando os filhos.
// A ideia principal eh a de que o percurso em pre-ordem tem no inicio
// a raiz da arvore. Adicionamos essa raiz na arvore, e iremos em cada recursao encontrar onde
// essa raiz esta no percurso in_ordem e fazer a mesma chamada para a parte
// esquerda e direita de onde esta essa raiz encontrada no percurso in_ordem.
No* gera_filhos(char *pre, char *in, int i_index_in, int j_index_in, int tam){
  // Se o indice i do subvetor for maior que o j 
  // nao ha mais como prosseguir, retrona null cortando a recursao atual.
  if(i_index_in>j_index_in)return NULL;

  // Cria a variavel que armazena o indice da raiz do atual subvetor da in-order 
  int novo_index_in=0,c=1; // Varivel c usada para controle do loop, uma vez encontrado encerra o loop
  for(int m=0;m<=tam&&c;m++){// Percorre o vetor do percurso pre-order que armazena "ordem das raizes visitadas"
    // Percorre o subvetor atual da in-order encontrando o indice de onde esta sua raiz.
    for(int n=i_index_in;n<=j_index_in&&c;n++){ 
      if(pre[m]==in[n]){
        novo_index_in=n;
        c=0;
      }
    }
  }

  // Cria o noh que contem a raiz do atual subvetor da in-order
  No* no = criar_no(in[novo_index_in], NULL, NULL);

  // Se for uma folha, nao continua a recursao, apenas retorna o no atual;
  if(i_index_in==j_index_in)return no;

  // Chama recursivamente para a parte esquerda da raiz do atual subvetor da in-order
  // salvando o resultado na parte esquerda do atual noh criado.
  no->esq=gera_filhos(pre,in,i_index_in,novo_index_in-1,tam);

  // Chama recursivamente para a parte direita da raiz do atual subvetor da in-order
  // salvando o resultado na parte direita do atual noh criado.
  no->dir=gera_filhos(pre,in,novo_index_in+1,j_index_in,tam);

  // Retorna o no atual criado para quem chamou a recursao
  return no;
}

// Implementacao de uma funcao de cria um noh da arvore
// recebendo o valor que o noh ira armazenar, 
// seu noh filho da esquerda e seu noh filho da direita
No* criar_no(int x, No *l, No *r) {
  // Alocacao de memoria para um novo no
  No *no = (No*) malloc(sizeof(No));

  // Seta o valor q o noh armazena
  no->dado = x;
  
  // Seta noh filho da esquerda
  no->esq = l;

  // Seta noh filho da direita
  no->dir = r;

  // Retorna o noh
 return no;
}


// Implementacao de uma funcao recursiva que 
// mostra o percurso em pos-ordem
void pos_ordem(No *raiz) {
  // Se a raiz nao for nula
  if (raiz != NULL) {
    // Chama pos-ordem para a esquerda
    pos_ordem(raiz->esq);

    // Chama pos-ordem para a direita
    pos_ordem(raiz->dir);

    // Printa o valor do dado
    printf("%c", raiz->dado);
  }
}

// Implementacao de funcao recursiva que 
// elimina a arvore da memoria
void destruir_arvore(No **raiz){
  // Se a raiz for nula, esta vazia a arvore nao prossegue
  if (*raiz == NULL) return;

  // Chama destruir_arvore para o filho da esquerda
  destruir_arvore(&((*raiz)->esq));

  // Chama destruir_arvore para o filho da direita
  destruir_arvore(&((*raiz)->dir));

  // Libera o noh quando chega nas folhas da arvore
  free(*raiz);
  *raiz = NULL;
}
