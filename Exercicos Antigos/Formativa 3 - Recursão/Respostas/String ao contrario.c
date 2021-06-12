#include <stdio.h>
#include <string.h>

//Faça um programa que leia uma string e a imprima ao contrário.

//Caso Trivial: String que só possui um '\0'.

//Caso 1 - String com dois caracteres
//Caso 2 - String com 3 caracteres

void imprime_contrario(char *string, int n){

	char letra = string[n];

	if(n == 0){
		printf("%c", letra);
	}

	else{
		printf("%c", letra);
		imprime_contrario(string, n-1);
	}
}

int main(){

	char string[501];
	int tamanho_string;

	scanf("%s", string);

	tamanho_string = strlen(string);

	imprime_contrario(string, tamanho_string-1);

	printf("\n");

	return 0;
}
