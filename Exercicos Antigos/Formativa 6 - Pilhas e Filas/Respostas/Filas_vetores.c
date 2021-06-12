#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int *v;
	int N;
	int inicio, fim;
}fila;

int enfileira (fila *f, int x){
	if(f -> fim == f -> inicio -1){
		return 0;
	}
	else if(f -> fim == f -> N-1 && f -> inicio == 0){
		return 0;
	}

	else{
		f -> v[f -> fim] = x;
		f -> fim++;
		f -> fim %= f -> N;
		return 1;
	}
}

int desenfileira(fila *f, int *y){
	//Verificando se a fila está vazia
	if(f -> fim == f -> inicio){
		return 0;
	}

	else{
		*y = f -> v[f -> inicio];
		f -> inicio++;
		f -> inicio %= f -> N;
		return 1;
	}
}
