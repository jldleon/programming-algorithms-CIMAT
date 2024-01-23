/* Tarea 3. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 3. Des­truc­tor:

- De­fine a de­struc­tor for the Car class that out­puts a mes­sage in­di­cat­ing that
a car ob­ject is be­ing de­stroyed.
************************************************/

#include <iostream>
#include <string>

class Car {
private:
    std::string make;  // Private data member for make
    std::string model; // Private data member for model
    int year;          // Private data member for year

public:
    // Default constructor
    Car() : make(""), model(""), year(0) {}

    // Parameterized constructor
    Car(const std::string& make, const std::string& model, int year)
        : make(make), model(model), year(year) {}

    // Destructor
    ~Car() {
        std::cout << "A car object is being destroyed." << std::endl;
    }

    // Public member functions to get and set the values (unchanged from previous example)
    std::string getMake() const {
        return make;
    }

    std::string getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }

    void setMake(const std::string& newMake) {
        make = newMake;
    }

    void setModel(const std::string& newModel) {
        model = newModel;
    }

    void setYear(int newYear) {
        year = newYear;
    }
};

int main() {
    // Creating a Car object using the default constructor
    Car defaultCar;

    // Output will include the message from the destructor when defaultCar goes out of scope
    return 0;
}
