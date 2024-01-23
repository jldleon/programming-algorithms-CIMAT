/* Tarea 3. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 8. Vir­tu­al Func­tion:

- De­fine a vir­tu­al func­tion in the Ve­hi­cle class named fu­el­Ef­fi­cien­cy
and over­ride it in the Car and Bike class­es to re­turn dif­fer­ent val­ues.
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

    // Virtual function for fuel efficiency
    virtual double fuelEfficiency() const {
        return 0.0;  // Default implementation for the base class
    }

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

    // Override the virtual function for fuel efficiency
    double fuelEfficiency() const override {
        // A specific implementation for cars (in miles per gallon)
        return 30.5;
    }

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

    // Override the virtual function for fuel efficiency
    double fuelEfficiency() const override {
        // A specific implementation for bikes (in miles per gallon)
        return 40.0;
    }

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

    // Displaying fuel efficiency using the virtual function
    std::cout << "Fuel Efficiency of Car: " << myCar.fuelEfficiency() << " mpg" << std::endl;
    std::cout << "Fuel Efficiency of Bike: " << myBike.fuelEfficiency() << " mpg" << std::endl;

    return 0;
}
