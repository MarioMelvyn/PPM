#include <stdio.h>

/* Declaración de la estructura "matcal" */
typedef struct {
    char materia[20];
    int calificacion;
} matcal;

/* Declaración de la estructura "alumno" */
typedef struct {
    int matricula;
    char nombre[20];
    matcal cal[5]; /* Un campo de esta estructura es a su vez estructura. */
} alumno;

/* Prototipos de funciones */
void F1(FILE *);
void F2(FILE *);
float F3(FILE *);

int main(void) {
    float promedioMateria4;
    FILE *ap;

    if ((ap = fopen("esc.dat", "rb")) != NULL) {
        F1(ap);
        F2(ap);
        promedioMateria4 = F3(ap);
        printf("\n\nPROMEDIO GENERAL MATERIA 4: %f", promedioMateria4);
    } else {
        printf("\nEl archivo no se puede abrir");
    }

    fclose(ap);

    return 0;
}

void F1(FILE *ap) {
    alumno alu;
    int j;
    float sum, pro;

    printf("\nMATRÍCULA y PROMEDIOS");

    fread(&alu, sizeof(alumno), 1, ap);

    while (!feof(ap)) {
        printf("\nMatrícula: %d", alu.matricula);
        sum = 0.0;

        for (j = 0; j < 5; j++) {
            sum += alu.cal[j].calificacion;
        }

        pro = sum / 5;
        printf("\tPromedio: %f", pro);

        fread(&alu, sizeof(alumno), 1, ap);
    }
}

void F2(FILE *ap) {
    alumno alu;

    rewind(ap);
    printf("\n\nALUMNOS CON CALIFICACIÓN > 9 EN MATERIA 3");

    fread(&alu, sizeof(alumno), 1, ap);

    while (!feof(ap)) {
        if (alu.cal[2].calificacion > 9) {
            printf("\nMatrícula del alumno: %d", alu.matricula);
        }

        fread(&alu, sizeof(alumno), 1, ap);
    }
}

float F3(FILE *ap) {
    alumno alu;
    int i = 0;
    float sum = 0.0, pro;

    rewind(ap);
    fread(&alu, sizeof(alumno), 1, ap);

    while (!feof(ap)) {
        i++;
        sum += alu.cal[3].calificacion;
        fread(&alu, sizeof(alumno), 1, ap);
    }

    pro = (float)sum / i;
    return pro;
}
