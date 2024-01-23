
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tamaño de la tabla hash
#define TAMANO_TABLA 10

// Estructura para los elementos en la tabla hash
struct Elemento {
    char clave[50];
    int valor;
    struct Elemento* siguiente;
};

// Estructura para la tabla hash
struct TablaHash {
    struct Elemento* tabla[TAMANO_TABLA];
};

// Función de hashing
int funcionHash(const char* clave);

struct Elemento* crearElemento(const char* clave, int valor);

void insertarElemento(struct TablaHash* tabla, const char* clave, int valor);

int buscarElemento(struct TablaHash* tabla, const char* clave);

int main() {
    struct TablaHash tabla;
    for (int i = 0; i < TAMANO_TABLA; i++) {
        tabla.tabla[i] = NULL;
    }

    // Insertar elementos en la tabla hash
    insertarElemento(&tabla, "nombre", 42);
    insertarElemento(&tabla, "edad", 25);
    insertarElemento(&tabla, "puntuacion", 98);

    // Realizar búsquedas en la tabla hash
    printf("Valor de 'nombre': %d\n", buscarElemento(&tabla, "nombre"));
    printf("Valor de 'edad': %d\n", buscarElemento(&tabla, "edad"));
    printf("Valor de 'puntuacion': %d\n", buscarElemento(&tabla, "puntuacion"));
    printf("Valor de 'no_existe': %d\n", buscarElemento(&tabla, "no_existe"));

    // Liberar memoria (puedes añadir esta parte al final de tu programa)
    for (int i = 0; i < TAMANO_TABLA; i++) {
        struct Elemento* actual = tabla.tabla[i];
        while (actual != NULL) {
            struct Elemento* siguiente = actual->siguiente;
            free(actual);
            actual = siguiente;
        }
    }

    return 0;
}

// Función de hashing
int funcionHash(const char* clave) {
    int suma = 0;
    for (int i = 0; clave[i] != '\0'; i++) {
        suma += clave[i];
    }
    return suma % TAMANO_TABLA;
}

// Función para crear un nuevo elemento
struct Elemento* crearElemento(const char* clave, int valor) {
    struct Elemento* nuevo = (struct Elemento*)malloc(sizeof(struct Elemento));
    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo elemento.\n");
        exit(1);
    }
    strcpy(nuevo->clave, clave);
    nuevo->valor = valor;
    nuevo->siguiente = NULL;
    return nuevo;
}

// Función para insertar un elemento en la tabla hash
void insertarElemento(struct TablaHash* tabla, const char* clave, int valor) {
    int indice = funcionHash(clave);
    struct Elemento* nuevo = crearElemento(clave, valor);

    // Insertar al principio de la lista (sin manejar colisiones)
    nuevo->siguiente = tabla->tabla[indice];
    tabla->tabla[indice] = nuevo;
}

// Función para buscar un elemento en la tabla hash
int buscarElemento(struct TablaHash* tabla, const char* clave) {
    int indice = funcionHash(clave);
    struct Elemento* actual = tabla->tabla[indice];

    while (actual != NULL) {
        if (strcmp(actual->clave, clave) == 0) {
            return actual->valor; // Se encontró la clave, se devuelve el valor asociado
        }
        actual = actual->siguiente;
    }

    return -1; // La clave no se encontró
}
