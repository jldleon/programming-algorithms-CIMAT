/* Tarea 3. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 10. Com­plex Num­bers Class:

Cre­ate a class named Com­plex to rep­re­sent com­plex num­bers. Over­load
the +, -, *, and / op­er­a­tors to per­form com­plex num­ber arith­metic. Also,
cre­ate a friend func­tion to out­put a com­plex num­ber in the for­mat a + bi
to the con­sole.
************************************************/

#include <iostream>

class Complex {
private:
    double real;  // Real part of the complex number
    double imag;  // Imaginary part of the complex number

public:
    // Constructor
    Complex(double real, double imag) : real(real), imag(imag) {}

    // Overloading the + operator for addition
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloading the - operator for subtraction
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overloading the * operator for multiplication
    Complex operator*(const Complex& other) const {
        return Complex((real * other.real) - (imag * other.imag), (real * other.imag) + (imag * other.real));
    }

    // Overloading the / operator for division
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex(((real * other.real) + (imag * other.imag)) / denominator,
                       ((imag * other.real) - (real * other.imag)) / denominator);
    }

    // Friend function to output a complex number in the format a + bi
    friend std::ostream& operator<<(std::ostream& os, const Complex& complex);
};

// Friend function definition
std::ostream& operator<<(std::ostream& os, const Complex& complex) {
    os << complex.real;
    if (complex.imag >= 0) {
        os << " + " << complex.imag << "i";
    } else {
        os << " - " << -complex.imag << "i";
    }
    return os;
}

int main() {
    // Creating complex numbers
    Complex complex1(2.0, 3.0);
    Complex complex2(1.0, -2.5);

    // Performing arithmetic operations and displaying the results
    std::cout << "Complex 1: " << complex1 << std::endl;
    std::cout << "Complex 2: " << complex2 << std::endl;

    Complex sum = complex1 + complex2;
    std::cout << "Sum: " << sum << std::endl;

    Complex difference = complex1 - complex2;
    std::cout << "Difference: " << difference << std::endl;

    Complex product = complex1 * complex2;
    std::cout << "Product: " << product << std::endl;

    Complex quotient = complex1 / complex2;
    std::cout << "Quotient: " << quotient << std::endl;

    return 0;
}
