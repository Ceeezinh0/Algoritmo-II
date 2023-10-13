#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//###########################################################################
// Estrutura para cadastro de paciente
struct Paciente {
    char nome[50];
    char estado[10];  // regular, ruim, pessimo
};
//###########################################################################

//###########################################################################
// Função para adicionar um paciente à lista
void AdicionaPaciente(struct Paciente *pacientes, int *numPacientes, const char *nome, const char *estado) {
    if (*numPacientes < 100) {
        struct Paciente novoPaciente;
        strcpy(novoPaciente.nome, nome);
        strcpy(novoPaciente.estado, estado);
        pacientes[*numPacientes] = novoPaciente;
        (*numPacientes)++;
        printf("Paciente %s adicionado com sucesso.\n", nome);
    } else {
        printf("A lista de pacientes esta cheia.\n");
    }
}
//###########################################################################

//###########################################################################
// Função para exibir a lista de pacientes
void MostraPaciente(struct Paciente *pacientes, int numPacientes) {
    int i;
    printf("Lista de Pacientes:\n");
    for (i = 0; i < numPacientes; i++) {
        printf("Nome: %s, Estado: %s\n", pacientes[i].nome, pacientes[i].estado);
    }
}
//###########################################################################

//###########################################################################
// Função para chamar o próximo paciente com pior estado de saúde
void ProximoPaciente(struct Paciente *pacientes, int *numPacientes) {
    int i;
    if (*numPacientes > 0) {
        int index = 0;
        char melhorEstado[10] = "regular";  // Inicializamos com o melhor estado possível

        // Encontrar o paciente com o pior estado de saúde na lista
        for (i = 0; i < *numPacientes; i++) {
            if (strcmp(pacientes[i].estado, "pessimo") == 0) {
                index = i;
                break;
            } else if (strcmp(pacientes[i].estado, "ruim") == 0) {
                index = i;
            }
        }

        struct Paciente proximoPaciente = pacientes[index];
        printf("Proximo paciente a ser atendido: %s, Estado: %s\n", proximoPaciente.nome, proximoPaciente.estado);

        // Removemos o paciente da lista, deslocando os outros pacientes para preencher o espaço vazio
        for (i = index; i < (*numPacientes - 1); i++) {
            pacientes[i] = pacientes[i + 1];
        }

        (*numPacientes)--;
    } else {
        printf("A lista de pacientes esta vazia.\n");
    }
}
//###########################################################################

int main() {
    struct Paciente pacientes[100];
    int numPacientes = 0;

    int escolha;
    char nome[50], estado[10];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Adicionar Paciente\n");
        printf("2. Chamar Proximo Paciente\n");
        printf("3. Exibir Lista de Pacientes\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Nome do Paciente: ");
                scanf("%s", nome);
                printf("Estado de Saude (regular, ruim, pessimo): ");
                scanf("%s", estado);
                AdicionaPaciente(pacientes, &numPacientes, nome, estado);
                break;
            case 2:
                ProximoPaciente(pacientes, &numPacientes);
                break;
            case 3:
                MostraPaciente(pacientes, numPacientes);
                break;
            case 4:
                exit(0);
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}
//###########################################################################
