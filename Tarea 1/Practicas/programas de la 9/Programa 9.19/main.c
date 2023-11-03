#include <stdio.h>

/* Declaración de la estructura "alumno" */
typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

/* Prototipo de función */
void ordena(FILE *, FILE *);

int main(void) {
    FILE *ar1, *ar2;
    ar1 = fopen("ad5.dat", "rb");  /* Se abre el archivo para lectura en modo binario. */
    ar2 = fopen("ad6.dat", "wb");  /* Se abre un nuevo archivo para escritura en modo binario. */

    if ((ar1 != NULL) && (ar2 != NULL)) {
        ordena(ar1, ar2);
        fclose(ar1);
        fclose(ar2);
    } else {
        printf("El archivo o los archivos no se pudieron abrir\n");
    }

    return 0; /* Retorna 0 para indicar que el programa ha terminado con éxito. */
}

void ordena(FILE *ap1, FILE *ap2) {
    alumno alu;
    int t, n, i;
    t = sizeof(alumno);

    fseek(ap1, 0, SEEK_END);   /* Coloca el puntero al final del archivo para obtener el número de registros. */
    n = ftell(ap1) / t;        /* Calcula el número de registros en el archivo. */

    rewind(ap1);              /* Reposiciona el puntero al principio del archivo. */

    for (i = 0; i < n; i++) {   /* Utiliza un ciclo ascendente. */
        fseek(ap1, i * sizeof(alumno), SEEK_SET);
        fread(&alu, sizeof(alumno), 1, ap1);
        fwrite(&alu, sizeof(alumno), 1, ap2);
    }
}
