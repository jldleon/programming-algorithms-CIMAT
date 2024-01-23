/* Tarea 4. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 8. Dynamic Size Matrix Operations

- Create a matrix and a vector of dynamic size, initialize them with some values.
- Perform multiplication of the matrix and the vector.
************************************************/

#include <iostream>
#include "Eigen/Dense"

int main() {
    // Create a dynamic-size matrix and vector
    Eigen::MatrixXd dynamicMatrix;
    Eigen::VectorXd dynamicVector;

    // Initialize the matrix and vector with values
    dynamicMatrix.resize(3, 3);
    dynamicMatrix << 1, 2, 3,
                     4, 5, 6,
                     7, 8, 9;

    dynamicVector.resize(3);
    dynamicVector << 1, 2, 3;

    // Perform matrix-vector multiplication
    Eigen::VectorXd result = dynamicMatrix * dynamicVector;

    std::cout << "Matrix:\n" << dynamicMatrix << "\n\n";
    std::cout << "Vector:\n" << dynamicVector << "\n\n";
    std::cout << "Result of Matrix-Vector Multiplication:\n" << result << std::endl;

    return 0;
}
