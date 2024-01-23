/* Tarea 2. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 9. Bus­ca­dor de Pa­la­bras en Tex­to:

Pide al usua­rio que in­gre­se el nom­bre de un ar­chi­vo que con­tie­ne un tex­to
y una pa­la­bra, y lue­go en­cuen­tra y mues­tra to­das las ocu­rren­cias de la pa­la-
bra en el tex­to, jun­to con el nú­me­ro de lí­nea y po­si­ción.
************************************************/

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename, word;
    std::cout << "Ingrese el nombre del archivo: ";
    std::cin >> filename;
    std::cout << "Ingrese la palabra a buscar: ";
    std::cin >> word;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        int line_number = 1;
        while (std::getline(file, line)) {
            size_t pos = 0;
            while ((pos = line.find(word, pos)) != std::string::npos) {
                std::cout << "Palabra encontrada en la línea " << line_number << ", posición " << pos << std::endl;
                pos += word.length();
            }
            line_number++;
        }
        file.close();
    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
    return 0;
}
