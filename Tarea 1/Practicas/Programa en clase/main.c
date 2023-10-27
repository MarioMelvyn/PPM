#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, n;
    char FRA[20][50];

    printf("\nIngrese el numero de filas del arreglo: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Ingrese la linea %d de texto: ", i + 1);
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
                FRA[i][j] = toupper(FRA[i][j]);
            else if (isupper(FRA[i][j]))
                FRA[i][j] = tolower(FRA[i][j]);
            printf("\nEl caracter '%c' tiene el codigo ASCII %d", FRA[i][j], FRA[i][j]);
            j++;
        }
        printf("\n\nLa cadena modificada es: %s", FRA[i]);
    }
    return 0;
}
