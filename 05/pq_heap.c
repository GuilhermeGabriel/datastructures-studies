#include <stdio.h>
#include <stdlib.h>
#include "pq_heap.h"

#define F_ESQ(i) (2*i+1) /*Filho esquerdo de i*/
#define F_DIR(i) (2*i+2) /*Filho direito de i*/
#define PAI(i) ((i-1)/2)
#define swap(a, b) {t_item tmp = *a; *a=*b; *b = tmp;}

PQ* pq_criar(int tam){
  PQ* p = (PQ*) malloc(sizeof(PQ));
  p->dados = (t_item*) malloc(tam * sizeof(t_item));
  p->idxs_vertices_heap = (int *) malloc(tam * sizeof(int));
  for(int i=0;i<tam;i++)p->idxs_vertices_heap[i]=-1;
  p->n = 0;
  p->tam = tam;
  return p;
}

void pq_destruir(PQ **p) {
  free((*p)->dados);
  free(*p);
  *p = NULL;
}

int prioridade(PQ *p, int v){
  int idx_vertice_dados=p->idxs_vertices_heap[v];
  return p->dados[idx_vertice_dados].priority;
}

/*
void set_dist_par_impar(PQ *p, int v, int par, int impar){
  int idx_vertice_dados=p->idxs_vertices_heap[v];
  p->dados[idx_vertice_dados].dist_par=par;
  p->dados[idx_vertice_dados].dist_impar=impar;
}

int dist_par(PQ *p, int v){
  int idx_vertice_dados=p->idxs_vertices_heap[v];
  return p->dados[idx_vertice_dados].dist_par;
}

int dist_impar(PQ *p, int v){
  int idx_vertice_dados=p->idxs_vertices_heap[v];
  return p->dados[idx_vertice_dados].dist_impar;
}*/

void pq_muda_prioridade(PQ *p, int ver, int priority){
  int idx_vertice_dados=p->idxs_vertices_heap[ver];
  p->dados[idx_vertice_dados].priority=priority;

  if(/*idx_vertice_dados==0 || */p->dados[PAI(idx_vertice_dados)].priority < p->dados[idx_vertice_dados].priority){
    desce_no_heap(p, idx_vertice_dados);
  }else{
    sobe_no_heap(p, idx_vertice_dados);
  }

}

int pq_vazia(PQ *p) {
  return p->n == 0;
}

int pq_cheia(PQ *p) {
  return p->n == p->tam;
}

void pq_adicionar(PQ *p, int v, int priority, int dist_par, int dist_impar){
  t_item item;
  item.priority=priority;
  item.dist_par=dist_par;
  item.dist_impar=dist_impar;
  item.vertice=v;

  p->dados[p->n] = item;

  //
  p->idxs_vertices_heap[item.vertice]=p->n;
  //

  p->n++;
  sobe_no_heap(p, p->n - 1);
}

void sobe_no_heap(PQ *p, int pos) {
  if (pos > 0 && p->dados[PAI(pos)].priority > p->dados[pos].priority) {

    //
    int v1=p->dados[PAI(pos)].vertice;
    int v2=p->dados[pos].vertice;  
    p->idxs_vertices_heap[v1]=pos;
    p->idxs_vertices_heap[v2]=PAI(pos);
    //

    swap(&p->dados[pos], &p->dados[PAI(pos)]);
    sobe_no_heap(p, PAI(pos));
  }
}

void desce_no_heap(PQ *p, int pos) {
  if (F_ESQ(pos) < p->n){

    int menor_filho = F_ESQ(pos);
    
    // se tem filho a direita
    if (F_DIR(pos) < p->n && p->dados[F_ESQ(pos)].priority > p->dados[F_DIR(pos)].priority){ 
      menor_filho = F_DIR(pos);
    }
    
    if (p->dados[pos].priority > p->dados[menor_filho].priority) {

      //
      int v1=p->dados[pos].vertice;
      int v2=p->dados[menor_filho].vertice;
      p->idxs_vertices_heap[v1]=menor_filho;
      p->idxs_vertices_heap[v2]=pos;
      //

      swap(&p->dados[pos], &p->dados[menor_filho]);
      desce_no_heap(p, menor_filho);
    }
  }
}

t_item pq_extrai_minimo(PQ *p) {
  t_item item = p->dados[0];

  //
  int v1=p->dados[0].vertice;
  int v2=p->dados[p->n - 1].vertice;
  p->idxs_vertices_heap[v1]=p->n - 1;
  p->idxs_vertices_heap[v2]=0;
  //

  swap(&p->dados[0], &p->dados[p->n - 1]);
  p->n--;
  desce_no_heap(p, 0);
  return item;
}