#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
  char tmp,onde_add='I';
  No *LTmp=criar_lista();
  No *LFinal=criar_lista();

  while(scanf("%c",&tmp),tmp!='$'){
    if(tmp=='['){
      if(onde_add=='I'){
        //adicionar a lista temporario no inicio da lista geral
      }
      if(onde_add=='F'){
        //adicionar a lista temporario no final da lista geral
      }

      onde_add='I';
      //limpar a temp
      //continue;
    }

    if(tmp==']'){
      if(onde_add=='I'){
        //adicionar a lista temporario no inicio da lista geral
      }
      if(onde_add=='F'){
        //adicionar a lista temporario no final da lista geral
      }

      onde_add='F';
      //limpar a temp
      //continue;
    }
    
    adicionar_final(&LTmp,tmp);
  }

  imprimir_lista(LTmp);

  return 0;
}