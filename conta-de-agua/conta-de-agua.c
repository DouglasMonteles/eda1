#include <stdio.h>

int main() {
  int waterConsumpsion = 0;
  int spendWater = 7;

  scanf("%d", &waterConsumpsion);

  for (int count = 11; count <= waterConsumpsion; count++) {
    if (count >= 11 && count <= 30) {
      spendWater++;
    } else if (count >= 31 && count <= 100) {
      spendWater += 2;
    } else if (count >= 101) {
      spendWater += 5;
    }
  }

  printf("%d\n", spendWater);

  return 0;
}