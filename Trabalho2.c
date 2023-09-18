#include <stdio.h>
#include <string.h>

// quantidade de matérias que temos e o histórico de cada uma delas
#define MAX_MATERIAS 6 
#define MAX_HISTORICO 6

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Materia {
    char Nome_Disciplina[50];
    char Nome_Professor[50];
    struct Data data_Recebida;
    struct Data data_Entrega;
    char Descricao[1000];
    int Dificuldade;
    int ativo; // utilizado para (exclusão lógica)
};

struct Historico {
    struct Materia *Nome; // Serve para linkar o Histórico com a matéria
    float Nota_P1;
    float Nota_P2;
    float Nota_T1;
    float Nota_T2;
    float Nota_final;
};

struct Materia materias[MAX_MATERIAS];
int num_materias = 0;

struct Historico historico[MAX_HISTORICO];
int num_historico = 0;

void cadastrarDisciplina() {
    if (num_materias < MAX_MATERIAS) {
        struct Materia novaMateria;
        printf("Nome da Disciplina: ");
        
        getchar(); // Limpar o buffer do teclado
        
        fgets(novaMateria.Nome_Disciplina, sizeof(novaMateria.Nome_Disciplina), stdin);
        novaMateria.Nome_Disciplina[strcspn(novaMateria.Nome_Disciplina, "\n")] = '\0'; // Remover o '\n' da entrada
        printf("Nome do Professor: ");
        fgets(novaMateria.Nome_Professor, sizeof(novaMateria.Nome_Professor), stdin);
        novaMateria.Nome_Professor[strcspn(novaMateria.Nome_Professor, "\n")] = '\0';
        printf("Digite a data de recebimento (DD MM AAAA): ");
        scanf("%d %d %d", &novaMateria.data_Recebida.dia, &novaMateria.data_Recebida.mes, &novaMateria.data_Recebida.ano);
        printf("Digite a data de entrega (DD MM AAAA): ");
        scanf("%d %d %d", &novaMateria.data_Entrega.dia, &novaMateria.data_Entrega.mes, &novaMateria.data_Entrega.ano);
        printf("Descricao: ");
        
        getchar();
        
        fgets(novaMateria.Descricao, sizeof(novaMateria.Descricao), stdin);
        novaMateria.Descricao[strcspn(novaMateria.Descricao, "\n")] = '\0';
        printf("Dificuldade: ");
        scanf("%d", &novaMateria.Dificuldade);
        novaMateria.ativo = 1; // Defina como ativo por padrão pois quando você cria é porque existe;
        materias[num_materias] = novaMateria;
        num_materias++;
        printf("Disciplina cadastrada com sucesso!\n");
    } 
	else {
        printf("Limite de disciplinas atingido!\n");
    }
}

void excluirDisciplina() {
    char nome[50];
    printf("Digite o nome da disciplina a ser excluída: ");
    getchar(); // Limpar o buffer do teclado
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remover o '\n' da entrada

    for (int i = 0; i < num_materias; i++) {
        if (strcmp(materias[i].Nome_Disciplina, nome) == 0) {
            materias[i].ativo = 0;
            printf("Disciplina %s excluída (exclusão lógica).\n", nome);
            return;
        }
    }
    printf("Disciplina %s não encontrada.\n", nome);
}




// Função para cadastrar histórico
void cadastrarHistorico() {
    if (num_historico < MAX_HISTORICO) {
        struct Historico novoHistorico;
        // Preencha os campos do histórico aqui...

        historico[num_historico] = novoHistorico;
        num_historico++;
        printf("Historico cadastrado com sucesso!\n");
    } else {
        printf("Limite de historicos atingido!\n");
    }
}

// Função para listar todas as disciplinas
void listarDisciplinas() {
    printf("Lista de Disciplinas Cadastradas:\n");
    printf("-----------------------------------------------------------\n");
    printf("| %-20s | %-20s | %-10s |\n", "Disciplina", "Professor", "Dificuldade");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < num_materias; i++) {
        if (materias[i].ativo) {
            printf("| %-20s | %-20s | %-10d |\n", materias[i].Nome_Disciplina, materias[i].Nome_Professor, materias[i].Dificuldade);
        }
    }

    printf("-----------------------------------------------------------\n");
}

// Função para consultar disciplina por Nome_Disciplina e Dificuldade
void consultarDisciplina() {
    char nome[50];
    int dificuldade;

    listarDisciplinas();

    printf("Digite o nome da disciplina desejada: ");
    getchar(); // Limpar o buffer do teclado
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remover o '\n' da entrada

    printf("Atividades da Disciplina \"%s\" (Dificuldade %d):\n", nome, dificuldade);
    printf("-----------------------------------------------------------\n");
    printf("| %-10s | %-10s | %-10s |\n", "Recebimento", "Entrega", "Descrição");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < num_materias; i++) {
        if (materias[i].ativo && strcmp(materias[i].Nome_Disciplina, nome) == 0 && materias[i].Dificuldade == dificuldade) {
            printf("| %02d/%02d/%04d | %02d/%02d/%04d | %-10s |\n",
                materias[i].data_Recebida.dia, materias[i].data_Recebida.mes, materias[i].data_Recebida.ano,
                materias[i].data_Entrega.dia, materias[i].data_Entrega.mes, materias[i].data_Entrega.ano,
                materias[i].Descricao);
        }
    }
    printf("-----------------------------------------------------------\n");
}

void consultarHistorico() {
    char nome[50];
    float nota_final;

    printf("Digite o nome da disciplina: ");
    getchar(); // Limpar o buffer do teclado
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remover o '\n' da entrada
    printf("Digite a nota final desejada: ");
    scanf("%f", &nota_final);

    printf("Histórico da Disciplina \"%s\" com Nota Final %.2f:\n", nome, nota_final);
    printf("-----------------------------------------------------------\n");
    printf("| %-10s | %-10s | %-10s |\n", "Nota_P1", "Nota_P2", "Nota_T1");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < num_historico; i++) {
        if (strcmp(historico[i].Nome->Nome_Disciplina, nome) == 0 && historico[i].Nota_final == nota_final) {
            printf("| %-10.2f | %-10.2f | %-10.2f |\n",
                   historico[i].Nota_P1, historico[i].Nota_P2, historico[i].Nota_T1);
        }
    }

    printf("-----------------------------------------------------------\n");
}

int main() {
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Disciplina\n");
        printf("2. Excluir Disciplina\n");
        printf("3. Consultar Disciplina\n");
        printf("4. Cadastrar Historico\n");
        printf("5. Consultar Historico\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarDisciplina();
                break;
            case 2:
                excluirDisciplina();
                break;
            case 3:
                consultarDisciplina();
                break;
            case 4:
                cadastrarHistorico();
                break;
            case 5:
                consultarHistorico();
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 6);

    return 0;
}

