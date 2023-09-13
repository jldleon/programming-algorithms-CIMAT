/* Tarea 3. Programacion y Algoritmos
    Parte 1: Lenguaje C

                        José Luis de León Carmona

    Ejercicio 6.

    ***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printVec(int n, int vec[n]);

int *bubbleSort(int, int *);

int *genSizeArray(int);

int *genIntArray(int n);

int **genArrayOfArrays(int, int *);

int *mergeArrays(int **, int, int *);

int main() {
    srand(time(0));

    int numArrays = 10;

    int *arraySizes = genSizeArray(numArrays);

    int **arrays = genArrayOfArrays(numArrays, arraySizes);

    int *mergedArray = mergeArrays(arrays, numArrays, arraySizes);

    // Liberar memoria
    for (int i = 0; i < numArrays; i++) {
        free(arrays[i]);
    }
    free(arrays);
    free(arraySizes);
    free(mergedArray);

    return 0;
}

int *mergeArrays(int **arrays, int n, int *sizes) {
    // Obtener la cantidad total de espacio requerido
    int totalSize = 0;
    for (int i = 0; i < n; i++) {
        totalSize += sizes[i];
    }

    // Crear el gran arreglo
    int *bigArray = (int *)malloc(totalSize * sizeof(int));

    // Copiar los valores de los arreglos individuales al gran arreglo
    int currentIndex = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            bigArray[currentIndex] = arrays[i][j];
            currentIndex++;
        }
    }

    bigArray = bubbleSort(totalSize, bigArray);

    printf("Arreglo Unido:\n");
    for (int i = 0; i < totalSize; i++) {
        printf("%d\t", bigArray[i]);
    }

    return bigArray;
}

int **genArrayOfArrays(int n, int *sizes) {
    int **arrays = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        arrays[i] = genIntArray(sizes[i]);
    }
    return arrays;
}

int *genIntArray(int n) {
    // Generar espacio para el arreglo
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
    return bubbleSort(n, arr);
}

int *genSizeArray(int n) {
    // Generar espacio para el arreglo de tamaños
    int *arr = (int *)malloc(n * sizeof(int));
    // Tamaño entre 5 y 25
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 21) + 5;
    }
    return arr;
}

int *bubbleSort(int n, int *arr) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

void printVec(int n, int vec[n]) {
    int i;

    for (i = 0; i < n; i++) {
        printVec("%d, ", vec[i]);
    }

}
