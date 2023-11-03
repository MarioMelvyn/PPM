#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Prototipo de la funci�n */
void cambia(FILE *, FILE *);

int main(void) {
    FILE *ar;
    FILE *ap;

    ar = fopen("arc.txt", "r");   /* Se abre el archivo "arc.txt" para lectura. */
    ap = fopen("arc1.txt", "w");  /* Se abre el archivo "arc1.txt" para escritura. */

    if ((ar != NULL) && (ap != NULL)) {
        cambia(ar, ap);
        fclose(ar);
        fclose(ap);
    } else {
        printf("No se pueden abrir los archivos\n");
    }

    return 0; /* Retorna 0 para indicar que el programa ha terminado con �xito. */
}

void cambia(FILE *ap1, FILE *ap2) {
    int i, j, k;
    char cad[30], *cad1 = "", *cad2 = "", aux[30];

    while (!feof(ap1)) {
        fgets(cad, 30, ap1);
        strcpy(cad1, cad);
        cad2 = strstr(cad1, "m�xico"); /* Localiza la subcadena "m�xico" en cad1. */

        while (cad2 != NULL) {
            cad2[0] = 'M'; /* Reemplaza la primera letra min�scula por may�scula. */
            i = strlen(cad1);
            j = strlen(cad2);
            k = i - j; /* Almacena la diferencia de las longitudes de cad1 y cad2. */

            if (k) {
                strncpy(aux, cad1, k); /* Copia la subcadena de k caracteres desde el inicio de cad1 hasta antes de "m�xico". */
                aux[k] = '\0';
                strcat(aux, cad2);
                strcpy(cad1, aux);
            } else {
                strcpy(cad1, cad2);
            }

            cad2 = strstr(cad1, "m�xico");
        }

        fputs(cad1, ap2); /* Escribe la cadena corregida en el archivo ap2. */
    }
}
