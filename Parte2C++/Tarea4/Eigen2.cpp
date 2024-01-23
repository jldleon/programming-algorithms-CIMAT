/* Tarea 4. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 2. Matrix Inversion and Determinant

- Create a 4x4 matrix.
- Compute its determinant.
- If it is invertible (non-zero determinant), compute its inverse.
************************************************/

#include <iostream>
#include "Eigen/Dense"

int main() {
    // Create a 4x4 matrix
    Eigen::MatrixXd matrix(4, 4);
    matrix << 1, 20, 3, 4,
              5, 3, 7, 8,
              9, 1, 1, 12,
              13, 15, 0, 0;

    // Compute the determinant
    double determinant = matrix.determinant();
    std::cout << "Determinant: " << determinant << std::endl;

    // Check if the matrix is invertible (non-zero determinant)
    if (determinant != 0) {
        // Compute the inverse
        Eigen::MatrixXd inverse = matrix.inverse();

        std::cout << "Original Matrix:\n" << matrix << "\n\n";
        std::cout << "Inverse Matrix:\n" << inverse << std::endl;
    } else {
        std::cout << "The matrix is not invertible (zero determinant)." << std::endl;
    }

    return 0;
}
