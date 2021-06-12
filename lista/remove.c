#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

void remove_depois(celula *p) {
  celula *lixo = p->prox;
  if (lixo != NULL) {
    p->prox = lixo->prox;
    free(lixo);
  }
}

void remove_elemento(celula *le, int x) {
  for (celula *elem = le; elem->prox != NULL; elem = elem->prox)
    if (elem->prox->dado == x) {
      remove_depois(elem);
      return;
    }
}

void remove_todos_elementos(celula *le, int x) {
  for (celula *elem = le; elem->prox != NULL; )
    if (elem->prox->dado == x)
      remove_depois(elem);
    else 
      elem = elem->prox;
}

// void imprime_lista(celula *le) {
//   for (celula *elem = le->prox; elem != NULL; elem = elem->prox)
//     printf("%d -> ", elem->dado);
  
//   printf("NULL\n");
// }

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

//   imprime_lista(le);

//   remove_depois(elem2);
//   imprime_lista(le);

//   remove_elemento(le, 1);
//   imprime_lista(le);

//   remove_todos_elementos(le, 1);
//   imprime_lista(le);

//   remove_depois(le);
//   imprime_lista(le);

//   free(le);
//   return 0;
// }