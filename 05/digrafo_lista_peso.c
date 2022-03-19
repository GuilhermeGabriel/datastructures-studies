#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "digrafo_lista_peso.h"

Grafo* criar_digrafo(int n) {
  Grafo *g = (Grafo*) malloc(sizeof(Grafo));
  g->n = n;
  g->L = (No**) malloc(n * sizeof(No*));
  for (int i=0;i<n;i++)g->L[i]=criar_lista();
  return g;
}

void reconstroi_grafo(Grafo* p, Grafo *g){
  for(int i=0;i<p->n;i++){
    No *t;
    for (t = p->L[i]; t != NULL; t = t->prox){
      int vizinho_de_i = t->v;
      int p1 = t->peso;

       No *u;
       for (u = p->L[vizinho_de_i]; u != NULL; u = u->prox){
        int adj = u->v;
        int p2 = u->peso;

        if(adj!=i)inserir_arco(g,i,adj,p1+p2);
       }
    }
  }
}

void destruir_digrafo(Grafo *g) {
  for(int i=0;i<g->n;i++)destruir_lista(g->L[i]); 
  free(g->L);
  free(g);
}

void inserir_arco(Grafo *p, int u, int v, int peso) {
  p->L[u] = inserir_na_lista(p->L[u], v, peso);
}

int dijkstra_quant_arest_par(Grafo *p, int u){
  int *pai = (int*) malloc(p->n * sizeof(int));
  int *distancia = (int*) malloc(p->n * sizeof(int));
  int *vis = (int*) malloc(p->n * sizeof(int));

  PQ *Fila = pq_criar(p->n); // Heap de MIN

  for (int v = 0; v < p->n; v++){
    pai[v]=-1;
    distancia[v]=-1;
    vis[v]=0;
    pq_adicionar(Fila, v, INT_MAX);
  }

  pai[u] = u;
  pq_muda_prioridade(Fila, u, 0);
  
  while (!pq_vazia(Fila)){
    t_item aux = pq_extrai_minimo(Fila);
    int v = aux.vertice;
    int dist_v = prioridade(Fila, v);

    distancia[v] = dist_v;
    
    if(dist_v == INT_MAX)break;

    No *t;
    for (t = p->L[v]; t != NULL; t = t->prox){
      int w = t->v;
      int peso = t->peso;

      if (dist_v + peso < prioridade(Fila, w)){
        pq_muda_prioridade(Fila, w, dist_v+peso);
        pai[w] = v;
      }
    }
  }
    
  int atual=pai[p->n-1];
  while(atual!=0){
    if(atual==-1||vis[atual])break;
    else vis[atual]=1;
    atual=pai[atual];
  }

  int resultado;
  if(atual!=0 || distancia[p->n-1]==INT_MAX){
    resultado = -1;
  }else{
    resultado = distancia[p->n-1];
  }

  pq_destruir(&Fila);
  
  free(pai);
  free(distancia);
  free(vis);  

  return resultado;
}