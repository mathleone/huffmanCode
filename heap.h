#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#include "heap.h"
#include <string.h>

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

Dados *new_Dados(int , char , Dados *, Dados *);

#endif // HEAP_H_INCLUDED
