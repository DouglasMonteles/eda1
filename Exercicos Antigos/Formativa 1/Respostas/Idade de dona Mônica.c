#include <stdio.h>

int main(){

	int idade_Monica = 0, idade_filho1 = 0, idade_filho2 = 0, idade_filho3 = 0, maior = 0;

	scanf("%d", &idade_Monica);
	scanf("%d", &idade_filho1);
	scanf("%d", &idade_filho2);

	idade_filho3 = idade_Monica  - idade_filho1 - idade_filho2;

	if(idade_filho1 > idade_filho2 && idade_filho1 > idade_filho3){
		maior = idade_filho1;
	}

	else if(idade_filho1 > idade_filho3 && idade_filho1 > idade_filho2){
		maior = idade_filho1;
	}

	else if(idade_filho2 > idade_filho1 && idade_filho2 > idade_filho3){
		maior = idade_filho2;
	}

	else if(idade_filho2 > idade_filho3 && idade_filho2 > idade_filho1){
		maior = idade_filho2;
	}

	else if(idade_filho3 > idade_filho1 && idade_filho3 > idade_filho2){
		maior = idade_filho3;
	}

	else if(idade_filho3 > idade_filho2 && idade_filho3 > idade_filho1){
		maior = idade_filho3;
	}

	printf("%d\n", maior);

	return 0;
}
