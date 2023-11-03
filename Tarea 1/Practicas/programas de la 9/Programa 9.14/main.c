#include <stdio.h>
#include <ctype.h>

/* Prototipo de la función */
void minymay(FILE *);

int main(void) {
    char p;
    FILE *ar;

    if ((ar = fopen("arc5.txt", "r")) != NULL) {
        minymay(ar); // Llama a la función "minymay" y pasa el archivo como parámetro.
        fclose(ar);
    } else {
        printf("No se pudo abrir el archivo\n");
    }

    return 0; // Retorna 0 para indicar que el programa ha terminado con éxito.
}

void minymay(FILE *arc) {
    int min = 0, may = 0;
    char p;

    while ((p = fgetc(arc)) != EOF) {
        if (islower(p)) {
            min++;
        } else if (isupper(p)) {
            may++;
        }
    }

    printf("Número de letras minúsculas: %d\n", min);
    printf("Número de letras mayúsculas: %d\n", may);
}
