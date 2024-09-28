//
// Created by 堕落天使 on 2024/9/19.
//
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct StackNode {
    TreeNode *data;
    struct StackNode *next;
} StackNode;

typedef struct Stack {
    StackNode *head;
    StackNode *tail;
} Stack;

// 进栈
void pushStack(Stack **stack, TreeNode *node) {
    // 分配节点
    StackNode *stackNode = (StackNode *)malloc(sizeof(StackNode));
    stackNode ->data = node;
    stackNode ->next = NULL;

    // 如果有头节点
    if((*stack) -> head == NULL) {
        (*stack) -> head = stackNode;
        (*stack) -> tail = stackNode;
    }
    else {
        stackNode ->next = (*stack) -> head;
        (*stack) -> head = stackNode;
    }
}

// 出栈
TreeNode * popStack(Stack **stack) {
    // 如果头节点为NULL
    if((*stack) -> head == NULL) {
        return NULL;
    }
    else {
        StackNode *headNode = (*stack) ->head;
        TreeNode *tree = (*stack) ->head ->data;
        (*stack) -> head = (*stack) ->head ->next;

        //释放StackNode
        free(headNode);
        return tree;
    }
}

// 出栈
TreeNode * topStack(Stack **stack) {
    // 如果头节点为NULL
    if((*stack) -> head == NULL) {
        return NULL;
    }
    else {
        return (*stack) ->head ->data;
    }
}

// 初始化tree
void initTree(TreeNode **node, char* data, int *index) {

    char c = data[*index];
    (*index)++;

    if(c == '#') {
        *node = NULL;
    }else {
        *node = (TreeNode *)malloc(sizeof(TreeNode));
        (*node) ->data = c;
        initTree(&(*node) ->left, data, index);
        initTree(&(*node) ->right, data, index);
    }
}

// 前序遍历
//void preOrder(TreeNode *node) {
//    if(node -> data == '#') {
//        return;
//    }else {
//        printf("%c ", node -> data);
//        if(node -> left != NULL) {
//            preOrder(node -> left);
//        }
//        if(node -> right != NULL) {
//            preOrder(node->right);
//        }
//    }
//}

// 前序遍历 非递归
/*void preOrder(TreeNode *node) {

    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack ->head = NULL;
    stack ->tail = NULL;

    pushStack(&stack, node);

    // 循环入栈
    while(stack ->head != NULL) {

        TreeNode *treeNode = popStack(&stack);
        printf("%c -> ", treeNode->data);

        if(treeNode ->left != NULL) {
            pushStack(&stack, treeNode ->left);
        }
        if(treeNode ->right != NULL) {
            pushStack(&stack, treeNode ->right);
        }
    }

    free(stack);
    printf("NULL");
}*/

void preOrder(TreeNode *node) {

    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack ->head = NULL;
    stack ->tail = NULL;


    // 循环入栈
    while(node != NULL || stack ->head != NULL) {

        if(node != NULL) {
            printf("%c -> ", node ->data);
            pushStack(&stack, node);
            node = node ->left;
        }
        else {
            TreeNode *poped = popStack(&stack);
            node = poped ->right;
        }
    }

    free(stack);
    printf("NULL");
}


int main() {

    TreeNode *root = NULL;
    int index = 0;

    initTree(&root, "ABC##D##EF##G##", &index);

    preOrder(root);

    free(root);

    return 0;
}
