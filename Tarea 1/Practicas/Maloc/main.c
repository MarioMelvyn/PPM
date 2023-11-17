#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumno
{
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    char direccion[20];
};

struct alumno* Malloc(int cantidad)
{
    return (struct alumno*)malloc(cantidad * sizeof(struct alumno));
}

int main(void)
{
    int cantidad_alumnos;

    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &cantidad_alumnos);

    struct alumno* alumnos = Malloc(cantidad_alumnos);

    for (int i = 0; i < cantidad_alumnos; ++i)
    {
        printf("\nIngrese la matrícula del alumno %d: ", i + 1);
        scanf("%d", &alumnos[i].matricula);
        fflush(stdin);

        printf("Ingrese el nombre del alumno %d: ", i + 1);
        gets(alumnos[i].nombre);

        printf("Ingrese la carrera del alumno %d: ", i + 1);
        gets(alumnos[i].carrera);

        printf("Ingrese el promedio del alumno %d: ", i + 1);
        scanf("%f", &alumnos[i].promedio);
        fflush(stdin);

        printf("Ingrese la dirección del alumno %d: ", i + 1);
        gets(alumnos[i].direccion);
    }

    printf("\nDatos de los alumnos\n");

    for (int i = 0; i < cantidad_alumnos; ++i)
    {
        printf("\nDatos del alumno %d\n", i + 1);
        printf("%d\n", alumnos[i].matricula);
        puts(alumnos[i].nombre);
        puts(alumnos[i].carrera);
        printf("%.2f\n", alumnos[i].promedio);
        puts(alumnos[i].direccion);
    }

    // Liberar la memoria asignada dinámicamente
    free(alumnos);
    return 0;
}
