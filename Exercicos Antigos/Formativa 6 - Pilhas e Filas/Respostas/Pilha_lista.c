#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
	int dado;
	struct celula *prox;
}celula;

//Função para empilhar
void empilha(celula *p, int x){
	celula *novo = malloc(sizeof(celula));
	novo -> dado = x;
	novo -> prox = p -> prox;
	p -> prox = novo;
}

//Função para desempilhar
int desempilha(celula *p, int *y){
	celula *lixo = p -> prox;

	if(lixo == NULL){
		return 0;
	}

	*y = lixo -> dado;

	p -> prox = lixo -> prox;
	free(lixo);

	return 1;
}
