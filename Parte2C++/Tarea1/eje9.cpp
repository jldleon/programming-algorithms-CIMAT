/* Tarea 1. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 9. File I/O:
Cre­ate a pro­gram that reads a file con­tain­ing a list of num­bers, cal­cu­lates the sum
and av­er­age of these num­bers, and writes the re­sults to a new file.
************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <fstream>
#include <vector>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile) {
        std::cerr << "Error opening the input file." << std::endl;
        return 1;
    }

    if (!outputFile) {
        std::cerr << "Error creating or opening the output file." << std::endl;
        return 1;
    }

    std::vector<int> numbers;
    int num;
    while (inputFile >> num) {
        numbers.push_back(num);
    }

    inputFile.close();

    int sum = 0;
    for (int n : numbers) {
        sum += n;
    }

    double average = static_cast<double>(sum) / numbers.size();

    outputFile << "Sum: " << sum << std::endl;
    outputFile << "Average: " << average << std::endl;

    outputFile.close();

    std::cout << "Results written to output.txt" << std::endl;

    return 0;
}
