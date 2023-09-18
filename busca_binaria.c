#include <stdio.h>

int main() {
    int tamanho_vetor, i, num_busca, j;
    scanf("%d", &tamanho_vetor);

    int V[tamanho_vetor];

    for (i = 0; i < tamanho_vetor; i++) {
        printf("Digite o valor para V[%d]: ", i);
        scanf("%d", &V[i]);
    }

    for (i = 0; i < tamanho_vetor - 1; i++) {
        for ( j = 0; j < tamanho_vetor - i - 1; j++) {
            if (V[j] > V[j + 1]) {
                int temp = V[j];
                
                V[j] = V[j + 1];
                V[j + 1] = temp;
            }
        }
    }

    printf("Valores do vetor ordenados em ordem crescente:\n");
    for (i = 0; i < tamanho_vetor; i++) {
        printf("V[%d] = %d\n", i, V[i]);
    }

    printf("Digite o numero a ser buscado: ");
    scanf("%d", &num_busca);

    int esquerda = 0;
    int direita = tamanho_vetor - 1;
    int encontrado = 0;

    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;

        if (V[meio] == num_busca) {
            printf("Numero encontrado na posicao %d.\n", meio);
            encontrado = 1;
            break;
        } 
        else if (V[meio] < num_busca) {
            esquerda = meio + 1;
        } 
        else {
            direita = meio - 1;
        }
    }

    if (!encontrado) {
        printf("Numero nao encontrado no vetor.\n");
    }

    return 0;
}
