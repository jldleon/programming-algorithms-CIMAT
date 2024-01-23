/* Tarea 4. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 1. Basic Matrix Operations

- Create a 3x3 matrix and a 3x1 vector.
- Perform matrix-vector multiplication.
- Compute the transpose of the matrix.
************************************************/

#include <iostream>
#include "Eigen/Dense"

int main() {
        // Define a 3x3 matrix
    Eigen::Matrix3d matrix;
    matrix << 1, 2, 3,
              4, 5, 6,
              7, 8, 9;

    // Define a 3-dimensional vector
    Eigen::Vector3d vector(1, 2, 3);

    // Perform matrix-vector multiplication
    Eigen::Vector3d result = matrix * vector;

    // Calcular la traspuesta usando la función transpose()
    Eigen::Matrix3d traspuesta = matrix.transpose();

    // Output the result
    std::cout << "Matrix:\n" << matrix << "\n\n";
    std::cout << "Vector:\n" << vector << "\n\n";
    std::cout << "Result of matrix-vector multiplication:\n" << result << std::endl;
     std::cout << "Traspuesta:\n" << traspuesta << std::endl;

    return 0;
}
