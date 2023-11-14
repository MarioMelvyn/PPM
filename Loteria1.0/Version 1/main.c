#include <stdlib.h>
#include <time.h>
#include <stdio.h>
//Mario Ramirez
int numerosLoteria[3];

// Función para generar los números ganadores de la lotería
void generarNumerosGanadores(int ganadores[3]) {
    srand(time(NULL)); // Inicializar la semilla para generar números aleatorios
    for (int i = 0; i < 3; ++i) {
        ganadores[i] = rand() % 10; // Generar números aleatorios entre 0 y 9
    }
}

// Función para tirar los dados y generar números aleatorios
void tirar() {
    printf("\n¡Has elegido tirar!\n");

    for (int i = 0; i < 3; ++i) {
        numerosLoteria[i] = rand() % 10; // Generar números aleatorios para la lotería
    }

    // Mostrar los números generados
    printf("---------------------------\n");
    printf("Números generados: %d %d %d\n", numerosLoteria[0], numerosLoteria[1], numerosLoteria[2]);
    printf("---------------------------\n\n");
}

// Función para imprimir los resultados y la hora de la jugada
void imprimir() {
    printf("\n¡Has seleccionado imprimir!\n");

    // Obtener la hora y fecha actual
    time_t tiempoActual;
    struct tm *infoTiempo;

    time(&tiempoActual);
    infoTiempo = localtime(&tiempoActual);

    // Mostrar la hora y fecha de la jugada
    printf("----------------------------------------------\n");
    printf("Hora de la jugada: %02d:%02d:%02d, Fecha: %02d/%02d/%04d\n",
           infoTiempo->tm_hour, infoTiempo->tm_min, infoTiempo->tm_sec,
           infoTiempo->tm_mday, infoTiempo->tm_mon + 1, infoTiempo->tm_year + 1900);
    printf("----------------------------------------------\n");

    // Generar y mostrar los números ganadores
    int numerosGanadores[3];
    generarNumerosGanadores(numerosGanadores);
    printf("Números ganadores: %d %d %d\n", numerosGanadores[0], numerosGanadores[1], numerosGanadores[2]);

    // Mostrar los números generados por el usuario
    printf("Números generados: %d %d %d\n", numerosLoteria[0], numerosLoteria[1], numerosLoteria[2]);

    // Verificar si se ganó la lotería (criterio simple: todos los números son iguales)
    if (numerosLoteria[0] == numerosLoteria[1] && numerosLoteria[1] == numerosLoteria[2]) {
        printf("¡Felicidades! Has ganado la lotería.\n");
    } else {
        printf("Lo siento, no has ganado esta vez. ¡Mejor suerte la próxima!\n");
    }

    printf("----------------------------------------------\n\n");
}

// Función principal
int main() {
    int opcion;

    do {
        // Mostrar el menú de opciones
        printf("----------------------------------------------\n");
        printf("        Menu Loteria Dominicana Mario         \n");
        printf("----------------------------------------------\n");
        printf("1. Tirar\n");
        printf("2. Imprimir\n");
        printf("0. Salir\n");
        printf("----------------------------------------------\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        // Manejar las opciones del usuario
        switch (opcion) {
            case 1:
                tirar();
                break;
            case 2:
                imprimir();
                break;
            case 0:
                printf("Saliendo del programa. ¡Hasta luego!\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }

    } while (opcion != 0);

    return 0;
}
