/* Tarea 3. Programacion y Algoritmos
    Parte 1: Lenguaje C

                        José Luis de León Carmona.

Ejercicio 3. Dado un arreglo bidimensional de enteros MxN, encontrar el máximo valor por cada
columna y cada renglón:
NOTA: Recorrer el arreglo (columnas y renglones) en forma eficiente.

B) Cuente el número de bytes del arreglo bidimensional con valor 0 (recuerde que cada
entero está representado por 4 bytes).

*************************************************/
#include <stdio.h>
#include <stdlib.h> // Para usar rand()
#include <time.h>

void randomArray (int M, int N, int arr[][N]);

void printArr(int ren, int col, int m[][col]);

void encontrarMaximos(int M, int N, int arr[][N]);

int contarBytesCeros(int entero);

int contarCerosEnMatriz(int M, int N, int arr[][N] );

int main() {
    srand(time(NULL));
    int M = 3;
    int N = 3;

    int arr[M][N];

    randomArray(M, N, arr);

    printf("Matriz aleatoria: \n");
    printArr(M, N, arr);

    encontrarMaximos(M, N, arr);

    int result = contarCerosEnMatriz(M, N, arr);

    printf("Numero de ceros (bytes) en el arreglo: %d", result);




    return 0;
}

int contarBytesCeros(int entero) {
    int contador = 0;

    // Recorremos los 4 bytes de un entero
    for (int i = 0; i < 4; i++) {
        // Extraemos un byte utilizando desplazamiento de bits
        unsigned char byte = (unsigned char)((entero >> (8 * i)) & 0xFF);
        // Verificamos si el byte es igual a cero
        if (byte == 0) {
            contador++;
        }
    }

    return contador;
}

int contarCerosEnMatriz(int M, int N, int arr[][N]) {
    int ceros = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            ceros += contarBytesCeros(arr[i][j]); //Si son enteros pequeños regresa 3 por entero, para enteros mucho mas grandes cada vez hay menos ceros
        }
    }

    return ceros;
}

void encontrarMaximos(int M, int N, int arr[][N]) {
    int maximosFilas[M];
    int maximosColumnas[N];

    // Encontrar máximos por filas
    for (int i = 0; i < M; i++) {
        int maximoFila = arr[i][0];
        for (int j = 1; j < N; j++) {
            if (arr[i][j] > maximoFila) {
                maximoFila = arr[i][j];
            }
        }
        maximosFilas[i] = maximoFila;
    }

    // Encontrar máximos por columnas
    for (int j = 0; j < N; j++) {
        int maximoColumna = arr[0][j];
        for (int i = 1; i < M; i++) {
            if (arr[i][j] > maximoColumna) {
                maximoColumna = arr[i][j];
            }
        }
        maximosColumnas[j] = maximoColumna;
    }

    // Imprimir los máximos por filas
    printf("Máximos por filas:\n");
    for (int i = 0; i < M; i++) {
        printf("Fila %d: %d\n", i, maximosFilas[i]);
    }

    // Imprimir los máximos por columnas
    printf("Máximos por columnas:\n");
    for (int j = 0; j < N; j++) {
        printf("Columna %d: %d\n", j, maximosColumnas[j]);
    }
}

void randomArray(int M, int N, int arr[][N]) {
    int i,j;

    for (i=0; i < M; i++) {
        for (j=0; j<N; j++) {
            arr[i][j] = rand();
        }
    }
}

void printArr(int ren, int col, int m[][col]) {
    int i, j;

    for (i = 0; i < ren; i++) {
        for (j = 0; j < col; j++) {
            printf("%-3d ", m[i][j]);
        }
        printf("\n");
    }
}
