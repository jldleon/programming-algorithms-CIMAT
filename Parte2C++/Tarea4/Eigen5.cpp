/* Tarea 4. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 5. Matrix Decompositions

- Create a 3x3 matrix.
- Perform LU decomposition on this matrix and extract the L and U matrices.
************************************************/

#include <iostream>
#include "Eigen/Dense"

int main() {
    // Create a 3x3 matrix
    Eigen::MatrixXd A(3, 3);
    A << 2, -1, 0,
         -1, 2, -1,
         0, -1, 2;

    // Perform LU decomposition
    Eigen::PartialPivLU<Eigen::MatrixXd> lu_decomposition(A);

    // Extract the L and U matrices
    Eigen::MatrixXd L = lu_decomposition.matrixLU().triangularView<Eigen::StrictlyLower>();
    Eigen::MatrixXd U = lu_decomposition.matrixLU().triangularView<Eigen::Upper>();

    std::cout << "Original Matrix A:\n" << A << "\n\n";
    std::cout << "Lower Triangular Matrix L:\n" << L << "\n\n";
    std::cout << "Upper Triangular Matrix U:\n" << U << std::endl;

    return 0;
}
