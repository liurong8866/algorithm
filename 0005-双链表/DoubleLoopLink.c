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
    list -> pre = list;
    list -> next = list;
    return list;
}

void headInsert(Node* head, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> pre = head;
    node -> next = head -> next;

    if(head -> next != NULL) {
        // 后元素
        head -> next ->pre = node;
    }

    // 首元素
    head -> next = node;
    head -> data++;
}

//void tailInsert(Node* head, int data) {
//    Node* node = (Node*)malloc(sizeof(Node));
//    node -> data = data;
//    node -> next = head;
//
//    Node* current = head;
//    while (current -> next != head) {
//        current = current -> next;
//    }
//
//    node -> pre = current;
//    current -> next = node;
//    head -> data++;
//}
// 优化版
void tailInsert(Node* head, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> next = head;
    node -> pre = head->pre;

    node->pre->next = node;
    head->pre = node;
    head -> data++;
}

int delete (Node* list, int data) {

    Node* current = list -> next;
    while (current != list) {
        if(current -> data == data) {
            current -> pre -> next = current -> next;
            current -> next -> pre = current -> pre;
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
    while (head != list) {
        printf("%d -> ", head -> data);
        tail = head;
        head = head->next;
    }

    printf("NULL\n");

    // 从后向前打印
    while (tail != list) {
        printf("%d <- ", tail -> data);
        tail = tail -> pre;
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

//    delete(list, 1);
//    delete(list, 4);
//    delete(list, 10);

    printList(list);
    return 0;
}