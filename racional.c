#include <stdio.h>
#include <stdlib.h>

/*-----------------------------------------------------------*/
typedef struct {
       int p, q;
} racional;
/*-----------------------------------------------------------*/
void iniciaRacional (int a, int b, racional *num) {
     (*num).p = a;
     (*num).q = b;     
}
/*-----------------------------------------------------------*/
int mdc (int a, int b) {
    int aux;
    while (a % b != 0) {
          aux = a % b;
          a = b;
          b = aux;
    }
    return b;
}
/*-----------------------------------------------------------*/
void reduzRacional (racional *num) {
     int aux = mdc ((*num).p,(*num).q);
     (*num).p /= aux;
     (*num).q /= aux;
}
/*-----------------------------------------------------------*/
void inverteRacional (racional *num) {
     (*num).p = -(*num).p;
}
/*-----------------------------------------------------------*/
void somaRacional (racional n1, racional n2, racional *n) {    
     int aux = n1.q*n2.q;
     (*n).p  = aux/n1.q*n1.p + aux/n2.q*n2.p;
     (*n).q = aux;
     reduzRacional (&(*n));
}
/*-----------------------------------------------------------*/
void multRacional (racional n1, racional n2, racional *n) {
     (*n).p = n1.p * n2.p;
     (*n).q = n1.q * n2.q; 
     reduzRacional (&(*n));         
 }
/*-----------------------------------------------------------*/
void divRacional (racional n1, racional n2, racional *n) {
     (*n).p = n1.p * n2.q;
     (*n).q = n1.q * n2.p; 
     // FAZER: verificar se denomimnador menor ou igual a zero !!!
     reduzRacional (&(*n));         
 }
/*-----------------------------------------------------------*/
int main() {
    racional x, y, z;
    iniciaRacional (20,30,&x);
    iniciaRacional (3,4,&y);
    printf ("\nx = %d / %d ",x.p,x.q);
    printf ("\ny = %d / %d ",y.p,y.q);    
    //-----------------
    printf ("\n\nReducao");
    reduzRacional (&x);
    reduzRacional (&y);
    printf ("\nx = %d / %d ",x.p,x.q);
    printf ("\ny = %d / %d ",y.p,y.q);    
    //-----------------
    printf ("\n\nSoma");
    somaRacional (x,y,&z);
    printf ("\nz = %d / %d ",z.p,z.q);
    //-----------------
    printf ("\n\nMultiplicacao");
    multRacional (x,y,&z);
    printf ("\nz = %d / %d ",z.p,z.q);
    //-----------------
    printf ("\n\nDivisao");
    divRacional (x,y,&z);
    printf ("\nz = %d / %d ",z.p,z.q);
    system ("pause");
}    
