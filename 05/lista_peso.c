#include <stdio.h>
#include <stdlib.h>
#include "lista_peso.h"

No* criar_lista(){
  return NULL;
}

void destruir_lista(No* p) {
  if (p != NULL) {
    destruir_lista(p->prox);
    free(p);
  }
}

No* inserir_na_lista(No *p, int x, int w) {
  No *novo = malloc(sizeof(No));
  novo->v = x;
  novo->peso = w;
  novo->prox = p;
  return novo;
}

