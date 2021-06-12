#include <stdio.h>

int main(){

	int conta1, conta2, conta3, soma_real, soma_doutorando;

	scanf("%d %d %d", &conta1, &conta2, &conta3);

	soma_real = conta1 + conta2 + conta3;

	scanf("%d", &soma_doutorando);

	if(soma_doutorando == soma_real){
		printf("Acertou\n");
	}

	else if(soma_doutorando != soma_real){
		printf("Errou\n");
	}

	return 0;
}
