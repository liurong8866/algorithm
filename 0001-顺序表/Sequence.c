//
// Created by 堕落天使 on 2024/9/10.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 2

typedef struct Sequence{
    int *data;
    int capacity;
    int length;
} Sequence;

// 创建
Sequence * initSequence(void) {
    Sequence *list = (Sequence *) malloc(sizeof(Sequence));
    list -> length = 0;
    list -> capacity = MAX_SIZE;
    list -> data = (int *)malloc(sizeof(int)*MAX_SIZE);
    return list;
}

// 扩容
void resizeSequence(Sequence *list) {

    list -> capacity = list ->capacity * 2;

    int *newData = (int *)malloc(sizeof(int) * list -> capacity);

    for(int i=0; i< list -> length; i++) {
        newData[i] = list -> data[i];
    }

    list -> data = newData;
}

// 插入元素
int insertSequence(Sequence *list, int index, int data) {

    // 扩容
    if(list->length >= MAX_SIZE) {
        resizeSequence(list);
    }

    // 超出边界值
    if(index < 0 || index > list -> length) return FALSE;

    for(int i=list -> length -1; i>=index; i--) {
        list -> data[i+1] = list -> data[i];
    }

    list -> data[index] = data;

    list -> length++;

    return TRUE;
}

// 删除
int deleteSequence(Sequence *list, int index) {
    // 越界
    if(index < 0 || index > list -> length) return FALSE;

    for(int i=index; i<list -> length -1; i++) {
        list -> data[i] = list -> data[i+1];
    }
    // 重新赋值空余的末尾
    list -> data[list -> length-1] = 0;
    list -> length--;
    return TRUE;
}


// 打印
void printSequence(Sequence *list) {
    for (int i = 0; i < list ->length; ++i) {
        printf("%d ", list -> data[i]);
    }
}

int main() {

    Sequence *list = initSequence();

    insertSequence(list, 0, 1);
    insertSequence(list, 1, 2);
    insertSequence(list, 2, 3);
    insertSequence(list, 3, 4);
    insertSequence(list, 3, 5);

    insertSequence(list, 0, 0);
    insertSequence(list, 0, -1);

    deleteSequence(list, 0);

    printSequence(list);

    return 0;
}