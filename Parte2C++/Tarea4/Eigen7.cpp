/* Tarea 4. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 7. Block Operations

- Create a 5x5 matrix.
- Extract a 3x3 block from this matrix.
- Replace a 2x2 block in the matrix with the identity matrix.
************************************************/

#include <iostream>
#include "Eigen/Dense"

int main() {
    // Create a 5x5 matrix
    Eigen::MatrixXd matrix(5, 5);
    matrix << 1, 2, 3, 4, 5,
              6, 7, 8, 9, 10,
              11, 12, 13, 14, 15,
              16, 17, 18, 19, 20,
              21, 22, 23, 24, 25;

    // Extract a 3x3 block from the matrix
    Eigen::MatrixXd block = matrix.block(1, 1, 3, 3);

    // Replace a 2x2 block with the identity matrix
    matrix.block(2, 2, 2, 2) = Eigen::MatrixXd::Identity(2, 2);

    std::cout << "Original Matrix:\n" << matrix << "\n\n";
    std::cout << "Extracted 3x3 Block:\n" << block << "\n\n";
    std::cout << "Modified Matrix:\n" << matrix << std::endl;

    return 0;
}
