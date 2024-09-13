//
// Created by 堕落天使 on 2024/9/11.
//
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 初始化
Node * initQueue() {
    Node *list = (Node *) malloc(sizeof (int));
    list -> data = 0;
    list -> next = list;
    return list;
}

// 入队列
void push(Node *list, int data) {
    Node *head = list;

    Node *node = (Node *) malloc(sizeof (int));
    node -> data = data;
    node -> next = head;

    list = list->next;
    while (list -> next != head) {
        list = list -> next;
    }
    list -> next = node;
    head -> data++;
}

// 出队列
int pop(Node *list) {

    if(list -> next == list) return -1;

    Node *p = list -> next;
    int result = p -> data;

    list -> next = list -> next -> next;

    free(p);

    return result;
}

// 查找
int top(Node *list) {
    if(list -> next == list) return -1;
    return list -> next -> data;
}

// 遍历
void printQueue(Node *list) {
    Node *head = list;
    list = list ->next;
    while (list != head) {
        printf("%d ", list -> data);
        list = list -> next;
    }
    printf("\n");
}

int main() {

    Node *list = initQueue();

    push(list, 1);
    push(list, 2);
    push(list, 3);

    printQueue(list);

    int a = pop(list);
    int b = pop(list);
    printf("%d %d", a, b);

    printf("\n");

    printQueue(list);

    return 0;
}