#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_İSİM_UZUNLUĞU 50

struct Student {
    char name[MAX_İSİM_UZUNLUĞU];
    int age;
    int number;
    struct Student* next;
};

// yeni öğrenci düğümü oluşturma
struct Student* createStudent(const char* name, int age, int number) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));

    int i;
    for (i = 0; name[i] != '\0' && i < MAX_İSİM_UZUNLUĞU - 1; i++) {
        newStudent->name[i] = name[i];
    }
    newStudent->name[i] = '\0';

    newStudent->age = age;
    newStudent->number = number;
    newStudent->next = NULL;
    return newStudent;
}

// listenin sonuna öğrenci düğümü ekleme
void insertStudent(struct Student** head, const char* name, int age, int number) {
    struct Student* newStudent = createStudent(name, age, number);
    if (*head == NULL) {
        *head = newStudent;
    } else {
        struct Student* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
    }
}

// bilgi listeleme ve öğrencileri sayma
void printStudents(struct Student* head) {
    int count = 0;
    struct Student* current = head;

    while (current != NULL) {
        count++;
        printf("%d- %s %d %d\n", count, current->name, current->age, current->number);
        current = current->next;
    }

    printf("Total Students: %d\n", count);
}

int main() {
    struct Student* head = NULL;

    char name[MAX_İSİM_UZUNLUĞU];
    int age, number;

    // öğrencileri listeye ekleme
    printf("Enter student information (name, age, number), or ' exit ' to finish:\n");
    int count = 0;
    while (1) {
        int result = scanf("%49s %d %d", name, &age, &number);
        if (result != 3) {
       
            if(strcmp(name,"exit")==0)
            break;//exıt(ı ile) yazılırsa listeyi sonlandırıyor

        }
        insertStudent(&head, name, age, number);
        count++;
    }


    printf("Student List:\n");
    printStudents(head);

    // belleği temizleme
    while (head != NULL) {
        struct Student* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
