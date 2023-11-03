#include <stdio.h>
#include <ctype.h>

/* Prototipo de la función */
void minymay(FILE *);

int main(void) {
    FILE *ap;

    if ((ap = fopen("arc.txt", "r")) != NULL) {
        minymay(ap); // Llama a la función "minymay" y pasa el archivo como parámetro.
        fclose(ap);
    } else {
        printf("No se puede abrir el archivo\n");
    }

    return 0; // Retorna 0 para indicar que el programa ha terminado con éxito.
}

void minymay(FILE *ap1) {
    char cad[30];
    int mi = 0, ma = 0;

    while (!feof(ap1)) {
        fgets(cad, 30, ap1); // Lee cadenas de caracteres del archivo utilizando la función fgets.
        int i = 0;

        while (cad[i] != '\0') {
            if (islower(cad[i])) {
                mi++;
            } else if (isupper(cad[i])) {
                ma++;
            }
            i++;
        }
    }

    printf("\nNúmero de letras minúsculas: %d\n", mi);
    printf("Número de letras mayúsculas: %d\n", ma);
}
