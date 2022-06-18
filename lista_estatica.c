#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa {
  int codigo;
  char nome[20];
  int idade;
} Pessoa;

typedef struct Lista {
  Pessoa *v;
  int inicio, fim, max, tam;
} Lista;

void start(Lista *l, int n) {
  l->v = malloc(n * sizeof(Pessoa));
  l->inicio = l->fim = 0;
  l->max = n;
  l->tam = 0;
}
bool vazia(Lista l) {
  if (l.inicio == l.fim)
    return true;
  return false;
}

bool cheia(Lista l) {
  if (l.fim == l.max)
    return true;
  return false;
}

int inserirNoFinal(Lista *l, Pessoa dado) {
  if (cheia(*l)) {
    return 0;
  }
  l->v[l->fim] = dado;
  l->fim++;
  l->tam++;
  return 1;
}
int inserirNoInicio(Lista *l, Pessoa dado) {
  if (cheia(*l)) {
    return 0;
  }
  for (int i = l->fim; i > 0; i--) {
    l->v[i] = l->v[i - 1];
  }
  l->v[0] = dado;
  l->fim++;
  l->tam++;
  return 1;
}
Pessoa removerNoFinal(Lista *l) {
  if (vazia(*l)) {
    printf("\n\nVazia\n");
    Pessoa tmp;
    tmp.codigo = -1;
    return tmp;
  }
  l->fim--;
  return l->v[l->fim];
}

Pessoa removerNoInicio(Lista *l) {
  Pessoa tmp;
  if (vazia(*l)) {
    printf("\n\nVazia\n");
    tmp.codigo = -1;
    return tmp;
  }
  tmp = l->v[0];
  for (int i = 0; i < l->fim - 1; i++) {
    l->v[i] = l->v[i + 1];
  }
  l->fim--;
  l->tam--;
  return tmp;
}

int inserirEmP(Lista *l, Pessoa dado, int p) {
  if (p < 0 || p > l->tam || cheia(*l)) {
    return 0;
  }
  for (int i = l->fim; i > p; i--) {
    l->v[i] = l->v[i - 1];
  }
  l->v[p] = dado;
  l->fim++;
  l->tam++;
  return 1;
}

void printLista(Lista l) {
  for (int i = l.inicio; i < l.fim; i++) {
    printf("%d  ", l.v[i].codigo);
    printf("%s  ", l.v[i].nome);
    printf("%d\n", l.v[i].idade);
  }
}

Lista clonar(Lista l) {
  Lista clone;
  start(&clone, l.tam);
  while (l.inicio != l.fim) {
    Pessoa tmp = removerNoFinal(&l);
    inserirNoFinal(&clone, tmp);
  }
  return clone;
}

Lista concatenar(Lista a, Lista b) {
  Lista concat;
  int tam = a.tam + b.tam;
  start(&concat, tam);
  for (int i = a.inicio; i < a.tam; i++) {
    Pessoa tmp = removerNoFinal(&a);
    inserirNoFinal(&concat, tmp);
  }
  for (int i = b.inicio; i < b.tam; i++) {
    Pessoa tmp = removerNoFinal(&b);
    inserirNoFinal(&concat, tmp);
  }
  return concat;
}

void inverter(Lista *l) {
  for (int i = 0; i < l->tam / 2; i++) {
    Pessoa tmp = l->v[i];
    l->v[i] = l->v[l->fim - 1 - i];
    l->v[l->fim - 1 - i] = tmp;
  }
}

int inserirOrdenado(Lista *l, Pessoa dado) {
  if (cheia(*l)) {
    return 0;
  }
  if (vazia(*l)) {
    inserirNoInicio(l, dado);
    return 1;
  }

  for (int i = 0; i < l->fim; i++) {
    if (dado.codigo < l->v[i].codigo) {
      inserirEmP(l, dado, i);
      return 1;
    }
  }
  inserirNoFinal(l, dado);
  return 1;
}

int maior(Lista *l) {
  int Maior;
  Maior = l->v[0].idade;
  for (int i = 0; i < l->fim; i++) {
    if (l->v[i].idade > Maior) {
      Maior = l->v[i].idade;
    }
  }
  return Maior;
}

int pesquisar(Lista *l, char pessoa[]) {
  for (int i = 0; i < l->tam; i++) {
    if (strcmp(l->v[i].nome, pessoa) == 0) {
      return l->v[i].codigo;
    }
  }
  return -1;
}

void ordenarPorCod(Lista *l){
  for(int i=0; i<l->tam-1; i++){
    for(int j=0; j<l->tam-i-1; j++){
      if(l->v[j].codigo>l->v[j+1].codigo){
        Pessoa tmp = l->v[j];
        l->v[j]=l->v[j+1];
        l->v[j+1]=tmp;
      }
    }
  }
}

void ordenarPorNome(Lista *l){
  for(int i=0; i<l->tam-1; i++){
    for(int j=0; j<l->tam-i-1; j++){
      if(strcmp(l->v[j].nome,l->v[j+1].nome)<0){
        Pessoa tmp = l->v[j];
        l->v[j]=l->v[j+1];
        l->v[j+1]=tmp;
      }
    }
  }
}

int main(){
    return 0;
}