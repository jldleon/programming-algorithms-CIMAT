/* Tarea 4. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 1. Vector Manipulation

Objective: Practice using vectors and understand dynamic array concepts.

- Create a std::vector<int> and initialize it with some values.
- Write a function to print the vector.
- Add some values to the end of the vector.
- Remove a few elements from the middle of the vector.
- Find a value in the vector using std::find.
************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>

void printVector(const std::vector<T>& vec) {
    std::cout<< "[" ;

    for (const T& elemento : vec) {
        std::cout<< elemento << " ";
    }

    std::cout<< "] \n";

}

int main() {
    // Create a vector
    std::vector<int> vec = {1, 2, 3, 4, 5};

    //Add some values to the end of the vector
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    //print vector
    printVector(vec);

    //Remove a few elements from the middle of the vector.
    std::size_t n = vec.size();
    n = n / 2;

    auto startIt = vec.begin() + n - 1;
    auto endIt = vec.begin() + n + 1;
    vec.erase(startIt, endIt);

    printVector(vec);

    //Find a value in the vector using
    int targetValue = 30;

    // Use std::find to find the target value in the vector
    auto it = std::find(vec.begin(), vec.end(), targetValue);

    // Check if the value was found
    if (it != vec.end()) {
        std::cout << "Value " << targetValue << " found at index " << std::distance(vec.begin(), it) << std::endl;
    } else {
        std::cout << "Value " << targetValue << " not found in the vector" << std::endl;
    }


    return 0;
}
