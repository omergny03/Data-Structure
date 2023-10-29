#include <stdio.h>
#include <stdlib.h>
#include <time.h>//rast gele sayı üretmek için

struct Node {
    int data;
    struct Node* next;
};

// verilerle düğüm oluşturma
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// listenin sonuna düğüm ekleme
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// listeyi yazdırma 
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) {
            printf("->");
        }
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    srand(time(NULL));

    // listete rastgele 100 sayı ekleme
    for (int i = 0; i < 100; i++) {
        int randomNum = rand() % 1000; // 0 ile 999 arasında rastgele tam sayılar
        insertNode(&head, randomNum);
    }

    // küçükten büyüğe sıralama
    struct Node* current = head;
    while (current != NULL) {
        struct Node* nextNode = current->next;
        while (nextNode != NULL) {
            if (current->data < nextNode->data) {
                int temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }
            nextNode = nextNode->next;
        }
        current = current->next;
    }

    // listeyi yazdırma
    printf(" rastgele uretilmis 100 sayiyi kucukten buyuge siralayan liste: \n");
    printList(head);

    // belleği temizleme işlemi çökme olmamasi için
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
