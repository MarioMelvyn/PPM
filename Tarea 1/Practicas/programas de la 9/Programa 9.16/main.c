#include <stdio.h>
#include <stdlib.h>

/* Prototipo de la función */
void sumypro(FILE *);

int main(void)
{
    FILE *ap;

    if ((ap = fopen("arc2.txt", "r")) != NULL) {
        sumypro(ap); // Llama a la función "sumypro" y pasa el archivo como parámetro.
        fclose(ap);
    } else {
        printf("No se puede abrir el archivo\n");
    }

    return 0; // Retorna 0 para indicar que el programa ha terminado con éxito.
}

void sumypro(FILE *ap1) {
    char cad[30];
    int i = 0;
    float sum = 0.0, r;

    while (!feof(ap1)) {
        fgets(cad, 30, ap1); // Lee la cadena del archivo.

        r = atof(cad);

        /* Recuerda que la función atof convierte una cadena de caracteres que
        contiene números reales a un valor de tipo double. Si la cadena comienza
        con otro carácter o no contiene números, regresa 0 o el valor queda indefinido. */

        if (r)
            {
            i++;
            sum += r;
        }
    }

    printf("\nSuma: %.2f", sum);

    if (i) {
        printf("\nPromedio: %.2f", sum / i); // Si el valor de i es distinto de cero, calcula el promedio.
    }
}
