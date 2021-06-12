#include <stdio.h>

float potenciacao(int a, int b){
	if(b == 0){
		return 1;
	}

	else if(b > 0){
		return a * potenciacao(a, b - 1);
	}

	return a;
}

int main(){

	int base, expoente;

	scanf("%d %d", &base, &expoente);

	if(expoente < 0){
		printf("%f\n", 1 / potenciacao(base, -expoente));
	}

	else if(base == 0 && expoente == 0){
		printf("indefinido\n");
	}

	else{
		printf("%f\n", potenciacao(base, expoente));
	}

	return 0;
}
