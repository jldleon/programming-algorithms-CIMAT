/* Tarea 5. Programación y algoritmos.
    Parte 1. Lenguaje C.

                José Luis de León Carmona.

Ejercicion 3. Aplicaciones de árboles binarios (Código de Huffman): Leer el archivo de entrada “Don-
Quijote-Ingles.txt (2.3MB)” y calcular el árbol del Huffman, compresión esperada y

código de compresión de cada una de las letras del alfabeto (no hacer distinción entre
mayúsculas y minúsculas).
Huffman Coding:
• Huffman Coding is a Greedy Algorithm that uses the frequency or probability of
characters for generating codes. A greedy algorithm is an approach for solving a
problem by selecting the best option available at the moment. It doesn't worry
whether the current best result will bring the overall optimal result.
• Here, we use the frequency of characters to create a Huffman tree and find out the
Huffman code for each character in the given string CONNECTION.
• It allows a Lossless Compression of data.
• It generates variable-length codes for all the different characters.
• To do this it uses variable-length encoding.
• This process is called as Huffman Encoding.
• The Time Complexity of Huffman Coding becomes O(NlogN), where N is the number
of unique characters in the given string.
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

// Estructura para un nodo del árbol de Huffman
typedef struct NodoHuffman {
    char caracter;
    int frecuencia;
    struct NodoHuffman *izquierdo;
    struct NodoHuffman *derecho;
} NodoHuffman;

NodoHuffman *crearNodoHuffman(char caracter, int frecuencia);

int compararNodosHuffman(const void *a, const void *b);

NodoHuffman *construirArbolHuffman(int frecuencias[26]);

void imprimirCodigosHuffman(NodoHuffman *raiz, int codigo[], int top);

void liberarArbolHuffman(NodoHuffman *raiz);

int main() {
    // Frecuencias de las letras del alfabeto (asumimos solo letras minúsculas)
    int frecuencias[26] = {0};

    FILE* file = fopen("Don-Quijote-Ingles.txt", "r");

    if (file == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }



    // Contar las frecuencias de las letras en el archivo
    int c;
    while ((c = fgetc(file)) != EOF) {
        if ((c >= 'a' && c <= 'z')) {
            frecuencias[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') { //Incluir mayusculas
            frecuencias[c - 'A']++;
        }
    }

    // Construir el árbol de Huffman
    NodoHuffman *raiz = construirArbolHuffman(frecuencias);

    // Arreglo para almacenar los códigos de compresión
    int codigo[100];
    int top = 0;

    // Imprimir los códigos de compresión
    printf("Códigos de compresión:\n");
    imprimirCodigosHuffman(raiz, codigo, top);

    // Calcular la compresión esperada


    // Liberar la memoria utilizada por el árbol de Huffman
    liberarArbolHuffman(raiz);

    return 0;
}

// Función para crear un nuevo nodo del árbol de Huffman
NodoHuffman *crearNodoHuffman(char caracter, int frecuencia) {
    NodoHuffman *nodo = (NodoHuffman *)malloc(sizeof(NodoHuffman));
    nodo->caracter = caracter;
    nodo->frecuencia = frecuencia;
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;
    return nodo;
}

// Función para comparar dos nodos de Huffman
int compararNodosHuffman(const void *a, const void *b) {
    NodoHuffman *nodoA = *(NodoHuffman **)a;
    NodoHuffman *nodoB = *(NodoHuffman **)b;
    return (nodoA->frecuencia - nodoB->frecuencia);
}

// Función para construir el árbol de Huffman
NodoHuffman *construirArbolHuffman(int frecuencias[26]) {
    int i;
    NodoHuffman *nodo;

    // Crear nodos para cada letra con frecuencia mayor que 0
    NodoHuffman *nodos[26];
    int numNodos = 0;
    for (i = 0; i < 26; i++) {
        if (frecuencias[i] > 0) {
            nodos[numNodos++] = crearNodoHuffman('a' + i, frecuencias[i]);
        }
    }

    // Construir el árbol de Huffman
    while (numNodos > 1) {
        // Ordenar los nodos por frecuencia
        qsort(nodos, numNodos, sizeof(NodoHuffman *), compararNodosHuffman);

        // Crear un nuevo nodo interno con los dos nodos de menor frecuencia
        nodo = crearNodoHuffman('$', nodos[0]->frecuencia + nodos[1]->frecuencia);
        nodo->izquierdo = nodos[0];
        nodo->derecho = nodos[1];

        // Eliminar los dos nodos de menor frecuencia y agregar el nuevo nodo
        nodos[0] = nodo;
        nodos[1] = nodos[numNodos - 1];
        numNodos--;
    }

    return nodos[0]; // Devolver el nodo raíz del árbol de Huffman
}

// Función para imprimir los códigos de compresión
void imprimirCodigosHuffman(NodoHuffman *raiz, int codigo[], int top) {
    // Si el nodo es una hoja, imprime el carácter y el código
    if (raiz->izquierdo == NULL && raiz->derecho == NULL) {
        printf("Caracter: %c, Código: ", raiz->caracter);
        for (int i = 0; i < top; i++) {
            printf("%d", codigo[i]);
        }
        printf("\n");
    }

    // Recorrer hacia la izquierda (0) y hacia la derecha (1)
    if (raiz->izquierdo) {
        codigo[top] = 0;
        imprimirCodigosHuffman(raiz->izquierdo, codigo, top + 1);
    }
    if (raiz->derecho) {
        codigo[top] = 1;
        imprimirCodigosHuffman(raiz->derecho, codigo, top + 1);
    }
}

void liberarArbolHuffman(NodoHuffman *raiz) {
    if (raiz == NULL) {
        return;
    }

    // Recursivamente liberar la memoria de los nodos izquierdo y derecho
    liberarArbolHuffman(raiz->izquierdo);
    liberarArbolHuffman(raiz->derecho);

    // Liberar el nodo actual
    free(raiz);
}


