#ifndef _LINKEDSTACK_H
#define _LINKEDSTACK_H
typedef char ElemType;
typedef struct linkNode
{
    ElemType data;
    struct linkNode *next;
} LinkStNode;

// 1.初始化栈
void InitStack(LinkStNode *&);
// 2.销毁栈
void DestoryStack(LinkStNode *&);
// 3.判断栈是否为空
bool IsEmpty(LinkStNode *&);
// 4.进栈
void Push(LinkStNode *&, ElemType);
// 5.出栈
bool Pop(LinkStNode *&, ElemType &);
// 6.取栈顶元素
bool Peek(LinkStNode *&, ElemType &);
// 判断输入的括号表达式是否配对
bool Match(char *, int);
#endif