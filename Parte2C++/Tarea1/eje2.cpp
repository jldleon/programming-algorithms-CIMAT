/* Tarea 1. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 2. Dy­nam­ic Mem­o­ry Al­lo­ca­tion:
Cre­ate a pro­gram that dy­nam­i­cal­ly al­lo­cates an ar­ray of user-spec­i­fied size, fills it with
ran­dom num­bers, and then de­allocates the ar­ray be­fore ex­it­ing.
************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    int n, i;
    std::cout << "Tamaño del arreglo: ";
    std::cin >> n;

    int* arr = new int[n];

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

    delete[] arr;

    return 0;
}
