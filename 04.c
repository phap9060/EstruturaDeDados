#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct estruturaLista {
  int num;
  struct estruturaLista *prox;
};

typedef struct estruturaLista Lista;
Lista *p1;
Lista *p2;


void list1(int x) {
  Lista *l = malloc(sizeof(Lista));
  l->num = x;

  l -> prox = p1;
  p1 = l;
}

void list2(int y) {
  Lista *l = malloc(sizeof(Lista));
  l->num = y;

  l -> prox = p2;
  p2 = l;
}

void list3(Lista *l) {
  if (l != NULL){
    printf("%d -> ", l->num);
    imprimirLista(l -> prox);
  }else{
    printf("NULL\n");
  }
}

void inverte(Lista *l1, Lista *l2){
  Lista *aux;
  aux = l1->prox;
  while(aux -> prox != NULL){
    aux = aux->prox;
  }
  aux->prox = l2->prox;
  free(l2);
}

int main(void){
  int l;
  list1(4);
  list1(3);
  list1(2);
  list1(1);

  printf("\nLista 1:\n");
  imprimirLista(p1);

  list2(8);
  list2(7);
  list2(6);
  list2(5);

  printf("Lista 2:\n");
  imprimirLista(p2);

  inverte(p1,p2);
  printf("\nListas juntas:\n");
  imprimirLista(p1);
  return 0;
}
