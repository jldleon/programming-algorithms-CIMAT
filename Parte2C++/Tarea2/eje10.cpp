/* Tarea 2. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 10. Si­mu­la­ción de Mon­te­car­lo:

Es­cri­be un pro­gra­ma que uti­li­ce la si­mu­la­ción de Mon­te­car­lo para
es­ti­mar el va­lor de π, pi­dien­do al usua­rio que es­pe­ci­fi­que el nú­me-
ro de "ti­ra­das" a si­mu­lar.
************************************************/

#include <iostream>
#include <random>

double estimar_pi(int num_tiradas) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(-1.0, 1.0);

    int puntos_dentro = 0;
    for (int i = 0; i < num_tiradas; i++) {
        double x = dis(gen);
        double y = dis(gen);
        if (x * x + y * y <= 1) {
            puntos_dentro++;
        }
    }

    return 4.0 * puntos_dentro / num_tiradas;
}

int main() {
    int num_tiradas;
    std::cout << "Ingrese el número de tiradas a simular: ";
    std::cin >> num_tiradas;

    double estimacion_pi = estimar_pi(num_tiradas);
    std::cout << "El valor estimado de pi es: " << estimacion_pi << std::endl;

    return 0;
}
