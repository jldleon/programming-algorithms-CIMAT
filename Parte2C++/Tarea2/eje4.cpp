/* Tarea 2. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 4. Si­mu­la­dor de Sis­te­ma de Ar­chi­vos:

- Crea un pro­gra­ma que si­mu­le un sis­te­ma de ar­chi­vos bá­si­co, per­mi­tien­do
al usua­rio crear, eli­mi­nar y lis­tar ar­chi­vos.
************************************************/
#include <iostream>
#include <vector>
#include <string>

class FileSystem {
private:
    std::vector<std::string> files;

public:
    void createFile(const std::string &filename) {
        files.push_back(filename);
        std::cout << "Archivo '" << filename << "' creado con éxito." << std::endl;
    }

    void deleteFile(const std::string &filename) {
        bool found = false;
        for (auto it = files.begin(); it != files.end(); ++it) {
            if (*it == filename) {
                it = files.erase(it);
                found = true;
                std::cout << "Archivo '" << filename << "' eliminado con éxito." << std::endl;
                break;
            }
        }
        if (!found) {
            std::cerr << "Archivo '" << filename << "' no encontrado." << std::endl;
        }
    }

    void listFiles() {
        if (files.empty()) {
            std::cout << "No hay archivos en el sistema." << std::endl;
        } else {
            std::cout << "Archivos en el sistema:" << std::endl;
            for (const auto &file : files) {
                std::cout << "- " << file << std::endl;
            }
        }
    }
};

int main() {
    FileSystem fs;
    int choice;
    std::string filename;

    do {
        std::cout << "\n1. Crear archivo\n2. Eliminar archivo\n3. Listar archivos\n4. Salir\nElija una opción: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Ingrese el nombre del archivo a crear: ";
                std::cin >> filename;
                fs.createFile(filename);
                break;
            case 2:
                std::cout << "Ingrese el nombre del archivo a eliminar: ";
                std::cin >> filename;
                fs.deleteFile(filename);
                break;
            case 3:
                fs.listFiles();
                break;
            case 4:
                std::cout << "Saliendo del programa." << std::endl;
                break;
            default:
                std::cerr << "Opción no válida. Inténtelo de nuevo." << std::endl;
                break;
        }

    } while (choice != 4);

    return 0;
}
