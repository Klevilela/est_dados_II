#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//typedef char Itemp;
typedef struct pilha{
	int max;
	int topo;
	char *item;
	//int *item;
}*Pilha;

Pilha pilha(int m){
	Pilha P = (Pilha)malloc(sizeof(struct pilha));
	P->max = m;
	P->topo = -1;
	P->item = (char*)malloc(m*sizeof(char));
	//P->item = (int*)malloc(m*sizeof(int));
	return P;
}

int vaziap(Pilha P){
	/* if (P->topo==-1) return 1;
	else return 0; */

	return P->topo == -1;
}

int cheiap(Pilha P){
	/* if (P->topo == P->max-1) return 1;
	else return 0; */
	return P->topo == P->max -1;
}


void empilha(char x, Pilha P){
	if (cheiap(P) == 1){
		puts("A pilha está cheia.");
		abort();
	}
	
	P->topo ++;
	P->item[P->topo] = x;
}

char desempilha(Pilha P){
	if (vaziap(P) == 1){puts("A pilha está vazia");return '\0';};
	//P->topo --;
	return P->item[P->topo--];
}

void destroiP(Pilha *Q){
	free((*Q)->item);
	free(*Q);
	*Q = NULL;
}