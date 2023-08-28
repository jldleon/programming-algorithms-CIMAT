/* Tarea 2. Programación y Algoritmos
    Parte 1: Lenguaje C

                    José Luis de León Carmona.

Ejercicio 4. Programa que evalúe la siguiente expresión:

cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + x^8/8! - ... = sum_(n=0)^∞ (-1)^n * (x^(2n)) / (2n)!

dónde “!” es el operador factorial. Cree una función Coseno(int num, float epsilon), que
tenga como entrada el número de términos a evaluar y una cota épsilon << 1, tal que la
función Coseno(x) se detenga cuando se cumpla cualquiera de los dos, num o épsilon <
|iter(N)-iter(N-1|).
NOTA: La función debe ser lo más eficiente posible.

********* ****************************************************/

#include <stdio.h>
#include <math.h>

double coseno(double, int, double);

int main() {
    double x, epsilon;
    int n;
    printf("Introduce el valor x(ángulo en radianes) para calcular cos(x): \n");
    scanf("%lf", &x);

    printf("Introduce el numero de terminos a calcular n: \n");
    scanf("%d", &n);

    printf("Introduce el limite epsilon<<1 \n");
    scanf("%lf", &epsilon);

    double result = coseno(x, n, epsilon);

    printf("Resultado: %lf", result);

    return 0;
}

double coseno(double x, int n, double epsilon) {
    double suma = 1;
    int signo = -1;
    double potencia = x*x;
    long int factorial = 2;

    for (int i=1; i<=n; i++){
        double suma_1 = suma;
        suma += (signo * potencia) / factorial;
        signo *= -1;
        potencia *= x*x;
        factorial *= (2*i+1)*(2*i+2);

        if (fabs(suma - suma_1) < epsilon) {
            return suma;
            }

    }

    return suma;
}

