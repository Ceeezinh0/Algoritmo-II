#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 100

struct Pessoa {
    char nome[50];
    char RG[12];
    char dataNascimento[11];
    char profissao[50];
};

struct Pessoa lista[MAX_ELEMENTS];
int numElementos = 0;

struct Data {
    int dia;
    int mes;
    int ano;
};

// Função para comparar RGs
int compararRG(const char *rg1, const char *rg2) {
    return strcmp(rg1, rg2);
}

// Função para comparar pessoas pelo nome
int compararPorNome(const void *a, const void *b) {
    return strcmp(((struct Pessoa *)a)->nome, ((struct Pessoa *)b)->nome);
}

// Função para comparar pessoas pelo RG
int compararPorRG(const void *a, const void *b) {
    return compararRG(((struct Pessoa *)a)->RG, ((struct Pessoa *)b)->RG);
}

void inserirElemento() {
    if (numElementos >= MAX_ELEMENTS) {
        printf("A lista esta cheia. Nao e possivel adicionar mais elementos.\n");
        return;
    }

    struct Pessoa novaPessoa;
    printf("Nome: ");
    scanf(" %49s", novaPessoa.nome); // Use %s para ler strings com espacos
    printf("RG: ");
    scanf(" %11s", novaPessoa.RG);
    printf("Data de Nascimento: ");
    scanf(" %10s", novaPessoa.dataNascimento);
    printf("Profissao: ");
    scanf(" %49s", novaPessoa.profissao);

    int i;
    // Encontre a posicao correta para a insercao ordenada pelo RG
    for (i = 0; i < numElementos; i++) {
        if (compararRG(novaPessoa.RG, lista[i].RG) < 0) {
            break;
        }
    }

    // Desloque os elementos para abrir espaco para a nova pessoa
    int j;
    for (j = numElementos; j > i; j--) {
        lista[j] = lista[j - 1];
    }

    // Insira a nova pessoa na posicao correta
    lista[i] = novaPessoa;

    numElementos++;
    printf("Pessoa inserida com sucesso!\n");
}

void removerElemento() {
    char rgARemover[12];
    int posicaoARemover = -1;

    if (numElementos == 0) {
        printf("A lista esta vazia. Nada para remover.\n");
        return;
    }

    printf("Digite o RG da pessoa que deseja remover: ");
    scanf(" %11s", rgARemover);

    int i;
    for (i = 0; i < numElementos; i++) {
        if (compararRG(rgARemover, lista[i].RG) == 0) {
            posicaoARemover = i;
            break;
        }
    }

    if (posicaoARemover == -1) {
        printf("Pessoa com o RG %s nao encontrada na lista.\n", rgARemover);
        return;
    }

    // Realize a remocao da pessoa na posicao encontrada
    for (i = posicaoARemover; i < numElementos - 1; i++) {
        lista[i] = lista[i + 1];
    }

    numElementos--;

    printf("Pessoa com RG %s foi removida com sucesso.\n", rgARemover);
}

void mostrarElementos() {
    int i;
    if (numElementos == 0) {
        printf("A lista esta vazia. Nada para mostrar.\n");
        return;
    }

    printf("Elementos na lista:\n");
    for (i = 0; i < numElementos; i++) {
        printf("Nome: %s\n", lista[i].nome);
        printf("RG: %s\n", lista[i].RG);
        printf("Data de Nascimento: %s\n", lista[i].dataNascimento);
        printf("Profissao: %s\n", lista[i].profissao);
        printf("\n");
    }
}

int contarElementos() {
    return numElementos;
}

void procurarPorRG() {
    char rgParaBuscar[12];
    int encontrado = 0;

    if (numElementos == 0) {
        printf("A lista esta vazia. Nada para procurar.\n");
        return;
    }

    printf("Digite o RG que deseja buscar: ");
    scanf(" %11s", rgParaBuscar);

    printf("Resultado da busca pelo RG %s:\n", rgParaBuscar);

    int i;
    for (i = 0; i < numElementos; i++) {
        if (compararRG(rgParaBuscar, lista[i].RG) == 0) {
            printf("Nome: %s\n", lista[i].nome);
            printf("RG: %s\n", lista[i].RG);
            printf("Data de Nascimento: %s\n", lista[i].dataNascimento);
            printf("Profissao: %s\n", lista[i].profissao);
            printf("\n");
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum elemento encontrado com o RG %s.\n", rgParaBuscar);
    }
}

void mostrarAcimaDe30Anos() {
    int i;
    if (numElementos == 0) {
        printf("A lista esta vazia. Nada para mostrar.\n");
        return;
    }

    printf("Pessoas com mais de 30 anos:\n");

    for (i = 0; i < numElementos; i++) {
        struct Data dataNascimento;
        sscanf(lista[i].dataNascimento, "%d/%d/%d", &dataNascimento.dia, &dataNascimento.mes, &dataNascimento.ano);
        dataNascimento.ano -= 1900; // Ajuste para o formato de ano da struct tm
        dataNascimento.mes--;

        time_t agora;
        time(&agora);

        // Calculo da idade com base na data atual
        double diferenca = difftime(agora, mktime(&dataNascimento));
        double anos = diferenca / (365.0 * 24 * 3600);

        if (anos > 30) {
            printf("Nome: %s\n", lista[i].nome);
            printf("Profissao: %s\n", lista[i].profissao);
            printf("\n");
        }
    }
}

int contarProfissoesDiferentes() {
    int i, j;
    if (numElementos == 0) {
        printf("A lista esta vazia. Nenhuma profissao para contar.\n");
        return 0;
    }

    char profissoesEncontradas[MAX_ELEMENTS][50];  // Array para armazenar profissões únicas
    int contadorProfissoes = 0;

    for (i = 0; i < numElementos; i++) {
        int profissaoDuplicada = 0;
        for (j = 0; j < contadorProfissoes; j++) {
            if (strcmp(lista[i].profissao, profissoesEncontradas[j]) == 0) {
                profissaoDuplicada = 1;
                break;
            }
        }

        if (!profissaoDuplicada) {
            strcpy(profissoesEncontradas[contadorProfissoes], lista[i].profissao);
            contadorProfissoes++;
        }
    }

    printf("Numero de profissoes diferentes na lista: %d\n", contadorProfissoes);
    return contadorProfissoes;
}


void ordenarPorNome() {
    if (numElementos <= 1) {
        printf("A lista tem 1 elemento ou esta vazia. Nada para ordenar.\n");
        return;
    }

    qsort(lista, numElementos, sizeof(struct Pessoa), compararPorNome);
    printf("A lista foi ordenada pelo campo 'nome'.\n");
}

void ordenarPorRG() {
    if (numElementos == 0) {
        printf("A lista esta vazia. Nada para ordenar.\n");
        return;
    }

    qsort(lista, numElementos, sizeof(struct Pessoa), compararPorRG);
    printf("A lista foi ordenada pelo campo 'RG'.\n");
}

int main() {
    int opcao;
    FILE *arquivo = fopen("lista_pessoas.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1; // Encerrar o programa com um código de erro
    }

    do {
        printf("\nMenu de Opcoes:\n");
        printf("1. Inserir elemento na lista ordenada pelo RG\n");
        printf("2. Remover elemento da lista\n");
        printf("3. Mostrar elementos da lista\n");
        printf("4. Contar numero de elementos da lista\n");
        printf("5. Procurar um elemento pelo RG\n");
        printf("6. Mostrar nome e profissao de pessoas acima de 30 anos\n");
        printf("7. Contar profissoes diferentes na lista\n");
        printf("8. Gerar lista ordenada pelo nome\n");
        printf("9. Gerar lista ordenada pelo RG\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirElemento();
                break;
            case 2:
                removerElemento();
                break;
            case 3:
                mostrarElementos();
                break;
            case 4:
                printf("Numero de elementos na lista: %d\n", contarElementos());
                break;
            case 5:
                procurarPorRG();
                break;
            case 6:
                mostrarAcimaDe30Anos();
                break;
            case 7:
                printf("Numero de profissoes diferentes: %d\n", contarProfissoesDiferentes());
                break;
            case 8:
                ordenarPorNome();
                break;
            case 9:
                ordenarPorRG();
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    // Feche o arquivo após terminar o loop do menu
    fclose(arquivo);

    return 0;
}

