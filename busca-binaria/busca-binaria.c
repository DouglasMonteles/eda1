#include <stdio.h>

int main() {
  int nLength;
  unsigned long int mLength;

  scanf("%d", &nLength);
  scanf("%lu", &mLength);
  
  if (nLength > 0) {
    int n[nLength];
    int m[mLength];

    for (int i = 0; i < nLength; i++)
      scanf("%d", &n[i]);

    for (int i = 0; i < mLength; i++)
      scanf("%d", &m[i]);

    for (int i = 0; i < mLength; i++) {
      int aux = 0;

      for (int j = 0; j < nLength; j++) {
        if (m[i] == n[j]) {
          printf("%d\n", j);
          aux = 1;
        }
      }

      if (aux == 0)
        printf("-1\n");
    }
  }

  return 0;
}
