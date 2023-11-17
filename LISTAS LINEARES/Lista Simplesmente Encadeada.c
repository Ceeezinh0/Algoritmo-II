#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct reg {
    int info;
    struct reg *prox;
} *no;

void cria_lista(no *lista) {
    *lista = NULL;
}

void inclui_inicio(no *lista, int info) {
    // Aloca dinamicamente um novo nó
    no p = (no)malloc(sizeof(struct reg));
    p->info = info;
    p->prox = *lista;
    *lista = p;
}

void mostra_lista(no lista) {
    printf("\nElementos da lista: ");
    while (lista) {
        printf("%d ", lista->info);
        lista = lista->prox;
    }
}

int conta_elementos(no lista) {
    int cont = 0;
    while (lista) {
        cont++;
        lista = lista->prox;
    }
    return cont;
}

int main() {
    int info;
    char resp;
    no lista;

    cria_lista(&lista);

    do {
        printf("Digite um numero inteiro: ");
        scanf("%d", &info);

        inclui_inicio(&lista, info);

        printf("Continua (S/N)? ");
        do {
            resp = toupper(getchar());
        } while (resp != 'N' && resp != 'S');
    } while (resp != 'N');

    mostra_lista(lista);

    printf("\n\nQuantidade de elementos da lista: %d", conta_elementos(lista));

    return 0;
}

