#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int strDist(char *str, char *sub) {
  if(strlen(str) < strlen(sub))
    return 0;
        
  if(strcmp(substr(str, 0, strlen(sub)), sub) == 0) {
    if (strcmp(substr(str, strlen(str) - strlen(sub), strlen(str)), sub) == 0) {
      return strlen(str);
    } else {
      return strDist(substr(str, 0, strlen(str)-1), sub);
    }
  }
  
  return strDist(substr(str, 1, strlen(str)), sub);
}

int main() {
  char str[101], sub[100];
  scanf("%s %s", str, sub);
  str[strlen(str)] = '\0';
  sub[strlen(sub)] = '\0';

  printf("%d\n", strDist(str, sub));
  return 0;
}