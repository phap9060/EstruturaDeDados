#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct noDaLista {
 char titulo[51]; 
 char autor[51]; 
 int ano; 
 int quantidade; 
 struct noDaLista *prox; 
};

typedef struct noDaLista Lista;
Lista *primeiro;

void list () {
  printf("\n");
  getchar();
  Lista *lista = malloc(sizeof(Lista));
  printf("Título:\n");
  fgets(lista->titulo, 51, stdin);
  printf("Autor:\n");
  fgets(lista->autor, 51, stdin);
  printf("Ano: ");
  scanf("%d", &lista->ano);
  printf("Quantidade: ");
  scanf("%d", &lista->quantidade);

  lista -> prox = primeiro;
  primeiro = lista;
}

void printList (Lista *lista) {
  if (lista != NULL){
    printf("Título: %s", lista->titulo);
    printf("Autor: %s", lista->autor);
    printf("Ano: %d\tQuantidade: %d\n", lista->ano, lista->quantidade);
    printf("- - - - - - - - - - - -\n");

    printList(lista->prox);
  }
}

int quantityList (Lista *lista){
  int aux=0;
  while (lista != NULL) {
    aux = aux + (lista -> quantidade);
    lista = lista->prox;
  }
  
  return aux;
}

void yearSearch (Lista *lista, int ano) {
  if (lista != NULL){
    if (ano == lista->ano) {
      printf("Título: %s", lista->titulo);
      printf("Autor: %s", lista->autor);
      printf("Ano: %d\tQuantidade: %d\n", lista->ano, lista->quantidade);
      printf("- - - - - - - - - - - -\n");
    }
    yearSearch (lista -> prox, ano);
  }
}


int main(void) {
  int op, qtd_livros, ano;
  do{
    printf("\n-_-_-_-_-_-_-_ MENU -_-_-_-_-_-_-_\n");
    printf("1 -> Cadastrar livro\n2 -> Observar cadastro\n");
    printf("3 -> Quantidade total de livros\n4 -> Pesquisar por Ano\n0 -> Sair\n");
    printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
    scanf("%d", &op);

    switch(op){
      case 1:
        list();
      break;

      case 2:
        printList(primeiro);
      break;

      case 3:
        qtd_livros = quantityList(primeiro);
        printf("\nNúmero de livros cadastrados: %d\n", qtd_livros);
      break;

      case 4:
        printf("Bote o ano: ");
        scanf("%d", &ano);
        printf("\n");
       yearSearch(primeiro,ano);
      break;

      case 0:
        printf("Tchau\n");
      break;

      default:
        printf("Inválido:\n");
    }
  }while(op!=0);
  return 0;
}
