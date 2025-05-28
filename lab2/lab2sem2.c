#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void appendNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    (*newNode).data = data;
    (*newNode).next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* lastNode = *head;
    while ((*lastNode).next != NULL) {
        lastNode = (*lastNode).next;
    }
    (*lastNode).next = newNode;
}


void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", (*temp).data);
        temp = (*temp).next;
    }
    printf("\n");
}


struct Node* createList() {
    struct Node* head = NULL;
    int data;
    printf("Введите значения, 0 для окончания: ");
    while (scanf("%d", &data) == 1 && data != 0) {
        appendNode(&head, data);
    }
    return head;
}

int main() {
    printf("Создание списка:\n");
    struct Node* head = createList();
    printf("Список: ");
    printList(head);        
    return 0;
}
