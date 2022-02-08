// GUILHERME GABRIEL FERREIRA SOUZA
// 11921ECP001

// Uso da diretiva ifndef para caso a constante ARVORE_BINARIA_H
// esteja definida, nao compilar o bloco de codigo novamente e evitar problemas.
#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

// Criacao de um tipo struct no que contem
// um dado e um ponteiro para o filho da esquerda e da direita.
typedef struct no {
  int dado;
  struct no *esq, *dir;
} No;

// Definicao de uma funcao mais simples (com menos parametros) para criar a arvore,
// ela recebe o percurso (array de char) em pre-ordem e em in-ordem, o tamanho
// do percurso e chama uma funcao recursiva que gera os filhos a partir dos dados
No* criaArvore(char *pre, char *in, int tam);

// Definicao de uma funcao com mais parametros para criar a arvore.
// Ela recebe o percurso (array de char) em pre-ordem, in-ordem, indice de inicio e fim
// do atual subvetor da in_order, o tamanho
// do percurso e chama a funcao recursivamente gerando os filhos.
No* gera_filhos(char *pre, char *in, int i_index_in, int j_index_in, int tam);

// Definicao de uma funcao de cria um noh da arvore
// recebendo o valor que o noh ira armazenar, 
// seu noh da esquerda e seu noh da direita
No* criar_no(int x, No *l, No *r);

// Definicao de uma funcao recursiva que 
// mostra o percurso em pos-ordem
void pos_ordem(No *raiz);

// Definicao de funcao recursiva que 
// elimina a arvore da memoria
void destruir_arvore(No **raiz);

#endif