#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* substr(char *str, int start, int end) {
  char *substring;
  int i, j;

  substring = (char*) malloc(sizeof(char) * (end - start + 1));
  
  for (i = start, j = 0; i < end; i++, j++) {
    substring[j] = str[i];
  }

  substring[j] = '\0';
  return substring;
}

int startWith(char *str, char *sub) {
  int subLength = strlen(sub);
  char *aux = (char*) malloc(sizeof(char) * subLength);

  for (int i = 0; i < subLength; i++)
    aux[i] = str[i];

  return (aux == sub && str[0] == sub[0]);
}

int endWith(const char *str, const char *suffix) {
  if (!str || !suffix)
    return 0;
  
  size_t lenstr = strlen(str);
  size_t lensuffix = strlen(suffix);

  if (lensuffix >  lenstr)
    return 0;

  return (strncmp(str + lenstr - lensuffix, suffix, lensuffix) == 0) ? 0 : 1;
}

int strDist(char* str, char *sub) {
  if (strlen(str) < strlen(sub))
    return 0;
  
  if (strstr(str, sub) == NULL)
    return 0;

  if (startWith(str, sub) == 0 && endWith(str, sub) == 0) {
    return strlen(str);
  }

  if (startWith(str, sub) == 0) {
    return strDist(substr(str, 0, strlen(str)-1), sub);
  }

  if (endWith(str, sub) == 0) {
    return strDist(substr(str, 1, strlen(str)), sub);
  }

  else return strDist(substr(str, 1, strlen(str)-1), sub);
}


int main() {
  char str[101], sub[100];
  scanf("%s %s", str, sub);

  printf("%d\n", strDist(str, sub));
  return 0;
}