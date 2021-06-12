#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int *V; //Vetor que tem elementos da pilha
	int N; //Tamanho de V
	int topo; //Indicador do topo
}pilha;

//Função para empilhar
void empilha(pilha *p, int x){
	if(p -> topo == p -> N){
		p -> V = realloc(p -> V, p -> N * 2 * sizeof(int));
		p -> N = p -> N * 2;
	}

	p -> V[p -> topo] = x;
	p -> topo++;
}

//Função para desempilhar
int desempilha (pilha *p, int *y){
	if(p -> topo > 0){
		p -> topo --;

	*y = p -> V[p -> topo];
	return 1;
	}

	else{
		return 0;
	}
}
