#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct estruturaLista {
  int num;
  struct estruturaLista *prox;
};

typedef struct estruturaListaLista;
Lista *primeiro;

void inserir(int x) {
  Lista *l = malloc(sizeof(Lista));
  l->num = x;

  l -> prox = primeiro;
  primeiro = l;
}

void print(Lista *l) {
  if (l != NULL){
    printf("%d -> ", l->num);
    imprimirLista(l -> prox);
  }else{
    printf("NULL\n");
  }
}

Lista *inverte(Lista *lista)
{
  Lista *anterior,*atual, *segundo;
  anterior =NULL;
  atual = lista;
  while(atual != NULL){
    segundo = atual -> prox;
    atual -> prox = anterior;
    anterior = atual;
    atual = segundo;
  }

  return anterior;
}


int main(void){
  print(8);
  print(7);
  print(6);
  print(5);
  print(4);
  print(3);
  print(2);
  print(1);

  print(primeiro);
  primeiro = inverte(primeiro);

  print(primeiro);

  return 0;
}
