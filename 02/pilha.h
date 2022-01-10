// GUILHERME GABRIEL FERREIRA SOUZA
// 11921ECP001

// Inclui a interface lista 
// para pegar o struct Lista
// e as definicoes das funcoes
#include "lista.h"

// Arquivo de definicoes
// Implementacoes em pilha.c

// Define um tipo Pilha como um tipo de Lista
typedef Lista Pilha;

// Definicao de funcao que cria uma pilha
void pilha_criar(Pilha** p);

// Definicao de funcao que insere no topo de uma pilha
void pilha_inserir(Pilha* p, char* valor);

// Definicao de uma funcao que mostra o valor
// que esta no topo da pilha
char* pilha_valor_topo(Pilha* p);

// Definicao de uma funcao que remove
// o valor que esta no topo da pilha
void pilha_remover(Pilha* p);

// Definicao de uma funcao que libera
// todos noh's de uma pilha da memoria
void pilha_liberar(Pilha** p);

// Definicao de uma funcao que imprime os noh's
// de uma pilha na ordem que foram inseridos
void pilha_imprimir_ordem_inserida(Pilha* p);

// Definicao de uma funcao que imprime os noh's
// de uma pilha na ordem em que estao naturalmente
void pilha_imprimir_ordem_natural(Pilha* p);

// Definicao de uma funcao que retorna 
// se a pilha esta vazia ou nao
int pilha_vazia(Pilha* p);
