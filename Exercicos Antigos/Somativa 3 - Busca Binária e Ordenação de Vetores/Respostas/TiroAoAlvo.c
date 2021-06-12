
#include <stdio.h>
#include <stdlib.h>

int busca_binaria(long long int *v, long long int n, long long int x){
	int e = -1;
	int d = n;
	while(e < d - 1){
		int m = (e + d) / 2;
		if(v[m] < x){
			e = m;
		}
		else{
			d = m;
		}
	}
	return n- d;
}

int main(){

	long long int quantidade_circulos, quantidade_tiros, ponto_x, ponto_y, pontuacao = 0;

	scanf("%lld %lld", &quantidade_circulos, &quantidade_tiros);

	long long int *circunferencias_circulos = malloc(sizeof(long long int) * quantidade_circulos);

	//Lendo os raios dos círculos
	for(int i = 0; i < quantidade_circulos; i++){
		scanf("%lld", &circunferencias_circulos[i]);
		circunferencias_circulos[i] = circunferencias_circulos[i] * circunferencias_circulos[i];
	}

	for(int i = 0; i < quantidade_tiros; i++){
		scanf("%lld %lld", &ponto_x, &ponto_y);

		pontuacao += busca_binaria(circunferencias_circulos, quantidade_circulos, ponto_x * ponto_x + ponto_y * ponto_y);
	}

	printf("%lld\n", pontuacao);

	return 0;
}
