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
Node * initStack() {
    Node *list = (Node *) malloc(sizeof (int));
    list -> data = 0;
    list -> next = NULL;
    return list;
}

// 入栈
void push(Node *list, int data) {
    Node *node = (Node *) malloc(sizeof (int));
    node -> data = data;
    node -> next = list -> next;

    list -> next = node;
    list -> data++;
}

// 出栈
int pop(Node *list) {

    if(list -> next == NULL) return -1;

    Node *p = list -> next;
    int result = p -> data;

    list -> next = list -> next -> next;

    free(p);

    return result;
}

// 查找
int top(Node *list) {

    if(list -> next == NULL) return -1;
    return list -> next -> data;
}

// 遍历
void printStack(Node *list) {
    list = list ->next;
    while (list != NULL) {
        printf("%d ", list -> data);
        list = list -> next;
    }
    printf("\n");
}

int main() {

    Node *list = initStack();

    push(list, 1);
    push(list, 2);
    push(list, 3);

    printStack(list);

    int a = pop(list);
    int b = pop(list);
    printf("%d %d ", a, b);

    printf("\n");

    printStack(list);

    return 0;
}