/* Tarea 4. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 4. Custom Comparator for Sorting

Objective: Understand custom comparators and lambda expressions.

- Define a std::vector<std::pair<int, std::string>>. Each pair consists of a number
and a string.
- Sort this vector based on the string length. If lengths are equal, sort by the number.
- Implement this using both a custom function and a lambda function.
************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

// Custom comparison function
bool customCompare(const std::pair<int, std::string>& lhs, const std::pair<int, std::string>& rhs) {
    // Compare by string length
    if (lhs.second.length() < rhs.second.length()) {
        return true;
    } else if (lhs.second.length() > rhs.second.length()) {
        return false;
    }

    // If string lengths are equal, compare by number
    return lhs.first < rhs.first;
}

int main() {
    // Define the vector of pairs
    std::vector<std::pair<int, std::string>> vec1 = {
        {2, "apple"},
        {1, "banana"},
        {3, "orange"},
        {2, "grape"},
        {1, "kiwi"}
    };

    std::cout << "Original Vector :\n";
    for (const auto& pair : vec1) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::vector<std::pair<int, std::string>> vec2 = vec1;

    // Sort the vector using the custom comparison function
    std::sort(vec1.begin(), vec1.end(), customCompare);

    std::cout << "\nSorted Vector (Custom Function):\n";
    for (const auto& pair : vec1) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Sort the vector using a lambda function
    std::sort(vec2.begin(), vec2.end(), [](const auto& lhs, const auto& rhs) {
        // Compare by string length
        if (lhs.second.length() < rhs.second.length()) {
            return true;
        } else if (lhs.second.length() > rhs.second.length()) {
            return false;
        }

        // If string lengths are equal, compare by number
        return lhs.first < rhs.first;
    });

    // Display the sorted vector using a lambda function
    std::cout << "\nSorted Vector (Lambda Function):\n";
    for (const auto& pair : vec2) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
