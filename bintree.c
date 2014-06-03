#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

int treeInsert(Dados *a, Dados *b){
	int freq = a->priority + b->priority;
	printf("%d\n", freq);
	return 0;
}

// no *criar(){
// 	return NULL;
// }

// void inserir(no **raiz, int a){
// 	if(*raiz==NULL){
// 		*raiz = malloc(sizeof(no));
// 		(*raiz)->frequency = elem;
// 		(*raiz)->esq = NULL;
// 		(*raiz)->dir = NULL;
// 	}
// 	if(elem<(*raiz)->frequency)
// 		inserir(&((*raiz)->esq), elem);
// 	if(elem>(*raiz)->frequency)
// 		inserir(&((*raiz)->dir), elem);
// }
// no *buscar(no *raiz, int elem){
// 	if (raiz==NULL)
// 		return NULL;
// 	if(elem==raiz->frequency)
// 		return raiz;
// 	if(elem<raiz->frequency)
// 		return buscar(raiz->esq, elem);
// 	if(elem>raiz->frequency)
// 		return buscar(raiz->dir, elem);
// }
// no* menor(no **raiz){
// 	no *aux = *raiz;
// 	if(aux->esq == NULL){
// 		*raiz = (*raiz)->dir;
// 		return aux;
// 	}
// 	else 
// 		return menor(&((*raiz)->esq));
// }
// void remover_no(no **raiz){
// 	no *pos;
// 	pos = *raiz;
// 	if((*raiz)->esq == NULL && (*raiz)->dir == NULL)
// 		*raiz = NULL;
// 	else if((*raiz)->esq == NULL)
// 		*raiz = (*raiz)->dir;
// 	else if((*raiz)->esq == NULL)
// 		*raiz = (*raiz)->esq;
// 	else{
// 		pos = menor(&((*raiz)->dir));
// 		(*raiz)->frequency = pos->frequency;
// 	}
// 	free(pos);
// }
// int remover(no **raiz, int elem){
// 	if(*raiz == NULL)
// 		return 0;
// 	if(elem==(*raiz)->frequency){
// 		remover_no(raiz);
// 		return 1;
// 	}
// 	if(elem<(*raiz)->frequency)
// 		return remover(&((*raiz)->esq), elem);
// 	if(elem>(*raiz)->frequency)
// 		return remover(&((*raiz)->dir), elem);
// }
// void ordem(no *raiz){
// 	if(raiz != NULL){
// 		ordem(raiz->esq);
// 		printf("%i\n", raiz->frequency);
// 		ordem(raiz->dir);
// 	}
// }
// void preordem(no *raiz){
// 	if(raiz != NULL){
// 		printf("%i\n", raiz->frequency);
// 		ordem(raiz->esq);
// 		ordem(raiz->dir);
// 	}
// }
// void posordem(no *raiz){
// 	if(raiz != NULL){
// 		ordem(raiz->esq);
// 		ordem(raiz->dir);
// 		printf("%i\n", raiz->frequency);
// 	}
// }