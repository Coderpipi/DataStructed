#ifndef _LINKEDQUEUE_H_
#define _LINKEDQUEUE_H_
typedef int ElemType;
// 元素结点
typedef struct qnode {
    ElemType data;
    struct qnode *next;
} DataNode;
typedef struct {
    DataNode *front;
    DataNode *rear;
} LinkQuNode;

// 1.初始化队列
void InitQueue(LinkQuNode *&);

// 2. 销毁队列
void Destoryqueue(LinkQuNode *&);

// 3.判断队列是否为空
bool QueueEmpty(LinkQuNode *);

// 4.进队列
void offer(LinkQuNode *&, ElemType);

// 5.出队列
bool poll(LinkQuNode *&, ElemType &);

#endif