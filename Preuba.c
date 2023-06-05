#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void crearmatriz(int matriz[23][3]){
    srand(time(NULL));
    
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

int main(){
    int X[3][23];
    crearmatriz(X);

    float promediosAlumnos[23];
    float promediosProgresos[3];

    // Calcular el promedio de cada alumno
    for(int i = 0; i < 23; i++){
        promediosAlumnos[i] = calcularPromedio(X[i]);
    }

    // Calcular el promedio de cada progreso
    for(int j = 0; j < 3; j++){
        float suma = 0;
        for(int i = 0; i < 23; i++){
            suma += X[j][i];
        }
        promediosProgresos[j] = suma / 23;
    }

    // Encontrar el mejor alumno
    int mejorAlumno = encontrarMejorAlumno(promediosAlumnos);

    // Imprimir los resultados
    printf("\nPromedio de calificaciones de cada alumno:\n");
    for(int i = 0; i < 23; i++){
        printf("Alumno %d: %.2f\n", i + 1, promediosAlumnos[i]);
    }

    printf("\nPromedio del grupo de estudiantes para cada progreso:\n");
    for(int j = 0; j < 3; j++){
        printf("Progreso %d: %.2f\n", j + 1, promediosProgresos[j]);
    }

    printf("\nAlumno con el mayor promedio de calificación durante el semestre:\n");
    printf("Alumno %d: %.2f\n", mejorAlumno + 1, promediosAlumnos[mejorAlumno]);

    return 0;
}
