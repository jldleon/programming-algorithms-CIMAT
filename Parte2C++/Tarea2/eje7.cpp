/* Tarea 2. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 7. Ve­ri­fi­ca­dor de Pa­rén­te­sis:

- Pide al usua­rio que in­gre­se una ex­pre­sión y ve­ri­fi­ca si los pa­rén­te­sis, cor-
che­tes y lla­ves es­tán bien ba­lan­cea­dos.
************************************************/

#include <iostream>
#include <stack>
#include <string>

bool verificador_parentesis(const std::string &expresion) {
    std::stack<char> pila;
    std::string abiertos = "([{";
    std::string cerrados = ")]}";

    for (char c : expresion) {
        if (abiertos.find(c) != std::string::npos) {
            pila.push(c);
        } else if (cerrados.find(c) != std::string::npos) {
            if (pila.empty() || abiertos.find(pila.top()) != cerrados.find(c)) {
                return false;
            }
            pila.pop();
        }
    }

    return pila.empty();
}

int main() {
    std::string expresion;
    std::cout << "Ingresa una expresión: ";
    std::getline(std::cin, expresion);

    if (verificador_parentesis(expresion)) {
        std::cout << "Los paréntesis están balanceados." << std::endl;
    } else {
        std::cout << "Los paréntesis no están balanceados." << std::endl;
    }

    return 0;
}
