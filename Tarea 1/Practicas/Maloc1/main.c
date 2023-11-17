#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *archivo = NULL;
    char *linea = NULL;
    size_t longitud = 0; // Longitud actual del búfer
    size_t capacidad = 1; // Capacidad inicial del búfer
    char caracter;

    // Abrir el archivo en modo escritura
    archivo = fopen("archivo.txt", "w");
    if (archivo == NULL)
    {
        fprintf(stderr, "Error al abrir el archivo para escritura.\n");
        return 1;
    }

    printf("Escribe en el archivo (presiona Enter para cerrar):\n");

    // Utilizar malloc para asignar memoria inicial
    linea = (char *)malloc(capacidad * sizeof(char));
    if (linea == NULL)
    {
        fprintf(stderr, "Error al asignar memoria.\n");
        fclose(archivo);
        return 1;
    }

    // Leer caracteres uno por uno hasta que se presione Enter
    while ((caracter = getchar()) != '\n')
    {
        // Realloc para ajustar el tamaño del búfer
        if (longitud == capacidad)
        {
            capacidad + 1; // Duplicar la capacidad
            linea = (char *)realloc(linea, capacidad * sizeof(char));
            if (linea == NULL)
            {
                fprintf(stderr, "Error al asignar memoria.\n");
                fclose(archivo);
                return 1;
            }
        }

        // Agregar el caracter al búfer
        linea[longitud++] = caracter;
    }

    // Escribir la línea en el archivo
    fprintf(archivo, "%s", linea);

    // Cerrar el archivo y liberar la memoria
    fclose(archivo);
    free(linea);

    printf("Archivo cerrado.\n");

    return 0;
}
