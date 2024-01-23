/* Tarea 1. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 4. Func­tion Point­ers:

Cre­ate a pro­gram that de­fines sev­er­al math­e­mat­i­cal op­er­a­tions (e.g., ad­di­tion, sub-
trac­tion, mul­ti­pli­ca­tion, di­vi­sion) as func­tions, and then cre­ates a func­tion point­er to call these func­tions based on user in­put.
************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>

double suma(double a, double b);

double resta(double a, double b);

double multiplicacion(double a, double b);

double division(double a, double b);

int main() {
    double a, b;
    char operacion;

    std::cout << "Ingresa tu operación: Ejemplo 2+2" << std::endl;
    std::cout << "Suma: + Resta: - Multiplicación: * Division: /" << std::endl;
    std::cin >> a >> operacion >> b;

    double (*oprPtr) (double, double) = nullptr;

    switch (operacion) {
        case '+':
            oprPtr = suma;
            break;
        case '-':
            oprPtr = resta;
            break;
        case '*':
            oprPtr = multiplicacion;
            break;
        case '/':
            oprPtr = division;
            break;
        default:
            std::cerr << "Operación Invalida" << std::endl;
            return 1;
    }

    if (oprPtr) {
        std::cout << "Result: " << oprPtr(a, b) << std::endl;
    }

    return 0;
}

double suma(double a, double b) {
    return a + b;
}

double resta(double a, double b) {
    return a - b;
}

double multiplicacion(double a, double b) {
    return a * b;
}

double division(double a, double b) {
    return a / b;
}
