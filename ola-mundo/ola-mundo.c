#include <stdio.h>

int main() {
  int n;
  char c[10] = {'1','+','1','-','3'};

  sscanf(c, "%d", &n);
  printf("n = %d\n", n);
  return 0;
}