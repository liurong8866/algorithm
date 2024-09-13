//
// Created by 堕落天使 on 2024/9/9.
//
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* initList() {
    Node* list = (Node*) malloc(sizeof (Node));
    list -> data = 0;
    list -> next = list;
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
    node -> next = head;

    Node* list = head -> next;
    // 找到链表尾
    while (list -> next != head) {
        list = list -> next;
    }

    list -> next = node;
    head -> data++;
}

int delete(Node* head, int data) {
    Node* current = head -> next;
    Node* preNode = head;

    while(current != head) {
        if(current ->data == data) {
            preNode -> next = current -> next;
            free(current);
            head -> data--;
            return TRUE;
        }
        preNode = current;
        current = current -> next;
    }
    return FALSE;
}

void printList(Node* list) {
    Node* node = list -> next;
    while (node != list) {
        printf("%d ", node -> data);
        node = node -> next;
    }
    printf("NULL\n");
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