/* Tarea 1. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 5. Dan­gling Point­ers:
Write a pro­gram that in­ten­tion­al­ly cre­ates a dan­gling point­er and then at­tempts to ac-
cess it. Doc­u­ment what hap­pens, and ex­plain how to fix the prob­lem.

************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>

/* EJEMPLO MAL HECHO DANGLING POINTER
#include <iostream>

int *fun() {
    int num = 47;
    return &num;
}

int main() {
    int *ptr = fun();
    std::cout<< ptr << std::endl;
    //Sale warning de local variable returned
    return 0;
}
*/

//Esta seria la forma correcta:
int* fun() {
    int* num = new int(47); // Asigna memoria
    return num;
}

int main() {
    int* ptr = fun();
    std::cout << *ptr << std::endl;

    // Liberar la memoria asignada
    delete ptr;

    return 0;
}
