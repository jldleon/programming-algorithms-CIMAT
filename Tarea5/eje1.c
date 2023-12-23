/* Tarea 5. Programación y algoritmos.
    Parte 1. Lenguaje C.

                José Luis de León Carmona.
Ejercicio 1. Explique cómo funciona los tiempos de datos “unions” y “enum”; de ejemplos
concretos.
*************************************************/

/* #Enumeracion
Una enumeración ("enum") es un tipo de dato que permite definir un conjunto de valores constantes enteros con nombre.
Los valores de una enumeración son enteros y se enumeran como una secuencia de constantes con nombres.
*/

/* #Union
Una "union" es una estructura de datos que permite almacenar diferentes tipos de datos en la misma ubicación de memoria.
A diferencia de las estructuras (structs), donde cada miembro tiene su propia ubicación de memoria,
en una "union" todos los miembros comparten la misma ubicación de memoria.
Esto significa que solo uno de los miembros de la unión puede tener un valor en un momento dado.
*/


#include <stdio.h>

// Definición de una enumeración para los días de la semana
enum DiaSemana {
    Lunes,
    Martes,
    Miercoles,
    Jueves,
    Viernes,
    Sabado,
    Domingo
};

// Definición de una unión para representar datos de diferentes tipos
union MiUnion {
    int entero;
    float flotante;
    char caracter;
};

int main() {
    // Uso de la enumeración
    enum DiaSemana hoy = Martes;

    printf("\n   Ejemplo Enumeración: \n");

    if (hoy == Martes) {
        printf("Hoy es Martes.\n");
    } else {
        printf("Hoy no es Martes.\n");
    }

    printf("\n     Ejemplo de Union   \n");

    // Uso de la unión
    union MiUnion datos;

    datos.entero = 42;
    printf("Valor entero: %d\n", datos.entero);

    datos.flotante = 3.14;
    printf("Valor flotante: %f\n", datos.flotante);

    datos.caracter = 'A';
    printf("Valor caracter: %c\n", datos.caracter);

    return 0;
}
