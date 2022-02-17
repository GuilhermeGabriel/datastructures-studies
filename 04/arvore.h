// GUILHERME GABRIEL FERREIRA SOUZA
// 11921ECP001

// Uso da diretiva ifndef para caso a constante ARVORE
// esteja definida, nao compilar o bloco de codigo novamente e evitar problemas.
#ifndef ARVORE
#define ARVORE

// Criacao de um tipo struct no que contem
// um dado e um ponteiro para o seu pai
typedef struct no {
  int dado;
  struct no *pai;
} No;

// Definicao de uma funcao de cria um noh da arvore
// recebendo o valor que o noh ira armazenar
No* criar_no(int x);

// Definicao de uma funcao link que recebe dois noh's: filho e pai
// linka o filho com o seu pai
void link(No* filho, No* pai);

// Definicao de uma funcao cut que recebe um noh
// e corta sua ligacao com o seu pai
void cut(No* no);

// Definicao de uma funcao lca que recebe dois noh's e 
// retorna qual o seu menor ancestral comum entre eles
int lca(No* a, No* b);

#endif