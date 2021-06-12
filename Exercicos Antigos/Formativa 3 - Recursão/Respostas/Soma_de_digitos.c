#include <stdio.h>

/* Como somar dígitos de um número */

//Jeito manual
//	int n, t, sum = 0, remainder;
//
//   printf("Enter an integer\n");
//   scanf("%d", &n);
//
//   t = n;
//
//   while (t != 0)
//   {
//      remainder = t % 10;
//      sum       = sum + remainder;
//      t         = t / 10;
//   }


//Jeito recursivo do professor

/*
 int somaDigitos (int num){
 	 if(num == 0){
 	     return 0;
 	   }

 	 else{
 	 	 return somaDigitos (num / 10) + num % 10;
 	 }
}
*/



//Jeito que eu fiz
unsigned long int soma_digitos(unsigned long int n, unsigned long int m){

	int soma = 0;

	//Caso Trivial = n é um digito só
	if(n < 10){
		soma += n;
	}

	else{
		unsigned long int p = m / 10;
		soma += n % m / p;
		soma += soma_digitos(n - (n % m / p * p), m / 10);
	}

	return soma;
}

int main(){

	unsigned long int numero, maximo = 1000000000000;
	scanf("%lu", &numero);

	//Retirando a unidade de centena de 100
	//printf("%d\n", numero - (numero % 1000 / 100 * 100));

	printf("%lu\n", soma_digitos(numero, maximo));

	return 0;
}
