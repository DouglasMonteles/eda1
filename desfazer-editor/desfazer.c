#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
  char dado[110];
} celula;

typedef struct pilha {
  int N, topo;
  celula *v;
} pilha;

pilha *cria_pilha() {
  pilha *p = malloc(sizeof(pilha));

  p->N = 110;
  p->v = malloc(p->N * sizeof(celula));
  p->topo = -1;
  return p;
}

void empilha(pilha *p, char str[110]) {
  if (p != NULL) {
    if (p->topo == p->N-1) {
      p->v = realloc(p->v, 2*p->N*sizeof(celula));
      if (p->v == NULL) 
        return;
      p->N *= 2;
    }

    p->topo++;
    strcpy(p->v[p->topo].dado, str);
  }
}

void desempilha (pilha *p) {
  if(p->topo != -1) {
    printf("%s\n", p->v[p->topo].dado);
		p->topo--;
	} else {
    printf("NULL\n");
	}
}

int main() {
  pilha *p;
  p = cria_pilha();

  char *opcao = malloc(sizeof(char) * 10);
  
  while (scanf("%s", opcao) != -1) {
    if (strcmp(opcao, "inserir") == 0) {                 // inserir
      char *aux = malloc(110*sizeof(char));
      char *STR = malloc(110*sizeof(char));

      scanf("%[^\n]", aux);
      if (strlen(aux) != 0) {
        strcpy(STR, aux+1);
        empilha(p, STR);
      }
    } else {         // desfazer
      desempilha(p);
    } 
  }

  return 0;
}