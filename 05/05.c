#include <stdio.h>
#include "digrafo_lista_peso.h"
#include "pq_heap.h"

int main(){
  int c, v, a, b, p;scanf("%d %d", &c, &v);
  Grafo *aux = criar_digrafo(c);

  for(int i=0;i<v;i++){
    scanf("%d %d %d", &a, &b, &p);
    inserir_arco(aux,a-1,b-1,p);
    inserir_arco(aux,b-1,a-1,p);
  }

  Grafo *G = criar_digrafo(c);
  for(int i=0;i<c;i++){
    No *t;
    for (t = aux->L[i]; t != NULL; t = t->prox){
      int vizinho_de_i = t->v;
      int p1= t->peso;

       No *u;
       for (u = aux->L[vizinho_de_i]; u != NULL; u = u->prox){
        int adj = u->v;
        int p2= u->peso;

        if(adj!=i)inserir_arco(G,i,adj,p1+p2);
       }
    }
  }

  dijkstra_prioridade_dist_par(G,0);
   
  return 0;
}