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