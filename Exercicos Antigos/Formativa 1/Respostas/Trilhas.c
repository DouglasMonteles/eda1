#include <stdio.h>

int i = 1;

int main(){

	int quantidade_trilhas, mais_facil, quantidade_pontos, menor = 0, soma = 0, resultado = 0;

	scanf("%d", &quantidade_trilhas);

	for(; i <= quantidade_trilhas; i++){

		scanf("%d", &quantidade_pontos);

		int array[quantidade_pontos];

		for(int j = 0; j < quantidade_pontos; j++){
			scanf("%d", &array[j]);
		}

		//Ida
		for(int k = 0; k < quantidade_pontos-1; k++){
			soma = array[k] - array[k+1];

			if(soma >= 0){
				soma = 0;
			}

			if(soma < 0){
				soma = -soma;
			}

			resultado += soma;

		}

		//Volta
		if(i == 1){
			menor = resultado;
			mais_facil = 1;
		}

		if(menor > resultado){
			menor = resultado;
			mais_facil = i;
		}

		resultado = 0;

		for(int l = quantidade_pontos; l >= 1; l--){
			soma = array[l] - array[l-1];

			if(soma > 0){
				soma = 0;
			}

			if(soma < 0){
				soma = -soma;
			}

			resultado += soma;
		}

		if(menor > resultado){
			menor = resultado;
			mais_facil = i;
		}

		resultado = 0;
	}

	printf("%d\n", mais_facil);

	return 0;
}
