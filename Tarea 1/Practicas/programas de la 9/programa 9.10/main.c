#include <stdio.h>

/* Definición de la estructura "alumno" */
typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

/* Prototipo de la función */
void modifica(FILE *);

int main(void) {
    FILE *ar;

    if ((ar = fopen("ad1.dat", "r+")) != NULL) {
        modifica(ar);  // Llama a la función "modifica" para modificar el promedio del alumno.
        fclose(ar);   // Cierra el archivo.
    } else {
        printf("El archivo no se puede abrir\n");
    }

    return 0;  // Retorna 0 para indicar que el programa ha terminado con éxito.
}

/* Función para modificar el promedio de un alumno en un archivo */
void modifica(FILE *ap)
{
    int d;
    alumno alu;

    printf("Ingrese el número de registro que desea modificar: ");
    scanf("%d", &d);

    fseek(ap, (d - 1) * sizeof(alumno), 0);
    /* Utilizamos fseek para posicionarnos en el registro correcto. Restamos 1 a 'd' porque los registros comienzan desde 0. */

    fread(&alu, sizeof(alumno), 1, ap);
    /* Leemos el registro que deseamos modificar. */

    printf("Ingrese el promedio correcto del alumno: ");
    scanf("%f", &alu.promedio);
    /* Modificamos el registro con el nuevo promedio. */

    fseek(ap, (d - 1) * sizeof(alumno), 0);
    /* Nos posicionamos nuevamente en el registro correcto para escribir el registro modificado. */

    fwrite(&alu, sizeof(alumno), 1, ap);
}
