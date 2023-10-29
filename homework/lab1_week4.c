#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

// listenin sonuna düğüm ekleme
struct Node* addNode(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

// tek sayıları listenin başına, çift sayıları sonuna ekleme
struct Node* addOddEvenToLinkedList() {
    struct Node* head = NULL;
    int num;

    while (1) {
        printf("Enter a number (-1 to stop): ");
        if (scanf("%d", &num) != 1) 

        if (num == -1) {
            break;
        }

        if (num % 2 == 1) {  // tek sayı
            head = addNode(head, num);
        } else {  // çift sayı
            head = addNode(head, num);
        }
    }

    return head;
}

// listeyi yazdırma
void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* myList = addOddEvenToLinkedList();
    printf(" liste : ");
    printLinkedList(myList);

    // belleği temizleme çökmemesi için
    while (myList != NULL) {
        struct Node* temp = myList;
        myList = myList->next;
        free(temp);
    }

    return 0;
}
