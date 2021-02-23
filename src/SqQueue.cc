#include "SqQueue.h"

#include <iostream>
void InitQueue(SqQueue *&q) {
  q = (SqQueue *)malloc(sizeof(SqQueue));
  q->front = q->rear = -1;
}
void DestoryQueue(SqQueue *&q) {
  free(q);
  q = nullptr;
}
bool IsEmpty(SqQueue *q) { return q->front == q->rear; }
bool offer(SqQueue *&q, ElemType e) {
  if (q->front == MAX - 1) {
    return false;
  }
  q->rear++;
  q->data[q->rear] = e;
  return true;
}
bool poll(SqQueue *&q, ElemType &e) {
  if (IsEmpty(q)) {
    return false;
  }
  q->front++;
  e = q->data[q->front];
  return true;
}