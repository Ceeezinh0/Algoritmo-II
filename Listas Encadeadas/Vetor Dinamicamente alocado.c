#include <stdlib.h>
#include <stdio.h>

int main () {
  int qte, i;
  int *vet;
  
  printf ("\nQuantidade de valores do vetor: ");
  scanf ("%d", &qte);
  
  if ((vet = (int *)malloc(qte * sizeof(int))) == NULL) {
    // A função malloc aloca dinamicamente uma quantidade específica de memória,
    // que nesse caso é qte * sizeof(int), calculando o tamanho necessário em bytes.
    printf ("Memória insuficiente");
    exit(1);
  }
  
  printf ("\nDigite os valores do vetor:");
  
  for (i = 0; i < qte; i++) {
    printf ("\nDigite o %d. elemento: ", i + 1);
    scanf ("%d", &vet[i]);
  }
  
  printf ("\nImprimindo os valores do vetor:");
  for (i = 0; i < qte; i++)
    printf ("\nvet[%d] = %d", i + 1, vet[i]);
  
  free(vet);
  // Libera a memória alocada dinamicamente.
}
