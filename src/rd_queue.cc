#include <cstdlib>
#include "rd_queue.h"

void InitQueue(RdQueue *&q) {
    q = (RdQueue *) malloc(sizeof(RdQueue));
    q->front = 0;
    q->count = 0;
}

bool offer(RdQueue *&q, ElemType e) {
    int rear;
    if (q->count == MAX) {
        return false;
    }
    rear = (q->front + q->count) % MAX;
    rear = (rear + 1) % MAX;
    q->data[rear] = e;
    q->front++;
    q->count++;
    return true;
}

bool pull(RdQueue *&q, ElemType &e) {
    if (q->count == 0) {
        return false;
    }
    q->front = (q->front + 1) % MAX;
    e = q->data[q->front];
    q->front--;
    q->count--;
    return true;
}

bool IsEmpty(RdQueue *q) {
    return q->count == 0;
}