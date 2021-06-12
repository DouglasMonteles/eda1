#include <stdio.h>
void triangulo (int n);

int main(){

 int valor;

 scanf("%d", &valor);

 triangulo (valor);


 return 0;
}

void triangulo (int n){

	int espaco;

	for(int i = 1; i <= n; ++i){
		for(espaco = 1; espaco <= n - i; ++espaco){
			printf(" ");
		}

		 for(int j = (i * 2)-2; j >= 0; j--){
		   printf("*");
		  }

		  printf("\n");
	}
 }
