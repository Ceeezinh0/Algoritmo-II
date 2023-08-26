#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <conio.h>

#define enter 13

// Função para verificar se a senha fornecida é correta
bool verificarSenha(const char *senha);

// Função para converter um número em seu equivalente por extenso
void numeroPorExtenso(int num);

// Função para converter um mês em seu equivalente por extenso
void mesPorExtenso(int mes);

// Função para converter centavos em seu equivalente por extenso
void centavosPorExtenso(int centavos);

// Função para converter um dia em seu equivalente por extenso
void diaPorExtenso(int dia);

// Função para esperar até que uma tecla específica seja pressionada
void esperatecla(int tecla);

int main();

int main() {
    // Variáveis locais utilizadas para armazenar informações do cheque
    int ch;
    char senha[20];
    double valorCheque;
    int dia, mes, ano, testeSenha = 5;
    ch = getch();

    while (testeSenha > 0) {
        // Solicita a senha
        printf("|\n|  Digite a senha: ");
        scanf("%s", senha);

        // Verifica a senha
        if (!verificarSenha(senha)) {
            printf("|\n|  Senha incorreta. Tente novamente.\n");
            testeSenha--;
            printf("|\n|  Tentativas restantes: %d\n", testeSenha);
            printf("|\n|  Pressione <ENTER> para continuar.");
            esperatecla(enter);
        } else {
            break;
        }
        system("cls");
    }
    system("cls");
    if (testeSenha == 0) {
        printf("|\n|  Muitas tentativas, tente novamente mais tarde.\n");
        printf("|\n|  Pressione <ENTER> para sair.");
        esperatecla(enter);
        return 0;
    }

    // Solicita o valor do cheque
    printf("|\n|  Digite o valor do cheque: R$ ");
    scanf("%lf", &valorCheque);

    // Extrai a parte inteira (reais) e a parte decimal (centavos)
    int reais = (int)floor(valorCheque);
    int centavos = (int)round((valorCheque - reais) * 100);

    // Solicita e armazena a data de preenchimento
    printf("|\n|  Digite a data de preenchimento (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    // Imprime o valor por extenso e centavos
    printf("|\n|  Valor por extenso: ");
    numeroPorExtenso(reais);
    printf(" reais e ");
    centavosPorExtenso(centavos);
    printf("    |\n");

    // Imprime a data por extenso
    printf("|\n|  Data de preenchimento: %d/%d/%d : ", dia, mes, ano);
    diaPorExtenso(dia);
    printf(" de ");
    mesPorExtenso(mes);
    printf(" de ");
    numeroPorExtenso(ano);
    printf("    |\n|");

    printf("\n|  Pressione <ENTER> para sair.");
    esperatecla(enter);

    return 0;
}
