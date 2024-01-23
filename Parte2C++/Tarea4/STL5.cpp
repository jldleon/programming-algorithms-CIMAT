/* Tarea 4. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 5. Stream Iterators and Copy Algorithm

Objective: Practice using stream iterators and algorithms together.

- Read integers from standard input using std::istream_iterator.
- Copy these integers to a std::vector<int> using std::copy.
- Sort the vector.
- Then, using std::ostream_iterator, write the sorted integers to the standard output.
************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    std::cout<< "Ingresa los valores enteros, al terminar presiona Ctrl + D: \n";
    // Read integers from standard input using std::istream_iterator
    std::istream_iterator<int> inputIterator(std::cin);
    std::istream_iterator<int> endIterator;

    // Copy these integers to a std::vector<int> using std::copy
    std::vector<int> myVector;
    std::copy(inputIterator, endIterator, std::back_inserter(myVector));

    // Sort the vector
    std::sort(myVector.begin(), myVector.end());

    // Write the sorted integers to standard output using std::ostream_iterator
    std::ostream_iterator<int> outputIterator(std::cout, " ");
    std::copy(myVector.begin(), myVector.end(), outputIterator);

    return 0;
}
