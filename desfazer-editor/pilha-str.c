#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
  char dado[110];
  struct celula *prox;
} celula;

int empilha (celula *p, char str[110]) {
  int cont = 0;
  celula *novo = malloc(sizeof(celula));
	while (str[cont] != '\n') {
    novo->dado[cont] = str[cont];
    cont++;
  }
	novo->prox = p->prox;
	p->prox = novo;
}

int desempilha (celula *p) {
  celula *lixo = p->prox;

	if(lixo == NULL) {
    printf("NULL\n");
		return 0;
	}

	printf("%s\n", lixo->dado);

	p->prox = lixo->prox;
	free(lixo);

	return 1;
}

int main() {
  char opcao[10];
  celula *p = malloc(sizeof(celula));
  
  while (scanf("%s", opcao) != EOF) {
    if (strcmp(opcao, "inserir") == 0) { // inserir
      char str[110];
      scanf(" %[^\n]", str);
      str[strlen(str)] = '\n';

      empilha(p, str);
    } else if (strcmp(opcao, "desfazer") == 0) {                            // desfazer
      desempilha(p);
    } 
  }

  return 0;
}