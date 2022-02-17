#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

int main(){
  int n,m,a,b; scanf("%d %d", &n, &m);
  char *comando=(char*)malloc(5*sizeof(char));

  No** arvores=(No**)malloc((n+1)*sizeof(No*));
  for(int i=0;i<=n;i++)arvores[i]=criar_no(i,NULL,NULL);

  while(m--){
    scanf("%s", comando);

    if(strcmp(comando,"lca")==0){
      scanf("%d %d", &a, &b);
      lca(arvores[a],arvores[b]);
    }

    if(strcmp(comando,"link")==0){
      scanf("%d %d", &a, &b);
      if(a!=b)link(arvores[a],arvores[b]);
    }

    if(strcmp(comando,"cut")==0){
      scanf("%d", &a);
      cut(arvores[a]);
    }
  }

  for(int i=0;i<=n;i++){
    free(arvores[i]);
    //destruir_arvore(&arvores[i]);
  }
  free(comando);
  free(arvores);

  return 0;
}