/* Tarea 1. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 6. Mem­o­ry Leak De­tec­tion:
Cre­ate a sim­ple pro­gram that in­ten­tion­al­ly leaks mem­o­ry. Then, use a mem­o­ry pro­filing tool to iden­ti­fy and fix the mem­o­ry leak.

************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>

void createMemoryLeak();

void fixMemoryLeak();

int main() {

    /* Esto crea un fuga de memoria intencional
    createMemoryLeak();

    std::cout << "Fugo de Memoria intencial" << std::endl;

    */

    fixMemoryLeak();

    std::cout << "Fuga de memoria corregida" << std::endl;

    return 0;
}

void createMemoryLeak() {
    int* ptr = new int(5); // Intentional memory leak
}

void fixMemoryLeak() {
    int* ptr = new int(5);
    delete ptr; // Deallocate the memory
}
