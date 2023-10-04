#include <stdio.h>
#include <stdlib.h>

void f1(void); /* Prototipo de función. */
int K = 5; /* Variable global. */

int main (void)
{
    int I;
    for (I = 1; I <= 3; I++)
        f1();

    return 0; /* Indica que el programa se ejecutó exitosamente. */
}

void f1(void)
{
    int K_local = 2; /* Cambiamos el nombre de la variable local a K_local. */
    K_local += K_local; /* Utilizamos la variable local K_local. */
    printf("\n\nEl valor de la variable local es: %d", K_local);
    K = K + K_local; /* Actualizamos la variable global K. */
    printf("\nEl valor de la variable global es: %d", K);
}
