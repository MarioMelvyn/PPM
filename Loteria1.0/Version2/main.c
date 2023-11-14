#include <stdlib.h>
#include <time.h>
#include <stdio.h>
//Mario Ramirez
int numerosLoteria[3];

// Función para generar los números ganadores de la lotería
void generarNumerosGanadores(int ganadores[3], int cantidadNumeros) {
    srand(time(NULL)); // Inicializar la semilla para generar números aleatorios
    for (int i = 0; i < cantidadNumeros; ++i) {
        ganadores[i] = rand() % 10; // Generar números aleatorios entre 0 y 9
    }
}

// Función para tirar los dados y generar números aleatorios
void tirar(int cantidadNumeros) {
    printf("\n¡Has elegido tirar!\n");

    for (int i = 0; i < cantidadNumeros; ++i) {
        numerosLoteria[i] = rand() % 10; // Generar números aleatorios para la lotería
    }

    // Mostrar los números generados
    printf("---------------------------\n");
    printf("Números generados: ");
    for (int i = 0; i < cantidadNumeros; ++i) {
        printf("%d ", numerosLoteria[i]);
    }
    printf("\n---------------------------\n\n");
}

// Función para jugar manualmente
void jugarManualmente(int cantidadNumeros) {
    printf("\n¡Has elegido jugar manualmente!\n");

    for (int i = 0; i < cantidadNumeros; ++i) {
        printf("Introduce el número %d: ", i + 1);
        scanf("%d", &numerosLoteria[i]);
    }

    // Mostrar los números introducidos
    printf("---------------------------\n");
    printf("Números introducidos: ");
    for (int i = 0; i < cantidadNumeros; ++i) {
        printf("%d ", numerosLoteria[i]);
    }
    printf("\n---------------------------\n\n");
}

// Función para imprimir los resultados y la hora de la jugada
void imprimir(int cantidadNumeros) {
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
    generarNumerosGanadores(numerosGanadores, cantidadNumeros);
    printf("Números ganadores: ");
    for (int i = 0; i < cantidadNumeros; ++i) {
        printf("%d ", numerosGanadores[i]);
    }
    printf("\n");

    // Mostrar los números generados por el usuario
    printf("Números generados: ");
    for (int i = 0; i < cantidadNumeros; ++i) {
        printf("%d ", numerosLoteria[i]);
    }
    printf("\n");

    // Verificar si se ganó la lotería (criterio simple: todos los números son iguales)
    int ganador = 1;
    for (int i = 0; i < cantidadNumeros; ++i) {
        if (numerosLoteria[i] != numerosGanadores[i]) {
            ganador = 0;
            break;
        }
    }

    if (ganador) {
        printf("¡Felicidades! Has ganado la lotería.\n");
    } else {
        printf("Lo siento, no has ganado esta vez. ¡Mejor suerte la próxima!\n");
    }

    printf("----------------------------------------------\n\n");
}

// Función principal
int main() {
    int opcion, subopcion;

    do {
        // Mostrar el menú de opciones
        printf("----------------------------------------------\n");
        printf("        Menu Loteria Dominicana Mario         \n");
        printf("----------------------------------------------\n");
        printf("1. Tirar\n");
        printf("2. Jugar manualmente\n");
        printf("3. Imprimir\n");
        printf("0. Salir\n");
        printf("----------------------------------------------\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        // Manejar las opciones del usuario
        switch (opcion) {
            case 1:
                printf("1. Un número\n");
                printf("2. Un pale (dos números)\n");
                printf("3. Una tripleta (tres números)\n");
                printf("Seleccione una opción: ");
                scanf("%d", &subopcion);
                tirar(subopcion);
                break;
            case 2:
                printf("1. Un número\n");
                printf("2. Un pale (dos números)\n");
                printf("3. Una tripleta (tres números)\n");
                printf("Seleccione una opción: ");
                scanf("%d", &subopcion);
                jugarManualmente(subopcion);
                break;
            case 3:
                printf("1. Un número\n");
                printf("2. Un pale (dos números)\n");
                printf("3. Una tripleta (tres números)\n");
                printf("Seleccione una opción: ");
                scanf("%d", &subopcion);
                imprimir(subopcion);
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
