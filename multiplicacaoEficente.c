#include<stdio.h>

int main(){
	int valor = 1, expoente, resultado, i;
	
	while(valor != 0){
		scanf("%d", &valor);
		scanf("%d", &expoente);
		
		int resultado =1;
		
		for(i=0; i< expoente; i++){
			if(expoente == 1){
				resultado = valor ;
				continue;
			}
			else if(expoente == 0){
				resultado = 1;
				continue;
			}
			resultado *= valor;
		}
		printf("%d ^ %d = %d\n", valor, expoente, resultado);
	}
	return 0;
}
/*Escreva uma função eficiente que receba inteiros positivos k e n e calcule kn
. Quantas multiplicações sua função executa?

Essa função ira executar para sempre a não ser quando o valor for 0;
*/