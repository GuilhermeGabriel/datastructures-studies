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
  struct no *esq, *dir, *pai;
} No;

// Definicao de uma funcao de cria um noh da arvore
// recebendo o valor que o noh ira armazenar, 
// seu noh da esquerda e seu noh da direita
No* criar_no(int x, No *l, No *r);

// Definicao de funcao recursiva que 
// elimina a arvore da memoria
void destruir_arvore(No **raiz);

void imprimir_arvore(No *raiz);
No* procurar_no(No *raiz, int x);
int numero_nos(No *raiz);
int altura(No *raiz);
void link(No* filho, No* pai);
void cut(No* no);
void lca(No* a, No* b);

#endif