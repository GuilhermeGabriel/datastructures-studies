// GUILHERME GABRIEL FERREIRA SOUZA
// 11921ECP001

// Biblioteca para entrada e saida de dados
#include <stdio.h>

// Interface para manipular digrafos
#include "digrafo_lista_peso.h"

int main(){
  // Criacao e leitura da quantidade de cidades e de estradas
  int c, v, a, b, p;
  scanf("%d %d", &c, &v);
  
  // Criacao de dois digrafos, um auxilar ira receber a entrada
  // e o outro sera gerado a partir do auxiliar seguindo a regra onde
  // aresta(a,b,p1) e aresta(b,c,p2) do digrafo auxiliar ira se tornar
  // a aresta(a,c,p1+p2) do digrafo usado para a solucao.
  // Sera explicado sua construcao posteriormente.
  Grafo *Aux = criar_digrafo(c);
  Grafo *G = criar_digrafo(c);

  // Faz a leitura do digrafo auxiliar
  for(int i=0;i<v;i++){
    scanf("%d %d %d", &a, &b, &p); // Faz leitura do vertice a e b e peso p
    
    // Como eh uma estrada de uma rodovia, eh possivel ir e voltar, 
    // logo devemos inserir o arco de ida e volta.

    inserir_arco(Aux,a-1,b-1,p); // Insere arco de a para b e o peso para ir de a para b
    inserir_arco(Aux,b-1,a-1,p); // Insere arco de b para a e o peso para ir de b para a
  }

  // Reconstroi o grafo que sera usado na solucao 
  // seguindo a regra aresta(a,b,p1) e aresta(b,c,p2) => aresta(a,c,p1+p2)
  reconstroi_grafo(Aux,G);

  // O (dijkstra) no digrafo reconstruido (usando pares de arestas)
  // ira nos responder se existe caminho minimo usando um numero par de
  // arestas e sua distancia minima.
  printf("%d\n",dijkstra_quant_arest_par(G,0));
  
  // Libera os dois digrafos da memoria
  destruir_digrafo(Aux);
  destruir_digrafo(G);
   
  // Encerra funcao principal
  return 0;
}