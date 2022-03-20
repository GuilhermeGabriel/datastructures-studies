// GUILHERME GABRIEL FERREIRA SOUZA
// 11921ECP001

// Biblioteca para entrada e saida de dados
#include <stdio.h>

// Biblioteca para manipulacao de memoria
#include <stdlib.h>

// Interface para manipular fila de prioridades (heap)
#include "pq_heap.h"

/*Macro que retorna filho esquerdo de i*/
#define F_ESQ(i) (2*i+1) 

/*Macro que retorna filho direito de i*/
#define F_DIR(i) (2*i+2) 

/*Macro que retorna pai de i*/
#define PAI(i) ((i-1)/2)

/*Macro que troca dois valores de lugar*/
#define swap(a, b) {t_item tmp = *a; *a=*b; *b = tmp;}

// Implementacao de uma funcao que cria uma heap
// recebendo seu tamanho
PQ* pq_criar(int tam){
  // Aloca memoria para a heap, seus elementos e um vetor de indices
  // que armazena a posicao de cada vertice na heap
  PQ* p = (PQ*) malloc(sizeof(PQ));
  p->dados = (t_item*) malloc(tam * sizeof(t_item));
  p->idxs_vertices_heap = (int *) malloc(tam * sizeof(int));
  for(int i=0;i<tam;i++)p->idxs_vertices_heap[i]=-1;
  
  // Seta a posicao para a proxima insercao no indice 0
  p->n = 0;

  // Seta a variavel que armazena o tamanho como o tamanho recebido
  p->tam = tam;

  // Retorna a heap
  return p;
}

// Implementacao de uma funcao que libera 
// o heap da memoria
void pq_destruir(PQ **p) {
  // Libera o array de dados e de indices
  free((*p)->dados);
  free((*p)->idxs_vertices_heap);

  // Libera a heap
  free(*p);
  *p = NULL;
}

// Implementacao de uma funcao que retorna a  
// prioridade de um vertice que esta na heap, eh usado
// o vetor de indices para acessar em O(1) o elemento na heap
int prioridade(PQ *p, int v){
  // Armazena qual o index do vertice no array de dados da heap
  int idx_vertice_dados=p->idxs_vertices_heap[v];

  // Retorna qual a sua prioridade
  return p->dados[idx_vertice_dados].priority;
}

// Implementacao de uma funcao que altera a
// prioridade de um elemento da heap. 
void pq_muda_prioridade(PQ *p, int ver, int priority){
  // Eh usado o vetor de indices para acessar em O(1) o elemento (vertice) na heap
  int idx_vertice_dados=p->idxs_vertices_heap[ver];

  // Altera-se sua prioridade
  p->dados[idx_vertice_dados].priority=priority;
 
  // Eh preciso corrigir a heap.
  // Caso a sua prioridade tenha maior valor que o seu pai, ela devera ou permanecer
  // no mesmo lugar ou descer na heap, caso contrario devera ou permanacer subir na heap.
  if(p->dados[PAI(idx_vertice_dados)].priority < p->dados[idx_vertice_dados].priority){
    desce_no_heap(p, idx_vertice_dados);
  }else{
    sobe_no_heap(p, idx_vertice_dados);
  }
}

// Implementacao de uma funcao que retorna se a heap esta vazia
int pq_vazia(PQ *p) {
  return p->n == 0;
}

// Implementacao de uma funcao que adiciona um elemento na heap
void pq_adicionar(PQ *p, int v, int priority){
  // Cria um novo elemento
  t_item item;
  item.priority=priority;
  item.vertice=v;
  
  // Seta ele no final do array de dados da heap
  p->dados[p->n] = item;

  // Atualiza sua posicao na heap la no array de indices 
  p->idxs_vertices_heap[item.vertice]=p->n;

  p->n++;
  // Chama a funcao sobe_na_heap corrigindo a heap
  sobe_no_heap(p, p->n - 1);
}

// Implementacao de uma funcao que corrige a heap subindo
// pra quando um elemento for inserido no final do array de dados da heap
void sobe_no_heap(PQ *p, int pos) {
  // Verifica se 'pos' ainda esta dentro do array de dados da heap
  // e caso esteja verifica se precisa subir ainda e caso precise troque o valor com o seu pai
  if (pos > 0 && p->dados[PAI(pos)].priority > p->dados[pos].priority) {

    // Para o vertice v1 e v2
    // salva no indice v1 e v2 do array de indice
    // a posicao onde v1 e v2 estara no array de dados da heap
    int v1=p->dados[PAI(pos)].vertice;
    int v2=p->dados[pos].vertice;  
    p->idxs_vertices_heap[v1]=pos;
    p->idxs_vertices_heap[v2]=PAI(pos);

    // Troca o valor do filho com o do pai
    swap(&p->dados[pos], &p->dados[PAI(pos)]);

    // Chama sobe na heap recursivamente
    sobe_no_heap(p, PAI(pos));
  }
}

// Implementacao de uma funcao que corrige a heap descendo
// pra quando um elemento for removido do 'topo' da heap
void desce_no_heap(PQ *p, int pos) {

  // Verifica se tem filho esquerdo
  if (F_ESQ(pos) < p->n){
    
    // Tomamos em um primeiro momento que o menor filho eh o da esquerda
    int menor_filho = F_ESQ(pos);
    
    // Verifica se tem filho a direita se ele eh menor do que o da esquerda que tomamos na linha anterior
    // caso o filho da direita seja menor, tomamos ele como menor filho
    if (F_DIR(pos) < p->n && p->dados[F_ESQ(pos)].priority > p->dados[F_DIR(pos)].priority){ 
      menor_filho = F_DIR(pos);
    }
    
    // Se o valor do pai eh maior do que o menor filho, troque o pai com o filho
    if (p->dados[pos].priority > p->dados[menor_filho].priority) {

      // Para o vertice v1 e v2
      // salva no indice v1 e v2 do array de indice
      // a posicao onde v1 e v2 estara no array de dados da heap
      int v1=p->dados[pos].vertice;
      int v2=p->dados[menor_filho].vertice;
      p->idxs_vertices_heap[v1]=menor_filho;
      p->idxs_vertices_heap[v2]=pos;

      // Troca o valor do filho com o do pai
      swap(&p->dados[pos], &p->dados[menor_filho]);

      // Chama desce na heap recursivamente
      desce_no_heap(p, menor_filho);
    }
  }
}


// Implementacao de uma funcao que extrai o minino da heap
t_item pq_extrai_minimo(PQ *p) {
  // O minino da heap esta no inicio do array de dados da heap
  t_item item = p->dados[0];

  // Para o vertice v1 e v2
  // salva no indice v1 e v2 do array de indice
  // a posicao onde v1 e v2 estara no array de dados da heap
  int v1=p->dados[0].vertice;
  int v2=p->dados[p->n - 1].vertice;
  p->idxs_vertices_heap[v1]=p->n - 1;
  p->idxs_vertices_heap[v2]=0;

  // Troca o valor extraido com o da ultima posicao
  // do array de dados da heap
  swap(&p->dados[0], &p->dados[p->n - 1]);

  // Diminui 1 na posicao onde ira adicionar na heap
  p->n--;

  // Chama desce na heap recursivamente
  desce_no_heap(p, 0);

  // Retorna o item extraido
  return item;
}