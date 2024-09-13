//
// Created by 堕落天使 on 2024/9/10.
//
#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct Node {
    int data;
    struct Node* pre;
    struct Node* next
} Node;

Node* initList() {
    Node* list = (Node*)malloc(sizeof(Node));
    list -> data = 0;
    list -> pre = NULL;
    list -> next = NULL;
    return list;
}

void headInsert(Node* head, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> pre = head;
    node -> next = head -> next;

    if(head -> next) {
        // 后元素
        head -> next ->pre = node;
    }

    // 首元素
    head -> next = node;
    head -> data++;
}

void tailInsert(Node* head, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> next = NULL;

    Node* current = head;
    while (current -> next != NULL) {
        current = current -> next;
    }
    node -> pre = current;
    current -> next = node;
    head -> data++;
}

int delete (Node* list, int data) {

    Node* current = list -> next;
    while (current != NULL) {
        if(current -> data == data) {
            current -> pre -> next = current -> next;
            if(current -> next != NULL) {
                current -> next -> pre = current -> pre;
            }
            free(current);
            list -> data--;
            return TRUE;
        }
        current = current -> next;
    }
    return FALSE;
}


void printList(Node* list) {
    Node* head = list -> next;
    Node* tail = list -> next;
    while (head != NULL) {
        printf("%d -> ", head -> data);
        tail = head;
        head = head->next;
    }

    printf("\n");

    // 从后向前打印
    while (tail != NULL) {
        printf("%d <- ", tail -> data);
        tail = tail -> pre;
    }
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

    delete(list, 1);
    delete(list, 4);
    delete(list, 10);

    printList(list);
    return 0;
}