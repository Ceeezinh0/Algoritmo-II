#include <stdlib.h>
#include <stdio.h>
//---------------------------------------------------------
// Declaração da estrutura de uma lista simplesmente encadeada
//---------------------------------------------------------
typedef struct reg *no;
struct reg {
  int info;
  struct reg *prox;
};
//---------------------------------------------------------
// Cria uma lista vazia
//---------------------------------------------------------
void cria_lista (no *lista) {
  *lista = NULL;
}
//----------------------------------------------------
// Inclui um elemento no final da lista
//----------------------------------------------------
void inclui_final (no *lista, int info){
  no p = (no) malloc(sizeof(struct reg));
  p->info = info;
  p->prox = NULL;
  if (*lista == NULL)
    *lista = p;
  else {
    no q = *lista;
    while (q->prox)
      q = q->prox;
    q->prox = p;
  }
}
//---------------------------------------------------------
// Mostra os elementos da lista
//---------------------------------------------------------
void mostra_lista (no lista) {
  no p = lista;
  printf ("\nElementos da lista: ");
  while (p) {   // while (p != NULL)
    printf ("%d ",p->info);
    p = p->prox;
  }
}
//---------------------------------------------------------
// Conta os elementos da lista
//---------------------------------------------------------
int conta_elementos (no lista) {
  no p = lista;
  int cont = 0;
  while (p) {   // while (p != NULL)
    cont++;
    p = p->prox;
  }
  return cont;
}
//---------------------------------------------------------
int main () {
  int info;
  char resp;
  no lista;
  cria_lista (&lista);   // lista = NULL;
  do {
    printf ("Digite um numero inteiro: ");
    scanf ("%d",&info);
    inclui_final (&lista,info);
    printf ("Continua (S/N)?");
    do {
      resp = toupper(getchar());
    } while (resp!='N' && resp!='S');
  } while (resp!='N');
  mostra_lista (lista);
  printf ("\nQuantidade de elementos da lista: %d",conta_elementos(lista));
}
