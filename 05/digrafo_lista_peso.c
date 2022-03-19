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

void destruir_digrafo(Grafo *g) {
  for(int i=0;i<g->n;i++)destruir_lista(g->L[i]); 
  free(g->L);
  free(g);
}

void inserir_arco(Grafo *p, int u, int v, int peso) {
  p->L[u] = inserir_na_lista(p->L[u], v, peso);
}

void remover_arco(Grafo *p, int u, int v) {
  p->L[u] = remover_da_lista(p->L[u], v);
}

void imprimir_arcos(Grafo *p) {
  for (int u = 0; u < p->n; u++){
    printf("%d: ", u); //imprime como um int
    imprimir_lista(p->L[u]);
  }
}

int* dijkstra_prioridade_dist_par(Grafo *p, int u){ // O(|V|+|E| lg(|V|))
  int *pai = (int *)malloc(p->n * sizeof(int));
  int *processado = (int*)malloc(p->n * sizeof(int));
  int *dist_copy = (int*)malloc(p->n * sizeof(int));
  int *visp = (int*)malloc(p->n * sizeof(int));

  PQ *Fila = pq_criar(p->n); // Heap de MIN

  for (int v = 0; v < p->n; v++){ // O(|V|lg|V|)
    pai[v] = -1;
    dist_copy[v]=-1;
    visp[v]=0;
    //processado[v]=0;
    pq_adicionar(Fila, v, INT_MAX, INT_MAX, INT_MAX); // O(lg|V|)
  }

  pai[u] = u;
  pq_muda_prioridade(Fila, u, 0);
  //set_dist_par_impar(Fila, u, 0, INT_MAX);
  
  while (!pq_vazia(Fila)){ // O(|E|lg|V|)
    t_item aux = pq_extrai_minimo(Fila);//Fila->dados[0];//(Fila);
    int v = aux.vertice;
    int dist_v = prioridade(Fila, v);

    dist_copy[v]=dist_v;
    
    //if(dist_v == INT_MAX)break;

    int dist_v_impar = dist_impar(Fila, v);
    int dist_v_par = dist_par(Fila, v);

    //if(d>dist[v].F and d>dist[v].S)continue;
    if (processado[v]) continue;
    processado[v] = 1;

    No *t;
    for (t = p->L[v]; t != NULL; t = t->prox){
      int w = t->v;
      int peso = t->peso;

      if (dist_v + peso < prioridade(Fila, w)){
        pq_muda_prioridade(Fila, w, dist_v+peso); // O(lg|V|)
        pai[w] = v;
      }

/*
      if (dist_v_impar + peso < dist_par(Fila, w)){
        set_dist_par_impar(Fila, w, dist_v_par+peso, dist_v_impar);
      }

      if (dist_v_par + peso < dist_impar(Fila, w)){
        set_dist_par_impar(Fila, w, dist_v_par, dist_v_impar+peso);
      }*/
    }
    //if(pq_vazia(Fila))
  }
    
  // for(int i=0;i<6;i++)
  //  printf("%d\n",Fila->dados[i].priority);  

  int *res = pai;
 //int atual=res[c-1],ant=-1,antant=-1;
  int atual=res[Fila->tam-1];
  while(atual!=0){
    if(visp[atual])break;
    else visp[atual]=1;

    atual=res[atual];
  }

  if(atual!=0 || dist_copy[Fila->tam-1]==INT_MAX){
    printf("-1\n");
  }else{
    printf("%d\n",dist_copy[Fila->tam-1]);
  }

  pq_destruir(&Fila);
  
  return pai;
}