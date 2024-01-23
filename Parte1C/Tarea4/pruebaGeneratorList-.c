#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definición de la estructura de un nodo en la lista ligada
struct ListNode {
    int val;
    struct ListNode* next;
};

// Función para insertar un nodo al final de la lista ligada
void insertNode(struct ListNode** head, int val) {
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
        insertNode(&head, randomValue);
    }

    return head;
}

// Función para imprimir una lista ligada
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    srand(time(NULL));
    // Número de listas que deseas generar
    int numLists = rand() % 10;

    // Arreglo de apuntadores a las cabezas de las listas ligadas aleatorias
    struct ListNode* randomLists[numLists];

    // Generar varias listas ligadas aleatorias y almacenarlas en el arreglo
    for (int i = 0; i < numLists; i++) {
        int dim = rand() % 10;
        randomLists[i] = generateRandomList(dim, 1, 100);
    }

    // Imprimir las listas ligadas generadas aleatoriamente
    printf("Listas ligadas aleatorias:\n");
    for (int i = 0; i < numLists; i++) {
        printf("Lista %d: ", i + 1);
        printList(randomLists[i]);
    }

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

