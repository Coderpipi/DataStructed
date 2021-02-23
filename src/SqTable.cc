#include "SqTable.h"

#include <algorithm>
#include <cstdio>
#include <cstdlib>
void createList(SqList *&L, ElemType a[], int n) {
  int i = 0, k = 0;
  L = (SqList *)malloc(sizeof(SqList));
  while (i < n) {
    L->data[k] = a[i];
    k++;
    i++;
  }
  L->length = n;
}

void InitList(SqList *&L) {
  L = (SqList *)malloc(sizeof(SqList));
  L->length = 0;
}

void DestroyList(SqList *&L) {
  free(L);
  L = nullptr;
}

bool ListIsEmpty(SqList *&L) { return L->length == 0; }

int ListLength(SqList *&L) { return L->length; }

void DispList(SqList *&L) {
  for (int i = 0; i < L->length; i++) {
    printf("%d", L->data[i]);
  }
  printf("\n");
}

bool GetElem(SqList *&L, int i, ElemType &e) {
  if (i < 1 || i > L->length) {
    return false;
  }

  e = L->data[i - 1];
  return true;
}

int LocateElem(SqList *&L, ElemType e) {
  int i = 0;
  while (i < L->length && e != L->data[i]) {
    i++;
  }
  if (i >= L->length) {
    return -1;
  } else {
    return i;
  }
}

bool ListInsert(SqList *&L, int i, ElemType e) {
  int j;
  if (i < 1 || i > L->length + 1) {
    return false;  // 参数i错误返回false ,
                   // 只能插在第1个元素后和最后一个元素及以前
  }
  i--;  // 将物理序号 转换为线性表的逻辑序号
  for (j = L->length; j > i; j--) {
    L->data[j] = L->data[j - 1];  // 将元素全部往后移一位
  }
  L->data[i] = e;  // 将元素放在对应的位置
  L->length++;     // 顺序表长度+1
  return true;
}

bool ListDelete(SqList *&L, int i, ElemType &e) {
  int j;
  if (i < 1 || i > L->length + 1) {
    return false;  // i 参数错误返回false
  }
  i--;             // 将物理序号转换为逻辑序号
  e = L->data[i];  // 存储这个被删除的元素
  for (j = i; j < L->length; j++) {
    L->data[j] = L->data[j + 1];  // 将每个元素都向前移一位
  }
  L->length--;
  return true;
}
void delnode1(SqList *&L, ElemType x) {
  int k = 0, i;
  for (i = 0; i < L->length; i++) {
    if (L->data[i] != x) {
      L->data[k] = L->data[i];
      k++;
    }
  }
  L->length = k;  // 将长度变成k
}

void delnode2(SqList *&L, ElemType x) {
  int i = 0, k = 0;
  while (i < L->length) {
    if (L->data[i] == x) {
      k++;
    } else {
      L->data[i - k] = L->data[i];
    }
    i++;
  }

  L->length -= k;  // 将顺序表的长度-k
}

void partitional(SqList *&L) {
  int i = 0, j = L->length - 1;
  ElemType privot = L->data[0];
  while (i < j) {
    // 开始查找大于他的元素的索引
    while (i < j && L->data[j] > privot) {
      j--;
    }
    while (i < j && L->data[i] <= privot) {
      i++;
    }
    if (i < j)  // 如果找到了就交换两个元素
    {
      swap(L->data[i], L->data[j]);
    }
  }
  swap(L->data[i], L->data[0]);  // 可能会第i个元素比0小, 交换data[i] 和 data[0]
}
