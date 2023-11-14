#include <stdlib.h>
#include <time.h>
#include <stdio.h>
//Mario Ramirez
int numerosLoteria[3];

// Funci�n para generar los n�meros ganadores de la loter�a
void generarNumerosGanadores(int ganadores[3]) {
    srand(time(NULL)); // Inicializar la semilla para generar n�meros aleatorios
    for (int i = 0; i < 3; ++i) {
        ganadores[i] = rand() % 10; // Generar n�meros aleatorios entre 0 y 9
    }
}

// Funci�n para tirar los dados y generar n�meros aleatorios
void tirar() {
    printf("\n�Has elegido tirar!\n");

    for (int i = 0; i < 3; ++i) {
        numerosLoteria[i] = rand() % 10; // Generar n�meros aleatorios para la loter�a
    }

    // Mostrar los n�meros generados
    printf("---------------------------\n");
    printf("N�meros generados: %d %d %d\n", numerosLoteria[0], numerosLoteria[1], numerosLoteria[2]);
    printf("---------------------------\n\n");
}

// Funci�n para imprimir los resultados y la hora de la jugada
void imprimir() {
    printf("\n�Has seleccionado imprimir!\n");

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

    // Generar y mostrar los n�meros ganadores
    int numerosGanadores[3];
    generarNumerosGanadores(numerosGanadores);
    printf("N�meros ganadores: %d %d %d\n", numerosGanadores[0], numerosGanadores[1], numerosGanadores[2]);

    // Mostrar los n�meros generados por el usuario
    printf("N�meros generados: %d %d %d\n", numerosLoteria[0], numerosLoteria[1], numerosLoteria[2]);

    // Verificar si se gan� la loter�a (criterio simple: todos los n�meros son iguales)
    if (numerosLoteria[0] == numerosLoteria[1] && numerosLoteria[1] == numerosLoteria[2]) {
        printf("�Felicidades! Has ganado la loter�a.\n");
    } else {
        printf("Lo siento, no has ganado esta vez. �Mejor suerte la pr�xima!\n");
    }

    printf("----------------------------------------------\n\n");
}

// Funci�n principal
int main() {
    int opcion;

    do {
        // Mostrar el men� de opciones
        printf("----------------------------------------------\n");
        printf("        Menu Loteria Dominicana Mario         \n");
        printf("----------------------------------------------\n");
        printf("1. Tirar\n");
        printf("2. Imprimir\n");
        printf("0. Salir\n");
        printf("----------------------------------------------\n");
        printf("Seleccione una opci�n: ");
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
                printf("Saliendo del programa. �Hasta luego!\n");
                break;
            default:
                printf("Opci�n no v�lida. Intente de nuevo.\n");
        }

    } while (opcion != 0);

    return 0;
}
