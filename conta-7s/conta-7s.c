#include <stdio.h>

void sevenCount(unsigned long int num, int *cont) {
  if (num != 0) {
    if (num % 10 == 7) {
      (*cont)++;
    }
    sevenCount(num / 10, cont);
  }
}

int main() {
  unsigned long int num;
  int cont = 0;

  scanf("%lu", &num);
  sevenCount(num, &cont);

  printf("%d\n", cont);

  return 0;
}