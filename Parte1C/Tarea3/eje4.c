/* Tarea 3. Programacion y Algoritmos
    Parte 1: Lenguaje C

                        José Luis de León Carmona.

Ejercicio 4. Dado una lista de nombres (strings) de N personas (apellido_paterno,
apellido_materno, Nombre(s)), escribir una función que ordene los nombres
alfabéQcamente usando un arreglo de apuntadores:
char **crea_arreglo(char **arr,...)
char **ordena(char **arr,...)

los nombres pueden tener disQnta longitud pero la memoria que ocupan debe ser la justa
(sin desperdicio); cuando un nombre sea prefijo de otro, considerar al nombre más corto
como menor. El ordenamiento debe ser a través de una función que reciba el arreglo de
apuntadores (como se muestra en la figura).

**********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LEN 100
//#define WID 80

void printStr(char *str[], int N);

char **crearArreglo(int n, int WID);

void ordena(char *s[], int n);

int main() {
    int n;
    int WID = 80;
    printf("Numero de nombres : \n");
    scanf("%d", &n);
    printf("Intoduce los nombres :\n");
    if (n > LEN) {
        printf("Error numero máximo de nombres %d", LEN);
        n = LEN;
    }

    char **cadenas = crearArreglo(n, WID);

    printf("Los nombres son:\n");
    printStr(cadenas, n);
    ordena(cadenas, n);
    printf("Ordenados :\n");
    printStr(cadenas, n);

    free(cadenas);

    return 0;
}

void ordena(char *s[], int n) {
    char *temp;
    int item, i;

    for (item = 1; item < n; item++) {
        temp = s[item];
        for (i = item; i > 0 && strcasecmp(s[i - 1], temp) > 0; i--);
        memcpy(&s[i + 1], &s[i], (item - i) * sizeof(char *));
        s[i] = temp;
    }
}

// Función para leer cadenas desde la entrada estándar y almacenarlas en un arreglo de cadenas
char **crearArreglo(int n, int WID) {
    char **s = (char **)malloc(n * sizeof(char *));
    if (s == NULL) {
        perror("Error en malloc");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        printf("%d :", i + 1);
        s[i] = (char *)malloc(WID * sizeof(char));
        if (s[i] == NULL) {
            perror("Error en malloc");
            exit(1);
        }
        if (fgets(s[i], WID, stdin) == NULL) {
            perror("Error al leer la cadena");
            exit(1);
        }
        // Eliminar el salto de línea al final de la cadena
        size_t longitud = strlen(s[i]);
        if (longitud > 0 && s[i][longitud - 1] == '\n') {
            s[i][longitud - 1] = '\0';
        }
    }

    return s;
}

void printStr(char *str[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%s\n", str[i]);
    }
}


