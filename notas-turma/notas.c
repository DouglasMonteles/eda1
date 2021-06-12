#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
  char matricula[10];
  double mediaAtividades;
  double mediaProvas;
  struct celula *prox;
} celula;

void inserir_no_final(celula *list, celula *elem) {
  celula *novo_elemento = malloc(sizeof(celula));
  novo_elemento->prox = NULL;
  celula *auxiliar = list;
  int cont = 0;
  
  while (elem->matricula[cont] != '\n') {
    novo_elemento->matricula[cont] = elem->matricula[cont];
    cont++;
  }

  novo_elemento->mediaAtividades = elem->mediaAtividades;
  novo_elemento->mediaProvas = elem->mediaProvas;

  if(list->prox == NULL) {
    list->prox = novo_elemento;
  } else {
    while(auxiliar->prox != NULL) {
      auxiliar=auxiliar->prox;
      if(auxiliar->prox == NULL) {
        auxiliar->prox = novo_elemento;
        return;
      }
    }
  }  
}

celula *enfileira(celula *f, celula *novo) {
	novo->prox = f->prox;
	f->prox = novo;
	f->mediaAtividades = novo->mediaAtividades;
  return novo;
}

void relatorioMediaAtividades (celula *le, celula *l1, celula *l2, double media) {
  for (celula *elem = le->prox; elem != NULL; elem = elem->prox) {
    if (elem->mediaAtividades <= media) {
      
    } else {
      //l2 = enfileira(l2, elem);
    }
  }
  
  // for (celula *elem = le->prox; elem != NULL; elem = elem->prox)
  //   le->prox = NULL;
  // free(le);
}

void imprime_lista(celula *le) {
  for (celula *elem = le->prox; elem != NULL; elem = elem->prox)
    printf("%.2f -> ", elem->mediaAtividades);
  
  printf("NULL\n");
}

int main() {
  celula *le = malloc(sizeof(celula));
  celula *l1 = malloc(sizeof(celula));
  celula *l2 = malloc(sizeof(celula));
  celula *elem1 = malloc(sizeof(celula));
  celula *elem2 = malloc(sizeof(celula));
  celula *elem3 = malloc(sizeof(celula));
  celula *elem4 = malloc(sizeof(celula));

  le->prox = elem1;
  
  elem1->matricula[0] = '1';
  elem1->matricula[1] = '\n';
  elem1->mediaProvas = 4.0;
  elem1->mediaAtividades = 10.0;
  elem1->prox = elem2;

  elem2->matricula[0] = '1';
  elem2->matricula[1] = '\n';
  elem2->mediaProvas = 4.0;
  elem2->mediaAtividades = 4.0;
  elem2->prox = elem3;

  elem3->matricula[0] = '1';
  elem3->matricula[1] = '\n';
  elem3->mediaProvas = 4.0;
  elem3->mediaAtividades = 9.5;
  elem3->prox = elem4;

  elem4->matricula[0] = '1';
  elem4->matricula[1] = '\n';
  elem4->mediaProvas = 4.0;
  elem4->mediaAtividades = 5.0;
  elem4->prox = NULL;

  relatorioMediaAtividades(le, l1, l2, 6.0);

  imprime_lista(l1);
  printf("\n");
  imprime_lista(l2);
  printf("\n");
  imprime_lista(le);
  printf("\n");
  return 0;
}

