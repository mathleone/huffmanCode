#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

void listar(Lista *l){
    int i;
    if(!PQEmpty(&l))
        for (i = 0; i < l->quant; i++)
            printf("%c ----- %d\n", l->Data[i].v, l->Data[i].priority);
    else
        printf("Heap Vazia\n");
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

Dados *PQDelmin(Lista **l)
{
    if((*l)->quant < 1)
        return NULL;
    Dados *min = malloc(sizeof(Dados));
    *min = (*l)->Data[0];
    (*l)->Data[0] = (*l)->Data[--(*l)->quant];
    PQDec(&(*l), 1);
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

void buildCode(Dados *l, char c[], int tam, char *vetCode[]){
    if(l != NULL){
        if(l->v>0){
            c[tam] = 0;
            vetCode[(int)l->v] = malloc((tam+1)*sizeof(char));
            strcpy(vetCode[l->v], c);
            printf("%c\t%s\t%d\t%s\n", l->v, c, (int)l->v, vetCode[(int)l->v]);
            return;
        }
        c[tam] = '0';
        buildCode(l->esq, c, tam+1, vetCode);
        c[tam] = '1';
        buildCode(l->dir, c, tam+1, vetCode);
    }
}

Dados *new_Dados(int priority, char c, Dados *a, Dados *b){
    Dados *Data = malloc(sizeof(Dados));
    printf("newDados - Prioridade: %d\n", priority);
    if(priority>0){
        printf("Prioridade nao nula, entao insere: %c com Prioridade %d\n", c, priority);
        Data->v = c; 
        Data->priority = priority;
    }
    else{
        printf("Prioridade nula, entao insere Prioridade %d + %d, char Nulo\n", a->priority, b->priority);
        Data->dir = a;
        Data->esq = b;
        Data->priority = a->priority + b->priority;
        printf("Caractere a esquerda: %c; Caractere a direita: %c\n", Data->dir->v, Data->esq->v);
    }
    return Data;
}