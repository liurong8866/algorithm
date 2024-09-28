//
// Created by 堕落天使 on 2024/9/13.
//
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode * right;
} TreeNode;

typedef struct QueueNode {
    TreeNode *data;
    struct QueueNode *next;
} QueueNode;

QueueNode* createQueue() {
    QueueNode *head = (QueueNode *)malloc(sizeof(QueueNode));
    head->data = NULL;
    head->next = NULL;
    return head;
}

void enqueue(QueueNode *head, TreeNode *data) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    while (head->next != NULL) {
        head = head->next;
    }
    head->next = newNode;
}

TreeNode * dequeue(QueueNode *head) {
    TreeNode *result = head->data;
    head = head->next;
    return result;
}

void process(TreeNode *node) {
    printf("%d\n", node->data);
}

void createTree(TreeNode **node) {
    char s;
    scanf("%c", &s);

    if(s == '#') {
        node = NULL;
    }
    else {
        *node = (TreeNode *)malloc(sizeof(TreeNode));
        (*node) -> data = s;
        createTree(&(*node)->left);
        createTree(&(*node)->right);
    }
}

void preOrder(TreeNode *node) {
    QueueNode *queue = createQueue();
    enqueue(queue, node);

    while(queue->data != NULL) {
        TreeNode* q = dequeue(queue);

        process(q);

        if(q -> left) {
            enqueue(queue, q -> left);
        }

        if(q ->right) {
            enqueue(queue, q ->right);
        }
    }
}


int main() {

    TreeNode *root;
    createTree(root);

    preOrder(root);

    return 0;
}
