/* Tarea 3. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 1. Ba­sic Class De­f­i­n­i­tion:

Cre­ate a class named Car with pri­vate data mem­bers for make, mod­el, and
year. Pro­vide pub­lic mem­ber func­tions to get and set the val­ues of these
data mem­bers.
************************************************/

#include <iostream>
#include <string>

class Car {
private:
    std::string make;
    std::string model;
    int year;

public:
    Car(const std::string& make, const std::string& model, int year)
        : make(make), model(model), year(year) {}

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
    Car myCar("Toyota", "Camry", 2022);

    std::cout << "Make: " << myCar.getMake() << std::endl;
    std::cout << "Model: " << myCar.getModel() << std::endl;
    std::cout << "Year: " << myCar.getYear() << std::endl;

    myCar.setMake("Honda");
    myCar.setModel("Accord");
    myCar.setYear(2023);

    std::cout << "\nUpdated Values:" << std::endl;
    std::cout << "Make: " << myCar.getMake() << std::endl;
    std::cout << "Model: " << myCar.getModel() << std::endl;
    std::cout << "Year: " << myCar.getYear() << std::endl;

    return 0;
}

