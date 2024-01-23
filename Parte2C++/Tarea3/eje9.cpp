/* Tarea 3. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 9. Pure Vir­tu­al Func­tion and Ab­stract Class:

Mod­i­fy the Ve­hi­cle class to have a pure vir­tu­al func­tion named num-
Wheels and im­ple­ment it in the Car and Bike class­es to re­turn the cor­rect
num­ber of wheels.
************************************************/

#include <iostream>
#include <string>

// Abstract Base class: Vehicle
class Vehicle {
protected:
    std::string brand;

public:
    // Constructor for Vehicle
    Vehicle(const std::string& brand) : brand(brand) {}

    // Pure virtual function for the number of wheels
    virtual int numWheels() const = 0;

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

    int numWheels() const override {
        return 4;
    }

    double fuelEfficiency() const override {
        return 25.0;
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


    int numWheels() const override {
        return 2;
    }


    double fuelEfficiency() const override {
        return 50.0;
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

    // Displaying information, fuel efficiency, and number of wheels for Car
    std::cout << "Car Information:" << std::endl;
    myCar.displayCarInfo();
    std::cout << "Fuel Efficiency of Car: " << myCar.fuelEfficiency() << " mpg" << std::endl;
    std::cout << "Number of Wheels of Car: " << myCar.numWheels() << std::endl;

    std::cout << "\n---------------------------------\n";

    // Displaying information, fuel efficiency, and number of wheels for Bike
    std::cout << "Bike Information:" << std::endl;
    myBike.displayBikeInfo();
    std::cout << "Fuel Efficiency of Bike: " << myBike.fuelEfficiency() << " mpg" << std::endl;
    std::cout << "Number of Wheels of Bike: " << myBike.numWheels() << std::endl;

    return 0;
}
