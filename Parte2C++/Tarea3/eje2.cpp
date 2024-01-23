/* Tarea 3. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 2. Con­struc­tor Over­load­ing:

- Ex­tend the Car class by pro­vid­ing mul­ti­ple con­struc­tors to ini­tial­ize the car
ob­ject in dif­fer­ent ways (de­fault con­struc­tor, pa­ra­me­ter­ized con­struc­tor,
etc.).
************************************************/

#include <iostream>
#include <string>

class Car {
private:
    std::string make;
    std::string model;
    int year;

public:
    Car() : make(""), model(""), year(0) {}  //Valores por default

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
    Car defaultCar;
    std::cout << "Default Car Values:" << std::endl;
    std::cout << "Make: " << defaultCar.getMake() << std::endl;
    std::cout << "Model: " << defaultCar.getModel() << std::endl;
    std::cout << "Year: " << defaultCar.getYear() << std::endl;


    Car paramCar("Ford", "Mustang", 2021);
    std::cout << "\nParameterized Car Values:" << std::endl;
    std::cout << "Make: " << paramCar.getMake() << std::endl;
    std::cout << "Model: " << paramCar.getModel() << std::endl;
    std::cout << "Year: " << paramCar.getYear() << std::endl;

    return 0;
}
