//
// Created by 堕落天使 on 2024/9/13.
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

// 创建树，前序插入
void creatTree(TreeNode **tree) {
    char data;
    scanf("%c \n", &data);

    if(data == '#') {
        tree = NULL;
    }
    else {
        *tree = (TreeNode *) malloc(sizeof (TreeNode));
        (*tree) -> data = data;
        creatTree(&(*tree) -> left);
        creatTree(&(*tree) -> right);
    }
}

void preOrder(TreeNode **tree) {
    if(*tree == NULL) {
        return;
    }
    else {
        printf("%c -> ", (*tree) -> data);
        preOrder(&(*tree)->left);
        preOrder(&(*tree)->right);
    }
}

void midOrder(TreeNode **tree) {
    if(*tree == NULL) {
        return;
    }
    else {
        midOrder(&(*tree)->left);
        printf("%c -> ", (*tree) -> data);
        midOrder(&(*tree)->right);
    }
}

void afterOrder(TreeNode **tree) {
    if(*tree == NULL) {
        return;
    }
    else {
        afterOrder(&(*tree)->left);
        afterOrder(&(*tree)->right);
        printf("%c -> ", (*tree) -> data);
    }
}

int main() {
    TreeNode *tree;
    creatTree(tree);
    preOrder(tree);
    midOrder(tree);
    afterOrder(tree);

    return 0;
}