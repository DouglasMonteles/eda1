#include <stdio.h>

int main(){

	int numero_aeroportos, numero_voos, mais_usado = 0, aeroporto_A, aeroporto_B, contador = 0;
	int identificador_aeroportos[101];

	scanf("%d %d", &numero_aeroportos, &numero_voos);

	if(numero_aeroportos >= 0 && numero_aeroportos <= 100){

		if(numero_voos >= 0 && numero_voos <= 10000){

			while(numero_aeroportos != 0 && numero_voos != 0){

				for(int i = 1; i <= numero_aeroportos; i++){
					identificador_aeroportos[i] = 0;
				}

				for(int i = 1; i <= numero_voos; i++){
					scanf("%d %d", &aeroporto_A, &aeroporto_B);

					identificador_aeroportos[aeroporto_A]++;
					identificador_aeroportos[aeroporto_B]++;
				}

				for(int i = 1; i <= numero_aeroportos; i++){

					if(identificador_aeroportos[i] > mais_usado){
						mais_usado = identificador_aeroportos[i];
					}
				}

				printf("Teste %d\n", contador+1);

				for(int i = 1; i <= numero_aeroportos; i++){
					if(identificador_aeroportos[i] == mais_usado){
						printf("%d ", i);
					}
				}

				printf("\n\n");
				contador++;
				mais_usado = 0;

				scanf("%d %d", &numero_aeroportos, &numero_voos);
			}
		}
	}


	return 0;
}
