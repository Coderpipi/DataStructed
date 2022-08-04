#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_

typedef int ElemType;
typedef struct DNode {
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
} DLinkNode;

// 1.使用头插法建立双链表
void CreateListF(DLinkNode *&, ElemType[], int);

// 2.使用尾插法建立双链表
void CreateListR(DLinkNode *&, ElemType[], int);

// 3.插入元素
bool ListInsert(DLinkNode *&, int, ElemType);

// 4.删除元素
bool ListDelete(DLinkNode *&, int, ElemType);

#endif