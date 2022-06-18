#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pilha {
  char *v;
  int topo;
  int max;
} Pilha;

void start(Pilha *p, int n) {
  p->v = malloc(n * sizeof(char));
  p->topo = 0;
  p->max = n;
}

int push(Pilha *p, char dado) {
  if (p->topo == p->max) {
    return 0;
  }
  p->v[p->topo] = dado;
  p->topo++;
  return 1;
}

char pop(Pilha *p) {
  if (p->topo == 0) {
    return '0';
  }
  return p->v[--p->topo];
}

void printPilha(Pilha p) {
  for (int i = 0; i < p.topo; i++) {
    printf("%c\n", p.v[i]);
  }
}

void clonar(Pilha *c, Pilha o) {
  start(c, o.topo);
  for (int i = 0; i < o.topo; i++) {
    push(c, o.v[i]);
  }
}

Pilha concatenar(Pilha a, Pilha b) {
  Pilha concat;
  int tam = a.topo + b.topo;
  start(&concat, tam);
  for (int i = 0; i < a.topo; i++) {
    push(&concat, a.v[i]);
  }
  for (int i = 0; i < b.topo; i++) {
    push(&concat, b.v[i]);
  }
  for (int i = 0; i < 10; i++) {
    int ch = 's';
    push(&concat, ch);
  }
  return concat;
}

void inverter(Pilha *p) {
  char tmp;
  for (int i = 0; i < p->topo / 2; i++) {
    tmp = p->v[p->topo - 1 - i];
    p->v[p->topo - 1 - i] = p->v[i];
    p->v[i] = tmp;
  }
}

int main(){
    return 0;
}