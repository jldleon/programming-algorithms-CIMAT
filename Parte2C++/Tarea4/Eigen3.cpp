/* Tarea 4. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 3. Eigenvalues and Eigenvectors

- Create a symmetric 3x3 matrix.
- Compute its eigenvalues and eigenvectors.
************************************************/

#include <iostream>
#include "Eigen/Dense"

int main() {
    // Create a symmetric 3x3 matrix
    Eigen::MatrixXd symmetricMatrix(3, 3);
    symmetricMatrix << 1, 2, 3,
                       2, 4, 5,
                       3, 5, 6;

    // Compute eigenvalues and eigenvectors
    Eigen::EigenSolver<Eigen::MatrixXd> solver(symmetricMatrix);
    Eigen::VectorXd eigenvalues = solver.eigenvalues().real();  // Eigenvalues
    Eigen::MatrixXd eigenvectors = solver.eigenvectors().real();  // Eigenvectors

    // Output the eigenvalues and eigenvectors
    std::cout << "Eigenvalues:\n" << eigenvalues << "\n\n";
    std::cout << "Eigenvectors:\n" << eigenvectors << std::endl;

    return 0;
}
