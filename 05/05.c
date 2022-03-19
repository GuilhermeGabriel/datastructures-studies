#include <stdio.h>
#include "digrafo_lista_peso.h"

int main(){
  int c, v, a, b, p;
  scanf("%d %d", &c, &v);
  
  Grafo *Aux = criar_digrafo(c);
  Grafo *G = criar_digrafo(c);

  for(int i=0;i<v;i++){
    scanf("%d %d %d", &a, &b, &p);
    inserir_arco(Aux,a-1,b-1,p);
    inserir_arco(Aux,b-1,a-1,p);
  }

  reconstroi_grafo(Aux,G);

  printf("%d\n",dijkstra_quant_arest_par(G,0));
  
  destruir_digrafo(Aux);
  destruir_digrafo(G);
   
  return 0;
}