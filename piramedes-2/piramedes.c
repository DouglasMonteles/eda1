#include <stdio.h>

void handleAsterisk(int quantity) {
  int count;

  for (count = 1; count <= quantity; count++) {
    printf("*");
  }
}

int main() {
  int lines, counter, counter2, counter3;

  scanf("%d", &lines);
  counter3 = (lines - 1);

  for (counter = 1; counter <= (lines * 2) - 1; counter += 2) {
    for (counter2 = 1; counter2 <= counter3; counter2++) {
      printf(" ");
    }
    handleAsterisk(counter);
    printf("\n");
    counter3--;
  }

  return 0;
}