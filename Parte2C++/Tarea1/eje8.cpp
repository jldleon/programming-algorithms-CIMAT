/* Tarea 1. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 8. Poly­mor­phism:
Ex­tend the pro­gram from ex­er­cise 7 to in­clude a func­tion that takes a point­er to the
base class, and uses poly­mor­phism to call the cor­rect area cal­cu­la­tion method for dif-
fer­ent de­rived class ob­jects.

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

void printArea(const Shape* shape);

int main() {
    Circle circle(5);
    Rectangle rectangle(4, 6);
    Triangle triangle(3, 8);

    printArea(&circle);
    printArea(&rectangle);
    printArea(&triangle);

    return 0;
}

void printArea(const Shape* shape) {
    std::cout << "Area: " << shape->calculateArea() << std::endl;
}
