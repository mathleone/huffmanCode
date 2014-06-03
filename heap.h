#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#include "heap.h"

typedef struct Dados{
	char v;
	int priority;
	struct Dados *esq;
	struct Dados *dir;
}Dados;

typedef struct Lista{
    struct Dados *Data;
    int quant;
}Lista;

int PQEmpty(Lista **);

void listar(Lista*);

Lista *PQInit(int);

void PQBuild(Lista**);

int PQIncrease(Lista**, int, Dados*);

int PQInsert(Lista**, Dados*);

Dados *PQDelmin(Lista**);

void PQDec(Lista**, int);

int treeInsert(Dados *, Dados *);

#endif // HEAP_H_INCLUDED
