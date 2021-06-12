#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

typedef struct celula {
	int dado;
	int linha, coluna;
	struct celula *prox;
	struct celula *ant;
} celula;

celula *primeiro; 
celula *ultimo; 

celula* cria_celula(int linha, int coluna, int dado);
void inserir(celula *novo);
void deletar(int linha, int coluna);
int vazia();
celula* dado_existente(int linha, int coluna);
void imprimir_elementos();
void imprimir_matriz();


celula* cria_celula(int linha, int coluna, int dado) {
	celula *novo;
	novo = (celula*)malloc(sizeof(celula));

	novo->dado = dado;
	novo->linha = linha;
	novo->coluna = coluna;

	return novo;
}

void inserir(celula *novo) {
	if(!ultimo) {
    novo->prox = NULL;
    novo->ant = NULL;

    ultimo = novo;
    primeiro = novo;
  } else {
    celula *p, *ant;

    p = primeiro; 
    ant = p->ant; 

    while(p) {
      if((p->linha < novo->linha) || ((p->linha == novo->linha) && (p->linha + p->coluna) < (novo->linha + novo->coluna))) {
        ant = p; 
        p = p->prox; 
      } else {
        if(p->ant) {
          p->ant->prox = novo;
          novo->prox = p;
          novo->ant = p->ant;
          p->ant = novo; 

          return; 
        }

        novo->prox = p; 
        novo->ant = NULL; 
        p->ant = novo; 
        primeiro = novo; 

        return; 
      }
    }

    ant->prox = novo;

    novo->prox = NULL;
    novo->ant = ant;

    ultimo = novo;
  }
}

int vazia() {
	if(!ultimo) {
		return 1;
  }
	return 0;
}

celula* dado_existente(int linha, int coluna) {
	celula* p = primeiro;

	while(p) {
		if(linha == p->linha && coluna == p->coluna)
			return p; 
		p = p->prox;
	}
	return NULL;
}

void imprimir_elementos() {
	celula* p = primeiro;

	while(p) {
		printf("(%d,%d)\n", p->linha, p->coluna);
		p = p->prox;
	}
}

void imprimir_produto(int *prod, int linhas, int colunas) {
	celula* p = primeiro;
  int cont = 0, soma = 0, linha = 0;
  int *resp = malloc(linhas * sizeof(int));

	while(p) {
    printf("(%d,%d,%d)\n", p->linha, p->coluna, p->dado);
    if (linha == p->linha) {
      
    }
    p = p->prox;
  }

  for (int i = 0; i < linhas; i++) {
    printf("%d\n", resp[i]);
  }
}


// void imprimir_matriz() {
// 	if(!vazia()) {
// 		int total_linhahas = ultimo->linha;
//     int total_colunaunas = -1;

// 		celula* p = primeiro;
// 		while(p) {
// 			if(p->coluna > total_colunaunas)
// 				total_colunaunas = p->coluna;
// 			p = p->prox;
// 		}

// 		for(int i = 0; i < total_linhahas; i++) {
// 			for(int j = 0; j < total_colunaunas; j++) {
// 				celula* cel = dado_existente(i + 1, j + 1);

// 				if(cel) 
// 					printf("%d\t", cel->dado);
// 				else 
// 					printf("X\t");
// 			}
// 			printf("\n");
// 		}
// 	}
// 	else
// 		printf("\nLista vazia!!\n");
// }

void produto_matriz(int *prod) {
	if(!vazia()) {
		int total_linhas = ultimo->linha;

		int total_colunas = -1;
		celula* p = primeiro;
		while(p) {
			if(p->coluna > total_colunas)
				total_colunas = p->coluna;
			p = p->prox;
		}

    for(int i = 0; i < total_linhas; i++) {
      int soma = 0;
			for(int j = 0; j < total_colunas; j++) {
				celula* cel = dado_existente(i + 1, j + 1);

				if (cel) { 
          soma += (cel->dado * prod[j]);
        }
			}
      printf("%d\n", soma);
		}
	}
	else
		printf("\nLista vazia!!\n");
}


int main() {
	celula *vet[MAX]; 
  int m, n, aux1, aux2, aux3, cont = 0;
  scanf("%d %d", &m, &n);

  do {
    scanf("%d %d %d", &aux1, &aux2, &aux3);
    if (aux1 != -1 && aux2 != -1 && aux3 != -1) {
      vet[cont] = cria_celula(aux1+1, aux2+1, aux3);
      cont++;
    }
  } while (aux1 != -1 && aux2 != -1 && aux3 != -1);

	for(int i = 0; i < cont; i++)
		inserir(vet[i]);

  int *prod = malloc(n * sizeof(int));

  for (int i = 0; i < n; i++)
    scanf("%d", &prod[i]);

  produto_matriz(prod);
  imprimir_produto(prod, n, m);

	return 0;
}