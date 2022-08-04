#include <cstdio>
#include <cstdlib>
#include "sq_stack.h"

void InitStack(SqStack *&s) {
    s = (SqStack *) malloc(sizeof(SqStack));
    s->top = -1;
}

void DestoryStack(SqStack *&s) {
    free(s);
}

bool IsEmpty(SqStack *&s) {
    return s->top == -1;
}

bool Push(SqStack *&s, ElemType e) {
    if (s->top == MAX - 1) // 判断当前栈是否满
    {
        return false;
    }
    s->top++;
    s->data[s->top] = e;
    return true;
}

bool Pop(SqStack *&s, ElemType &e) {
    if (IsEmpty(s)) { // 判断栈是否为空
        return false;
    }
    e = s->data[s->top];
    s->top--;
    return true;
}

bool Peek(SqStack *&s, ElemType &e) {
    if (IsEmpty(s)) {
        return false;
    }
    e = s->data[s->top];
    return true;
}

// 判断一个字符串是否为回文串
bool symmetry(ElemType str[]) {
    int i;
    ElemType e;
    SqStack *st;
    InitStack(st);
    for (i = 0; str[i] != '\0'; i++) {
        Push(st, str[i]);
    }
    for (i = 0; str[i] != '\0'; i++) {
        Pop(st, e);
        if (e != str[i]) {
            DestoryStack(st);
            return false;
        }
    }
    DestoryStack(st);
    return true;
}

int main(int argc, char *argv[]) {

    char str[] = "abcbe";
    bool ok = symmetry(str);
    if (ok) {
        printf("is true\n");
    } else {
        printf("is false\n");
    }

    return 0;
}