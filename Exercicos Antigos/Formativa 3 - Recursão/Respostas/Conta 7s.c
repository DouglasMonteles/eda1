#include <stdio.h>

void conta_setes(unsigned long int numero, int *contador){
	if(numero != 0){
		if(numero % 10 == 7){
			(*contador)++;
		}
		conta_setes(numero / 10, contador);
	}
}

int main() {

	unsigned long int numero;
	int contador = 0;

	scanf("%lu", &numero);

	conta_setes(numero, &contador);

	printf("%d\n", contador);

	return 0;
}
