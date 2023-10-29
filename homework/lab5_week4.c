#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {//sürekli struct yazmamak için typedef kullandm
    char name[50];
    struct Student* next;
} Student;

// verilen öğrenci adını bulduktan sonra düğüm silme
void deleteNextNode(Student* head, const char* studentName) {
    Student* current = head;

    while (current != NULL && current->next != NULL) {
        // sonraki düğümün adının verilen öğrenci adıyla eşleşip eşlenmediğini kontrol
        if (strcmp(current->next->name, studentName) == 0) {
            Student* nodeToDelete = current->next;
            current->next = nodeToDelete->next;
            free(nodeToDelete);
            return; // düğümü sil,fonksiyondan çık
        }
        current = current->next;
    }
}

void printList(Student* head) {
    Student* current = head;

    while (current != NULL) {
        printf("%s -> ", current->name);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
  
    Student* head = NULL;
    head = (Student*)malloc(sizeof(Student));
    strcpy(head->name, "Elif");
    head->next = (Student*)malloc(sizeof(Student));
    strcpy(head->next->name, "Berre");
    head->next->next = (Student*)malloc(sizeof(Student));
    strcpy(head->next->next->name, "Dilara");
    head->next->next->next = NULL;

    printf("listenin ilk hali: ");
    printList(head);

    const char* ogrenciİsimSilme = "Berre";
    deleteNextNode(head, ogrenciİsimSilme);

    printf("dogrusal listeden silindikten sonra liste '%s': ", ogrenciİsimSilme);
    printList(head);

    //belleği temizleme
    while (head != NULL) {
        Student* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
