
#include <stdlib.h>
#include "LinkedStack.h"

void InitStack(LinkStNode *&s)
{
    s = (LinkStNode *)malloc(sizeof(LinkStNode));
    s->next = nullptr;
}
void DestoryStack(LinkStNode *&s)
{
    LinkStNode *pre = s, *p = s->next;
    while (p != nullptr)
    {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}
bool IsEmpty(LinkStNode *&s)
{
    return s->next = nullptr;
}
void Push(LinkStNode *&s, ElemType e)
{
    LinkStNode *p = (LinkStNode *)malloc(sizeof(LinkStNode));
    p->data = e;
    p->next = s->next;
    s->next = p;
}
bool Pop(LinkStNode *&s, ElemType &e)
{
    LinkStNode *p;
    if (s->next == nullptr)
    {
        return false;
    }
    p = s->next;
    e = s->data;
    s->next = p->next;
    free(p);
    return true;
}
bool Peek(LinkStNode *&s, ElemType &e)
{
    if (s->next == nullptr)
    {
        return false;
    }
    e = s->next->data;
    return true;
}
bool Match(char *exp, int n)
{
    int i = 0;
    ElemType e;
    bool Match = true;
    LinkStNode *st;
    InitStack(st);
    while (i < n && Match)
    {
        if (exp[i] == '(') // 遇到左括号,入栈
        {
            Push(st, exp[i]);
        }
        else if (exp[i] == ')') // 遇到右括号,开始判断
        {
            if (Peek(st, e))
            {
                if (e != '(') // 如果栈顶不是左括号, 变为false
                {
                    Match = false;
                }
                else
                {
                    Pop(st, e);
                }
            }
            else
            {
                Match = false; // 栈空也将标志位置为false;
            }
        }
        i++;
    }
    if (IsEmpty(st))
    {
        Match = false;
    }
    DestoryStack(st); // 释放空间
    return Match;
}