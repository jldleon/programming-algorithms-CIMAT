/* Tarea 2. Programación y Algoritmos
    Parte 1: Lenguaje C

                    José Luis de León Carmona.

    Ejercicio 2. (10%) Programa que acepte un fracción del tipo a/b tal que (a,b) Î enteros, y la reduzca
a sus términos mínimos. Ejem: 6/24 à 1⁄4. Debe encontrar el GCD.
NOTA: Utilice una función para calcular el GCD y lo regrese a la función main().

*******************************************************************/
#include <stdio.h>

int GreatestDivisor(int, int);

int main() {
    int a, b;
    printf("Introduce dos enteros a/b: \n");
    scanf("%d/%d", &a, &b);


    int gdc = GreatestDivisor(a, b);

    int new_a = a/gdc;

    int new_b = b/gdc;

    printf("Fracción Reducida: %d/%d", new_a, new_b);

    return 0;
}


int GreatestDivisor(int n1, int n2){
    //n2 tiene que ser el mayor para que funcione el algoritmo de GCD
    if (n1 > n2){
    int t = n2;
    n2 = n1;
    n1 = t;
    }


    while (n1 != 0){
        int t = n1;
        n1 = n2%n1;
        n2 = t;
    }
    return n2;
}
