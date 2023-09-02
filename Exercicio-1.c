#include <stdio.h>
#include <stdlib.h>

struct hm {
  int horas;
  int minutos;
};

void converte (int t, struct hm *horario) {
  (*horario).horas = t / 60;
  (*horario).minutos = t % 60;
}    

int main() {
  int tempo;
  struct hm t;    
  system ("cls");
  printf ("Digite um tempo (em minutos): ");
  scanf ("%d",&tempo);
  converte (tempo,&t);
  printf ("\n%d minutos = %d horas e %d minutos.\n\n",tempo,t.horas,t.minutos);
}    
