#include <stdio.h>

int main() {
    FILE *arq;

    if ((arq = fopen("arq.txt", "r+")) != NULL) {
        int m, n; // Declare as dimensões da matriz

        fscanf(arq, "%d %d", &m, &n); // Leia as dimensões da matriz do arquivo

        // Agora que você sabe as dimensões, você pode declarar suas matrizes:
        int matriz1[m][n], matriz2[m][n], soma[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Use & para obter o endereço da variável para o fscanf
                fscanf(arq, "%d", &matriz1[i][j]);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                fscanf(arq, "%d", &matriz2[i][j]);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                soma[i][j] = matriz1[i][j] + matriz2[i][j];
            }
        }
        
        // Use fprintf para escrever no arquivo
        fprintf(arq, "\n");

        for (int i = 0; i < m; i++) {
            fprintf(arq, "\n");
			printf("\n");
            for (int j = 0; j < n; j++) {
                // Use fprintf para escrever no arquivo
                fprintf(arq, "%d\t", soma[i][j]);

                printf("%d\t", soma[i][j]);
            }
        }
        fclose(arq);
    }

    return 0;
}
