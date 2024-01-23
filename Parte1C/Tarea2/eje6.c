/* Tarea 2. Programación y Algoritmos
    Parte 1: Lenguaje C

                    José Luis de León Carmona.

Ejercicio 6. Dado N elementos, escriba un programa que encuentre el 3er elemento mayor y
cuente el número de elementos pares e impares.

**************************************************************/

#include <stdio.h>

int main() {
    int N, pares=0, impares=0, pri=0, sec=0, ter=0;
    printf("¿Cuantos elementos vas a introducir?: \n");
    scanf("%d", &N);

    for (int i=1; i <= N; i++) {
        int num;
        printf("Introduce el %d° entero de %d \n", i, N);
        scanf("%d", &num);

        if (num > pri){
            int tem1 = pri;
            int tem2 = sec;
            pri = num;
            sec = tem1;
            ter = tem2;
            //break;
        } else if (num > sec) {
            int tem1 = sec;
            sec = num;
            ter = tem1;
            //break;
        } else if (num > ter) {
            ter = num;
            //break;
        }

        printf("El tercer mayor: %d \n", ter);

        if (num % 2 == 0) {
            pares++;
        } else {
            impares++;
        }

        printf("Numero de pares: %d \n", pares);
        printf("Numero de impares: %d \n", impares);
    }

    return 0;
}
