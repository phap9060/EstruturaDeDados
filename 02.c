#include <stdio.h>
#include <stdlib.h>
#include <string.h>




struct Facebook {
  char nome[40];
  int id;
  struct Facebook *prox;
  struct Facebook *amigo;
};

typedef struct Facebook Face;
face *inicio;
int identificador = 0;

void cadastroPessoa () {
  getchar();
  face *lista= (face*) malloc(sizeof(face));
  printf("Qual o nome?\n");
  fgets(lista->nome, 40, stdin);
  
  lista -> prox = NULL;
  if (inicio == NULL){
    inicio = lista;
  }else{
    face *aux = inicio;
    while(aux -> prox != NULL){
      aux = aux -> prox;
    }
    aux -> prox = lista;
  }

  contador++;
  lista -> id = contador;
}


void adicionar(int amigo1, int amigo2, Face *lista){
  face *aux = inicio;
  aux = lista;

  if (lista == NULL){
    printf("Amigo não encontrado\n");
    exit (1);
  }
  else{
    while(amigo1 != aux -> id) {
      aux = aux -> prox;
    }
    if (amigo1 == aux -> id) {
      face *aux2 = inicio;
      
      while((amigo2 != aux2 -> id) && (aux2 -> prox != NULL)){
        aux2 = aux2 -> prox;
      }

      if(amigo2 == aux2 -> id) {
        face *aux3 = aux;
        while(aux3 -> amigo != NULL){
          aux3 = aux3 -> prox;
        }
        aux3 -> amigo = aux2;
      }
    }
  }
  printf("Eba\n %s  %s são seus amigos, tchau solidão", aux -> nome, aux -> amigo -> nome);
  
}

void resposta (face *L) {
  if (L != NULL) {
    printf("Nome: %s", L -> nome);
    printf("ID: %d\n", L -> id);
    
    imprimir(L -> prox);
  }
}


int main(void){
  int op, id1, id2;
  do {
    printf("\n\n1 - Cadastrar\n2 - Adicionar\n3 - Retornar List\n0 - Sair\n");
    printf("Opção: ");
    scanf("%d", &op);
    switch (op) {
      case 1:
        cadastroPessoa();
      break;

      case 2:
        printf("Digite o ID da primeira pessoa: ");
        scanf("%d", &id1);
        printf("Digite o ID da segunda pessoa: ");
        scanf("%d", &id2);

        adicionar(id1, id2, inicio);
      break;

      case 3:
        resposta(inicio);
      break;

      case 0:
        printf("\nAté a próxima\n");
      break;

      default:
        printf("\nSelecione uma das 3 opções\n");
    }
  }while(op != 0);

  return 0;
}
