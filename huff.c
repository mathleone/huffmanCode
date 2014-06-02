#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

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

typedef struct ASCIIMap{
	int freqVet[256];
	int diffChar;
}ASCIIMap;

void MapAscII(char *b, ASCIIMap *Freq){
	while(*b)
		if(Freq->freqVet[(int)*b++]++==0)
			Freq->diffChar++;
		printf("\n%d caracteres diferentes\n", Freq->diffChar);
	printf("\n");
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
			PQInsert(&Heap, Data);
			printf("%d --- %c\n", Freq.freqVet[i], i);
		}
	printf("\n");
	
	//lista Heap
	listar(Heap);
	return 0;
}