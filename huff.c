#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.h"

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
	FILE *fp;
	char *b;// = inputString(stdin, 10);

	if ((fp = fopen("teste.txt", "r"))==NULL){
		printf("Cannot open file \n");
		exit(1);
	}
	int cnt=0;
	while(fgetc(fp) != EOF)
	    cnt++;
	b = malloc(cnt*sizeof(char));
	int c, n=0;
	while((c=fgetc(fp) != EOF))
		b[n++] = (char)c;
	b[n] = '\0';
	//char *b = fp;
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
			PQInsert(&Heap, new_Dados(Freq.freqVet[i], i, NULL, NULL));
			printf("%d --- %c\n", Freq.freqVet[i], i);
		}
	//printf("\n");
	//lista Heap
	listar(Heap);
	//Insere os dados da heap em uma arvore
	while(Heap->quant>1){
		PQInsert(&Heap, new_Dados(0, 'c', PQDelmin(&Heap),PQDelmin(&Heap)));
		listar(Heap);
	}
	listar(Heap);
	char *vetCode[256] = {NULL}, code[8];
	buildCode(Heap->Data,code, 0, vetCode);
	for(i=0; i<255; i++)
		if(vetCode[i]!=NULL)
			printf("%s\n", vetCode[i]);
	char *Encoded = malloc(8*strlen(b)*sizeof(char));
	Encoded = huffmanEncode(b, vetCode, Encoded);
	printf("Encoded Text: %s\n", Encoded);
	printf("De %d para %d bits\n", ptrlen(b)*8, ptrlen(Encoded));
	if ((fp = fopen("myfile", "w"))==NULL){
		printf("Cannot open file \n");
		exit(1);
	}
	while(*Encoded)
	if (fwrite(Encoded++, 1, 1, fp) !=1){
		printf("Write error occurred");
		exit(1);
	}
	//char *buf = malloc(8*sizeof(char));
	//int j, k;
	//for(i=1; i<=ptrlen(Encoded);i+=8){
	//	printf("%d\n", i);
	//	j=0;
	//	if(ptrlen(Encoded)-i+1 == ptrlen(Encoded)%8)
	//		for(; j<8-(ptrlen(Encoded)-i+1); j++)
	//			buf[j] = '0';
	//	k = j;
	//	for(; j<8; j++){
	//		printf("%d\t%d\t%d\t%c\n", i, j, i+j-1, Encoded[(((i+j)-1)-k)]);
	//		buf[j] = Encoded[(((i+j)-1)-k)];
	//	}
	//	printf("%s\n", buf);
	//	printf("\n");
	//}
		//if(i==ptrlen(Encoded)/8)
			//printf("%d --- %d\n", i, ptrlen(Encoded)-(ptrlen(Encoded)/8)+1);
		//for(j=0; j<8; j++){
		//	buf[j] = Encoded[i+j-1];
		//	printf("%c", buf[j]);
		//}
		//for(j=0; j<(8-ptrlen(Encoded)%8==8?0:8-ptrlen(Encoded)%8); j++){
		//	printf("%d - %d - %d\n", i, j, (8-ptrlen(Encoded)%8==8?0:8-ptrlen(Encoded)%8));
		//	buf[j] = '0';
		//}
		//for(;j<8;j++){
		//	printf("%d - %d\n", i, j);
		//	buf[j] = Encoded[i+j];
		//}
	//printf("%c -- %d -- %d -- %d\n", *Encoded++, i, ptrlen(Encoded), 8-ptrlen(Encoded)%8);


	fclose(fp);
	return 0;
}

