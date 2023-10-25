#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int T, P, N;
    printf("Ingrese los valores de T, P y N: ");
    scanf("%d %d %d", &T, &P, &N);

    if (P != 0)
    {
        if (pow((double)T / P, N) == (pow((double)T, N) / pow((double)P, N)))
            printf("\nSe comprueba la igualdad");
        else
            printf("\nNo se comprueba la igualdad");
    }
    else
        printf("\nP tiene que ser diferente de cero");

    return 0;
}
