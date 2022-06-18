#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa {
  int codigo;
  char nome[20];
  int idade;
} Pessoa;

typedef struct Celula {
  Pessoa dado;
  struct Celula *prox;
} Celula;

typedef struct Lista {
  Celula *inicio, *fim;
  int tam;
} Lista;

void start(Lista *l) {
  Celula *tmp = malloc(sizeof(Celula));
  l->inicio = l->fim = tmp;
  l->tam = 0;
}
Celula *newCelula(Pessoa dado) {
  Celula *tmp = malloc(sizeof(Celula));
  if (tmp == NULL) {
    return 0;
  }
  tmp->dado = dado;
  tmp->prox = NULL;
  return tmp;
}

int inserirFim(Lista *l, Pessoa dado) {
  Celula *tmp = newCelula(dado);
  if (tmp == NULL) {
    return 0;
  }
  l->fim->prox = tmp;
  l->fim = tmp;
  l->tam++;
  return 1;
}

Pessoa removerFim(Lista *l) {
  Pessoa res;
  if (l->inicio == l->fim) {
    res.codigo = -1;
    return res;
  }
  Celula *tmp = l->inicio;
  while (tmp->prox != l->fim) {
    tmp = tmp->prox;
  }
  res = l->fim->dado;
  l->fim = tmp;
  free(l->fim->prox);
  l->fim->prox = NULL;
  l->tam--;
  return res;
}

void printLista(Lista *l) {
  Celula *tmp = l->inicio->prox;
  while (tmp != NULL) {
    printf("%d  ", tmp->dado.codigo);
    printf("%s  ", tmp->dado.nome);
    printf("%d\n", tmp->dado.idade);
    tmp = tmp->prox;
  }
}

Lista clonar(Lista *l) {
  Lista tmp;
  start(&tmp);
  Celula *Ctmp = l->inicio->prox;
  while (Ctmp != NULL) {
    inserirFim(&tmp, Ctmp->dado);
    Ctmp = Ctmp->prox;
  }
  return tmp;
}

Lista concatenar(Lista *a, Lista *b) {
  Lista tmp;
  start(&tmp);
  Celula *Ctmp = a->inicio->prox;
  while (Ctmp != NULL) {
    inserirFim(&tmp, Ctmp->dado);
    Ctmp = Ctmp->prox;
  }

  Ctmp = b->inicio->prox;
  while (Ctmp != NULL) {
    inserirFim(&tmp, Ctmp->dado);
    Ctmp = Ctmp->prox;
  }
  return tmp;
}

void inverter(Lista *l) {
  int n = l->tam;
  Pessoa *v = malloc(n * sizeof(Pessoa));
  Celula *tmp = l->inicio->prox;
  for (int i = 0; tmp != NULL; i++) {
    v[i] = tmp->dado;
    tmp = tmp->prox;
  }
  tmp = l->inicio->prox;
  for (int i = n - 1; i >= 0; i--) {
    tmp->dado = v[i];
    tmp = tmp->prox;
  }
}

int inserirOrdenado(Lista *l, Pessoa dado) {
  if (l->inicio == l->fim) {
    int res = inserirFim(l, dado);
    return res;
  }

  for (Celula *tmp = l->inicio; tmp != l->fim; tmp = tmp->prox) {
    if (dado.idade < tmp->prox->dado.idade) {
      Celula *c = newCelula(dado);
      if (c == NULL) {
        return 0;
      }
      Celula *proxima = tmp->prox;
      tmp->prox = c;
      c->prox = proxima;
      l->tam++;
      return 1;
    }
  }

  int res = inserirFim(l, dado);
  return res;
}

Pessoa maior(Lista *l) {
  Celula *tmp = l->inicio->prox;
  Pessoa P = tmp->dado;
  while (tmp != l->fim) {
    if (tmp->dado.idade < tmp->prox->dado.idade) {
      P = tmp->prox->dado;
      tmp = tmp->prox;
    }
  }
  return P;
}

int pesquisar(Lista *l, char pessoa[]) {
  Celula *tmp = l->inicio->prox;
  while (tmp != NULL) {
    if (strcmp(tmp->dado.nome, pessoa) == 0) {
      return tmp->dado.codigo;
    }
    tmp = tmp->prox;
  }
  return -1;
}

void ordenarPorCodigo(Lista *l) {
  int n = l->tam;
  Pessoa *v = malloc(n * sizeof(Pessoa));
  Celula *tmp = l->inicio->prox;
  for (int i = 0; tmp != NULL; i++) {
    v[i] = tmp->dado;
    tmp = tmp->prox;
  }

  int i, j, min;
  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (v[j].codigo < v[min].codigo) {
        min = j;
      }
    }
    Pessoa p = v[min];
    v[min] = v[i];
    v[i] = p;
  }

  tmp = l->inicio->prox;
  for (int i = 0; i < n; i++) {
    tmp->dado = v[i];
    tmp = tmp->prox;
  }
}

void ordenarPorNome(Lista *l) {
  int n = l->tam;
  Pessoa *v = malloc(n * sizeof(Pessoa));
  Celula *tmp = l->inicio->prox;
  for (int i = 0; tmp != NULL; i++) {
    v[i] = tmp->dado;
    tmp = tmp->prox;
  }

  int i, j, min;
  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (strcmp(v[j].nome, v[min].nome) < 0) {
        min = j;
      }
    }
    Pessoa p = v[min];
    v[min] = v[i];
    v[i] = p;
  }

  tmp = l->inicio->prox;
  for (int i = 0; i < n; i++) {
    tmp->dado = v[i];
    tmp = tmp->prox;
  }
}

int main(){
    return 0;
}