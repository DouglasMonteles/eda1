#include <stdio.h>

float recursivePow(float a, float b) {
  return (b == 0) ? 1 : (a * recursivePow(a, b - 1));
}

int main() {
  int a, b;

  scanf("%d %d", &a, &b);

  if (b < 0) {
    printf("%.3f\n", 1 / (recursivePow(a, (b * (-1)))));
  } else if (a == 0 && b == 0) {
    printf("indefinido\n");
  } else {
    printf("%.1f\n", recursivePow(a, b));
  }

  return 0;
}