#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
  int *dados;
  int N, topo;
} pilha;

void empilha(pilha *p, int x){
	if(p->topo == p->N){
		p->dados = realloc(p->dados, p->N * 2 * sizeof(int));
		p->N = p->N * 2;
	}

	p->dados[p->topo] = x;
	p->topo++;
}