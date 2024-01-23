/* Tarea 4. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 6. Norms and Normalization

- Create a random vector of size 5.
- Compute its Euclidean (L2) norm.
- Normalize the vector.
************************************************/

#include <iostream>
#include "Eigen/Dense"

int main() {
    // Create a random vector of size 5
    Eigen::VectorXd randomVector = Eigen::VectorXd::Random(5);

    // Compute its Euclidean (L2) norm
    double euclideanNorm = randomVector.norm();

    // Normalize the vector
    Eigen::VectorXd normalizedVector = randomVector / euclideanNorm;

    std::cout << "Random Vector:\n" << randomVector << "\n\n";
    std::cout << "Euclidean (L2) Norm: " << euclideanNorm << "\n\n";
    std::cout << "Normalized Vector:\n" << normalizedVector << std::endl;

    return 0;
}
