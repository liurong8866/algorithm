//
// Created by 堕落天使 on 2024/9/9.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* initList() {
    Node* list = (Node*) malloc(sizeof (Node));
    list -> data = 0;
    list -> next = NULL;
    return list;
}

// 头插法
void headInsert(Node* head, int data) {
    Node* node = (Node*) malloc(sizeof (Node));
    node -> data = data;
    node -> next = head -> next;

    head -> next = node;
    head -> data++;
}

// 尾插法
void tailInsert(Node* head, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> next = NULL;

    Node* list = head -> next;
    while (list -> next != NULL) {
        list = list -> next;
    }

    list -> next = node;
    head -> data++;
}

void delete(Node* head, int data) {
     Node* current = head -> next;
     Node* preNode = head;

     while(current != NULL) {
         if(current ->data == data) {
             preNode -> next = current -> next;
             free(current);
             head -> data--;
             break;
         }
         preNode = current;
         current = current -> next;
     }
}

void printList(Node* list) {
    list = list -> next;
    while (list) {
        printf("%d ", list -> data);
        list = list -> next;
    }
    printf("\n");
}

int main() {

    Node* list = initList();
    headInsert(list, 1);
    headInsert(list, 2);
    headInsert(list, 3);
    headInsert(list, 4);
    headInsert(list, 5);

    tailInsert(list, 6);
    tailInsert(list, 7);
    tailInsert(list, 8);
    tailInsert(list, 9);
    tailInsert(list, 10);

    delete(list, 5);
    delete(list, 4);
    delete(list, 10);

    printList(list);

    return 0;
}