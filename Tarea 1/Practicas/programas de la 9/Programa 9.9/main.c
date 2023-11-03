 #include <stdio.h>

/* Definición de la estructura "alumno" */
typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

/* Prototipo de la función */
void lee(FILE *);

int main(void) {
    FILE *ar;

    if ((ar = fopen("ad1.dat", "rb")) != NULL) {
        lee(ar);  // Llama a la función "lee" para leer y mostrar información de los alumnos.
        fclose(ar);   // Cierra el archivo.
    } else {
        printf("\nEl archivo no se puede abrir\n");
    }

    return 0;  // Retorna 0 para indicar que el programa ha terminado con éxito.
}

/* Función para leer bloques de datos de un archivo de acceso directo */
void lee(FILE *ap) {
    alumno alu;

    while (fread(&alu, sizeof(alumno), 1, ap) == 1) {
        printf("Matrícula: %d\tCarrera: %d\tPromedio: %f\t", alu.matricula, alu.carrera, alu.promedio);
        printf("Nombre: %s\n", alu.nombre);
    }
}
