// GUILHERME GABRIEL FERREIRA SOUZA
// 11921ECP001

// Criacao de um tipo struct no que contem
// um valor e um ponteiro para o proximo no.
// Struct no renomeado para Lista.
typedef struct no {
    char v[50];
    struct no* prox;
} Lista;

// Arquivo de definicoes
// Implementacoes em lista.c

// Definicao de uma funcao que cria uma lista
void cria_lista(Lista **l);

// Definicao de uma funcao que 
// insere no comeco de uma lista
void insere_comeco(Lista *l, char* valor);

// Definicao de uma funcao que remove
// o comeco de uma lista
void remove_comeco(Lista *l);

// Definicao de uma funcao que libera uma lista
void libera_lista(Lista **l);
