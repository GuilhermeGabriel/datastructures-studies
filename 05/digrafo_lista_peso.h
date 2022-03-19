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

void inserir_arco(Grafo *p, int u, int v, int w);
void remover_arco(Grafo *p, int u, int v);

//int tem_arco(Grafo *p, int u, int v);
void imprimir_arcos(Grafo *g);
int* dijkstra_prioridade_dist_par(Grafo *p, int u);

#endif