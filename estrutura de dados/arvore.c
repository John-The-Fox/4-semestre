#include <stdlib.h>
#include arvore.h

typedef struct No;

typedef struct No{
	int data;
	No* esquerda;
	No* direita;
}

typedef struct arvore{
	No*raiz;
} Arvore;

Arvore* criar_arvore