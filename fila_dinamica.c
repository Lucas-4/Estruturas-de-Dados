#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa {
  char nome[20];
  int idade;
} Pessoa;

typedef struct Celula {
  Pessoa dado;
  struct Celula *prox;
} Celula;

typedef struct Fila {
  Celula *inicio, *fim;
  int tam;
} Fila;

Celula *newCelula(Pessoa dado) {
  Celula *tmp = malloc(sizeof(Celula));
  if (tmp == NULL) {
    return tmp;
  }
  tmp->dado = dado;
  tmp->prox = NULL;
  return tmp;
}

void start(Fila *f) {
  Celula *tmp = malloc(sizeof(Celula));
  tmp->prox = NULL;
  f->inicio = f->fim = tmp;
  f->tam = 0;
}

int queue(Fila *f, Pessoa dado) {
  Celula *tmp = newCelula(dado);
  if (tmp == NULL) {
    return -1;
  }
  f->fim->prox = tmp;
  f->fim = tmp;
  f->tam++;
  return 1;
}

Pessoa dequeue(Fila *f) {
  if (f->inicio == f->fim) {
    Pessoa p;
    p.idade = -1;
    return p;
  }
  Celula *tmp = malloc(sizeof(Celula));
  tmp = f->inicio;
  f->inicio = f->inicio->prox;
  f->tam--;
  free(tmp);
  return f->inicio->dado;
}

void printFila(Fila *f) {
  Celula *tmp = f->inicio->prox;
  while (tmp != NULL) {
    printf("%s  ", tmp->dado.nome);
    printf("%d\n", tmp->dado.idade);
    tmp = tmp->prox;
  }
}

int priorqueue(Fila *f, Pessoa dado) {
  if (dado.idade < 65) {
    int n = queue(f, dado);
    return n;
  }

  Celula *tmp = newCelula(dado);
  if (tmp == NULL) {
    return -1;
  }
  Celula *t = f->inicio;
  while (t != NULL) {
    if (t->prox->dado.idade < dado.idade) {
      Celula *Tprox = t->prox;
      t->prox = tmp;
      tmp->prox = Tprox;
      f->tam++;
      return 1;
    }
  }

  f->fim->prox = tmp;
  f->fim = tmp;
  f->tam++;
  return 1;
}

Fila concatenar(Fila *a, Fila *b) {
  Fila temp;
  start(&temp);
  Celula *tmp = a->inicio->prox;
  while (tmp != NULL) {
    queue(&temp, tmp->dado);
    tmp = tmp->prox;
  }
  tmp = b->inicio->prox;
  while (tmp != NULL) {
    queue(&temp, tmp->dado);
    tmp = tmp->prox;
  }
  return temp;
}

void inverter(Fila *f) {
  int n = f->tam;
  Pessoa *v = malloc(n * sizeof(Pessoa));
  for (int i = 0; f->inicio != f->fim; i++) {
    v[i] = dequeue(f);
  }
  for (int i = n - 1; i >= 0; i--) {
    queue(f, v[i]);
  }
  free(v);
}

int main(){
    return 0;
}