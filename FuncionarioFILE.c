#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionario {
    char nome[30];
    char cargo[30];
    int rg;
    float salario;
};

int main() {
    int opc;
    struct funcionario funcionario;
    FILE *arq;

    if ((arq = fopen("funcionario.dat", "wb")) == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    do{
        printf("\nDigite o nome: \n");
        fflush(stdin);
        gets(funcionario.nome);

        printf("Digite o cargo: \n");
        gets(funcionario.cargo);

        printf("Digite o RG: \n");
        scanf("%d", &funcionario.rg);

        printf("Digite o salario: \n");
        scanf("%f", &funcionario.salario);

        fwrite(&funcionario, sizeof(funcionario), 1, arq);

        printf("\nQUER CADASTRAR OUTRA PESSOA?\nSIM----1\nNAO----Qualquer outro número\n");
        scanf("%d", &opc);
    } 
	while (opc == 1);
    fclose(arq);
    return 0;
}
