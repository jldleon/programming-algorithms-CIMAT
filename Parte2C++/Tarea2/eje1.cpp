/* Tarea 2. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 1. Aná­li­sis de Tex­to:

- So­li­ci­ta al usua­rio que in­gre­se el nom­bre de un ar­chi­vo que con­tie­ne un
tex­to y lue­go ana­li­za el tex­to para con­tar el nú­me­ro de pa­la­bras, el nú­me­ro
de ca­rac­te­res y el nú­me­ro de ve­ces que apa­re­ce cada le­tra del al­fa­be­to.
************************************************/


#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>

int main() {
    std::string filename;
    std::cout << "Ingrese el nombre del archivo que contiene el texto: ";
    std::cin >> filename;

    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    std::string word;
    int wordCount = 0;
    int charCount = 0;
    std::map<char, int> letterCount;

    while (file >> word) {
        wordCount++;
        charCount += word.size();
        for (char c : word) {
            if (isalpha(c)) {
                c = tolower(c);
                letterCount[c]++;
            }
        }
    }

    std::cout << "Número de palabras: " << wordCount << std::endl;
    std::cout << "Número de caracteres: " << charCount << std::endl;
    std::cout << "Número de veces que aparece cada letra del alfabeto:" << std::endl;
    for (char c = 'a'; c <= 'z'; ++c) {
        std::cout << c << ": " << letterCount[c] << std::endl;
    }

    file.close();
    return 0;
}
