
#include <stdio.h>
#include <stdlib.h>

/* Suma positivos. El programa, al recibir como datos N numeros enteros, obtiene la suma de los enteros positivos. I, N, NUM, SUM: variables de tipo entero. */
int main(void)
{
    int I, N, NUM, SUM;
    SUM = 0;

    printf("Ingrese el numero de datos: \t");
    scanf("%d", &N);

    for (I = 1; I <= N; I++)
    /*el bucle for se encarga de repetir el proceso de ingresar datos y acumular la suma de los números positivos según
     el número total de datos proporcionados por el usuario (N). */
    {
        printf("Ingrese el dato numero %d:\t", I);
        scanf("%d", &NUM);

        if (NUM > 0)
        {
            SUM = SUM + NUM;
        }
    }

    printf("\nLa suma de los numeros positivos es: %d", SUM);

    return 0;
}

