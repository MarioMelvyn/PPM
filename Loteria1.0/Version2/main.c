#include <stdlib.h>
#include <time.h>
#include <stdio.h>
//Mario Ramirez
int numerosLoteria[3];

// Funci�n para generar los n�meros ganadores de la loter�a
void generarNumerosGanadores(int ganadores[3], int cantidadNumeros) {
    srand(time(NULL)); // Inicializar la semilla para generar n�meros aleatorios
    for (int i = 0; i < cantidadNumeros; ++i) {
        ganadores[i] = rand() % 10; // Generar n�meros aleatorios entre 0 y 9
    }
}

// Funci�n para tirar los dados y generar n�meros aleatorios
void tirar(int cantidadNumeros) {
    printf("\n�Has elegido tirar!\n");

    for (int i = 0; i < cantidadNumeros; ++i) {
        numerosLoteria[i] = rand() % 10; // Generar n�meros aleatorios para la loter�a
    }

    // Mostrar los n�meros generados
    printf("---------------------------\n");
    printf("N�meros generados: ");
    for (int i = 0; i < cantidadNumeros; ++i) {
        printf("%d ", numerosLoteria[i]);
    }
    printf("\n---------------------------\n\n");
}

// Funci�n para jugar manualmente
void jugarManualmente(int cantidadNumeros) {
    printf("\n�Has elegido jugar manualmente!\n");

    for (int i = 0; i < cantidadNumeros; ++i) {
        printf("Introduce el n�mero %d: ", i + 1);
        scanf("%d", &numerosLoteria[i]);
    }

    // Mostrar los n�meros introducidos
    printf("---------------------------\n");
    printf("N�meros introducidos: ");
    for (int i = 0; i < cantidadNumeros; ++i) {
        printf("%d ", numerosLoteria[i]);
    }
    printf("\n---------------------------\n\n");
}

// Funci�n para imprimir los resultados y la hora de la jugada
void imprimir(int cantidadNumeros) {
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
    generarNumerosGanadores(numerosGanadores, cantidadNumeros);
    printf("N�meros ganadores: ");
    for (int i = 0; i < cantidadNumeros; ++i) {
        printf("%d ", numerosGanadores[i]);
    }
    printf("\n");

    // Mostrar los n�meros generados por el usuario
    printf("N�meros generados: ");
    for (int i = 0; i < cantidadNumeros; ++i) {
        printf("%d ", numerosLoteria[i]);
    }
    printf("\n");

    // Verificar si se gan� la loter�a (criterio simple: todos los n�meros son iguales)
    int ganador = 1;
    for (int i = 0; i < cantidadNumeros; ++i) {
        if (numerosLoteria[i] != numerosGanadores[i]) {
            ganador = 0;
            break;
        }
    }

    if (ganador) {
        printf("�Felicidades! Has ganado la loter�a.\n");
    } else {
        printf("Lo siento, no has ganado esta vez. �Mejor suerte la pr�xima!\n");
    }

    printf("----------------------------------------------\n\n");
}

// Funci�n principal
int main() {
    int opcion, subopcion;

    do {
        // Mostrar el men� de opciones
        printf("----------------------------------------------\n");
        printf("        Menu Loteria Dominicana Mario         \n");
        printf("----------------------------------------------\n");
        printf("1. Tirar\n");
        printf("2. Jugar manualmente\n");
        printf("3. Imprimir\n");
        printf("0. Salir\n");
        printf("----------------------------------------------\n");
        printf("Seleccione una opci�n: ");
        scanf("%d", &opcion);

        // Manejar las opciones del usuario
        switch (opcion) {
            case 1:
                printf("1. Un n�mero\n");
                printf("2. Un pale (dos n�meros)\n");
                printf("3. Una tripleta (tres n�meros)\n");
                printf("Seleccione una opci�n: ");
                scanf("%d", &subopcion);
                tirar(subopcion);
                break;
            case 2:
                printf("1. Un n�mero\n");
                printf("2. Un pale (dos n�meros)\n");
                printf("3. Una tripleta (tres n�meros)\n");
                printf("Seleccione una opci�n: ");
                scanf("%d", &subopcion);
                jugarManualmente(subopcion);
                break;
            case 3:
                printf("1. Un n�mero\n");
                printf("2. Un pale (dos n�meros)\n");
                printf("3. Una tripleta (tres n�meros)\n");
                printf("Seleccione una opci�n: ");
                scanf("%d", &subopcion);
                imprimir(subopcion);
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
