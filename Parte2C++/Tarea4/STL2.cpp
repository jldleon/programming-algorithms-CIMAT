/* Tarea 4. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 2. Map Operations

Objective: Get familiar with associative containers.

- Create a std::map<std::string, int> that will store the number of occurrences of each
word in a text.
- Read words from the standard input and count their occurrences in the map.
- Print each word and its corresponding count.
************************************************/

#include <iostream>
#include <map>
#include <string>
#include <sstream>

int main() {
    // Create a map to store word occurrences
    std::map<std::string, int> wordOccurrences;

    // Input text
    std::string text = "this is a sample text, this text will be used to demonstrate word occurrences.";

    // Process the text and count word occurrences
    std::istringstream iss(text);
    std::string word;

    while (iss >> word) {
        wordOccurrences[word]++;
    }

    // Print the word occurrences
    std::cout << "Word Occurrences:\n";
    for (const auto& pair : wordOccurrences) {
        std::cout << pair.first << ": " << pair.second;
    }

    return 0;
}
