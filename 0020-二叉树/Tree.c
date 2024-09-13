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

void creatTree(TreeNode **tree) {
    char data;
    scanf("%c \n", &data);

    if(data == '#') {
        // 为空节点
        *tree = NULL;
    }
    else {
        *tree = (TreeNode *) malloc(sizeof (TreeNode));
        (*tree) -> data = data;

        creatTree(&((*tree) -> left));

        creatTree(&((*tree) -> right));
    }

}

int main() {
    return 0;
}