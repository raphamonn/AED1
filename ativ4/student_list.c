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

Student* list_findByRa(StudentList* list, unsigned int ra) {
    Node* cur = list->head;

    while (cur != NULL) {
        if (student_getRa(cur->student) == ra) {
            return cur->student;
        }
        cur = cur->next;
    }

    return NULL;
}

void list_incrementGrades(StudentList* list, float increment) {
    Node* cur = list->head;

    while (cur != NULL) {
        student_setGrade(cur->student, student_getGrade(cur->student) + increment);
        cur = cur->next;
    }
}

double list_averageGrade(StudentList* list) {
    if (list_size(list) == 0) {
        // Evitar divisão por zero se a lista estiver vazia
        return 0.0;
    }

    double totalGrades = 0.0;
    Node* cur = list->head;

    while (cur != NULL) {
        totalGrades += student_getGrade(cur->student);
        cur = cur->next;
    }

    return totalGrades / list_size(list);
}

StudentList* list_filterFailed(StudentList* list) {
    StudentList* failedList = list_create();
    Node* cur = list->head;

    while (cur != NULL) {
        if (student_getGrade(cur->student) < 6.0) {
            list_insertFirst(failedList, student_getRa(cur->student), student_getName(cur->student), student_getGrade(cur->student));
        }
        cur = cur->next;
    }

    return failedList;
}

StudentList* list_filterPassed(StudentList* list) {
    StudentList* passedList = list_create();
    Node* cur = list->head;

    while (cur != NULL) {
        if (student_getGrade(cur->student) >= 6.0) {
            list_insertFirst(passedList, student_getRa(cur->student), student_getName(cur->student), student_getGrade(cur->student));
        }
        cur = cur->next;
    }

    return passedList;
}

StudentList* list_filterExam(StudentList* list) {
    StudentList* examList = list_create();
    Node* cur = list->head;

    while (cur != NULL) {
        float grade = student_getGrade(cur->student);
        if (grade < 6.0 && grade >= 4.0) {
            list_insertFirst(examList, student_getRa(cur->student), student_getName(cur->student), student_getGrade(cur->student));
        }
        cur = cur->next;
    }

    return examList;
}
