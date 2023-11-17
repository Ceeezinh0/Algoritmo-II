#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int info;
    struct reg *prox;
} *no;

void cria_lista(no *lista) {
    *lista = NULL;
}

void inclui_inicio(no *lista, int info) {
    no p = (no)malloc(sizeof(struct reg));
    p->info = info;
    p->prox = *lista;
    *lista = p;
}

void mostra_lista(no lista) {
    no p = lista;
    printf("\nElementos da lista: ");
    while (p) {
        printf("%d ", p->info);
        p = p->prox;
    }
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

        printf("Continua (S/N)?");
        do {
            resp = toupper(getchar());
        } while (resp != 'N' && resp != 'S');
    } while (resp != 'N');

    mostra_lista(lista);

    return 0;
}

