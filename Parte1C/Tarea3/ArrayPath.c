/* Tarea 3. Programacion y Algoritmos
    Parte 1: Lenguaje C

                        José Luis de León Carmona.

Ejercicio 2. Escribir un programa que genere una caminata aleatoria en una matriz de 10x10. El
arreglo debe contener inicialmente puntos  ́. ́, y debe recorrerse basado en el residuo de
un número aleatoria (usar srand y rand()) cuyos resultado puede ser {0 (arriba), 1 (abajo),
2 (izq), 3 (der)}, que indican la dirección a moverse. A) Verificar que el movimiento no se
salga del arreglo de la matriz, y B) No se puede visitar el mismo lugar más de una vez. Si
alguna de estas condiciones se presenta, intentar moverse hacia otra dirección definida;
si todas las posiciones están ocupadas, finalizar el programa e imprimir el resultado.

*****************************************************************************************/
#include <stdio.h>
#include <stdlib.h> // Para usar rand()
#include <time.h>

#define N 10

void printArr(int ren, int col, int m[][col]);

int movs_posibles(int x, int y, int m[][y]);

int main() {
    int arr[N][N];
    int i, j;
    srand(time(NULL));

    //Llenar la matriz de 10 x 10 con -1
    for (i=0; i < N; i++) {
        for (j=0; j < N; j++) {
            arr[i][j] = -1;
        }
    }

    printf("Arreglo inicial (-1) significa que no ha sido caminado: \n");
    printArr(N, N, arr);

    int x = rand()%9; // Posición inicial en x
    int y = rand()%9; // Posición inicial en y

    int pasos = 0;
    arr[x][y] = 0; //primer paso

    int movs_pos = movs_posibles(x, y, arr);

    while (movs_pos > 0) {
            int mov = rand() % 4;

            switch(mov) {
                case 0: //Arriba
                    if (0 <= x - 1 && arr[x-1][y] == -1) {
                        x -= 1;
                        pasos++;
                        arr[x][y] = pasos;
                    } break;

                case 1: //Abajo
                    if (x + 1 < 10 && arr[x+1][y] == -1) {
                        x += 1;
                        pasos++;
                        arr[x][y] = pasos;
                    } break;

                case 2: //Izquierda
                    if (0 <= y - 1 && arr[x][y-1] == -1) {
                        y -= 1;
                        pasos++;
                        arr[x][y] = pasos;
                    } break;

                case 3: //Derecha
                    if (y + 1 < 10 && arr[x][y+1] == -1) {
                        y += 1;
                        pasos++;
                        arr[x][y] = pasos;
                    } break;
            }

        movs_pos = movs_posibles(x, y, arr);
    }


    printf("\n");
    printf("Caminata Aleatoria Generada: \n");
    printArr(N, N, arr);

    return 0;
}

int movs_posibles(int x, int y, int m[][y]) {
    int count = 0;

    if ((x + 1) < 10 && m[x + 1][y] == -1) {
        count++;
    }

    if (m[x][y+1] == -1 && (y + 1) < 10) {
        count++;
    }

    if (m[x-1][y] == -1 && (x - 1) > -1) {
        count++;
    }

    if (m[x][y-1] == -1 && (y - 1) > -1) {
        count++;
    }

    return count;

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

