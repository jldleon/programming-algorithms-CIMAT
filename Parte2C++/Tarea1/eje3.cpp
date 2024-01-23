/* Tarea 1. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 3. Smart Point­ers:
Re­write the pro­gram from ex­er­cise 2 us­ing smart point­ers to man­age the mem­o­ry.
************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>

int main() {
    int n, i;
    std::cout << "Tamaño del arreglo: ";
    std::cin >> n;

    //Smart pointer
    std::unique_ptr<int[]>arr(new int[n]);

    //Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (i = 0; i < n; i++) {
        arr[i] = std::rand() % 100;
    }

    std::cout << "Arreglo aleatorio: [";
    for (i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout  << "]" << std::endl;

    //Memory dellocation happens automatically using smart pointers
    //delete[] arr;

    return 0;
}
