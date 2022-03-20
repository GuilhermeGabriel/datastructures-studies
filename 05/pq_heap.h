// GUILHERME GABRIEL FERREIRA SOUZA
// 11921ECP001

// Uso da diretiva ifndef para caso a constante PQ_HEAP_H
// esteja definida, nao compilar o bloco de codigo novamente e evitar problemas.
#ifndef PQ_HEAP_H
#define PQ_HEAP_H

//Dados
typedef struct {
  int vertice, priority; // Armazena o vertice e sua prioridade
} t_item;

typedef struct {
  // Array de dados da heap
  t_item *dados; 

  // Array de indices que armazena a posicao
  // de cada vertice no array de dados heap
  int *idxs_vertices_heap;
  
  // Tamanho da heap e posicao para adicionar novo elemento
  int tam, n;
} PQ;

// Definicao de uma funcao que cria uma heap
// recebendo seu tamanho
PQ* pq_criar(int tam);

// Definicao de uma funcao que libera 
// o heap da memoria
void pq_destruir(PQ **p);

// Definicao de uma funcao que altera a
// prioridade de um elemento da heap. 
void pq_muda_prioridade(PQ *p, int ver, int priority);

// Definicao de uma funcao que retorna a  
// prioridade de um vertice que esta na heap, eh usado
// o vetor de indices para acessar em O(1) o elemento na heap
int prioridade(PQ *p, int v);

// Definicao de uma funcao que adiciona um elemento na heap
void pq_adicionar(PQ *p, int v, int priority);

// Definicao de uma funcao que extrai o minino da heap
t_item pq_extrai_minimo(PQ *p);

// Definicao de uma funcao que corrige a heap subindo
// pra quando um elemento for inserido no final do array de dados da heap
void sobe_no_heap(PQ *p, int pos);

// Definicao de uma funcao que corrige a heap descendo
// pra quando um elemento for removido do 'topo' da heap
void desce_no_heap(PQ *p, int pos);

// Definicao de uma funcao que retorna se a heap esta vazia
int pq_vazia(PQ* p);

#endif