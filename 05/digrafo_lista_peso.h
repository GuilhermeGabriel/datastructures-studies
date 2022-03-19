#ifndef DIGRAFO_LISTA_PESO_H
#define DIGRAFO_LISTA_PESO_H

#include "lista_peso.h"
#include "pq_heap.h"

//Dados
typedef struct {
  No **L; //Lista de adjacencias
  int n;
} Grafo;

//Funcoes
Grafo* criar_digrafo(int n);
void destruir_digrafo(Grafo *p);

void reconstroi_grafo(Grafo* p, Grafo* g);
void inserir_arco(Grafo *p, int u, int v, int w);

int dijkstra_quant_arest_par(Grafo *p, int u);

#endif