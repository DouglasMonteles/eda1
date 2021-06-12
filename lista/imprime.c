#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

void imprime (celula *le) {
  celula *elem = le->prox;
  while (elem != NULL) {
    printf("%d -> ", elem->dado);
    elem = elem->prox;
  }
  printf("NULL\n");
}

void imprime_rec (celula *le) {
  celula *elem = le->prox;
  if (elem == NULL) {
    printf("NULL\n");
  } else {
    printf("%d -> ", elem->dado);
    return imprime_rec(elem);
  }
}

// int main() {
//   celula *le = malloc(sizeof(celula));
//   celula *elem1 = malloc(sizeof(celula));
//   celula *elem2 = malloc(sizeof(celula));
//   celula *elem3 = malloc(sizeof(celula));
//   celula *elem4 = malloc(sizeof(celula));
//   celula *elem5 = malloc(sizeof(celula));

//   le->prox = elem1;

//   elem1->dado = 1;
//   elem1->prox = elem2;

//   elem2->dado = 2;
//   elem2->prox = elem3;

//   elem3->dado = 3;
//   elem3->prox = elem4;

//   elem4->dado = 1;
//   elem4->prox = elem5;

//   elem5->dado = 1;
//   elem5->prox = NULL;

//   imprime(le);
//   imprime_rec(le);

//   free(le);
//   return 0;
// }
