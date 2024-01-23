/* Tarea 4. Programación y Algoritmos.
    Parte 1. Lenguaje C.

                Jose Luis de Leon Carmona.

Ejercicio 2. Listas Ligadas: Crear un programa que implemente una lista ligada y despliegue un
menú con las siguientes operaciones:

a. Inserta nodo;
b. Elimina nodo;
c. No. de nodos;
d. Busca valor;
e. Invertir orden (modificar ligas);
f. Ordena;
g. Imprime;
h. Fin;

*****************************************************/

#include <stdio.h>
#include <stdlib.h>

//Estrucctura para un nodo de la lista
struct Node {
    int data;
    struct Node* next;
};

void printLinkedList(struct Node* head);

struct Node* createNode(int data);

void insertNode(struct Node** head, int data, int pos);

int LengthLinkedList(struct Node* head);

void deleteNode(struct Node** head, int pos);

void search(struct Node* head, int x);

void reverse(struct Node** head);

void sort(struct Node** head);


int main() {
    struct Node* head = NULL; //Lista vacia
    int opcion, dato, pos, result;

    do {
        printf("\n         MENU:               \n");
        printf("1. Inserta nodo\n2. Elimina nodo\n3. No. de nodos\n4. Busca valor\n5. Invertir orden (modificar ligas)\n6. Ordena\n7. Imprime\n8. Fin\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el valor: ");
                scanf("%d", &dato);
                printf("Ingrese la posición: ");
                scanf("%d", &pos);
                insertNode(&head, dato, pos);
                printf("Elemento %d Agregado en la posicion %d \n\n", dato, pos);
                break;

            case 2:
                printf("Ingresa la posicion: ");
                scanf("%d", &pos);
                deleteNode(&head, pos);
                break;

            case 3:
                result = LengthLinkedList(head);
                printf("\n Numero de Nodos: %d ", result);
                break;

            case 4:
                printf("\n Ingresa el valor: \n");
                scanf("%d", &dato);
                search(head, dato);
                break;

            case 5:
                reverse(&head);
                printf("\n La lista ha sido invertida \n");
                break;

            case 6:
                sort(&head);
                printf("\n La Lista ha sido ordenada \n");
                break;

            case 7:
                printLinkedList(head);
                break;

            case 8:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción no válida. Intente de nuevo.\n");

        }




    } while (opcion != 8);

    //Liberar Memoria

    struct Node* actual = head;
    while (actual != NULL) {
        struct Node* next = actual->next;
        free(actual);
        actual = next;
    }



    return 0;
}

void sort(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
    //Lista vacia o ordenada
    return;
    }

    struct Node* sortedList = NULL;
    struct Node* actual = *head;

    while (actual != NULL) {
        struct Node* next = actual->next;

        if (sortedList == NULL || actual->data <= sortedList->data) {
            actual->next = sortedList;
            sortedList = actual;

        } else {
            struct Node* temp = sortedList;
            while ( temp->next != NULL && temp->next->data < actual->data) {
                temp = temp->next;
            }
            actual->next = temp->next;
            temp->next = actual;
        }
        actual = next;
    }

    *head = sortedList;
}

void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* actual = *head;
    struct Node* next = NULL;

    while (actual != NULL) {
        next = actual->next;
        actual->next = prev;

        prev = actual;
        actual = next;
    }

    *head = prev;

}
void search(struct Node* head, int x) {
    struct Node* actual = head;

    while (actual != NULL) {
        if (actual->data == x) {
            printf("SI! El valor %d esta en la lista \n", x);
            return;
        }
        actual = actual->next;
    }
    printf("NO! El valor %d NO esta en la lista \n ", x);
}

void deleteNode(struct Node** head, int pos) {
    int l = LengthLinkedList(*head);
    int i;

    if ( pos < 0) {
        pos = 0;
    }

    if (pos > l) {
        pos = l-1;
    }

    if (pos == 0) {  //Eliminar el nodo de la cabeza
        struct Node* temp = *head;
        *head = temp->next;
        free(temp);
        return;
    }

    struct Node* prevNode = *head;
    for (i = 0; i < pos - 1; i++) {
        prevNode = prevNode->next;
    }

    struct Node* actual = prevNode->next;

    prevNode->next = actual->next;
    free(actual);
}

int LengthLinkedList(struct Node* head) {
    int count = 0;
    struct Node* actual = head;

    while (actual != NULL) {
        count++;
        actual = actual->next;
    }

    return count;
}

/* Funcion de insertar un nuevo nodo donde se pide la posicion, si la posicion es menor a cero se inserta
al principio y si es mayor a la longuitud de la lista se inserta al final*/
void insertNode(struct Node** head, int data, int pos) {
    int i = 0;
    int l = LengthLinkedList(*head);

    if (pos < 0) { //Agregar al inicio
        pos = 0;
        }

    if (pos > l ) { //Agregar al final
        pos = l;
    }


    struct Node* newNode = createNode(data);
    if (pos == 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* actual = *head;

        while (actual != NULL & i < pos - 1) {
            actual = actual->next;
            i++;
        }

        if (actual == NULL) {
            printf("ERROR en la posicion");
            free(newNode);
        }

        newNode->next = actual->next;
        actual->next = newNode;

    }
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("ERROR");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void printLinkedList(struct Node* node) {
    printf("[");
    while (node != NULL) {
        printf("%d, ", node->data);
        node = node->next;
    }

    printf("] \n");

}

