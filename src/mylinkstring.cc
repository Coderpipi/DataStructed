/**
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
| FILENAME: mylinkstring
|
| FILETYPE: CPP
|
| DESCRIPTION: 链串的各种操作的实现
|
| AUTHOR: LBW
|
| EMAIL: 2582482991@qq.com
|
| CREATETIME: 2021-3-20
|
| MODIFYTIME: 2021-3-20
|
| VERSION: 1.0-SNAPSHOT
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
#include "mylinkstring.h"

#include <cstdio>
#include <cstdlib>

void StrAssign(LinkStrNode *&s, char cstr[]) {
  LinkStrNode *r, *p;
  s = (LinkStrNode *)malloc(sizeof(LinkStrNode));
  r = s;  // r始终指向尾结点
  for (int i = 0; cstr[i] != '\0'; ++i) {
    p = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    p->data = cstr[i];
    r->next = p;
    r = p;
  }
  r->next = nullptr;  // 尾结点的next置空
}

void DestoryStr(LinkStrNode *&s) {
  LinkStrNode *pre = s, *p = s->next;  // pre指向结点p的前驱结点
  while (p != nullptr) {               // 扫描链串s
    free(pre);                         // 释放结点
    pre = p;
    p = pre->next;  // 指向下一个结点
  }
  free(pre);  // 循环结束时,p为null, pre指向尾结点
}

void StrCpy(LinkStrNode *&s, LinkStrNode *t) {
  LinkStrNode *p = t->next, *q, *r;
  s = (LinkStrNode *)malloc(sizeof(LinkStrNode));
  r = s;                  // r指向尾结点
  while (p != nullptr) {  // 扫描链串t的所有节点
    q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    q->data = p->data;  // 将p结点赋值到q结点
    r->next = q;        // 将q结点连接到s的末尾
    r = q;
    p = p->next;
  }
  r->next = nullptr;  // 尾结点的next置空
}

bool Equal(LinkStrNode *s1, LinkStrNode *s2) {
  LinkStrNode *p = s1->next, *q = s2->next;
  while (p != nullptr && q != nullptr && p->data == q->data) {
    p = p->next;
    q = q->next;
  }
  if (p == nullptr && q == nullptr) {
    return true;
  }
  return false;
}

int Length(LinkStrNode *&s) {
  int i = 0;  // 用于记录s的长度
  LinkStrNode *p = s->next;
  while (p != nullptr) {  // 扫描s串
    i++;
    p = p->next;
  }
  return i;
}

LinkStrNode *Concat(LinkStrNode *s, LinkStrNode *t) {
  LinkStrNode *str, *p = s->next, *q, *r;
  str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
  r = str;                // r指向结果串的尾结点
  while (p != nullptr) {  // 扫描s的所有结点
    q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    q->data = p->data;  // 将p复制到q中
    r->next = q;
    r = q;  // 将q连接到str的末尾
    p = p->next;
  }
  p = p->next;
  while (p != nullptr) {  // 扫描t的所有结点
    q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    q->data = p->data;  // 将p结点复制到q中
    r->next = q;        // 将q连接到str的末尾
    r = q;
    p = p->next;
  }
  r->next = nullptr;  // 将尾结点的next置空
  return str;
}

LinkStrNode *SubString(LinkStrNode *s, int i, int j) {
  LinkStrNode *str, *p = s->next, *q, *r;
  str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
  str->next = nullptr;  // 置结果串为空串
  r = str;              // r指向str的尾结点
  if (i <= 0 || i > Length(s) || j < 0 || i + j - 1 > Length(s)) {
    return str;  // 参数不正确直接返回空串
  }
  for (int k = 1; k < i; ++k) {
    p = p->next;  // 让p指向链串s的第i个数据结点
  }
  for (int k = 1; k <= j; ++k) {
    q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    q->data = p->data;
    r->next = q;
    r = q;
    p = p->next;
  }
  r->next = nullptr;
  return str;
}

LinkStrNode *InsertStr(LinkStrNode *s, int i, LinkStrNode *t) {
  LinkStrNode *str, *p = s->next, *p1 = t->next, *q, *r;
  str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
  str->next = nullptr;                // 置结果串为空串
  r = str;                            // r指向结果串的尾结点
  if (i <= 0 || i > Length(s) + 1) {  // 参数不正确时返回空串
    return str;
  }
  for (int k = 1; k < i; ++k) {
    // 将s的前i个结点复制到str
    q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    q->data = p->data;
    r->next = q;
    r = q;
    p = p->next;
  }

  while (p != nullptr) {
    q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    q->data = p->data;
    r->next = q;
    r = q;
    p1 = p1->next;
  }
  while (p != nullptr) {  // 将p结点及其后的结点复制到str
    q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    q->data = p->data;
    r->next = q;
    r = q;
    p = p->next;
  }
  r->next = nullptr;  // 尾结点的next域置空
  return str;
}

LinkStrNode *DelStr(LinkStrNode *s, int i, int j) {
  LinkStrNode *str, *p = s->next, *q, *r;
  str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
  str->next = nullptr;  // 置结果串为空串
  r = str;
  if (i <= 0 || i > Length(s) || j < 0 || i + j - 1 > Length(s)) {
    return str;  // 当参数不正确时返回空串
  }
  for (int k = 1; k < i; k++) {
    q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    q->data = p->data;
    r->next = q;
    r = q;
    p = p->next;
  }
  for (int k = 0; k < j; k++) {
    p = p->next;  // 让p沿next跳j个结点
  }
  while (p != nullptr) {
    q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    q->data = p->data;
    r->next = q;
    r = q;
    p = p->next;
  }
  r->next = nullptr;
  return str;
}

LinkStrNode *Replace(LinkStrNode *s, int i, int j, LinkStrNode *t) {
  LinkStrNode *str, *p = s->next, *p1 = t->next, *q, *r;
  str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
  str->next = nullptr;  // 将结果串置为空串
  r = str;              // r指向新建链表的尾结点
  if (i <= 0 || i > Length(s) || j < 0 || i + j - 1 > Length(s)) {
    return str;  // 参数不正确时返回空串
  }
  for (int k = 0; k < i - 1; ++k) {  // 将s的前i-1个结点复制到str
    q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    q->data = p->data;
    q->next = nullptr;
    r->next = q;
    r = q;
    p = p->next;
  }
  for (int k = 0; k < j; ++k) {
    p = p->next;  // 将p沿next跳j个结点
  }
  while (p != nullptr) {
    q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    q->data = p->data;
    q->next = nullptr;
    r->next = q;
    r = q;
    p = p->next;
  }
  r->next = nullptr;
  return str;
}

void DispStr(LinkStrNode *s) {
  LinkStrNode *p = s->next;
  while (p != nullptr) {
    printf("%c", p->data);
  }
  printf("\n");
}
