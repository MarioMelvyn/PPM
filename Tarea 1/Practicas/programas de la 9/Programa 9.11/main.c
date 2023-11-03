#include <stdio.h>

/* Definición de la estructura "empleado" */
typedef struct {
    int clave;
    int departamento;
    float salario;
    float ventas[12];
} empleado;

/* Prototipo de la función */
void incrementa(FILE *);

int main(void) {
    FILE *ar;

    if ((ar = fopen("ad5.dat", "r+")) != NULL) {
        incrementa(ar);  // Llama a la función "incrementa" para aumentar los salarios de los empleados.
        fclose(ar);      // Cierra el archivo.
    } else {
        printf("El archivo no se puede abrir\n");
    }

    return 0;  // Retorna 0 para indicar que el programa ha terminado con éxito.
}

/* Función para incrementar los salarios de los empleados con ventas anuales superiores a 1,000,000 pesos */
void incrementa(FILE *ap) {
    int i, j;
    float sum;
    empleado emple;
    int t = sizeof(empleado);

    fseek(ap, 0, SEEK_SET);  // Posiciona el puntero al inicio del archivo (sin necesidad real en este programa).

    fread(&emple, sizeof(empleado), 1, ap);  // Lee el primer registro del archivo.

    while (!feof(ap)) {
        i = ftell(ap) / t;  // Obtiene la posición actual del puntero y calcula el número de registro.

        sum = 0;

        for (j = 0; j < 12; j++) {
            sum += emple.ventas[j];  // Calcula las ventas anuales de cada empleado.
        }

        if (sum > 1000000) {
            emple.salario *= 1.10;  // Incrementa el salario en un 10%.
            fseek(ap, (i - 1) * t, SEEK_SET);  // Posiciona el puntero para escribir el registro actualizado.
            fwrite(&emple, sizeof(empleado), 1, ap);

            fseek(ap, i * t, SEEK_SET);  // Posiciona el puntero para leer el siguiente registro.
        }

        fread(&emple, sizeof(empleado), 1, ap);
    }
}
