#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

void insere_inicio (celula *le, int x) {
  celula *novo = malloc(sizeof(celula));
  if (novo != NULL) {
    novo->dado = x;
    novo->prox = le->prox;
    le->prox = novo;
  }
}
// 10 & 3
void insere_antes (celula *le, int x, int y) {
  for (celula *elem = le; elem->prox != NULL; elem = elem->prox) {
    if (elem->prox->dado == y) {
      celula *elem1 = malloc(sizeof(celula));
      elem1->dado = elem->dado;
      celula *prox = elem;
      elem1->prox = prox;
      elem->dado = x;
    }
  }
}

void imprime (celula *le) {
  celula *elem = le->prox;
  while (elem != NULL) {
    printf("%d -> ", elem->dado);
    elem = elem->prox;
  }
  printf("NULL\n");
}

int main() {
  celula *le = malloc(sizeof(celula));
  celula *elem1 = malloc(sizeof(celula));
  celula *elem2 = malloc(sizeof(celula));
  celula *elem3 = malloc(sizeof(celula));
  celula *elem4 = malloc(sizeof(celula));
  celula *elem5 = malloc(sizeof(celula));

  le->prox = elem1;

  elem1->dado = 1;
  elem1->prox = elem2;

  elem2->dado = 2;
  elem2->prox = elem3;

  elem3->dado = 3;
  elem3->prox = elem4;

  elem4->dado = 1;
  elem4->prox = elem5;

  elem5->dado = 1;
  elem5->prox = NULL;

  insere_inicio(le, 0);
  insere_antes(le, 10, 3);
  imprime(le);

  return 0;
}
