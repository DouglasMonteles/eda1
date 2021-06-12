#include <stdio.h>
#include <string.h>

void reverseString(char *str, int length) {
  char letra = str[length];
  
  if (length == 0) {
    printf("%c", letra);
  } else {
    printf("%c", letra);
    reverseString(str, length-1);
  }
}

int main() {
  char str[501];
  int length;

  scanf("%s", str);
  length = strlen(str);

  reverseString(str, length-1);
  printf("\n");

  return 0;
}