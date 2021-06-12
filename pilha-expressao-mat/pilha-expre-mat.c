#include <stdio.h>
#include <string.h>
#define TAM 500

struct celula {
  int topo;
  int pilha[TAM];
};

void push(struct celula *p, int item){
  if(p->topo != TAM){
    p->pilha[p->topo++] = item;
  }
}

int empty(struct celula *p){
  if(p->topo == 0) 
    return -1;
  else 
    return 0;
}

int pop(struct celula *p){
  if(!empty(p)){
    return p->pilha[--p->topo];
  }
}

int top(struct celula *p){
  if(!empty(p)) {
    return p->pilha[p->topo-1];
  } 
}

void main() {
  struct celula pilha;
  int abre, fecha, id, i;
  char expressao[TAM];
  i = abre = fecha = pilha.topo = 0;
  
  fgets(expressao, TAM, stdin);
  for(i; expressao[i] != '\n'; i++) {
    if((expressao[i] == '(') || (expressao[i] == '[') || (expressao[i] == '{')){
      abre++;
      if(expressao[i] == '(') id = 1;
      else if(expressao[i] == '[') id = 2;
      else id = 3;
      push(&pilha, id);
    } else if((expressao[i] == ')') || (expressao[i] == ']') || (expressao[i] == '}')) {
      fecha++;
      if(expressao[i] == ')') id = 1;
      else if(expressao[i] == ']') id = 2;
      else id = 3;
      if(id == top(&pilha)) pop(&pilha);
    }       
  }

  if(empty(&pilha)) {
    if(abre == fecha) {
      printf("sim\n");
    } else {
      printf("nao\n");
    }
  } else {
    printf("nao\n");
  }
}