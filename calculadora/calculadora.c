#include <stdio.h>

int getNumberFromChar(char charNumber[100]) {
  int number;
  sscanf(charNumber, "%d", &number);
  return number;
}

int main() {
  int length, i = 0, j = 0, result = 0, test = 1, contNumber = 0;
  char expression[100];

  scanf("%d", &length);

  if (length != 0) {
    scanf("%s", expression);

    while (length != 0) {
      while (expression[i] != '\0') {
        char aux[100];
        char sign[1];

        while (expression[i] != '+' && expression[i] != '-' && expression[i] != '\0') {
          aux[j] = expression[i];
          i++;
          j++;
        }

        aux[j] = '\0';
        contNumber++;

        if (contNumber <= length) {
          if (sign[0] == '+') {
            result += getNumberFromChar(aux);
          } else if (sign[0] == '-') {
            result -= getNumberFromChar(aux);
          } else {
            result = getNumberFromChar(aux);
          }
        }

        sign[0] = expression[i];
        i++;
        j = 0;
      }

      printf("Teste %d\n%d\n\n", test, result);
      test++;

      scanf("%d", &length);
      if (length == 0) {
        break;
      } else {
        scanf("%s", expression);
      }
      result = 0;
      i = 0;
      j = 0;
      contNumber = 0;
    }
  }

  return 0;
}