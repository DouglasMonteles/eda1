#include <stdio.h>
#include <stdlib.h>

int findIndex(int casa, int* encomendas, int qtdEncomendas) {
  for (int i = 0; i < qtdEncomendas; i++) {
    if (encomendas[i] == casa)
      return i;
  }
  return -1;
}

int tempoEntrega(int* numCasas, int* numEncomendas, int qtdCasas, int qtdEncomendas) {
  int cont = 0, i, j, index = -1;

  for (i = 0; i < qtdCasas; i++) {
    for (j = 0; j < qtdEncomendas; j++) {
      if (numEncomendas[j] == numCasas[i] && numEncomendas[j] != numEncomendas[j-1]) {
        cont += (i - (index == -1) ? j : index);
        index = j;
      }
    } 
  }

  return cont;
}

int main() {
  int qtdCasas, qtdEncomendas;
  scanf("%d %d", &qtdCasas, &qtdEncomendas);

  int* numCasas = malloc(sizeof(int) * qtdCasas);
  int* numEncomendas = malloc(sizeof(int) * qtdEncomendas);

  for (int i = 0; i < qtdCasas; i++) {
    int num;
    scanf("%d", &num);
    numCasas[i] = num;
  }

  for (int i = 0; i < qtdEncomendas; i++) {
    int num;
    scanf("%d", &num);
    numEncomendas[i] = num;
  }

  printf("%d\n", tempoEntrega(numCasas, numEncomendas, qtdCasas, qtdEncomendas));
  return 0;
}