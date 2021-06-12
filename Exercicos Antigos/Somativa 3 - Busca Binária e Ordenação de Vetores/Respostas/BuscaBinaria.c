#include <stdio.h>
#include <stdlib.h>

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

int busca_binaria(int *v, int n, int x){
	int e = -1;
	int d = n;
	while(e < d - 1){
		int m = (e + d) / 2;
		if(v[m] < x){
			e = m;
		}
		else{
			d = m;
		}
	}
	return d;
}

int main(){

	int N, M, num_N, num_M;

	scanf("%d %d", &N, &M);

	int *vetor_N = malloc(sizeof(int) * N);
	int *vetor_M = malloc(sizeof(int) * M);

	for(int i = 0; i < N; i++){
		scanf("%d", &num_N);
		vetor_N[i] = num_N;
	}

	for(int i = 0; i < M; i++){
		scanf("%d", &num_M);
		vetor_M[i] = num_M;
	}

	insert_sort(vetor_N, N);

	for(int i = 0; i < M; i++){
		printf("%d\n", busca_binaria(vetor_N, N, vetor_M[i]));
	}

	return 0;
}
