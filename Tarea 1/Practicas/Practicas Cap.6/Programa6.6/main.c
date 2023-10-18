#include <stdio.h>
#include <stdlib.h>

/* Intercambia.
El programa intercambia las columnas de un arreglo bidimensional. Los
➥elementos de la primera columna se intercambian con los de la última,
➥los de la segunda con los de la penúltima, y así sucesivamente. */
const int MAX = 50;
void Lectura(float [][MAX], int, int);
void Intercambia(float [][MAX], int, int); /* Prototipos de funciones. */
void Imprime(float [][MAX], int, int);
void main(void)
{
int F, C;
float MAT[MAX][MAX];
do
{
printf("Ingrese el número de filas: ");
scanf("%d", & F);
}
while (F > MAX || F < 1); /* Se verifica que el número de filas sea correcto. */
do
{
printf("Ingrese el número de columnas: ");
scanf("%d", &C);
}
while (C > MAX || C < 1); /* Se verifica que el número de columnas sea
➥correcto. */
Lectura(MAT, F, C);
Intercambia(MAT, F, C);
Imprime(MAT, F, C);
}
void Lectura(float A[][MAX], int F, int C)
/* La función Lectura se utiliza para leer un arreglo bidimensional de tipo
➥real de F filas y C columnas. */
{
int I, J;
for (I=0; I< F; I++)
for (J=0; J<C; J++)
{
printf("Ingrese el elemento %d %d: ", I+1, J+1);
scanf("%f", &A[I][J]);
}
}
void Intercambia(float A[][MAX], int F, int C)
/* Esta función se utiliza para intercambiar las columnas del arreglo
bidimensional. Observa que el índice correspondiente a las columnas sólo se
mueve hasta la mitad del arreglo. */
{
int I, J;
float AUX;
/* Observa que en esta función el índice I se utiliza para las columnas, y el
índice J para las filas. */
for (I=0; I < (C / 2); I++)
for (J=0; J< F; J++)
{
AUX = A[J][I];
A[J][I] = A[J][C-I-1];
A[J][C-I-1]=AUX;
}
}
void Imprime(float A[][MAX], int F, int C)
/* La función Imprime se utiliza para escribir un arreglo bidimensional de tipo
➥real de F filas y C columnas. */
{
int I, J;
for (I=0; I< F; I++)
for (J=0; J<C; J++)
printf("\nElemento %d %d: %5.2f", I+1, J+1, A[I][J]);
}
