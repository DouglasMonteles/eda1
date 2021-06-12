#include <stdio.h>

void handleLinePyramid(int linesOfPyramid) {
  for (int counter = 1; counter <= linesOfPyramid; counter++) {
    for (int counter2 = 1; counter2 <= counter; counter2++) {
      printf("%.2d ", counter);
    }
    printf("\n");
  }
}

void handleColumnPyramid(int columnsOfPyramid) {
  int counter2 = 1;

  for (int counter = 1; counter <= columnsOfPyramid; counter++) {
    for (counter2 = 1; counter2 <= counter; counter2++) {
      printf("%.2d ", counter2);
    }
    counter2 = 1;
    printf("\n");
  }
}

int main() {
  int number;

  scanf("%d", &number);

  if (number >= 1 && number < 100) {
    handleLinePyramid(number);
    printf("\n");
    handleColumnPyramid(number);
  }

  return 0;
}