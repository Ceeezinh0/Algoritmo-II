#include <stdlib.h>
#include <stdio.h>

// esse programa vai adicionando na frente da lista

typedef struct reg *no;
struct reg {
  int info; // armazena o valor do nó
  struct reg *prox; // ponteiro para o próximo nó da lista
};

void cria_lista (no *lista) {
  *lista = NULL; // inicia uma lista vazia
}

void inclui_inicio (no *lista, int info){
	//malloc só para (incluir)
  no p = (no) malloc(sizeof(struct reg)); // isso foi visto no programa (Vetor Dinamicamente alocado.c), que está nesse diretório
  
  p->info = info;
  p->prox = *lista;
  *lista = p;
}

void mostra_lista (no lista) {
  no p = lista;
  
  printf ("\nElementos da lista: ");
  
  while (p) {
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
    printf ("Digite um numero inteiro: \n");
    scanf ("%d",&info);
    inclui_inicio (&lista,info);
    printf ("Continua (S/N)?\n");
    do {
      resp = toupper(getchar());
    } 
	while (resp!='N' && resp!='S');
  } 
  while (resp!='N');
  mostra_lista (lista);
}
