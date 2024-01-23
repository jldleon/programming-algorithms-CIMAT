/* Tarea 3. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 6. Op­er­a­tor Over­load­ing:

Ex­tend the Box class to over­load the + op­er­a­tor to add two Box ob­jects
(i.e., add their cor­re­spond­ing di­men­sions).
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

    // Friend function declaration for overloading the + operator
    friend Box operator+(const Box& box1, const Box& box2);

    // Function to display the dimensions of the Box
    void displayDimensions() const {
        std::cout << "Length: " << length << ", Breadth: " << breadth << ", Height: " << height << std::endl;
    }
};

// Overloading the + operator for Box objects
Box operator+(const Box& box1, const Box& box2) {
    // Adding corresponding dimensions
    return Box(box1.length + box2.length, box1.breadth + box2.breadth, box1.height + box2.height);
}

int main() {
    // Creating two Box objects
    Box box1(3.0, 4.0, 5.0);
    Box box2(1.5, 2.5, 3.5);

    // Using the overloaded + operator to add two Box objects
    Box resultBox = box1 + box2;

    // Displaying the dimensions of the original boxes and the result box
    std::cout << "Box 1 Dimensions:" << std::endl;
    box1.displayDimensions();

    std::cout << "\nBox 2 Dimensions:" << std::endl;
    box2.displayDimensions();

    std::cout << "\nResultant Box Dimensions:" << std::endl;
    resultBox.displayDimensions();

    return 0;
}
