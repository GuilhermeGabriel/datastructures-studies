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
        if(lista_esta_vazia(&LFinal)){
          while(!lista_esta_vazia(&LTmp)){
            int elem_inicio=obter_inicio(&LTmp);
            remover_inicio(&LTmp);
            adicionar_final(&LFinal,elem_inicio);
          }
        }else{
          inverter_lista(&LTmp);
          while(!lista_esta_vazia(&LTmp)){
            int elem_inicio=obter_inicio(&LTmp);
            remover_inicio(&LTmp);
            adicionar_inicio(&LFinal,elem_inicio);
          }
        }
      }
      if(onde_add=='F'){
        // while(!lista_esta_vazia(&LTmp)){
        //   int elem_inicio=obter_inicio(&LTmp);
        //   remover_inicio(&LTmp);
        //   adicionar_final(&LFinal,elem_inicio);
        // }
      }
      onde_add='I';
      destruir_lista(&LTmp);
      continue;
    }

    adicionar_final(&LTmp,tmp);
  }
/*
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
*/
   /* adicionar_final(&LTmp,tmp);
    //adicionar_inicio(LTmp,tmp);
  }*/

  //tem q ter o bagui pra caso n houver ] ou [
  //if()
  //inverter_lista(&LTmp);
  imprimir_lista(LFinal);
  //printf("\n%c",obter_inicio(&LTmp));
  //printf("%d",tamanho_lista(LTmp));

  return 0;
}

//O sapo na[o lava o p[$