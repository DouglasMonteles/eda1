#include <stdio.h>

void traco(int qtd) {
  if (qtd == 1) {
    printf("-");
  } else {
    printf("-");
    traco(qtd-1);
  }
}

void handleRegua(int n) {
  if (n == 1) {
    printf(".-");
  } else {
    handleRegua(n-1);
    printf("\n");
    printf(".");
    traco(n);
    printf("\n");
    handleRegua(n-1);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  if (n > 0) {
    handleRegua(n);
    printf("\n");
  }

  return 0;
}