/* Tarea 3. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 4. Func­tion Over­load­ing:

- Cre­ate a class named Cal­cu­la­tor that has over­loaded mem­ber func­tions
for ad­di­tion which can add two in­te­gers, two dou­bles, or two com­plex
num­bers.
************************************************/

#include <iostream>
#include <complex>

class Calculator {
public:
    // Addition for two integers
    int add(int a, int b) {
        return a + b;
    }

    // Addition for two doubles
    double add(double a, double b) {
        return a + b;
    }

    // Addition for two complex numbers
    std::complex<double> add(const std::complex<double>& a, const std::complex<double>& b) {
        return a + b;
    }
};

int main() {
    Calculator myCalculator;

    // Adding two integers
    int sumInt = myCalculator.add(5, 10);
    std::cout << "Sum of integers: " << sumInt << std::endl;

    // Adding two doubles
    double sumDouble = myCalculator.add(3.5, 2.7);
    std::cout << "Sum of doubles: " << sumDouble << std::endl;

    // Adding two complex numbers
    std::complex<double> complex1(1.0, 2.0);
    std::complex<double> complex2(2.5, 1.5);
    std::complex<double> sumComplex = myCalculator.add(complex1, complex2);

    std::cout << "Sum of complex numbers: " << sumComplex << std::endl;

    return 0;
}
