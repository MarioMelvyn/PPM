#include <stdio.h>

/* Prototipo de la función */
int cuenta(char);

int main(void) {
    int res;
    char car;

    printf("Ingrese el carácter que se va a buscar en el archivo: ");
    car = getchar();
    fflush(stdin); // Limpiar el búfer del teclado.

    res = cuenta(car);

    if (res != -1) {
        printf("\n\nEl carácter %c se encuentra en el archivo %d veces\n", car, res);
    } else {
        printf("No se pudo abrir el archivo\n");
    }

    return 0; // Retorna 0 para indicar que el programa ha terminado con éxito.
}

int cuenta(char car) {
    int res = 0;
    char p;
    FILE *ar;

    if ((ar = fopen("arc.txt", "r")) != NULL) { // Se abre el archivo para lectura.
        while ((p = getc(ar)) != EOF) { // Se trabaja con el archivo mientras no se llegue al fin de este.
            if (p == car) { // Se realiza la comparación de los caracteres.
                res++;
            }
        }

        fclose(ar);
        return res;
    } else {
        return -1; // Retorna -1 si no se pudo abrir el archivo.
    }
}
