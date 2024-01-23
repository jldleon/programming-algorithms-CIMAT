/* Tarea 2. Programación y Algoritmos
    Parte 1: Lenguaje C

                    José Luis de León Carmona.
Ejercicio 3. Programa que imprima un número entero dado de n dígitos al revés. Ejem,
entrada:79373, salida: 37397.
B) Verificar si el número es palíndromo, esto es representa el mismo número escrito al
revés, por ejemplo 45954, 93466439.
**************************************************************/

#include <stdio.h>
#include <math.h> // Lubreria para utilizar la funcíón pow y log10

int NumReverse(int); //Función que regresa el numero al reves, esto mismo sirve para ver si es palindromo

int main() {
    int n;
    printf("Ingresa un numero entero: \n");
    scanf("%d", &n);

    int result = NumReverse(n);

    printf("Numero al reves: %d \n", result);

    if (result == n){
        printf("Es palindromo \n");
    } else {
        printf("No es palindromo  \n");
    }

    return 0;
}

int NumReverse(int n) {
    double loga = log10((double)n);
    int p = (int)loga + 1;  //Numero de digitos de n
    n = (int)n;

    if (p == 1){
        return n;
    }

    int num = 0;  //Variable para guardar el numero al reves

    while(n != 0){
        int res = n % 10; //Residuo de la divison n/10
        num += res*pow(10, p - 1 );
        n = n / 10;
        p--;
    }

    return num;
}
