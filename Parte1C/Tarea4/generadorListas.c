#include <stdio.h>
#include <stdlib.h>

struct ListNode* generateRandomList(int n, int min, int max) {
    struct ListNode* head = NULL;
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        int randomValue = rand() % (max - min + 1) + min;
        insertNode(&head, randomValue);
    }

    return head;
}

void insertNode(struct ListNode** head, int val);


int main() {

    return 0;
}

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
