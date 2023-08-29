#include <stdio.h>
#include <string.h>
int main() {
 char str[10];
 int num;
 printf ("Digite um numero: ");
 scanf("%d",&num);
 itoa (num,str,2);
 printf ("Valor binario: %s\n",str);
 itoa (num,str,10);
 printf ("Valor decimal: %s\n",str);
 itoa (num,str,16);
 printf ("Valor hexadecimal: %s\n",str);
 return 0;
} 
