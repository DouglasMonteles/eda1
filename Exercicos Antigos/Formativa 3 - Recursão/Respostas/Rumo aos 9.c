#include <stdio.h>

int soma_digitos(int numero){
	if(numero == 0){
		return 0;
	}

	else{
		return soma_digitos(numero / 10) + numero % 10;
	}
}

int grau_nove(int numero){
	int soma = 0;

	if(numero == 9){
		soma++;
	}

	else{
		soma += grau_nove(soma_digitos(numero)) + 1;
	}

	return soma;
}

int main(){

	char numero[1001];
	int soma_da_string = 0;

	scanf("%s", numero);

	while(numero[0] != '0' || numero[1] != '\0'){
	for(int i = 0; numero[i] != '\0'; i++){
		soma_da_string += numero[i] - '0';
	}

	if(soma_digitos(soma_da_string) % 9 == 0){
		printf("%s is a multiple of 9 and has 9-degree %d.\n", numero, grau_nove(soma_da_string));
	}

	else{
		printf("%s is not a multiple of 9.\n", numero);
	}
	soma_da_string = 0;
	scanf("%s", numero);
	}

	return 0;
}
