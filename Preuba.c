#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void crearmatriz(int matriz[23][3]) {
    srand(time(NULL));
    for (int i = 0; i < 23; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = rand() % 11;
            printf(" (%d) ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para calcular promedios
float calcularPromedio(int calificaciones[], int numCalificaciones) {
    float suma = 0;
    for (int i = 0; i < numCalificaciones; i++) {
        suma += calificaciones[i];
    }
    return suma / numCalificaciones;
}

// Función para encontrar el índice del alumno con el promedio más alto
int encontrarMejorAlumno(float promedios[], int numAlumnos) {
    int mejorAlumno = 0;
    for (int i = 0; i < numAlumnos; i++) {
        if (promedios[i] > promedios[mejorAlumno]) {
            mejorAlumno = i;
        }
    }
    return mejorAlumno;
}

// Función principal
int main() {
    int X[23][3];
    srand(time(NULL));
    crearmatriz(X);
    float promediosAlumnos[23];
    float promediosProgresos[3];

    // Calcular el promedio de cada alumno
    for (int i = 0; i < 23; i++) {
        promediosAlumnos[i] = calcularPromedio(X[i], 3);
    }

    // Calcular el promedio de cada progreso
    for (int j = 0; j < 3; j++) {
        float suma = 0;
        for (int i = 0; i < 23; i++) {
            suma += X[i][j];
        }
        promediosProgresos[j] = suma / 23;
    }

    // Encontrar el mejor alumno
    int mejorAlumno = encontrarMejorAlumno(promediosAlumnos, 23);

    // Imprimir los resultados
    printf("\nPromedio de calificaciones de cada alumno:\n");
    for (int i = 0; i < 23; i++) {
        printf("Alumno %d: %.2f\n", i + 1, promediosAlumnos[i]);
    }

    printf("\nPromedio del grupo de estudiantes para cada progreso:\n");
    for (int j = 0; j < 3; j++) {
        printf("Progreso %d: %.2f\n", j + 1, promediosProgresos[j]);
    }

    printf("\nAlumno con el mayor promedio de calificación durante el semestre:\n");
    printf("Alumno %d: %.2f\n", mejorAlumno + 1, promediosAlumnos[mejorAlumno]);

    return 0;
}
