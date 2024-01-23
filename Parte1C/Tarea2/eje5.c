/* Tarea 2. Programación y Algoritmos
    Parte 1: Lenguaje C

                    José Luis de León Carmona.

Ejercicio 5. Programa que convierta un número decimal a cualquier base (considere de base 2
a 16).

***********************************************************/
#include <stdio.h>

double CambiarBase(int, int);

int main() {
    int num;
    int base;

    printf("Numero decimal que quieres cambiar \n");
    scanf("%d", &num);

    printf("A que base lo cambio (considere de base 2 a 16): \n");
    scanf("%d", &base);

    CambiarBase(num, base);
    return 0;
}

double CambiarBase(int num, int base) {
int res, chr;
long long int aux = 0;
    for (int n = num; n > 0; n = n/base ) {
        res = n % base;

        if (res < 10) {      //Obtenemos el codigo ASCII de los numeros y de los caracteres
            res = res + 48;
        } else {
            res = res + 55;
        }

        aux = aux*100 + res; //Se guardan los codigos en esta variable auxiliar para luego imprimir los carateres
        //printf("%lld \n", aux);
    }



    for (long long int m = aux; m > 0; m = m/100) {
        chr = m % 100;
        printf("%c", chr);
    }
}
