#ifndef SORT_H_
#define SORT_H_
typedef int KeyType;
typedef char InfoType;
typedef struct {
  KeyType key;
  InfoType data;
} RecType;

// 1.直接插入排序
void InsertSort(RecType[], int);
// 2.折半插入排序
void BinInsertSort(RecType[], int);
// 3.希尔排序
void ShellSort(RecType[], int);
// 4.冒泡排序
void BubbleSort(RecType[], int);
// 5.改进冒泡排序
void BubbleSortWithFlag(RecType[], int);
// 6.快速排序
void QuickSort(RecType[], int, int);
// 7.简单选择排序
void SelectSort(RecType[], int);
// 8.堆排序

// 9.归并排序
void MergeSort(RecType[], int, int, int);
#endif