// #include <stdio.h>
// #include <stdlib.h>

// typedef struct celula {
//   int dado;
//   struct celula *prox;
// } celula;

// typedef struct fila {
//  celula *inicio;
//  celula *fim;
// } fila;

// fila *cria_fila() {
//   fila *filaCriada = (fila*) malloc(sizeof(fila));
//   filaCriada->inicio = NULL;
//   filaCriada->fim = NULL;

//   return filaCriada;
// }

// void *adiciona_carta_na_fila(fila *p, int carta){
//   celula *novo = (celula*) malloc(sizeof(celula));
//   novo->dado = carta;
//   novo->prox = NULL;

//   if(p->inicio == NULL){
//     p->inicio = novo;
//     p->fim = novo;
//   } else {
//     p->fim->prox = novo;
//     p->fim = novo;
//   }
// }

// int getCarta(fila *p){
//   int carta;
//   celula *celCarta;

//   celCarta = p->inicio;
//   carta = celCarta->dado;

//   p->inicio = celCarta->prox;

//   if(p->inicio == NULL) {
//     p->fim = NULL;
//   }

//   free(celCarta);
//   return carta;
// }

// int vazio(fila *p){
//   return p->inicio == NULL;
// }

// int main() {
//   int n, i, carta, cont = 0;
//   fila *fila;

//   fila = cria_fila();

//   scanf("%d", &n);

//   if (n) {
//     cont = n;

//     for(i=1; i<=n; i++) {
//       adiciona_carta_na_fila(fila, i);
//     }
//   }

//   printf("Cartas descartadas:");

//   while(cont != 1) {
//     printf(" %d", getCarta(fila));
//     adiciona_carta_na_fila(fila, getCarta(fila));

//     if(cont != 2) {
//       printf(",");
//     }

//     cont--;
//   }

//   if(!vazio(fila)) {
//     printf("\nCarta restante: %d\n", getCarta(fila));
//   }

//   return 0;
// }































#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
  int *valor;
  int topo;
} pilha;

void criaPilha (pilha * p){
  p->topo = 0;
  p->valor = malloc (1000 * sizeof (int));
  if (p == NULL)
    exit (EXIT_FAILURE);
}

void enfileirar (pilha * p){
  int final = p->valor[p->topo - 1];
  for (int i = p->topo; i > 0; i--)
    {
      p->valor[i] = p->valor[i - 1];
    }
  p->valor[0] = final;
}


int desempilhar (pilha * p){
  int r = p->valor[p->topo - 1];
  p->topo--;
  return r;
}

void empilhar (pilha * p, int x){
  p->valor[p->topo] = x;
  p->topo++;
}

int main ()
{

  int num_cartas;
  int i, j;
  pilha *p = malloc (sizeof (pilha));
  scanf ("%d", &num_cartas);
  criaPilha (p);
  int *resto = malloc ((num_cartas - 1) * sizeof (int));

  for (i = num_cartas; i > 0; i--)
    empilhar (p, i);

  for (i = 0, j = num_cartas; j > 1; i++, j--)
    {

      resto[i] = desempilhar (p);
      enfileirar (p);
    }
  
  printf ("Cartas descartadas:");

  for (int j = 0; j < num_cartas - 2; j++)
    {
      printf (" %d,", resto[j]);
    }
  printf (" %d\n", resto[num_cartas - 2]);
  printf ("Carta restante: %d\n", p->valor[0]);


  return 0;
}