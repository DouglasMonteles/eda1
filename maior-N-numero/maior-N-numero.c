#include <stdio.h>

int main() {
  int number, higherNumber;

  scanf("%d", &number);
  higherNumber = number;

  do {
    if (higherNumber < number) {
      higherNumber = number;
    } 
  } while (scanf("%d", &number) != EOF);

  printf("%d\n", higherNumber);

  return 0;
}