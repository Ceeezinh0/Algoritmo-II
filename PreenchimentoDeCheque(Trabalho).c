#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool verificarSenha(const char *senha) {
    // Aqui você pode definir a senha secreta
    const char *senhaSecreta = "senha123";
    return strcmp(senha, senhaSecreta) == 0;
}

void numeroPorExtenso(int num) {
    const char *unidades[] = {"", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove"};
    const char *dezAVinte[] = {"", "onze", "doze", "treze", "catorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};
    const char *dezenas[] = {"", "dez", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
    const char *centenas[] = {"", "cento", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"};

    if (num >= 1 && num <= 9) {
        printf("%s", unidades[num]);
    } else if (num >= 11 && num <= 19) {
        printf("%s", dezAVinte[num - 10]);
    } else if (num >= 21 && num <= 99) {
        int dezena = num / 10;
        int unidade = num % 10;
        printf("%s", dezenas[dezena]);
        if (unidade > 0) {
            printf(" e %s", unidades[unidade]);
        }
    } else if (num >= 100 && num <= 999) {
        int centena = num / 100;
        int resto = num % 100;
        printf("%s", centenas[centena]);
        if (resto > 0) {
            printf(" e ");
            numeroPorExtenso(resto);
        }
    } else if (num >= 1000 && num <= 999999) {
        int milhar = num / 1000;
        int resto = num % 1000;
        numeroPorExtenso(milhar);
        printf(" mil");
        if (resto > 0) {
            printf(" e ");
            numeroPorExtenso(resto);
        }
    }
}

void mesPorExtenso(int mes) {
    const char *nomesMeses[] = {"", "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    
    if (mes >= 1 && mes <= 12) {
        printf("%s", nomesMeses[mes]);
    }
}

void centavosPorExtenso(int centavos) {
    const char *unidadesCentavos[] = {"", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove"};
    const char *dezenasCentavos[] = {"", "", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
    
    if (centavos >= 1 && centavos <= 9) {
        printf("%s centavos", unidadesCentavos[centavos]);
    } else if (centavos >= 10 && centavos <= 99) {
        int dezenaCentavos = centavos / 10;
        int unidadeCentavos = centavos % 10;
        
        if (unidadeCentavos == 0) {
            printf("%s centavos", dezenasCentavos[dezenaCentavos]);
        } else {
            printf("%s e %s centavos", dezenasCentavos[dezenaCentavos], unidadesCentavos[unidadeCentavos]);
        }
    }
}

void diaPorExtenso(int dia) {
    const char *numerosPorExtenso[] = {"", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove", "dez", "onze", "doze", "treze", "catorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove", "vinte", "vinte e um", "vinte e dois", "vinte e três", "vinte e quatro", "vinte e cinco", "vinte e seis", "vinte e sete", "vinte e oito", "vinte e nove", "trinta", "trinta e um"};

    if (dia >= 1 && dia <= 31) {
        printf("dia %s", numerosPorExtenso[dia]);
    }
}

int main() {
	char senha[20];
    double valorCheque;
    int dia, mes, ano;
    
    // Solicita a senha
    printf("Digite a senha: ");
    scanf("%s", senha);
    
    // Verifica a senha
    if (!verificarSenha(senha)) {
        printf("Senha incorreta. Encerrando o programa.\n");
        return 1;
    }
    
    // Solicita o valor do cheque
    printf("Digite o valor do cheque: R$ ");
    scanf("%lf", &valorCheque);
    
    // Extrai a parte inteira (reais) e a parte decimal (centavos)
    int reais = (int)floor(valorCheque);
    int centavos = (int)round((valorCheque - reais) * 100);
    
    // Solicita e armazena a data de preenchimento
    printf("Digite a data de preenchimento (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &dia, &mes, &ano);
    
    // Imprime o valor por extenso e centavos
    printf("Valor por extenso: ");
    numeroPorExtenso(reais);
    printf(" reais e ");
    centavosPorExtenso(centavos);
    printf("\n");
    
    // Imprime a data por extenso
    printf("Data de preenchimento: %d/%d/%d : ", dia, mes, ano);
    diaPorExtenso(dia);
    printf(" de ");
    mesPorExtenso(mes);
    printf(" de ");
    numeroPorExtenso(ano);
    printf("\n");
    
    return 0;
}
