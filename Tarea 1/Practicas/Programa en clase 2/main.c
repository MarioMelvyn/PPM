#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int i, j, n, mi = 0, ma = 0;
    char FRA[20][50];

    printf("\nIngrese el numero de filas del arreglo: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Ingrese la línea %d de texto: ", i + 1);
        fflush(stdin);
        gets(FRA[i]);
    }
    printf("\n\n");
    for (i = 0; i < n; i++)
    {
        j = 0;
        while (FRA[i][j] != '\0')
        {
            if (islower(FRA[i][j]))
                mi++;
            else if (isupper(FRA[i][j]))
                ma++;
            printf("\nEl codigo ASCII de '%c' es %d", FRA[i][j], FRA[i][j]);
            j++;
        }
        printf("\n\nNumero de letras minsculas: %d", mi);
        printf("\nNumero de letras mayusculas: %d", ma);
        mi = 0;
        ma = 0;
    }
    return 0;
}
