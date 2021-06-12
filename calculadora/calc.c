#include <stdio.h>

int main() {
  int m; // 1 <= m <= 100
  int cont, i, j, k, sinal, resultado = 0;
  char expressao[1000];

  scanf("%d", &m);

  i = 1;
  j = 0;
  k = 0;
  sinal = 0;

  while (m != 0) {
    scanf("%s", expressao);

    j = 0;
    k = 0;
    sinal = 0;

    for (cont = 1; cont <= m; cont++) {
      char aux[1000];
      int numero;

      while (expressao[j] != '+' && expressao[j] != '-' && expressao[j] != '\0') {
        aux[k] = expressao[j];
        j++;
        k++;
      }

      aux[k] = '\0';

      sscanf(aux, "%d", &numero);
      if (sinal == 1) { // sinal '-'
        numero = (-1) * numero;
      }

      resultado += (numero);

      sinal = (expressao[j] == '-' && expressao[j] != '\0') ? 1 : 0;
      j++;
      k = 0;
    }
    
    printf("Teste %d\n", i);
    printf("%d\n", resultado);
    printf("\n");
    i++;
    resultado = 0;

    scanf("%d", &m);
  }

  return 0;
}