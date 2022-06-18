#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
  char dado;
  struct Celula *prox;
} Celula;

typedef struct Pilha {
  Celula *topo;
  int tam;
} Pilha;

Celula *newCelula(char dado) {
  Celula *tmp = malloc(sizeof(Celula));
  if (tmp == NULL) {
    return NULL;
  }
  tmp->dado = dado;
  tmp->prox = NULL;
  return tmp;
}

void start(Pilha *p) {
  p->topo = NULL;
  p->tam = 0;
}

int push(Pilha *p, char dado) {
  Celula *tmp = newCelula(dado);
  if (tmp == NULL) {
    return 0;
  }
  tmp->prox = p->topo;
  p->topo = tmp;
  p->tam++;
  return 1;
}

char pop(Pilha *p) {
  if (p->topo == NULL) {
    return '0';
  }
  Celula *tmp = p->topo;
  p->topo = p->topo->prox;
  char res = tmp->dado;
  free(tmp);
  p->tam--;
  return res;
}

void printPilha(Pilha *p) {
  Celula *tmp = p->topo;
  while (tmp != NULL) {
    printf("%c\n", tmp->dado);
    tmp = tmp->prox;
  }
}

Pilha clonar(Pilha *p) {
  Pilha temp;
  start(&temp);
  int n = p->tam;
  Celula *tmp = p->topo;
  char *v = malloc(n * sizeof(char));
  for (int i = n - 1; tmp != NULL; i--) {
    v[i] = tmp->dado;
    tmp = tmp->prox;
  }
  for (int i = 0; i < n; i++) {
    push(&temp, v[i]);
  }
  free(v);
  return temp;
}

Pilha concatenar(Pilha *a, Pilha *b) {
  Pilha temp;
  start(&temp);
  int n = a->tam + b->tam;
  char *v = malloc(n * sizeof(char));
  Celula *tmp = a->topo;
  for (int i = a->tam - 1; tmp != NULL; i--) {
    v[i] = tmp->dado;
    tmp = tmp->prox;
  }
  tmp = b->topo;
  for (int i = n - 1; tmp != NULL; i--) {
    v[i] = tmp->dado;
    tmp = tmp->prox;
  }
  for (int i = 0; i < n; i++) {
    push(&temp, v[i]);
  }
  free(v);
  return temp;
}
void inverter(Pilha *p) {
  int n = p->tam;
  char *v = malloc(n * sizeof(char));
  for (int i = 0; p->topo != NULL; i++) {
    v[i] = pop(p);
  }
  for (int i = 0; i < n; i++) {
    push(p, v[i]);
  }
  free(v);
}

int main(){
    return 0;
}