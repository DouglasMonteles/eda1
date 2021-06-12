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

int main(){
  int numero, n;

	scanf("%d", &n);
  int *num = malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
    scanf("%d", &numero);
    num[i] = numero;
  }
  
  insert_sort(num, n);

	for(int i = 0; i < n; i++){
		if(i == n-1) {
			printf("%d", num[i]);
			printf("\n");
		} else {
		  printf("%d ", num[i]);
		}
	}

	return 0;
}
