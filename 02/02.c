// GUILHERME GABRIEL FERREIRA SOUZA
// 11921ECP001

// Biblioteca para entrada e saida de dados
#include <stdio.h>

// Biblioteca para manipulacao de memoria
#include <stdlib.h>

// Biblioteca para manipulacao de strings
#include <string.h>

// Interface para manipular pilha
#include "pilha.h"

int main(){
  // Cria duas pilhas, uma para as paginas e uma para o buffer
  Pilha *Pags,*Buffer;
  pilha_criar(&Pags);
  pilha_criar(&Buffer);

  // Aloca dois arrays de char dinamicamente, um para
  // armazenar o comando, outra para o link do site
  char *comando=(char*)malloc(10*sizeof(char));
  char *site=(char*)malloc(50*sizeof(char));
  
  // Enquanto o comando não for de encerrar, roda o programa
  while(scanf("%s",comando),strcmp(comando,"encerra")!=0){
    // Se o comando for de acessar o site
    if(strcmp(comando,"acessa")==0){
      // Le o link e insere no topo da pilha de paginas
      scanf("%s",site);
      pilha_inserir(Pags,site);
      
      // Se o link do site a ser acessado for o topo do 
      // buffer, apenas libera o topo do buffer, caso contrario
      // libera todo o buffer
      if(strcmp(site,pilha_valor_topo(Buffer))==0){
        // Remove apenas o topo do buffer
        if(!pilha_vazia(Buffer))pilha_remover(Buffer);
      }else{
        // Remove todo o buffer
        while(!pilha_vazia(Buffer))pilha_remover(Buffer);
      }
    }

    // Se o comando for de voltar uma pagina
    if(strcmp(comando,"volta")==0){
      // Insere no topo do buffer a ultima pagina acessada
      pilha_inserir(Buffer,pilha_valor_topo(Pags));
      // Remove a ultima pagina acessada da pilha de paginas
      pilha_remover(Pags);
    }

    // Se o comando for de avancar uma pagina
    if(strcmp(comando,"avanca")==0){
      // Se o buffer nao tiver vazio
      if(!pilha_vazia(Buffer)){
        // Insere na pilha de paginas, o topo do buffer
        pilha_inserir(Pags,pilha_valor_topo(Buffer));
        // Remove o topo do buffer
        pilha_remover(Buffer);
      }
    }

    // Se o comando for de imprimir
    if(strcmp(comando,"imprime")==0){
      // Imprime a pilha de paginas na ordem em que foram inseridas
      pilha_imprimir_ordem_inserida(Pags);

      // Imprime o buffer na ordem natual da pilha
      pilha_imprimir_ordem_natural(Buffer);

      // Printa uma quebra de linha para formatacao
      printf("\n");
    }
  }

  // Libera da memoria o array de char que armazena o comando e o link do site
  free(comando);
  free(site);
  // Libera da memoria a pilha de paginas e o pilha de buffer
  pilha_liberar(&Pags);
  pilha_liberar(&Buffer);

  // Encerra o programa
  return 0;
}
