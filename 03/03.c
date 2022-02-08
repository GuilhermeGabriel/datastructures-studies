#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"

int main(){
  int c, n; scanf("%d",&c);
  char *pre=(char*)malloc(60*sizeof(char));
  char *in=(char*)malloc(60*sizeof(char));
  
  while(c--){
    scanf("%d %s %s",&n,pre,in);
    
    No* raiz = criaArvore(pre,in,n);
    //imprimir_arvore(raiz);
    //pre_ordem(raiz);
    pos_ordem(raiz);
    printf("\n");
    //printf("%c",raiz->dado);

    //printf("%d %s %s\n", n, pre, in);
  }

  return 0;
}