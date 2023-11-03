 #include <stdio.h>

/* Definici�n de la estructura "alumno" */
typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

/* Prototipo de la funci�n */
void escribe(FILE *);

int main(void) {
    FILE *ar;

    if ((ar = fopen("ad1.dat", "wb")) != NULL) {
        escribe(ar);  // Llama a la funci�n "escribe" para ingresar datos de alumnos en el archivo.
        fclose(ar);   // Cierra el archivo.
    } else {
        printf("\nEl archivo no se puede abrir\n");
    }

    return 0;  // Retorna 0 para indicar que el programa ha terminado con �xito.
}

/* Funci�n para ingresar datos de alumnos y guardarlos en un archivo */
void escribe(FILE *ap) {
    alumno alu;
    int i = 0, r;

    printf("�Desea ingresar informaci�n sobre alumnos? (S�-1  No-0): ");
    scanf("%d", &r);

    while (r) {
        i++;

        printf("Matr�cula del alumno %d: ", i);
        scanf("%d", &alu.matricula);

        printf("Nombre del alumno %d: ", i);
        fflush(stdin);  // Limpia el b�fer del teclado.
        gets(alu.nombre);

        printf("Carrera del alumno %d: ", i);
        scanf("%d", &alu.carrera);

        printf("Promedio del alumno %d: ", i);
        scanf("%f", &alu.promedio);

        fwrite(&alu, sizeof(alumno), 1, ap);
        // Escribe la informaci�n del alumno en el archivo.

        printf("�Desea ingresar informaci�n sobre m�s alumnos? (S�-1 No-0): ");
        scanf("%d", &r);
    }
}
