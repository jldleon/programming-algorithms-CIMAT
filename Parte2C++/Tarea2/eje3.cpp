/* Tarea 2. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 3. Or­de­na­mien­to de Da­tos:

- Pide al usua­rio que in­gre­se una lis­ta de nom­bres y eda­des, y lue­go or­de­na
y mues­tra la lis­ta pri­me­ro por edad y lue­go por nom­bre.
************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Person {
public:
    std::string name;
    int age;

    // Constructor
    Person(const std::string &n, int a) : name(n), age(a) {}

    // Comparación por edad
    static bool compareByAge(const Person &a, const Person &b) {
        return a.age < b.age;
    }

    // Comparación por nombre
    static bool compareByName(const Person &a, const Person &b) {
        return a.name < b.name;
    }
};

int main() {
    int n;
    std::cout << "Ingrese la cantidad de personas: ";
    std::cin >> n;
    std::cin.ignore(); // Para limpiar el buffer después de leer el entero

    std::vector<Person> people;
    std::string name;
    int age;

    for (int i = 0; i < n; i++) {
        std::cout << "Ingrese el nombre de la persona " << i + 1 << ": ";
        std::getline(std::cin, name);
        std::cout << "Ingrese la edad de la persona " << i + 1 << ": ";
        std::cin >> age;
        std::cin.ignore(); // Para limpiar el buffer después de leer el entero
        people.emplace_back(name, age);
    }

    // Ordenar por edad y luego por nombre
    std::sort(people.begin(), people.end(), Person::compareByAge);
    std::cout << "\nOrdenado por edad:" << std::endl;
    for (const auto &person : people) {
        std::cout << "Nombre: " << person.name << ", Edad: " << person.age << std::endl;
    }

    std::sort(people.begin(), people.end(), Person::compareByName);
    std::cout << "\nOrdenado por nombre:" << std::endl;
    for (const auto &person : people) {
        std::cout << "Nombre: " << person.name << ", Edad: " << person.age << std::endl;
    }

    return 0;
}
