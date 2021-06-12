#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula_str {
  char str[110];
} celula_str;

typedef struct pilha_str {
  int N, topo;
  celula_str *v;
} pilha_str;

pilha_str *cria_pilha_str() {
  pilha_str *p = malloc(sizeof(pilha_str));

  p->N = 110;
  p->v = malloc(sizeof(celula_str) * p->N);
  p->topo = -1;
  return p;
}

void empilha_str(pilha_str *p, char str[110]) {
  if (p != NULL) {
    if (p->topo == p->N-1) {
      p->v = realloc(p->v, 2*p->N*sizeof(celula_str));
      if (p->v == NULL) 
        return;
      p->N *= 2;
    }

    p->topo++;
    strcpy(p->v[p->topo].str, str);
  }
}

void desempilha_str (pilha_str *p) {
  if(p->topo != -1) {
    printf("%s\n", p->v[p->topo].str);
		p->topo--;
	} else {
    printf("NULL\n");
	}
}

int main() {
  pilha_str *p;
  p = cria_pilha_str();

  char *opcao = malloc(sizeof(char) * 8);
  
  while (scanf("%s", opcao) != -1) {
    if (strcmp(opcao, "inserir") == 0) { 
      char *STR = malloc(110*sizeof(char));

      scanf(" %[^\n]", STR);
      empilha_str(p, STR);
    } else {         
      desempilha_str(p);
    } 
  }

  return 0;
}