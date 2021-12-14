#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main(){
  char tmp,onde_add='I';
  No *LTmp=criar_lista();
  No *LFinal=criar_lista();

  while(scanf("%c",&tmp),tmp!='\n'){
    if(tmp=='['||tmp==']'||tmp=='$'){
      if(onde_add=='I'){
        if(lista_esta_vazia(&LFinal)){
          adicionar_lista_final(&LFinal,&LTmp);
        }else{
          adicionar_lista_inicio(&LFinal,&LTmp);
        }
      }
      if(onde_add=='F'){
        adicionar_lista_final(&LFinal,&LTmp);
      }
      
      if(tmp=='[')onde_add='I';
      if(tmp==']')onde_add='F';

      destruir_lista(&LTmp);
      continue;
    }

    adicionar_final(&LTmp,tmp);
  }

  int inverter=0;
  char *comando=(char*)malloc(15*sizeof(15));
  while(scanf(" %[^\n]",comando),strcmp(comando,"FIM")!=0){
    if(comando[0]=='S'){
      substituir_na_lista(LFinal,comando[11],comando[13]);
    }

    if(comando[0]=='I'){
      inverter_lista(&LFinal);
    }
  }

  imprimir_lista(LFinal);

  free(comando);
  destruir_lista(&LTmp);
  destruir_lista(&LFinal);

  return 0;
}