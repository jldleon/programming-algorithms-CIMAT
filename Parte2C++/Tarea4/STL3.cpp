/* Tarea 4. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 3. Using Algorithms

Objective: Learn to use the algorithm library for common operations.

- Create a std::vector<int> and fill it with random numbers.
- Sort the vector using std::sort.
- Find the largest and smallest elements using std::min_element and std::max_element.
- Shuffle the elements using std::random_shuffle (or std::shuffle with a random engine
if C++11 or later).
************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

template <typename T>

void printVector(const std::vector<T>& vec) {
    std::cout<< "[" ;

    for (const T& elemento : vec) {
        std::cout<< elemento << " ";
    }

    std::cout<< "] \n";

}

int main() {
    // Create a vector and fill it with random numbers
    std::vector<int> vec;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < 10; ++i) {
        vec.push_back(std::rand() % 100 + 1);
    }

    // Display the original vector
    std::cout << "Original Vector: ";
    printVector(vec);

    // Sort the vector using std::sort
    std::sort(vec.begin(), vec.end());

    std::cout << "Sorted Vector: ";
    printVector(vec);

    //Find the largest and smallest elements
    auto minElement = std::min_element(vec.begin(), vec.end());
    auto maxElement = std::max_element(vec.begin(), vec.end());

    std::cout << "Smallest Element: " << *minElement << std::endl;
    std::cout << "Largest Element: " << *maxElement << std::endl;

    //Shuffle the elements
    std::random_shuffle(vec.begin(), vec.end());

    std::cout << "Shuffled Vector: ";
    printVector(vec);

    return 0;
}
