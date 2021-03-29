#include "DLinkList.h"

#include <cstdio>
#include <cstdlib>

void CreateListF(DLinkNode *&L, ElemType a[], int n) {
  DLinkNode *s;
  L = (DLinkNode *)malloc(sizeof(DLinkNode));
  L->prior = L->next = nullptr;
  for (int i = 0; i < n; i++) {
    s = (DLinkNode *)malloc(sizeof(DLinkNode));
    s->data = a[i];
    s->next = L->next;
    if (L->next != nullptr) {
      L->next->prior = s;
    }
    L->next = s;
    s->prior = L;
  }
}
void CreateListR(DLinkNode *&L, ElemType a[], int n) {
  DLinkNode *s, *r;
  L = (DLinkNode *)malloc(sizeof(DLinkNode));
  r = L;
  for (int i = 0; i < n; i++) {
    s = (DLinkNode *)malloc(sizeof(DLinkNode));
    s->data = a[i];
    r->next = s;
    s->prior = r;
    r = s;
  }
  r->next = nullptr;
}
bool ListInsert(DLinkNode *&L, int i, ElemType e) {
  int j = 0;
  DLinkNode *p = L, *s;
  if (i <= 0) {
    return false;
  }
  while (j < i - 1 && p != nullptr) {
    j++;
    p = p->next;
  }
  if (p == nullptr) {
    return false;
  } else {
    s = (DLinkNode *)malloc(sizeof(DLinkNode));
    s->data = e;
    s->next = p->next;
    if (p->next != nullptr) {
      p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    return true;
  }
}
bool ListDelete(DLinkNode *&L, int i, ElemType &e) {
  int j = 0;
  DLinkNode *p = L, *q;
  if (i <= 0) {
    return false;
  }
  while (j < i - 1 && p != nullptr) {
    j++;
    p = p->next;
  }
  if (p == nullptr) {
    return false;
  } else {
    q = p->next;
    if (q == nullptr) {
      return false;
    }

    e = q->data;
    p->next = q->next;
    if (q->next != nullptr) {
      p->next->prior = p;
    }
    free(q);
    return true;
  }
}
