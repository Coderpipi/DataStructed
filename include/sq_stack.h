#ifndef _SQSTACK_H_
#define _SQSTACK_H_
#define MAX 50

typedef char ElemType;
typedef struct {
  ElemType data[MAX];
  int top;
} SqStack;
// 1.初始化栈
void InitStack(SqStack *&);
// 2.销毁栈
void DestoryStack(SqStack *&);
// 3.判断栈是否为空
bool IsEmpty(SqStack *&);
// 4.进栈
bool Push(SqStack *&, ElemType);
// 5.出栈
bool Pop(SqStack *&, ElemType &);
// 6.查看栈顶元素
bool Peek(SqStack *&, ElemType &);
#endif