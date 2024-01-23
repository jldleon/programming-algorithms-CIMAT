/* Tarea 1. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 10. Er­ror Hand­ling:
Write a func­tion that per­forms di­vi­sion of two num­bers, han­dles di­vi­sion by
zero with a try/catch block, and re­ports any er­rors to the user.
************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <fstream>
#include <vector>

double divideNumbers(double numerator, double denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Error: Division by zero");
    }
    return numerator / denominator;
}

int main() {
    double a, b;
    std::cout << "Enter the numerator: ";
    std::cin >> a;
    std::cout << "Enter the denominator: ";
    std::cin >> b;

    try {
        double result = divideNumbers(a, b);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
