#include <stdio.h>
#include <stdlib.h>

/* Serie.
El programa imprime los términos y obtiene la suma de una determinada serie.
I, SSE y CAM: variable de tipo entero. */

void main(void)
{
    int I = 2, CAM = 1;
    long SSE = 0;
    while (I <= 2500)
        /*while en este programa sirve para calcular e imprimir los números en la serie hasta que el número en la serie exceda 2500,
         y luego imprime la suma total de los números en la serie.*/
{
    SSE = SSE + I;
    printf("\t %d", I);
    if (CAM)
{
    I += 5;
    CAM--;
}
else
{
    I += 3;
    CAM++;
}
}
printf("\nLa suma de la serie es: %ld", SSE);
}
