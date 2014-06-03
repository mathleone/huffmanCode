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
	while(i<8){
		i++;
		c[i] = a%2 ? '1' : '0';
		a=a/2;
		printf("%c\n", c[i]);
	}
	return c;
}