// GUILHERME GABRIEL FERREIRA SOUZA
// 11921ECP001

// Uso da diretiva ifndef para caso a constante DIGRAFO_LISTA_PESO_H
// esteja definida, nao compilar o bloco de codigo novamente e evitar problemas.

#ifndef DIGRAFO_LISTA_PESO_H
#define DIGRAFO_LISTA_PESO_H

// Interface para manipular lista ligada de noh com peso
#include "lista_peso.h"

// Interface para manipular fila de prioridade (heap)
#include "pq_heap.h"

//Dados
typedef struct {
  No **L; // Lista de adjacencias (armazena os vertices do digrafo e seus adjacentes)
  int n; // tamanho do digrafo
} Grafo;

// Definicao de uma funcao que cria um digrafo
// recebendo a quantiade de vertices
Grafo* criar_digrafo(int n);

// Definicao de uma funcao que libera 
// o digrafo da memoria.
void destruir_digrafo(Grafo *p);

// Definicao de uma funcao que cria um reconstroi um digrafo
// seguindo a regra onde a aresta(a,b,p1) e aresta(b,c,p2) do digrafo recebido
// ira se tornar a aresta(a,c,p1+p2) do digrafo reconstruido.
void reconstroi_grafo(Grafo* p, Grafo* g);

// Definicao de uma funcao que insere um arco no digrafo
// de u a v com peso 'peso'.
// No indice 'u' do array insere um elemento v com peso 'peso'.
void inserir_arco(Grafo *p, int u, int v, int w);

// Definicao de funcao dijkstra para o digrafo reconstruido.
// O (dijkstra) no digrafo reconstruido (usando pares de arestas)
// ira nos responder se existe caminho minimo usando um numero par de
// arestas e sua distancia minima.
int dijkstra_quant_arest_par(Grafo *p, int u);

#endif