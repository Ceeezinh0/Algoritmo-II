#include <stdlib.h>
#include <stdio.h>

// esse programa vai adicionando na frente da lista

typedef struct reg *no;
struct reg {
  int info;
  struct reg *prox;
};

void cria_lista (no *lista) {
  *lista = NULL;
}

void inclui_inicio (no *lista, int info){
  no p = (no) malloc(sizeof(struct reg));
  p->info = info;
  p->prox = *lista;
  *lista = p;
}

void mostra_lista (no lista) {
  no p = lista;
  printf ("\nElementos da lista: ");
  while (p) {   // while (p != NULL)
    printf ("%d ",p->info);
    p = p->prox;
  }
}

int main () {
  int info;
  char resp;
  no lista;
  cria_lista (&lista);   // lista = NULL;
  do {
    printf ("\nDigite um numero inteiro: ");
    scanf ("%d",&info);
    inclui_inicio (&lista,info);
    printf ("\nContinua (S/N)?");
    do {
      resp = toupper(getchar());
    } while (resp!='N' && resp!='S');
  } while (resp!='N');
  mostra_lista (lista);
}
