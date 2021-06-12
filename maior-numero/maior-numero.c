#include <stdio.h>

int main() {
  int n1, n2, n3, n4, counter;
  int higherNumber;

  scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

  higherNumber = n1;

  if (higherNumber < n1) {
    higherNumber = n1;
  }
  
  if (higherNumber < n2) {
    higherNumber = n2;
  }

  if (higherNumber < n3) {
    higherNumber = n3;
  }

  if (higherNumber < n4) {
    higherNumber = n4;
  }

  printf("%d\n", higherNumber);

  return 0;
}