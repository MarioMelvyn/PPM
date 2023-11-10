#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Letras minúsculas y mayúsculas.
El programa, al recibir como dato un archivo formado por cadenas de caracteres,
➥determina el número de letras minúsculas y mayúsculas que hay en el archivo, e
➥intercambia las letras mayúsculas por minúsculas y viceversa. */

void minymay(FILE *);

int main(void)
{
    char p;
    FILE *ar;
    if ((ar = fopen("prueba.txt", "r")) != NULL)
    {
        minymay(ar);
        fclose(ar);
    }
    else
        printf("No se pudo abrir el archivo");

    return 0;
}

void minymay(FILE *arc)
{
    int min = 0, may = 0;
    char p;
    while ((p = fgetc(arc)) != EOF)
    {
        if (islower(p))
        {
            may++;
            p = toupper(p);  // Convierte minúscula en mayúscula
        }
        else if (isupper(p))
        {
            min++;
            p = tolower(p);  // Convierte mayúscula en minúscula
        }

        putchar(p);  // Imprime el carácter modificado en la consola
    }

    printf("\nNumero de minusculas: %d", min);
    printf("\nNumero de mayusculas: %d", may);
}
