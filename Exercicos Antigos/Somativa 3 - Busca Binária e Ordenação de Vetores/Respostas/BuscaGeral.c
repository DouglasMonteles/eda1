#include <stdio.h>
#include <stdlib.h>

typedef struct elementos{
	int dado;
	int posicao;
}elemento;

void insert_sort(elemento vetor[], int quantidade){
	int troca_dado, troca_posicao;

	//Loop para percorrer todo o vetor
	for(int i = 1; i < quantidade; i++){
		int proximo = i;

		while((proximo != 0) && vetor[proximo].dado < vetor[proximo-1].dado){
			troca_dado = vetor[proximo].dado;
			troca_posicao = vetor[proximo].posicao;

			vetor[proximo].dado = vetor[proximo-1].dado;
			vetor[proximo].posicao = vetor[proximo-1].posicao;

			vetor[proximo-1].dado = troca_dado;
			vetor[proximo-1].posicao = troca_posicao;

			proximo--;
		}
	}
}

int busca_binaria(elemento vetor[], int quantidade, int chave){
	int inicio = 0;
	int fim = quantidade - 1;

	while(inicio <= fim){
		//Encontra o meio
		int meio = (inicio + fim) / 2;

		//Se a chave estiver no meio, retorna meio
		if(chave == vetor[meio].dado){
			return vetor[meio].posicao;
		}

		//Se a chave for menor que o valor do meio, passa para o próximo elemento
		if(chave < vetor[meio].dado){
			fim = meio - 1;
		}

		else{
			inicio = meio + 1;
		}
	}

	//Se não achar nada...
	return -1;
}


int main(){

	int N, M, num_N, num_M;

	scanf("%d %d", &N, &M);

	elemento *vetor_N = malloc(sizeof(elemento) * N);
	int *vetor_M = malloc(sizeof(int) * M);

	for(int i = 0; i < N; i++){
		scanf("%d", &num_N);
		vetor_N[i].dado = num_N;
		vetor_N[i].posicao = i;
	}

	for(int i = 0; i < M; i++){
		scanf("%d", &num_M);
		vetor_M[i] = num_M;
	}

	//Ordenando o vetor
	insert_sort(vetor_N, N);

	//Fazendo a busca binária
	for(int i = 0; i < M; i++){
		printf("%d\n", busca_binaria(vetor_N, N, vetor_M[i]));
	}

	return 0;
}
