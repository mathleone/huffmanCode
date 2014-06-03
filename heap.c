#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

void listar(Lista *l){
    int i;
    for (i = 0; i < l->quant; i++)
        printf("%c ----- %d\n", l->Data[i].v, l->Data[i].priority);
    printf("\n");
}

void PQDec(Lista **vet, int i){
    int l = 2*i, r = (2*i)+1, menor=0;
    if(l <= (*vet)->quant  && (*vet)->Data[l-1].priority < (*vet)->Data[i-1].priority)
        menor = l-1;
    else
        menor = i-1;
    if(r<=(*vet)->quant  && (*vet)->Data[r-1].priority<(*vet)->Data[menor].priority)
        menor = r-1;
    if(menor!=i-1){
        Dados Buf = (*vet)->Data[menor];
        (*vet)->Data[menor] = (*vet)->Data[i-1];
        (*vet)->Data[i-1] = Buf;
        PQDec(&(*vet), menor+1);
    }
}

Dados PQDelmin(Lista **l)
{
    if((*l)->quant < 1)
        return 0;
    Dados min = (*l)->Data[0];
    (*l)->Data[0] = (*l)->Data[--(*l)->quant];
    PQDec(&(*l), 1);
    printf("%d --- %c\n", min.priority, min.v);
    return min;
}

void PQBuild(Lista **vet)
{
    int i;
    int sizeA = (*vet)->quant;
    for(i = sizeA/2; i > 0; i--)
        PQDec(&(*vet), i);
}

int PQEmpty(Lista **l){
    return (*l)->quant == 0 ? 1 : 0;
}

Lista *PQInit(int size)
{
    Lista *l = malloc(sizeof(Lista));
    l->quant = 0;
    l->Data = malloc(size*sizeof(Dados));
    return l;
}

int PQIncrease(Lista **l, int i, Dados *chave)
{
    if(chave->priority > (*l)->Data[i].priority)
        return 0;
    (*l)->Data[i] = *chave;
    //(*l)->Data[i].v = chave->v;
    while(i > -1 && (*l)->Data[i/2].priority > (*l)->Data[i].priority){
        Dados Buf = (*l)->Data[i/2];
        (*l)->Data[i/2] = (*l)->Data[i];
        (*l)->Data[i] = Buf;
        i = i/2;
    }
    return 1;
}

int PQInsert(Lista **l, Dados *chave)
{
    (*l)->Data[(*l)->quant].priority = 32678;
    (*l)->quant++;
    if(PQIncrease(&(*l), (*l)->quant-1, chave))
        return 1;
    else
        return 0;
}

//int treeInsert(Dados *a, Dados *b){
//    printf("%d --- %d\n", a->priority, b->priority);
//    int freq = a->priority + b->priority;
//    printf("%d\n", freq);
//    return 0;
//}