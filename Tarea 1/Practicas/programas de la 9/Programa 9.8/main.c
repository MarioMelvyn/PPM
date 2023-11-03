 #include <stdio.h>

/* Definición de la estructura "alumno" */
typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

/* Prototipo de la función */
void escribe(FILE *);

int main(void) {
    FILE *ar;

    if ((ar = fopen("ad1.dat", "wb")) != NULL) {
        escribe(ar);  // Llama a la función "escribe" para ingresar datos de alumnos en el archivo.
        fclose(ar);   // Cierra el archivo.
    } else {
        printf("\nEl archivo no se puede abrir\n");
    }

    return 0;  // Retorna 0 para indicar que el programa ha terminado con éxito.
}

/* Función para ingresar datos de alumnos y guardarlos en un archivo */
void escribe(FILE *ap) {
    alumno alu;
    int i = 0, r;

    printf("¿Desea ingresar información sobre alumnos? (Sí-1  No-0): ");
    scanf("%d", &r);

    while (r) {
        i++;

        printf("Matrícula del alumno %d: ", i);
        scanf("%d", &alu.matricula);

        printf("Nombre del alumno %d: ", i);
        fflush(stdin);  // Limpia el búfer del teclado.
        gets(alu.nombre);

        printf("Carrera del alumno %d: ", i);
        scanf("%d", &alu.carrera);

        printf("Promedio del alumno %d: ", i);
        scanf("%f", &alu.promedio);

        fwrite(&alu, sizeof(alumno), 1, ap);
        // Escribe la información del alumno en el archivo.

        printf("¿Desea ingresar información sobre más alumnos? (Sí-1 No-0): ");
        scanf("%d", &r);
    }
}
