#include <stdio.h>

struct tipoFiliacao {
  char nome[80];
  char nomeMae[80];
  char nomePai[80];
};

struct tipoFiliacao separaLinhaCSV(char linha[240]) {
  struct tipoFiliacao tipo;
  int i = 0, j = 0;

  while (linha[i] != ',') {
    tipo.nome[j] = linha[i];
    i++;
    j++;
  }

  tipo.nome[j] = '\0';

  i++;
  j = 0;

  while (linha[i] != ',') {
    tipo.nomeMae[j] = linha[i];
    i++;
    j++;
  } 

  tipo.nomeMae[j] = '\0';

  i++;
  j = 0;

  while (linha[i] != '\0') {
    tipo.nomePai[j] = linha[i];
    i++;
    j++;
  }

  tipo.nomePai[j] = '\0';

  //printf("%s\n%s\n%s\n", tipo.nome, tipo.nomeMae, tipo.nomePai);
  return tipo;
}

// int main() {
//   separaLinhaCSV("Pedro da Silva Pontes de Aguiar Neto Souza Martins,Pedro da Silva Pontes de Aguiar Neto Souza Martins,Guilherme Lopesss");
//   return 0;
// }