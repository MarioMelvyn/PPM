#include <stdio.h>
#include <stdlib.h>

/* Factorial.
El programa calcula el factorial de un número entero.
FAC, I, NUM: variables de tipo entero. */
void main(void)
{
int I, NUM;
long FAC;
printf("\nIngrese el numero: ");
scanf("%d", &NUM);
if (NUM >= 0)
{
FAC = 1;
for (I=1; I <= NUM; I++) /*for en este programa se utiliza para calcular el factorial de un número (NUM) ingresado por el usuario.*/
    FAC *= I;
printf("\El factorial de %d es: %ld", NUM, FAC);
}
else
printf("\nError en el dato ingresado");
}
