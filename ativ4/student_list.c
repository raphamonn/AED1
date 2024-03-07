/**
 * NAO EDITE AS FUNCOES QUE JA ESTAO PRONTAS, 
 * APENAS IMPLEMENTE AS NOVAS
*/

#include "student_list.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    Student* student;
    struct Node* next;
} Node;

struct StudentList {
    Node* head;
};


StudentList *list_create() {
    StudentList *list = malloc(sizeof(StudentList));

    list->head = NULL;

    return list;
}

void list_destroy(StudentList *list) {
    Node *trash = list->head;

    while (trash != NULL) {
        list->head = trash->next;

        student_destroy(trash->student);
        free(trash);
        trash = list->head;
    }
    free(list);
}

void list_insertFirst(StudentList *list, unsigned int ra, char* name, float grade) {
    Node *newNode = malloc(sizeof(Node));

    newNode->student = student_create(ra, name, grade);
    newNode->next = list->head;
    list->head = newNode;
}

void list_insertAfter(StudentList *list, int position, unsigned int ra, char* name, float grade) {
    if (position <= 0 || list->head == NULL) {
        list_insertFirst(list, ra, name, grade);
    } else {
        Node* cur = list->head;
        int i = 0;       

        while (i < position && cur->next != NULL) {
            cur = cur->next;
            i++;
        }

        Node* newNode = malloc(sizeof(Node));
        
        newNode->student = student_create(ra, name, grade);
        newNode->next = cur->next;
        cur->next = newNode;
    }
}


Student* list_get(StudentList *list, int position) {
    if (position < 0) {
        return list->head->student;
    }

    Node *cur = list->head;
    int i = 0;

    while (i < position && cur->next != NULL) {
        cur = cur->next;
        i++;
    }

    return cur->student;
}

void list_print(StudentList *list) {
    Node *cur = list->head;

    while (cur != NULL) {
        student_print(cur->student);
        if (cur->next != NULL) {
            printf(" -> ");
        }
        cur = cur->next;
    }
    printf("\n");
}

int list_size(StudentList *list) {
    Node *cur = list->head;
    int count = 0;

    while (cur != NULL) {
        count++;
        cur = cur->next;
    }

    return count;
}

bool list_isEmpty(StudentList *list) {
    return list->head == NULL;
}

// new functions
Student* list_findByRa(StudentList* list, unsigned int ra) {
    Node* cur = list->head;

    while (cur != NULL) {
        if (cur->student->ra == ra) {
            return cur->student;
        }
        cur = cur->next;
    }

    return NULL;  
}

void list_incrementGrades(StudentList* list, float amount) {
    Node* cur = list->head;

    while (cur != NULL) {
        cur->student->grade += amount;
        cur = cur->next;
    }
}

float list_averageGrade(StudentList* list) {
    if (list_isEmpty(list)) {
        return 0.0;  
    }

    Node* cur = list->head;
    float totalGrade = 0.0;
    int count = 0;

    while (cur != NULL) {
        totalGrade += cur->student->grade;
        count++;
        cur = cur->next;
    }

    return totalGrade / count;
}

StudentList* list_filterFailed(StudentList* list) {
    StudentList* failedList = list_create();
    Node* cur = list->head;

    while (cur != NULL) {
        if (cur->student->grade < 6.0) {
            list_insertFirst(failedList, cur->student->ra, cur->student->name, cur->student->grade);
        }
        cur = cur->next;
    }

    return failedList;
}

StudentList* list_filterPassed(StudentList* list) {
    StudentList* passedList = list_create();
    Node* cur = list->head;

    while (cur != NULL) {
        if (cur->student->grade >= 6.0) {
            list_insertFirst(passedList, cur->student->ra, cur->student->name, cur->student->grade);
        }
        cur = cur->next;
    }

    return passedList;
}

StudentList* list_filterExam(StudentList* list) {
    StudentList* examList = list_create();
    Node* cur = list->head;

    while (cur != NULL) {
        if (cur->student->grade >= 4.0 && cur->student->grade < 6.0) {
            list_insertFirst(examList, cur->student->ra, cur->student->name, cur->student->grade);
        }
        cur = cur->next;
    }

    return examList;
}
