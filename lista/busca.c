#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

celula *busca (celula *le, int x) {
  celula *p;
  p = le;
  while (p != NULL && p->dado != x) 
    p = p->prox; 
  return p;
}

celula *busca_rec (celula *le, int x) {
  if (le == NULL)  return NULL;
  if (le->dado == x)  return le;
  return busca_rec (le->prox, x);
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

//   printf("%d\n", busca(le, 30)->dado);
//   printf("%d\n", busca_rec(le, 1)->dado);
  

//   return 0;
// }

