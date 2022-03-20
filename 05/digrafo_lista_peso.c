// GUILHERME GABRIEL FERREIRA SOUZA
// 11921ECP001

// Biblioteca para entrada e saida de dados
#include <stdio.h>

// Biblioteca para manipulacao de memoria
#include <stdlib.h>

// Biblioteca para usar a constante INT_MAX
#include <limits.h>

// Interface para manipular digrafos
#include "digrafo_lista_peso.h"

// Implementacao de uma funcao que cria um digrafo
// recebendo a quantiade de vertices
Grafo* criar_digrafo(int n) {
  //Aloca memoria dinamicamente para o digrafo
  Grafo *g = (Grafo*) malloc(sizeof(Grafo));

  // Seta sua quantidade de vertices
  g->n = n;

  // Aloca um array de noh's onde cada indice representa um vertice.
  // Cada vertice eh uma lista ligada que contem os vertices a que ele 
  // esta ligado e o peso para ir ate o mesmo.
  g->L = (No**) malloc(n * sizeof(No*));
  for (int i=0;i<n;i++)g->L[i]=criar_lista();

  // retorna esse grafo
  return g;
}

// Implementacao de uma funcao que cria um reconstroi um digrafo
// seguindo a regra onde a aresta(a,b,p1) e aresta(b,c,p2) do digrafo recebido
// ira se tornar a aresta(a,c,p1+p2) do digrafo reconstruido.
void reconstroi_grafo(Grafo* p, Grafo *g){
  // Pra todos os vertices i do grafo
  for(int i=0;i<p->n;i++){

    // Olha para vertices vizinhos de i
    No *t;
    for (t = p->L[i]; t != NULL; t = t->prox){
      int vizinho_de_i = t->v;
      int p1 = t->peso;
        
       // Olha para os vizinhos dos vizinhos de i
       No *u;
       for (u = p->L[vizinho_de_i]; u != NULL; u = u->prox){
        int adj = u->v;
        int p2 = u->peso;

        // Cria uma arco no novo digrafo, saindo do vertice i para cada
        // vizinho dos vizinhos de i com o peso do caminho das duas arestas.
        if(adj!=i)inserir_arco(g,i,adj,p1+p2);
       }
    }
  }
}

// Implementacao de uma funcao que libera 
// o digrafo da memoria
void destruir_digrafo(Grafo *g) {
  // Chama a funcao de destruir cada lista ligada 
  // que esta no array de lista ligada
  for(int i=0;i<g->n;i++)destruir_lista(g->L[i]); 

  // Libera a lista
  free(g->L);

  // Libera o grafo
  free(g);
}

// Implementacao de uma funcao que insere um arco no digrafo
// de u a v com peso 'peso'.
// No indice 'u' do array insere um elemento v com peso 'peso'.
void inserir_arco(Grafo *p, int u, int v, int peso) {
  p->L[u] = inserir_na_lista(p->L[u], v, peso);
}

// Implementacao de funcao dijkstra para o digrafo reconstruido.
// O (dijkstra) no digrafo reconstruido (usando pares de arestas)
// ira nos responder se existe caminho minimo usando um numero par de
// arestas e sua distancia minima.
int dijkstra_quant_arest_par(Grafo *p, int u){
  // Alocacao dinamica de 3 arrays

  // Array pai que armazena o pai de cada vertice, podendo no fim
  // ter o 'path' em si do menor caminho.
  int *pai = (int*) malloc(p->n * sizeof(int));

  // Array usado para armazenar a distancia (minima)
  // para aquele vertice, assim que o vertice sai da fila de prioridades.
  int *distancia = (int*) malloc(p->n * sizeof(int));

  // Array usado para saber se um vertice ja foi visitado no momento
  // que estou percorrendo o 'path' criado, isso ira evitar que
  // o algoritmo entre em loop infinito.
  int *vis = (int*) malloc(p->n * sizeof(int));

  // Cria a heap com tamanho n (heap de min), seu tamanho nao eh aumentado.
  PQ *Fila = pq_criar(p->n);

  // Preenche o vetor de pais, de distancia, 
  // de visitados, e a fila de prioridade com os vertices
  // todos com distancia infinita seguindo a logica do dijkstra.
  for (int v = 0; v < p->n; v++){
    pai[v]=-1;
    distancia[v]=-1;
    vis[v]=0;
    pq_adicionar(Fila, v, INT_MAX);
  }

  // O pai do primeiro vertice eh ele msm
  pai[u] = u;

  // Muda a distancia do primeiro vertice para 0
  // pois comecamos dele.
  pq_muda_prioridade(Fila, u, 0);
  
  // Enquanto a fila de prioridade nao for vazia
  while (!pq_vazia(Fila)){
    // Extrai o valor com maior prioridade (menor distancia)
    // da fila.
    t_item aux = pq_extrai_minimo(Fila);
    int v = aux.vertice;
    int dist_v = prioridade(Fila, v);

    // Salva a distancia ate esse vertice que foi removido da fila de prioridades
    distancia[v] = dist_v;
    
    // Se eu for removido um vertice com distancia infinita
    // estamos tratando de um outro grafo, logo podemos finalizar o dijkstra
    // pois nao tera caminho de um grafo ate esse outro grafo, todos terao distancia infinita.
    if(dist_v == INT_MAX)break;

    // Para cada vizinho do vertice removido da fila de prioridades
    No *t;
    for (t = p->L[v]; t != NULL; t = t->prox){
      int w = t->v;
      int peso = t->peso;

      // Verifica se consigo diminuir a distancia ate seus vizinhos
      // caso consiga, diminua usando a funcao 'pq_muda_prioridade'
      if (dist_v + peso < prioridade(Fila, w)){
        pq_muda_prioridade(Fila, w, dist_v+peso);

        // Salva qual o pai do vertice que foi alterado.
        pai[w] = v;
      }
    }
  }
  
  // Como o problema quer saber se eh possivel sair da primeira cidade
  // e ir ate a ultima cidade passando por um numero par de pedagios.
  // Se comecando do ultimo vertice conseguimos chegar na primeira (vertice 0)
  // basta imprimir a distancia para chegar no ultimo vertice, caso nao exista
  // um caminho, basta imprimirmos -1.
  int atual=pai[p->n-1];
  while(atual!=0){
    if(atual==-1||vis[atual])break;
    else vis[atual]=1;
    atual=pai[atual];
  }

  int resultado;
  // Se partindo da cidade final, nao chegarmos na primeira cidade
  // ou a distancia da ultima cidade for infinita (nem chegou a ser visitada),
  // eh o indicativo que nao existe caminho ate ela.
  if(atual!=0 || distancia[p->n-1]==INT_MAX){
    resultado = -1;
  }else{
    // Caso contrario, eh possivel sair da primeira cidade e ir ate a ultima
    // basta imprimir a distancia ate a ultima, pois o grafo foi reconstuido
    // em caminhos pares.
    resultado = distancia[p->n-1];
  }

  // Libera a fila de prioridades (heap de min) da memoria
  pq_destruir(&Fila);
  
  // libera os array auxiliares da memoria
  free(pai);
  free(distancia);
  free(vis);  

  // retorna o resultado.
  return resultado;
}