 #include <stdio.h>

/* Definici�n de la estructura "alumno" */
typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

/* Prototipo de la funci�n */
void lee(FILE *);

int main(void) {
    FILE *ar;

    if ((ar = fopen("ad1.dat", "rb")) != NULL) {
        lee(ar);  // Llama a la funci�n "lee" para leer y mostrar informaci�n de los alumnos.
        fclose(ar);   // Cierra el archivo.
    } else {
        printf("\nEl archivo no se puede abrir\n");
    }

    return 0;  // Retorna 0 para indicar que el programa ha terminado con �xito.
}

/* Funci�n para leer bloques de datos de un archivo de acceso directo */
void lee(FILE *ap) {
    alumno alu;

    while (fread(&alu, sizeof(alumno), 1, ap) == 1) {
        printf("Matr�cula: %d\tCarrera: %d\tPromedio: %f\t", alu.matricula, alu.carrera, alu.promedio);
        printf("Nombre: %s\n", alu.nombre);
    }
}
