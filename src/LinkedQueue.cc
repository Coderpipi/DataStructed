/**
+++++++++++++++++++++++++++++++++++++
| FILENAME:                              
|                                          
| FILETYPE: CPP                          
|                                          
| AUTHOR: LBW                            
|                                          
| EMAIL: 2582482991qq.com             
|                                           
| CREATETIME:                           
|                                          
| MODIFYTIME:                           
|                                          
| VERSION: 1.0-SNAPSHOT                
+++++++++++++++++++++++++++++++++++++
*/
#include <cstdio>
#include <cstdlib>
#include "LinkedQueue.h"

void InitQueue(LinkQuNode *&q)
{
    q = (LinkQuNode *)malloc(sizeof(LinkQuNode));
    q->front = q->rear = nullptr;
}
void DestoryQueue(LinkQuNode *&q)
{
    DataNode *pre = q->front, *p;
    if (pre != nullptr)
    {
        p = pre->next;
        while (p != nullptr)
        {
            free(pre);
            pre = p;
            p = p->next;
        }
        free(pre);
    }
    free(q);
}
bool QueueEmpty(LinkQuNode *q)
{
    return q->rear == nullptr;
}
void offer(LinkQuNode *&q, ElemType e)
{
    DataNode *p;
    p = (DataNode *)malloc(sizeof(DataNode));
    p->data = e;
    p->next = nullptr;
    if (q->rear == nullptr)
    {
        q->front = q->rear = p;
    }
    else
    {
        q->rear->next = p;
        q->rear = p;
    }
}
bool poll(LinkQuNode *&q, ElemType &e)
{
    DataNode *t;
    if (q->rear == nullptr)
    {
        return false;
    }
    t = q->front;
    if (q->front == q->rear)
    {
        q->front = q->rear = nullptr;
    }
    else
    {
        q->front = q->front->next;
    }
    e = t->data;
    free(t);
    return true;
}
