#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int entero = 0;
    float flotante = 0.0;
    double decimal = 0.0;
    char letra = 'a';

    printf("\nMemoria ocupada en byte entero %i", sizeof (entero));
    printf("\nMemoria ocupada en byte flotante %i", sizeof (flotante));
    printf("\nMemoria ocupada en byte double %i", sizeof (decimal));
    printf("\nMemoria ocupada en byte caracter %i", sizeof (letra));
    printf("\nMemoria ocupada en byte long %i", sizeof (entero));

    printf("\nDireccion de memoria de decimal %p",&decimal);
}
