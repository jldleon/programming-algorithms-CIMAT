/* Tarea 4. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 4. Solving Linear Systems

- Create a 3x3 matrix ( A ) and a 3x1 vector ( b ).
- Solve the linear system ( Ax = b ).
************************************************/

#include <iostream>
#include "Eigen/Dense"

int main() {
    // Create a 3x3 matrix A
    Eigen::MatrixXd A(3, 3);
    A << 2, -1, 0,
         -1, 2, -1,
         0, -1, 2;

    // Create a 3x1 vector b
    Eigen::VectorXd b(3);
    b << 1, -2, 1;

    // Solve the linear system Ax = b
    Eigen::VectorXd x = A.lu().solve(b);

    std::cout << "Matrix A:\n" << A << "\n\n";
    std::cout << "Vector b:\n" << b << "\n\n";
    std::cout << "Solution x:\n" << x << std::endl;

    return 0;
}
