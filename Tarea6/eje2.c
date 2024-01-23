/* Tarea 6. Programacin y Algoritmos.
    Parte 1. Lenguaje C.

                José Luis de León Carmona.

Ejercicio 2. Programa que implemente una tabla de Hash modificada, para la almacenamiento y
búsqueda de números enteros*.

Una vez creada la Tabla con los correspondientes árboles binarios de búsqueda (en
orden), el programa debe desplegar el siguiente menú:
• Insertar Nodo (dar dato a insertar);
• Imprimir Tabla en orden (imprime toda la información en la tabla de Hash
recorriendo los árboles en orden);
• Desplegar el índice y árbol con mayor profundidad en la Tabla;

****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definición de la estructura de un nodo de árbol binario
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Estructura de un elemento de la tabla hash
struct HashTableItem {
    int key;
    struct TreeNode* tree;
};

// Definición de la estructura de la tabla hash
struct HashTable {
    int size;
    struct HashTableItem** table;
};


struct TreeNode* createNode(int data);

struct HashTable* createHashTable(int size);

struct TreeNode* insertNode(struct TreeNode* root, int data);

void insertHashTable(struct HashTable* table, int key, int data) ;

void inorderTraversal(struct TreeNode* root);

void printHashTable(struct HashTable* table);

void findMaxDepth(struct HashTable* table, int* maxIndex, int* maxDepth);

void inorderTraversalFromNode(struct TreeNode* root);

int calculateDepth(struct TreeNode* root);

int main() {
    srand(time(NULL));
    int size;
    printf("Ingrese el tamaño de la tabla hash: ");
    scanf("%d", &size);

    struct HashTable* table = createHashTable(size);

    // Llenar la tabla con datos aleatorios
    int numData = size*3;
    for (int i = 0; i < numData; i++) {
        int key = rand() % size;
        int data = rand() % 9 + 1;
        insertHashTable(table, key, data);
    }

    int option, key, data;
    int maxIndex, maxDepth;

    while (1) {
        printf("\nMenú:\n");
        printf("1. Insertar Nodo\n");
        printf("2. Imprimir Tabla en orden\n");
        printf("3. Desplegar el índice y árbol con mayor profundidad\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Ingrese la clave para insertar: ");
                scanf("%d", &key);
                printf("Ingrese el dato a insertar: ");
                scanf("%d", &data);
                insertHashTable(table, key, data);
                break;
            case 2:
                printf("\nTabla Hash en orden:\n");
                printHashTable(table);
                break;
            case 3:
                findMaxDepth(table, &maxIndex, &maxDepth);
                if (maxIndex != -1) {
                    printf("El índice con la mayor profundidad es %d y su profundidad es %d\n", maxIndex, maxDepth);
                    printf("Árbol correspondiente:\n");
                    inorderTraversalFromNode(table->table[maxIndex]->tree);
                    printf("\n");
                } else {
                    printf("La tabla está vacía.\n");
                }
                break;
            case 4:
                return 0;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    }

    return 0;
}
// Función para imprimir un árbol binario en orden desde un nodo dado
void inorderTraversalFromNode(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversalFromNode(root->left);
        printf("%d ", root->data);
        inorderTraversalFromNode(root->right);
    }
}

// Función para crear un nuevo nodo de árbol binario
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Función para crear una tabla hash
struct HashTable* createHashTable(int size) {
    struct HashTable* table = (struct HashTable*)malloc(sizeof(struct HashTable));
    table->size = size;
    table->table = (struct HashTableItem**)malloc(sizeof(struct HashTableItem*) * size);
    for (int i = 0; i < size; i++) {
        table->table[i] = NULL;
    }
    return table;
}

// Función para insertar un nodo en un árbol binario de búsqueda
struct TreeNode* insertNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Función para insertar un elemento en la tabla hash
void insertHashTable(struct HashTable* table, int key, int data) {
    int index = key % table->size;
    if (table->table[index] == NULL) {
        table->table[index] = (struct HashTableItem*)malloc(sizeof(struct HashTableItem));
        table->table[index]->key = key;
        table->table[index]->tree = createNode(data);
    } else {
        table->table[index]->tree = insertNode(table->table[index]->tree, data);
    }
}

// Función para imprimir un árbol binario en orden
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Función para imprimir la tabla hash en orden
void printHashTable(struct HashTable* table) {
    for (int i = 0; i < table->size; i++) {
        if (table->table[i] != NULL) {
            printf("Key: %d, Tree in order: ", table->table[i]->key);
            inorderTraversal(table->table[i]->tree);
            printf("\n");
        }
    }
}

// Función para encontrar el índice y el árbol con la mayor profundidad en la tabla hash
void findMaxDepth(struct HashTable* table, int* maxIndex, int* maxDepth) {
    *maxIndex = -1;
    *maxDepth = -1;
    for (int i = 0; i < table->size; i++) {
        if (table->table[i] != NULL) {
            // Calcula la profundidad del árbol
            int depth = calculateDepth(table->table[i]->tree);
            if (depth > *maxDepth) {
                *maxDepth = depth;
                *maxIndex = i;
            }
        }
    }
}

// Función para calcular la profundidad de un árbol binario
int calculateDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftDepth = calculateDepth(root->left);
    int rightDepth = calculateDepth(root->right);
    return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}
