#ifndef _RDQUEUE_H_
#define _RDQUEUE_H_
#define MAX 50

typedef char ElemType;

typedef struct
{
    ElemType data[MAX];
    int front;
    int count;
} RdQueue;

// 1.初始化环形队列
void InitQueue(RdQueue *&);
// 2.进队
bool offer(RdQueue *&, ElemType);
// 3.出队
bool pull(RdQueue *&, ElemType &);
// 4.判断队列是否空
bool IsEmpty(RdQueue *);
#endif