/* Tarea 4. Programación y Algoritmos.
    Parte 1. Lenguaje C.

                Jose Luis de Leon Carmona.
Ejercicio #. Una funcion que recibe un arreglo de N apuntadores a nodos cabeza de listas ligadas
y mezcle los arreglos en una sola lista ligada ordenada. No declarar nueva memoria para los nodos.
******************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definición de la estructura de un nodo en la lista ligada
struct ListNode {
    int val;
    struct ListNode* next;
};

void insertNode(struct ListNode** head, struct ListNode* newNode);

struct ListNode* mergeSortedLists(struct ListNode** lists, int numLists);

void printList(struct ListNode* head);

void insertNode2(struct ListNode** head, int val);

struct ListNode* generateRandomList(int n, int min, int max);


int main() {
    srand(time(NULL));
    // Número de listas que deseas generar
    int numLists = rand() % 20;

    // Arreglo de apuntadores a las cabezas de las listas ligadas aleatorias
    struct ListNode* randomLists[numLists];

    // Generar varias listas ligadas aleatorias y almacenarlas en el arreglo
    for (int i = 0; i < numLists; i++) {
        int dim = rand() % 20;
        randomLists[i] = generateRandomList(dim, -100, 100);
    }

     // Imprimir las listas ligadas generadas aleatoriamente
    printf("Listas ligadas aleatorias:\n");
    for (int i = 0; i < numLists; i++) {
        printf("Lista %d: ", i + 1);
        printList(randomLists[i]);
    }

    // Llamar a la función para combinar y ordenar las listas
    struct ListNode* mergedList = mergeSortedLists(randomLists, numLists);

    // Imprimir la lista resultante
    printf("Lista ordenada combinada:\n");
    printList(mergedList);


    // Liberar la memoria de las listas ligadas
    for (int i = 0; i < numLists; i++) {
        while (randomLists[i] != NULL) {
            struct ListNode* temp = randomLists[i];
            randomLists[i] = randomLists[i]->next;
            free(temp);
        }
    }

    return 0;
}

// Función para insertar un nodo en la lista ligada ordenadamente
void insertNode(struct ListNode** head, struct ListNode* newNode) {
    struct ListNode* current = *head;
    struct ListNode* prev = NULL;

    while (current != NULL && current->val < newNode->val) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        newNode->next = *head;
        *head = newNode;
    } else {
        prev->next = newNode;
        newNode->next = current;
    }
}

// Función para combinar y ordenar listas ligadas
struct ListNode* mergeSortedLists(struct ListNode** lists, int numLists) {
    struct ListNode* result = NULL;

    // Fusionar todas las listas en una sola
    for (int i = 0; i < numLists; i++) {
        while (lists[i] != NULL) {
            struct ListNode* newNode = lists[i];
            lists[i] = lists[i]->next;
            newNode->next = NULL;
            insertNode(&result, newNode);
        }
    }

    return result;
}

// Función para imprimir una lista ligada
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Función para insertar un nodo al final de la lista ligada
void insertNode2(struct ListNode** head, int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (!newNode) {
        fprintf(stderr, "Error: No se pudo asignar memoria para el nodo.\n");
        exit(1);
    }
    newNode->val = val;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct ListNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Función para generar una lista ligada aleatoria con n nodos y valores en el rango [min, max]
struct ListNode* generateRandomList(int n, int min, int max) {
    struct ListNode* head = NULL;


    for (int i = 0; i < n; i++) {
        int randomValue = rand() % (max - min + 1) + min;
        insertNode2(&head, randomValue);
    }

    return head;
}


