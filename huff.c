#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "huffman.h"
// int huffmanCode(C){
// 	int n = strlen(C);
// 	Q = PQInit(C);
// 	Node *z;
// 	for(i=0; i<n; i++){
// 		z = malloc(sizeof(Node));
// 		z->left = x = PQDelmin(Q);
// 		z->right = y = PQDelmin(Q);
// 		f[z] = f[x] + f[y];
// 		PQInsert(Q, z);
// 	}
// 	return PQDelmin(Q);
// }
char *inputString(FILE* fp, size_t size){
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(char)*size);
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(char)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(char)*len);
}

int main(){
	char *b = inputString(stdin, 10);
	int i;
	//declara o mapeamento da tabela ascii
	ASCIIMap Freq;
	Freq.diffChar = 0;
	for(i=0;i<256;i++)
		Freq.freqVet[i] = 0;
	
	//armazena as frequencias em freqVet e conta os caracteres diferentes em diffChar
	MapAscII(b, &Freq);
	//inicializa a Heap
	Lista *Heap = PQInit(Freq.diffChar);
	
	//Insere os dados na Heap
	Dados *Data = malloc(sizeof(Dados));
	for(i=0;i<256;i++)
		if(Freq.freqVet[i]){
			Data->priority = Freq.freqVet[i];
			Data->v = i;
			Data->dir = Data->esq = NULL;
			PQInsert(&Heap, Data);
			printf("%d --- %c\n", Freq.freqVet[i], i);
		}
	printf("\n");
	Dados min1, min2;
	//lista Heap
	listar(Heap);
	while(Heap->quant>1){
		//min = PQDelmin(&Heap); //treeInsert(PQDelmin(&Heap), PQDelmin(&Heap));
		min1 = PQDelmin(&Heap);
		min2 = PQDelmin(&Heap);
		printf("%d\n", min1.priority);
		printf("%d\n", min2.priority);
		treeInsert(min1, min2);
	}
	// char *c = malloc(8*sizeof(char));
	// c = atoBin(c, 135);
	// for(i=0; i<8; i++)
	// 	printf("%c", c[i]);
	// int asc = bintoA(c);
	// printf("%d\n", asc);
		//inserir(&arvore, PQDelmin(&Heap));

	//ordem(arvore);

	return 0;
}