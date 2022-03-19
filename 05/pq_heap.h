#ifndef PQ_HEAP_H
#define PQ_HEAP_H

//Dados
typedef struct {
  int vertice, priority;
} t_item;

typedef struct {
  t_item *dados;
  int *idxs_vertices_heap;
  int tam, n;
} PQ;

//Funcoes
PQ* pq_criar(int tam);
void pq_destruir(PQ **p);

void pq_muda_prioridade(PQ *p, int ver, int priority);
int prioridade(PQ *p, int v);

void pq_adicionar(PQ *p, int v, int priority);
t_item pq_extrai_minimo(PQ *p);

void sobe_no_heap(PQ *p, int pos);
void desce_no_heap(PQ *p, int pos);

int pq_vazia(PQ* p);

#endif