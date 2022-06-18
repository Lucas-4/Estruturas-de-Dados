#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa {
  char nome[20];
  int idade;
} Pessoa;

typedef struct Fila {
  Pessoa *v;
  int inicio, fim, max, tam;
} Fila;

void start(Fila *f, int n) {
  f->v = malloc((n + 1) * sizeof(Pessoa));
  f->inicio = f->fim = 0;
  f->max = n + 1;
  f->tam = 0;
}

bool queue(Fila *f, Pessoa dado) {
  if ((f->fim + 1) % f->max == f->inicio) {
    return false;
  }
  f->v[f->fim] = dado;
  f->fim = (f->fim + 1) % f->max;
  f->tam++;
  return true;
}

Pessoa dequeue(Fila *f) {
  Pessoa tmp;
  if (f->inicio == f->fim) {
    strcpy(tmp.nome, "");
    return tmp;
  }
  tmp = f->v[f->inicio];
  f->inicio = (f->inicio + 1) % f->max;
  f->tam--;
  return tmp;
}

void printFila(Fila f) {
  for (int i = f.inicio; i != f.fim; i = (i + 1) % f.max) {
    printf("%s ", f.v[i].nome);
    printf("%d", f.v[i].idade);
    printf("\n");
  }
}

Fila clonar(Fila f) {
  Fila clone;
  start(&clone, f.tam);
  for (int i = f.inicio; i != f.fim; i = ((i + 1) % f.max)) {
    queue(&clone, f.v[i]);
  }
  return clone;
}

Fila concatenar(Fila a, Fila b) {
  Fila c;
  int size = a.tam + b.tam;
  start(&c, size);
  for (int i = a.inicio; i != a.fim; i = ((i + 1) % a.max)) {
    queue(&c, a.v[i]);
  }
  for (int i = b.inicio; i != b.fim; i = ((i + 1) % b.max)) {
    queue(&c, b.v[i]);
  }
  return c;
}

void inverter(Fila *f) {
  if (f->tam == 0) {
    return;
  }
  Pessoa data = dequeue(f);
  inverter(f);
  queue(f, data);
}

int main(){
    return 0;
}