#include <stdio.h>

int main(){

	int tamanho_vetor, numero_procurado, achado = 0;

	scanf("%d", &tamanho_vetor);

	int vetor[tamanho_vetor];

	for(int i = 0; i < tamanho_vetor; i++){
		scanf("%d", &vetor[i]);
	}

	scanf("%d", &numero_procurado);

	for(int i = 0; i < tamanho_vetor; i++){
		if(vetor[i] == numero_procurado){
			achado = 1;
		}
	}

	if(achado == 0){
		printf("nao pertence\n");
	}

	else if(achado != 0){
		printf("pertence\n");
	}

	return 0;
}
