#include <stdio.h>
#include <stdlib.h>

int main() {
    int qte, i;
    int *vet;

    printf("Quantidade de valores do vetor: ");
    scanf("%d", &qte);

    vet = (int *)malloc(qte * sizeof(int));
    
	if (vet == NULL) {
        printf("Memória insuficiente\n");
        exit(1);
    }
    
    printf("Digite os valores do vetor:\n");
    for (i = 0; i < qte; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vet[i]);
    }
    
    printf("Imprimindo os valores do vetor:\n");
    for (i = 0; i < qte; i++)
        printf("vet[%d] = %d\n", i + 1, vet[i]);

    free(vet);
    return 0;
}

