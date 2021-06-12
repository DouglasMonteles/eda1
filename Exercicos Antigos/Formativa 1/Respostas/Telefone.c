#include <stdio.h>
#include <string.h>

int main(){

	char String_leitura[16], digito;

	scanf("%s", String_leitura);

	for(int i = 0; i < strlen(String_leitura); i++){

		digito = String_leitura[i];

		if(digito == 'A' || digito == 'B' || digito == 'C'){
			digito = '2';
		}

		else if(digito == 'D' || digito == 'E' || digito == 'F'){
			digito = '3';
		}

		else if(digito == 'G' || digito == 'H' || digito == 'I'){
			digito = '4';
		}

		else if(digito == 'J' || digito == 'K' || digito == 'L'){
			digito = '5';
		}

		else if(digito == 'M' || digito == 'N' || digito == 'O'){
			digito = '6';
		}

		else if(digito == 'P' || digito == 'Q' || digito == 'R' || digito == 'S'){
			digito = '7';
		}

		else if(digito == 'T' || digito == 'U' || digito == 'V'){
			digito = '8';
		}

		else if(digito == 'W' || digito == 'X' || digito == 'Y' || digito == 'Z'){
			digito = '9';
		}

		String_leitura[i] = digito;
	}

	printf("%s\n", String_leitura);

	return 0;
}
