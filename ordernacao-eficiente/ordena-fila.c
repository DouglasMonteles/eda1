#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no *prox;
}no;

no *cria_fila(){
	no *novo = malloc(sizeof(no));
	novo -> prox = novo;
	return novo;
}

void enfileira(no **f, int x){
	no *novo = malloc(sizeof(no));
	novo -> prox = (*f) -> prox;
	(*f) -> prox = novo;
	(*f) -> dado = x;
	*f = novo;
}

void desenfileira (no *f, int *y){
	no *lixo =  f -> prox;
	*y = lixo -> dado;
	f-> prox = lixo -> prox;
	free(lixo);
}

void insert_sort(int vetor[], int quantidade){
	int troca;

	//Loop para percorrer todo o vetor
	for(int i = 1; i < quantidade; i++){
		int proximo = i;

		while((proximo != 0) && (vetor[proximo] < vetor[proximo -1])){
			troca = vetor[proximo];
			vetor[proximo] = vetor[proximo - 1];
			vetor[proximo - 1] = troca;
			proximo--;
		}
	}
}

int main(){

	int contador = 0, numero_lido = 1;
	no *fila = cria_fila();

	while(scanf("%d", &numero_lido) != EOF){
		contador++;
		enfileira(&fila, numero_lido);
	}

	int *vetor = malloc(sizeof(int) * contador);

	for(int i = 0; i < contador; i++){
		desenfileira(fila, &numero_lido);
		vetor[i] = numero_lido;
	}

	insert_sort(vetor, contador);

	for(int i = 0; i < contador; i++){
		if(i == contador -1){
			printf("%d", vetor[i]);
			printf("\n");
		}
		else{
		printf("%d ", vetor[i]);
		}
	}

	return 0;
}