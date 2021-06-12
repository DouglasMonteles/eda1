#include <stdio.h>

int main(){

	int maior, numero;

	scanf("%d", &numero);

	maior = numero;

	while(scanf("%d", &numero) != EOF){

		if(numero > maior){
			maior = numero;
		}
	}

	printf("%d\n", maior);

	return 0;
}
