/* Tarea 4. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 9. Vector-wise and Row-wise Operations

- Create a 3x3 matrix.
- Compute the sum and mean of each row.
- Normalize each column of the matrix.
************************************************/

#include <iostream>
#include "Eigen/Dense"

int main() {
    // Create a 3x3 matrix
    Eigen::MatrixXd matrix(3, 3);
    matrix << 1, 2, 3,
              4, 5, 6,
              7, 8, 9;

    // Compute the sum and mean of each row
    Eigen::VectorXd rowSum = matrix.rowwise().sum();
    Eigen::VectorXd rowMean = matrix.rowwise().mean();

    // Normalize each column of the matrix
    Eigen::MatrixXd normalizedMatrix = matrix.colwise().normalized();

    std::cout << "Original Matrix:\n" << matrix << "\n\n";
    std::cout << "Row Sum:\n" << rowSum << "\n\n";
    std::cout << "Row Mean:\n" << rowMean << "\n\n";
    std::cout << "Normalized Matrix (Column-wise):\n" << normalizedMatrix << std::endl;

    return 0;
}
