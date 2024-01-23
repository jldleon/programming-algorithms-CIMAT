/* Tarea 3. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 7. In­heri­t­an­ce:

Cre­ate a class named Ve­hi­cle and de­rive Car and Bike class­es from it.

Add spe­cif­ic mem­bers to Ve­hi­cle, Car, and Bike to demon­strate in­her­i-
tance.
************************************************/

#include <iostream>
#include <string>

// Base class: Vehicle
class Vehicle {
protected:
    std::string brand;

public:
    // Constructor for Vehicle
    Vehicle(const std::string& brand) : brand(brand) {}

    // Member function to display vehicle information
    void displayInfo() const {
        std::cout << "Brand: " << brand << std::endl;
    }
};

// Derived class: Car
class Car : public Vehicle {
private:
    int numDoors;

public:
    // Constructor for Car
    Car(const std::string& brand, int doors) : Vehicle(brand), numDoors(doors) {}

    // Member function to display car information
    void displayCarInfo() const {
        displayInfo();
        std::cout << "Type: Car" << std::endl;
        std::cout << "Number of Doors: " << numDoors << std::endl;
    }
};

// Derived class: Bike
class Bike : public Vehicle {
private:
    bool hasBasket;

public:
    // Constructor for Bike
    Bike(const std::string& brand, bool basket) : Vehicle(brand), hasBasket(basket) {}

    // Member function to display bike information
    void displayBikeInfo() const {
        displayInfo();
        std::cout << "Type: Bike" << std::endl;
        std::cout << "Has Basket: " << (hasBasket ? "Yes" : "No") << std::endl;
    }
};

int main() {
    // Creating objects of Car and Bike
    Car myCar("Toyota", 4);
    Bike myBike("Schwinn", true);

    // Displaying information using member functions of the derived classes
    std::cout << "Car Information:" << std::endl;
    myCar.displayCarInfo();

    std::cout << "\nBike Information:" << std::endl;
    myBike.displayBikeInfo();

    return 0;
}
