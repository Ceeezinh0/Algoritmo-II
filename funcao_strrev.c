#include <stdio.h>
#include <string.h>
int main(){
 char string[20];
 printf("Invertendo uma string\n");
 printf("Entre com a string :");
 scanf(" %[^\n]", string);
 printf("Invertendo ==> %s",strrev(string));
 return 0;
}
