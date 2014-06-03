#ifndef HUFFMAN_H_INCLUDED
#define HUFFMAN_H_INCLUDED

#include <stdio.h>
#include <string.h>
typedef struct ASCIIMap{
	int freqVet[256];
	int diffChar;
}ASCIIMap;

void MapAscII(char *, ASCIIMap *);

char *atoBin(char [], int);

#endif