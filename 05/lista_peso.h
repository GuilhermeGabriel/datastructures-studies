// GUILHERME GABRIEL FERREIRA SOUZA
// 11921ECP001

// Uso da diretiva ifndef para caso a constante LISTA_PESO_H
// esteja definida, nao compilar o bloco de codigo novamente e evitar problemas.
#ifndef LISTA_PESO_H
#define LISTA_PESO_H

//Dados
typedef struct No {
  int v; // Vertice
  int peso; // Peso ate ele
  struct No *prox; // ponteiro para o proximo noh da lista ligada
} No;

// Implementacao de uma funcao que cria a lista ligada
No* criar_lista();

// Implementacao de uma funcao que remove todos
// os elementos da lista ligada da memoria
void destruir_lista(No* p);

// Implementacao de uma funcao que 
// insere um elemento (vertice) na lista ligada recebendo
// o valor e o peso ate ele

No* inserir_na_lista(No *p, int x, int w);

#endif
