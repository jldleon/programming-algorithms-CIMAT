/* Tarea 1. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 1. Ba­sic Poin­ter Arith­me­tic:
Write a func­tion that takes a point­er to an ar­ray of in­te­gers and the size of the ar­ray as
ar­gu­ments. The func­tion should re­turn the sum of all the ar­ray el­e­ments us­ing point­er
arith­metic.
************************************************/

#include <iostream>

int sumArray(int* arr, int n);

int main () {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = sumArray(arr, size);
    std::cout << "Suma: " << result << std::endl;

    return 0;
}

int sumArray(int* arr, int n) {
    int sum = 0, i;
    int* ptr = arr;

    for (i = 0; i < n; i++) {
        sum += *ptr;
        ptr++;
    }

    return sum;
}



