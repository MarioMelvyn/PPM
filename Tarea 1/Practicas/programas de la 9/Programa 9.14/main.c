#include <stdio.h>
#include <ctype.h>

/* Prototipo de la funci�n */
void minymay(FILE *);

int main(void) {
    char p;
    FILE *ar;

    if ((ar = fopen("arc5.txt", "r")) != NULL) {
        minymay(ar); // Llama a la funci�n "minymay" y pasa el archivo como par�metro.
        fclose(ar);
    } else {
        printf("No se pudo abrir el archivo\n");
    }

    return 0; // Retorna 0 para indicar que el programa ha terminado con �xito.
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

    printf("N�mero de letras min�sculas: %d\n", min);
    printf("N�mero de letras may�sculas: %d\n", may);
}
