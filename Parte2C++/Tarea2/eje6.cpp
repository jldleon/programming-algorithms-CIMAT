/* Tarea 2. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 6. Ma­ne­ja­dor de Con­tac­tos:

- Crea un pro­gra­ma que per­mi­ta al usua­rio agre­gar, eli­mi­nar, bus­car y lis­tar
con­tac­tos, al­ma­ce­nan­do la in­for­ma­ción en un ar­chi­vo.
************************************************/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Definición de la clase Contacto
class Contacto {
    string nombre;
    string telefono;
    string email;

public:
    Contacto(string nombre, string telefono, string email) : nombre(nombre), telefono(telefono), email(email) {}

    string getNombre() const {
        return nombre;
    }

    string getTelefono() const {
        return telefono;
    }

    string getEmail() const {
        return email;
    }
};

// Definición de la clase LibretaDeContactos
class LibretaDeContactos {
    vector<Contacto> contactos;
    string fileName;

    void saveToFile() {
        ofstream file(fileName);
        if (file.is_open()) {
            for (const auto &contacto : contactos) {
                file << contacto.getNombre() << " " << contacto.getTelefono() << " " << contacto.getEmail() << "\n";
            }
            file.close();
        } else {
            cout << "No se pudo abrir el archivo para guardar." << endl;
        }
    }

public:
    LibretaDeContactos(string fileName) : fileName(fileName) {}

    void agregarContacto(const Contacto &contacto) {
        contactos.push_back(contacto);
        saveToFile();
    }

    void eliminarContacto(const string &nombre) {
        for (auto it = contactos.begin(); it != contactos.end(); ++it) {
            if (it->getNombre() == nombre) {
                contactos.erase(it);
                saveToFile();
                return;
            }
        }
        cout << "No se encontró el contacto." << endl;
    }

    Contacto buscarContacto(const string &nombre) {
        for (const auto &contacto : contactos) {
            if (contacto.getNombre() == nombre) {
                return contacto;
            }
        }
        throw runtime_error("Contacto no encontrado");
    }

    void listarContactos() const {
        for (const auto &contacto : contactos) {
            cout << "Nombre: " << contacto.getNombre() << ", Teléfono: " << contacto.getTelefono() << ", Email: " << contacto.getEmail() << endl;
        }
    }
};

int main() {
    LibretaDeContactos libreta("contactos.txt");
    int choice;
    string nombre, telefono, email;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Agregar contacto" << endl;
        cout << "2. Eliminar contacto" << endl;
        cout << "3. Buscar contacto" << endl;
        cout << "4. Listar contactos" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese su elección: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Ingrese nombre, teléfono y email separados por espacios: ";
                cin >> nombre >> telefono >> email;
                libreta.agregarContacto(Contacto(nombre, telefono, email));
                break;
            case 2:
                cout << "Ingrese el nombre del contacto a eliminar: ";
                cin >> nombre;
                libreta.eliminarContacto(nombre);
                break;
            case 3:
                cout << "Ingrese el nombre del contacto a buscar: ";
                cin >> nombre;
                try {
                    Contacto contacto = libreta.buscarContacto(nombre);
                    cout << "Contacto encontrado: Nombre: " << contacto.getNombre() << ", Teléfono: " << contacto.getTelefono() << ", Email: " << contacto.getEmail() << endl;
                } catch (const runtime_error &e) {
                    cout << e.what() << endl;
                }
                break;
            case 4:
                libreta.listarContactos();
                break;
            case 5:
                return 0;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    }

    return 0;
}
