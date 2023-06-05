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
