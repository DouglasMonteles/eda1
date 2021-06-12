#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  char matricula[10];
  double mediaAtividades;
  double mediaProvas;
  struct celula *prox;
} celula;

void limpar_lista(celula *head) {
  celula *p, *aux;
  p = head;

  while (p) {
    aux = p->prox;
    free(p);
    p = aux;
  }
}

celula *inicializar() {
  celula *no = malloc(sizeof(celula));
  no->prox = NULL;
  return no;
}
celula *inclui(celula *le, int x) {
  celula *no = inicializar();
  no->mediaAtividades = x;
  celula *aux = le;

  while (aux->prox) {
    aux = aux->prox;
  }

  aux->prox = no;
}

void imprime(celula *le) {
  celula *aux = le->prox;

  while (aux) {
    printf("%.2f -> ", aux->mediaAtividades);
    aux = aux->prox;
  }

  printf("NULL\n");
}

void relatorioMediaAtividades(celula *le, celula *l1, celula *l2, double media) {
  celula *p = le, *p1 = l1, *p2 = l2;

  while (p->prox) {
    celula *paux = p->prox;

    if (((p->prox->mediaAtividades) <= media) == 0) {
        p2->prox = p->prox;
        p2 = p2->prox;
    } else {
      p1->prox = p->prox;
      p1 = p1->prox;
    }
    p = p->prox;
  }

  p1->prox = NULL;
  p2->prox = NULL;
}

// int main() {
//   celula *le = malloc(sizeof(celula));
//   le->prox = NULL;
//   inclui(le, 2.0);
//   inclui(le, 3.0);
//   inclui(le, 4.0);
//   inclui(le, 5.0);
//   inclui(le, 7.0);
//   inclui(le, 9.0);
//   celula *l1 = inicializar();
//   celula *l2 = inicializar();
//   divide_lista(le, l1, l2, 6.0);
//   imprime(l1);
//   imprime(l2);
//   limpar_lista(le);
//   imprime(le);

//   return 0;
// }