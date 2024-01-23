/* Tarea 4. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 10. Advanced: Sparse Matrices

- Create a sparse matrix of size 100x100 with very few non-zero elements.
- Perform a matrix-vector multiplication with a dense vector.
- Convert the sparse matrix to a dense format and perform the same operation, comparing
the time taken for each.
************************************************/

#include <iostream>
#include "Eigen/Dense"
#include "Eigen/Sparse"
#include <chrono>

int main() {
    // Create a sparse matrix of size 100x100 with very few non-zero elements
    Eigen::SparseMatrix<double> sparseMatrix(100, 100);

    // Assign some random non-zero values to the sparse matrix
    for (int i = 0; i < 100; ++i) {
        sparseMatrix.insert(i, i) = 1.0;  // Assign 1.0 to diagonal elements
        sparseMatrix.insert(i, (i + 1) % 100) = 0.5;  // Assign 0.5 to off-diagonal elements
    }

    // Finalize the sparse matrix
    sparseMatrix.makeCompressed();

    // Create a dense vector for matrix-vector multiplication
    Eigen::VectorXd denseVector = Eigen::VectorXd::Random(100);

    // Measure the time taken for sparse matrix-vector multiplication
    auto startSparse = std::chrono::high_resolution_clock::now();
    Eigen::VectorXd resultSparse = sparseMatrix * denseVector;
    auto endSparse = std::chrono::high_resolution_clock::now();
    auto durationSparse = std::chrono::duration_cast<std::chrono::microseconds>(endSparse - startSparse);

    // Convert the sparse matrix to a dense format
    Eigen::MatrixXd denseMatrix = sparseMatrix;

    // Measure the time taken for dense matrix-vector multiplication
    auto startDense = std::chrono::high_resolution_clock::now();
    Eigen::VectorXd resultDense = denseMatrix * denseVector;
    auto endDense = std::chrono::high_resolution_clock::now();
    auto durationDense = std::chrono::duration_cast<std::chrono::microseconds>(endDense - startDense);

    // Compare the results
    std::cout << "Time taken for Sparse Matrix-Vector Multiplication: " << durationSparse.count() << " microseconds\n";
    std::cout << "Time taken for Dense Matrix-Vector Multiplication: " << durationDense.count() << " microseconds\n";

    return 0;
}
