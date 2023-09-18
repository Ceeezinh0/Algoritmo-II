#include <stdio.h>
#include <string.h>

// Definindo as structs
struct Data {
    int dia;
    int mes;
    int ano;
};

struct Materia {
    char Nome_Diciplina[50];
    char Nome_Professor[50];
    struct Data data_Recebida;
    struct Data data_Entrega;
    char Descricao[50];
    int Dificuldade;// daatividade
};

struct Historico{
    struct Materia *Nome; // Serve para linkar o Histórico com a matéria
    float Nota_P1;
    float Nota_P2;
    float Nota_T1;
    float Nota_T2;
    float Nota_final;
};

// Iniciando as Funções
void Cadastro(struct Materia *disciplina, int *contador) {
    if (*contador < 6) {
        printf("Informe o nome da tarefa: ");
        scanf(" %[^\n]", disciplina[*contador].Nome_Diciplina);
        printf("Informe o nome do professor: ");
        scanf(" %[^\n]", disciplina[*contador].Nome_Professor);
        printf("Informe a data (dia mes ano): ");
        scanf("%d %d %d", &disciplina[*contador].data.dia, &disciplina[*contador].data.mes, &disciplina[*contador].data.ano);
        printf("Informe o objetivo da disciplina: ");
        scanf(" %[^\n]", disciplina[*contador].Objetivo);
        printf("Informe a dificuldade da disciplina: ");
        scanf("%d", &disciplina[*contador].Dificuldade);

        (*contador)++;
    } 
    else {
        printf("Limite de disciplinas atingido.\n");
    }
}

void Alterar(struct Materia *disciplina, int contador) {
    int indice;

    printf("Informe o indice da disciplina que deseja alterar: ");
    scanf("%d", &indice);

    if (indice >= 0 && indice < contador) {
        printf("Informe o novo nome da tarefa: ");
        scanf(" %[^\n]", disciplina[indice].Nome_Diplina);
        printf("Informe o novo nome do professor: ");
        scanf(" %[^\n]", disciplina[indice].Nome_Professor);
        printf("Informe a nova data (dia mes ano): ");
        scanf("%d %d %d", &disciplina[indice].data.dia, &disciplina[indice].data.mes, &disciplina[indice].data.ano);
        printf("Informe o novo objetivo da disciplina: ");
        scanf(" %[^\n]", disciplina[indice].Objetivo);
        printf("Informe a nova dificuldade da disciplina: ");
        scanf("%d", &disciplina[indice].Dificuldade);
    } 
    else {
        printf("Indice invalido.\n");
    }
}

void Excluir(struct Materia *disciplina, int *contador) {
    int indice;

    printf("Informe o indice da disciplina que deseja excluir: ");
    scanf("%d", &indice);

    if (indice >= 0 && indice < *contador) {
        // Para excluir, você pode mover as disciplinas seguintes uma posição para trás.
        for (int i = indice; i < (*contador - 1); i++) {
            disciplina[i] = disciplina[i + 1];
        }
        (*contador)--;
    } 
    else {
        printf("Indice invalido.\n");
    }
}

void Consultar(struct Materia *disciplina, int contador) {
    printf("--------------------------------------------------------------------------\n");
    printf("|   Tarefa   |   Professor   |   Data   |   Objetivo   |   Dificuldade   |\n");
    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < contador; i++) {
        printf("|   %-10s |   %-12s |   %02d/%02d/%04d   |   %-12s |   %-12d   |\n",
            disciplina[i].Nome_Diciplina, disciplina[i].Nome_Professor,
            disciplina[i].data.dia, disciplina[i].data.mes, disciplina[i].data.ano,
            disciplina[i].Objetivo, disciplina[i].Dificuldade);
    }

    printf("---------------------------------------------------------------------------\n");
}

int main() {
    struct Materia Disciplina[6];
    int contador = 0;
    int opcao;

    do {
        printf("\nSelecione uma opcao:\n");
        printf("1 - Cadastrar disciplina\n");
        printf("2 - Alterar disciplina\n");
        printf("3 - Excluir disciplina\n");
        printf("4 - Consultar disciplinas\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                Cadastro(Disciplina, &contador);
                break;
            case 2:
                Alterar(Disciplina, contador);
                break;
            case 3:
                Excluir(Disciplina, &contador);
                break;
            case 4:
                Consultar(Disciplina, contador);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
