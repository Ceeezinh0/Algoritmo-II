#include <stdlib.h>
typedef struct reg *no;
struct reg {
           int info;
           struct reg *prox;
};
no lista;
//------------------------------------------------------   
// Cria uma lista vazia
//------------------------------------------------------
void cria_lista (no *lista) {
  *lista = NULL;
} 
//------------------------------------------------------
// Mostra os elementos da lista
//------------------------------------------------------
void mostra_lista (no lista) {
  no p = lista;
  printf ("\nElementos da lista: ");
  while (p) {  // while (p != NULL)
    printf ("%d ",p->info);
    p = p->prox;
  }
}
//------------------------------------------------------
// Inclui um elemento numa lista ordenada
//------------------------------------------------------
void inclui_ordenada (no *lista, int info){
  // criacao do no
  no p = (no) malloc(sizeof(struct reg));
  p->info = info;
  // se lista for vazia ou elemento menor que o primeiro elemento da lista
  if (*lista == NULL || info <= (*lista)->info){
    p->prox = *lista;
    *lista = p;
  }     
  else {
    no q = *lista, r;
    while (q != NULL && q->info < info){
      r = q;
      q = q->prox;
    }      
    p->prox = q; 
    r->prox = p;
  } 
}
//------------------------------------------------------
// Programa Principal
//------------------------------------------------------
int main () {
  int info;
  char resp;
  cria_lista (&lista);
  do {
    printf ("Digite um numero inteiro: ");
    scanf ("%d",&info);
    inclui_ordenada (&lista,info);
    mostra_lista (lista);
    printf ("\n\nContinua (S/N)? ");   
    do {
      resp = toupper(getch());
    } while (resp!='N' && resp!='S');
  } while (resp!='N');
  mostra_lista (lista);
}      
