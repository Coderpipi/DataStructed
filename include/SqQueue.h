#ifndef _SQQUEUE_H_
#define _SQQUEUE_H_
#define MAX 50

typedef char ElemType;
typedef struct {
  ElemType data[MAX];
  int front, rear;
} SqQueue;

// 1. 初始化队列
void InitQueue(SqQueue *&);
// 2.销毁队列
void DestoryQueue(SqQueue *&);
// 3.判断队列是否为空
bool IsEmpty(SqQueue *);
// 4.入队
bool offer(SqQueue *&, ElemType);
// 5.出队
bool poll(SqQueue *&, ElemType &);
#endif