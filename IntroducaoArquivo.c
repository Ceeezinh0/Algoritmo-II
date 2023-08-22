#include<stdio.h>

int main(){
	
	FILE *arq;
	arq = (fopen("arq.dat", "wb"));// abri o arquivo
	int fclose(arq);//fecha o arquivo
	
	return 0;
}