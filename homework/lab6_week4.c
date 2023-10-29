#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Student {
    char name[50];
    struct Student* next;
} Student;

// en uzun ismi bulma 
void printLongestNameRecord(Student* head) {
    if (head == NULL) {
        printf("liste boş.\n");
        return;
    }

    Student* current = head;
    int max_uzunluk = 0;
    char uzun_isim[50];

    while (current != NULL) {
        int current_length = strlen(current->name);
        if (current_length > max_uzunluk) {
            max_uzunluk = current_length;
            strcpy(uzun_isim, current->name);
        }
        current = current->next;
    }

    printf("listedeki en uzun isim: %s\n", uzun_isim);
    printf("uzunluk: %d\n", max_uzunluk);
}

int main() {

    Student* head = NULL;
    head = (Student*)malloc(sizeof(Student));
    strcpy(head->name, "Elif");
    head->next = (Student*)malloc(sizeof(Student));
    strcpy(head->next->name, "Berre");
    head->next->next = (Student*)malloc(sizeof(Student));
    strcpy(head->next->next->name, "Abdurrahmangazi");
    head->next->next->next = NULL;

    printf("Liste: \n");
    printLongestNameRecord(head);

    // belleği temizleme
    while (head != NULL) {
        Student* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
