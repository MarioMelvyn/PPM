#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Pares e impares.
El programa, al recibir como datos N n�meros enteros, obtiene la suma de los n�meros pares y calcula el promedio de los impares.
I, N, NUM, SPA, SIM, CIM: variables de tipo entero. */

void main(void)
{
int I, N, NUM, SPA = 0, SIM = 0, CIM = 0;
printf("Ingrese el numero de datos que se van a procesar:\t");
scanf("%d", &N);
if (N > 0)
{
for (I=1; I <= N; I++) /* for en este programa sirve para procesar una serie de n�meros ingresados por el usuario, sumar los n�meros pares e impares por separado y contar el n�mero de n�meros impares.
Al final del bucle, el programa imprime la suma de los n�meros pares y el promedio de los n�meros impares.*/
{
printf("\nIngrese el numero %d: ", I);
scanf("%d", &NUM);
if (NUM)
    if (pow(-1, NUM) > 0)
    SPA = SPA + NUM;
else
{
    SIM = SIM + NUM;
    CIM++;
   }

}
printf("\n La suma de los numeros pares es: %d", SPA);
printf("\n El promedio de numeros impares es: %5.2f", (float)(SIM / CIM));
}
else
printf("\n El valor de N es incorrecto");
}
