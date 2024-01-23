/* Tarea 3. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 5. Friend Func­tion:

Cre­ate a class named Box with pri­vate data mem­bers for length, breadth,
and height. De­fine a friend func­tion to cal­cu­late and re­turn the vol­ume of
the box.
************************************************/

#include <iostream>

class Box {
private:
    double length;
    double breadth;
    double height;

public:
    // Constructor
    Box(double l, double b, double h) : length(l), breadth(b), height(h) {}

    // Friend function declaration
    friend double calculateVolume(const Box& box);
};

// Friend function definition
double calculateVolume(const Box& box) {
    // Accessing private members of the Box class
    return box.length * box.breadth * box.height;
}

int main() {
    // Creating a Box object
    Box myBox(3.0, 4.0, 5.0);

    // Using the friend function to calculate the volume
    double volume = calculateVolume(myBox);

    // Print the calculated volume
    std::cout << "Volume of the box: " << volume << std::endl;

    return 0;
}
