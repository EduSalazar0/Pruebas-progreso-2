#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void crearmatriz(int matriz[23][3]){
    for(int i = 0; i < 23; i++){
        for(int j = 0; j < 3; j++){
            matriz[i][j] = rand() % 11;
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para calcular promedios
float calcularPromedio(float calificaciones[], int numCalificaciones){
    float suma = 0;
    for(int i = 0; i < numCalificaciones; i++){
        suma += calificaciones[i];
    }
    return suma / numCalificaciones;
}

// Función para encontrar el índice del alumno con el promedio más alto
int encontrarMejorAlumno(float promedios[]){
    int mejorAlumno = 0;
    for(int i = 1; i < 23; i++){
        if(promedios[i] > promedios[mejorAlumno]){
            mejorAlumno = i;
        }
    }
    return mejorAlumno;
}