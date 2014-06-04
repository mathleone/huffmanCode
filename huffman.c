#include "huffman.h"

void MapAscII(char *b, ASCIIMap *Freq){
	while(*b)
		if(Freq->freqVet[(int)*b++]++==0)
			Freq->diffChar++;
		printf("\n%d caracteres diferentes\n", Freq->diffChar);
	printf("\n");
}

char *atoBin(char c[], int a){
	int i=0;
	for(i=0;i<8;i++){
		c[i] = a%2 ? '1' : '0';
		a=a/2;		
	}
	return c;
}

int my_pow(int x, int y){
	int result=1.0;
	int i;
	for (i = 0; i < y; i++)
		result = result * x;
	return result;
}
int bintoA(char c[]){
	int i=0, pot=0, a=0, bit=0;
	printf("\n\n");
	for(i=0;i<8;i++){
		bit = c[i]=='1'?1:0;
		a = a+(bit*my_pow(2,i));
	}
	return a;
}

