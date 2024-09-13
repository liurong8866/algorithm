//
// Created by 堕落天使 on 2024/9/12.
//
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct String {
    char *data;
    int length;
} String;

// 初始化
String * initString() {
    String *s = (String *)malloc(sizeof (String));
    s -> data = NULL;
    s -> length = 0;
    return s;
}

// 赋值
void stringAssign(String *s, char *data) {
    if(s -> data) {
        free(s -> data);
    }

    int len = 0;
    char *temp = data;
    while (*temp) {
        len++;
        temp++;
    }
    if(len ==0) {
        s -> data = NULL;
        s -> length = 0;
    }
    else {
        temp = data;
        s -> length = len;
        // len + 1 是为了保存字符串末尾的 \0 字符
        s -> data = (char *)malloc(sizeof (char) * (len +1));

        for (int i = 0; i < len; i++, temp++) {
            s -> data[i] = *temp;
        }
    }
}

// 打印
void printString(String *s) {
    for (int i = 0; i < s->length; i++) {
        printf("%c ->", s->data[i]);
    }
    printf("\n");
}

// 暴力
int forceMatch(String *content, String *find) {
    int i = 0;
    int j = 0;
    while (i<content->length && j<find->length) {
        if(content -> data[i] == find -> data[j]) {
            i++;
            j++;
        }
        else {
            i = i - j + 1;
            j = 0;
        }
    }
    return j == find->length;

}

int main() {

    String *s1 = initString();
    stringAssign(s1, "Hello");

    String *s2 = initString();
    stringAssign(s2, "e1llo");

    printf("%d ",forceMatch(s1, s2));

    return 0;
}