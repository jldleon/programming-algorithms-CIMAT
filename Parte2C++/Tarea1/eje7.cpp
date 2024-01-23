/* Tarea 1. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 7. Class In­heri­t­an­ce:

Cre­ate a base class rep­re­sent­ing a geo­metric shape, and de­rived class­es rep­re­sent-
ing spe­cif­ic types of shapes (e.g., cir­cle, rec­tangle, tri­an­gle). Im­ple­ment a method to
cal­cu­late the area of each shape.

************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>


class Shape {
public:
    virtual double calculateArea() const = 0;
};


class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }
};


class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double calculateArea() const override {
        return length * width;
    }
};


class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double calculateArea() const override {
        return 0.5 * base * height;
    }
};

int main() {
    Circle circle(5);
    Rectangle rectangle(4, 6);
    Triangle triangle(3, 8);

    std::cout << "Area of the circle: " << circle.calculateArea() << std::endl;
    std::cout << "Area of the rectangle: " << rectangle.calculateArea() << std::endl;
    std::cout << "Area of the triangle: " << triangle.calculateArea() << std::endl;

    return 0;
}
