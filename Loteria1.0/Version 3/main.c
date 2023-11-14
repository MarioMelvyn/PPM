#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
//Mario Ramirez
int numerosLoteria[3];
char tipoJugada[20];
int apuesta;

// Función para generar los números ganadores de la lotería
void generarNumerosGanadores(int ganadores[], int cantidadNumeros) {
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

// Función para apostar
void apostar() {
    printf("\n¡Has elegido apostar!\n");
    printf("Introduce tu apuesta: ");
    scanf("%d", &apuesta);
    printf("Has apostado %d.\n", apuesta);
}

// Función para guardar las jugadas en un archivo
void guardarJugadas(int cantidadNumeros) {
    FILE *archivo = fopen("jugadas.txt", "a");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    // Obtener la hora y fecha actual
    time_t tiempoActual;
    struct tm *infoTiempo;

    time(&tiempoActual);
    infoTiempo = localtime(&tiempoActual);

    fprintf(archivo, "Hora de la jugada: %02d:%02d:%02d, Fecha: %02d/%02d/%04d\n",
           infoTiempo->tm_hour, infoTiempo->tm_min, infoTiempo->tm_sec,
           infoTiempo->tm_mday, infoTiempo->tm_mon + 1, infoTiempo->tm_year + 1900);

    fprintf(archivo, "Tipo de jugada: %s\n", tipoJugada);

    fprintf(archivo, "Números jugados: ");
    for (int i = 0; i < cantidadNumeros; ++i) {
        fprintf(archivo, "%d ", numerosLoteria[i]);
    }
    fprintf(archivo, "\n\n");

    fclose(archivo);

    printf("Jugada guardada con éxito.\n");
}

// Función para borrar las jugadas del archivo
void borrarJugadas() {
    remove("jugadas.txt");
    printf("Jugadas borradas con éxito.\n");
}

// Función para ver el historial de jugadas
void verHistorial() {
    FILE *archivo = fopen("jugadas.txt", "r");
    char linea[100];

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    printf("\nHistorial de jugadas:\n");
    printf("---------------------------\n");
    while (fgets(linea, sizeof(linea), archivo)) {
        printf("%s", linea);
    }
    printf("---------------------------\n\n");

    fclose(archivo);
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
        printf("Has ganado %d.\n", apuesta * 70);
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
        printf("3. Apostar\n");
        printf("4. Guardar jugadas\n");
        printf("5. Borrar jugadas\n");
        printf("6. Ver historial\n");
        printf("7. Imprimir\n");
        printf("0. Salir\n");
        printf("----------------------------------------------\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        // Manejar las opciones del usuario
        switch (opcion) {
            case 1:
            case 2:
                printf("1. Un número\n");
                printf("2. Un pale (dos números)\n");
                printf("3. Una tripleta (tres números)\n");
                printf("Seleccione una opción: ");
                scanf("%d", &subopcion);
                if (subopcion == 1) {
                    strcpy(tipoJugada, "Un número");
                } else if (subopcion == 2) {
                    strcpy(tipoJugada, "Un pale");
                } else if (subopcion == 3) {
                    strcpy(tipoJugada, "Una tripleta");
                }
                if (opcion == 1) {
                    tirar(subopcion);
                } else {
                    jugarManualmente(subopcion);
                }
                break;
            case 3:
                apostar();
                break;
            case 4:
                guardarJugadas(subopcion);
                break;
            case 5:
                borrarJugadas();
                break;
            case 6:
                verHistorial();
                break;
            case 7:
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
