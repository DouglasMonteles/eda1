#include <stdio.h>

int main(){
	char frase[10001], procura[41], substitui[41];
	int posProcura;

	scanf(" %[^\n]", frase);
	scanf(" %s", procura);
	scanf(" %s", substitui);

	posProcura = 0;

	for(int i = 0; frase[i] != '\0'; i++){
		if(procura[posProcura] == frase[i]){
			posProcura++;
		}

		else{
			if(posProcura > 0){
				if(procura[posProcura] == '\0'){
					printf("%s", substitui);
					posProcura = 0;
				}
				else {
					while (posProcura > 0){
						printf("%c", frase[i-posProcura]);
						posProcura--;
					}
				}
			}
			printf("%c", frase[i]);
		}
	}

	if(posProcura > 0 && procura[posProcura] == '\0'){
		printf("%s", substitui);
		posProcura = 0;
	}
	printf("\n");

	return 0;
}
