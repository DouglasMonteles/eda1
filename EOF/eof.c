#include <stdio.h>

int main() {
  int number, count = 0;

  while (scanf("%d", &number) == 1) {
    count++;
  }
  
  printf("%d\n", count);

  return 0;
}