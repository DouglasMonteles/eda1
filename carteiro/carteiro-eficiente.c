#include <stdio.h>
#include <stdlib.h>

typedef struct elementos{
	int dado;
	int posicao;
}elemento;

void mergeSort(elemento vetor[], int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho;
    elemento *vetorTemp;
    if(posicaoInicio == posicaoFim) return;
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;

    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);

    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (elemento *) malloc(sizeof(elemento) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) { 
            vetorTemp[k].dado = vetor[j].dado;
            vetorTemp[k].posicao = vetor[j].posicao;
            j++;
            k++;
        }
        else {
            if (j == posicaoFim + 1) {
                vetorTemp[k].dado = vetor[i].dado;
                vetorTemp[k].posicao = vetor[i].posicao;
                i++;
                k++;
            }
            else {
                if (vetor[i].dado < vetor[j].dado) {
                    vetorTemp[k].dado = vetor[i].dado;
                    vetorTemp[k].posicao = vetor[i].posicao;
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k].dado = vetor[j].dado;
                    vetorTemp[k].posicao = vetor[j].posicao;
                    j++;
                    k++;
                }
            }
        }

    }
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i].dado = vetorTemp[i - posicaoInicio].dado;
        vetor[i].posicao = vetorTemp[i - posicaoInicio].posicao;
    }
    free(vetorTemp);
}

int busca_binaria(elemento vetor[], int quantidade, int chave){
	int inicio = 0;
	int fim = quantidade - 1;

	while(inicio <= fim) {
		int meio = (inicio + fim) / 2;

		if(chave == vetor[meio].dado){
			return vetor[meio].posicao;
		}

    if(chave < vetor[meio].dado){
			fim = meio - 1;
		} else{
			inicio = meio + 1;
		}
	}

	return -1;
}


int main(){

	int qtdCasas, qtdEncomendas, num_N, num_M, cont = 0, index = 0;

	scanf("%d %d", &qtdCasas, &qtdEncomendas);

	elemento *numCasas = malloc(sizeof(elemento) * qtdCasas);
	int *numEncomendas = malloc(sizeof(int) * qtdEncomendas);

	for(int i = 0; i < qtdCasas; i++){
		scanf("%d", &num_N);
		numCasas[i].dado = num_N;
		numCasas[i].posicao = i;
	}

	for(int i = 0; i < qtdEncomendas; i++){
		scanf("%d", &num_M);
		numEncomendas[i] = num_M;
	}

	mergeSort(numCasas, 0, qtdCasas-1);

  for(int i = 0; i < qtdEncomendas; i++) {
    int casaIndex = busca_binaria(numCasas, qtdCasas, numEncomendas[i]);

    if (numEncomendas[i] != numEncomendas[i-1]) {
      int aux = (casaIndex - index);
      if (aux < 0)
        aux = aux * (-1);
      cont += aux;
    }
    
    index = casaIndex;
	}

  printf("%d\n", cont);
	return 0;
}
