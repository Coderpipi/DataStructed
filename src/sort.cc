/**
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
| FILENAME: sort
|
| FILETYPE: CPP
|
| DESCRIPTION: 各种排序的实现
|
| AUTHOR: LBW
|
| EMAIL: 2582482991@qq.com
|
| CREATETIME: 2021-02-20
|
| MODIFYTIME: 2021-02-20
|
| VERSION: 1.0-SNAPSHOT
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
#include "sort.h"

#include <iostream>

using namespace std;

void InsertSort(RecType R[], int n) {
  int j;
  RecType tmp;
  for (int i = 1; i < n; i++) {
    if (R[i].key < R[i - 1].key) {
      tmp = R[i];  // 如果当前元素需要排序, 保存当前元素
      j = i - 1;   // 记录当前下标
      do {
        R[j + 1] = R[j];  // 所有元素向后移动
        j--;
      } while (j >= 0 && R[j].key > tmp.key);
      R[j + 1] = tmp;  // 将元素放在j+1处
    }
  }
}
void BinInsertSort(RecType R[], int n) {
  int j, low, high;
  RecType tmp;
  for (int i = 0; i < n; i++) {
    if (R[i].key < R[i - 1].key) {
      tmp = R[i];  // 如果当前的元素需要排序,将其保存起来
      low = 0;
      high = n - 1;
      while (low <= high) {
        int mid = low + ((high - low) >> 1);
        if (tmp.key < R[mid].key) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
      for (j = i - 1; j >= high + 1; --j) {
        R[j + 1] = R[j];
      }
      R[high + 1] = tmp;
    }
  }
}
void ShellSort(RecType R[], int n) {
  int j;
  int d = n / 2;
  RecType tmp;
  while (d > 0) {
    for (int i = d; i < n; i++) {
      tmp = R[i];
      j = i - d;
      while (j >= 0 && tmp.key < R[j].key) {
        R[j + d] = R[j];
        j -= d;
      }
      R[j + d] = tmp;
    }
    d /= 2;
  }
}
void BubbleSort(RecType R[], int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = n - 1; j > i; --j) {
      if (R[j].key < R[j - 1].key) {
        auto tmp = R[j];
        R[j] = R[j - 1];
        R[j - 1] = tmp;
      }
    }
  }
}
void BubbleSortWithFlag(RecType R[], int n) {
  for (int i = 0; i < n; ++i) {
    bool flag = false;  // 指定一个标志位,
    //如果某一趟排序中该标志位没有变化, 说明已经排序好,直接返回即可
    for (int j = n - 1; j > i; --j) {
      if (R[j].key < R[j - 1].key) {
        auto tmp = R[j];
        R[j] = R[j - 1];
        R[j - 1] = tmp;
        flag = true;
      }
    }
    if (!flag) {
      return;
    }
  }
}
void QuickSort(RecType R[], int start, int end) {
  int left = start;
  int right = end;
  RecType tmp = R[start];
  if (left > right) return;
  while (left < right) {
    while (left < right && R[right].key >= tmp.key) {
      --right;
    }
    while (left < right && R[left].key <= tmp.key) {
      ++left;
    }
    if (left < right) {
      RecType t = R[left];
      R[left] = R[right];
      R[right] = t;
    }
  }
  R[start] = R[left];
  R[left] = tmp;

  QuickSort(R, start, left - 1);  // 递归处理左半部分
  QuickSort(R, left + 1, end);    // 递归处理右半部分
}
void SelectSort(RecType R[], int n) {
  int k;
  for (int i = 0; i < n; i++) {
    k = i;
    for (int j = i + 1; j < n; j++) {
      if (R[j].key < R[k].key) {
        k = j;
      }
      if (k != i) {
        auto tmp = R[k];
        R[k] = R[i];
        R[i] = tmp;
      }
    }
  }
}
void sift(RecType R[], int low, int high) {
  int i = low;
  int j = 2 * i;
  RecType tmp = R[i];
  while (j < high) {
    if (j < high && R[j].key < R[j + 1].key) {
      ++j;
    }
    if (tmp.key < R[j].key) {
      R[i] = R[j];
      i = j;
      j = 2 * i;
    } else {
      break;
    }
  }
  R[i] = tmp;
}
void HeapSort(RecType R[], int n) {
  for (int i = n / 2; i >= 1; --i) {  // 循环建立初始堆, 调用n / 2次sift算法
    sift(R, i, n);
  }
  for (int i = n; i >= 2;
       --i) {  // 因为共有n个元素, 构建初始大顶堆时已经产生了一个排序好的元素,
               // 对剩余的n-1个元素再重新构造堆
    swap(R[1], R[i]);  // 将最后一个元素与R[1]交换, 因为堆顶元素是排好序的元素,
    sift(R, 1, i - 1);  // 对[1..i-1]来重新构造堆, 得到i-1个结点的堆
  }
}
void MergeSort(RecType R[], int low, int mid, int high) {
  RecType *R1;
  int i = low;
  int j = mid + 1;
  int k = 0;
  R1 = (RecType *)malloc(sizeof(RecType) * (high - low + 1));
  while (i <= mid && j <= high) {
    if (R[i].key <= R[j].key) {
      R1[k] = R[i];
      ++i;
      ++k;
    } else {
      R1[k] = R[j];
      ++j;
      ++k;
    }
  }
  while (i <= mid) {
    R1[k] = R[i];
    ++i;
    ++k;
  }
  while (j <= high) {
    R1[k] = R[j];
    ++j;
    ++k;
  }
  for (k = 0, i = low; i <= high; ++k, ++i) {
    R[i] = R1[k];
  }
  free(R1);
}