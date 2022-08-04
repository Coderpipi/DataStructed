#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
typedef int ElemType;
typedef struct LNode {
    ElemType data;      // 存放数据
    struct LNode *next; // 指向后继结点
} LinkNode;           // 单链表结点

// 1. 头插法建立单链表
void CreateListF(LinkNode *&, ElemType[], int);

// 2. 尾插法建立单链表
void CreateListR(LinkNode *&, ElemType[], int);

// 3.初始化线性表
void InitList(LinkNode *&);

// 4.销毁线性表
void DestotyList(LinkNode *&);

// 5.判断线性表是否为空表
bool ListIsEmpty(LinkNode *&);

// 6.求线性表的长度
int ListLength(LinkNode *&);

// 7.输出线性表
void DispList(LinkNode *&);

// 8.求线性表中某个下标的数据元素值
bool GetElem(LinkNode *&, int, ElemType);

// 9.按元素值查找
int LocateElem(LinkNode *&, ElemType);

// 10. 插入数据元素
bool ListInsert(LinkNode *&, int, ElemType);

// 11. 删除数据元素
bool ListDelete(LinkNode *&, int, ElemType);

// 应用: 找到单链表中的元素值最大的一个结点,并删除该节点
void delMaxNode(LinkNode *&);

#endif