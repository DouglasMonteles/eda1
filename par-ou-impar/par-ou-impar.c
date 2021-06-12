#include <stdio.h>

int main() {
  int matchers, counter;
  int value1, value2, sum;
  int winner[1000], winnerCount = 0;
  char player1[11], player2[11];

  scanf("%d", &matchers);

  while (matchers != 0) {
    scanf("%s", player1);
    scanf("%s", player2);

    for (counter = 0; counter < matchers; counter++) {
      scanf("%d %d", &value1, &value2);

      sum = (value1 + value2);

      if (sum % 2 == 0) {
        winner[counter] = 1;
      } else {
        winner[counter] = 2;
      }
    }

    winnerCount++;
    printf("Teste %d\n", winnerCount);

    for (counter = 0; counter < matchers; counter++) {
      if (winner[counter] == 1) {
        printf("%s\n", player1);
      } else {
        printf("%s\n", player2);
      }
    }
    
    printf("\n");
    scanf("%d", &matchers);
  }
  
  return 0;
}