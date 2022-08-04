#include <cstdio>
#include <cstdlib>
#include "linked_list.h"

void CreateListF(LinkNode *&L, ElemType a[], int n) {
    LinkNode *s;
    L = (LinkNode *) malloc(sizeof(LinkNode));
    L->next = nullptr;          // 头结点的next置空
    for (int i = 0; i < n; i++) // 循环建立链表
    {
        s = (LinkNode *) malloc(sizeof(LinkNode));
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }
}

void CreateListR(LinkNode *&L, ElemType a[], int n) {
    LinkNode *s, *r;
    L = (LinkNode *) malloc(sizeof(LinkNode));
    r = L;
    for (int i = 0; i < n; i++) {
        s = (LinkNode *) malloc(sizeof(LinkNode));
        s->data = a[i];
        r->next = s;
        r = s;
    }

    r->next = nullptr;
}

void InitList(LinkNode *&L) {
    L = (LinkNode *) malloc(sizeof(LinkNode));
    L->next = nullptr;
}

void DestoryList(LinkNode *&L) {
    LinkNode *pre = L, *p = L->next;
    while (p != nullptr) {
        free(pre);
        pre = p;
        p = p->next;
    }

    free(pre);
}

bool ListIsEmpty(LinkNode *&L) {
    return L->next == nullptr;
}

int ListLength(LinkNode *&L) {
    int n = 0;
    LinkNode *p = L;
    while (p != nullptr) {
        n++;
        p = p->next;
    }
    return n;
}

void DispList(LinkNode *&L) {
    LinkNode *p = L->next;
    while (p != nullptr) {
        printf("%d", p->data);
        p = p->next;
    }

    printf("\n");
}

bool GetElem(LinkNode *&L, int i, ElemType &e) {
    int j = 0;
    LinkNode *p = L;
    if (i <= 0) {
        return false;
    }
    while (j < i && p != nullptr) {
        i++;
        p = p->next;
    }
    if (p == nullptr) {
        return false;
    } else {
        e = p->data;
        return true;
    }
}

int LocateElem(LinkNode *&L, ElemType e) {
    int i = 1;
    LinkNode *p = L->next;
    while (p != nullptr && p->data != e) {
        p = p->next;
        i++;
    }
    if (p == nullptr) {
        return 0;
    } else {
        return i;
    }
}

bool ListInsert(LinkNode *&L, int i, ElemType e) {
    int j = 0;
    LinkNode *p = L, *s;
    if (i <= 0) {
        return false;
    }
    while (j < i && p != nullptr) {
        j++;
        p = p->next;
    }
    if (p == nullptr) {
        return false;
    } else {
        s = (LinkNode *) malloc(sizeof(LinkNode));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }
}

bool ListDelete(LinkNode *&L, int i, ElemType &e) {
    int j = 0;
    LinkNode *p = L, *q;
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
        p->next = q->next;
        free(q);
        return true;
    }
}

void delMaxNode(LinkNode *&L) {
    LinkNode *p = L->next, *pre = L, *maxp = p, *maxpre = pre;
    while (p != nullptr) {
        if (maxp->data < p->data) {
            maxp = p;
            maxpre = pre;
        }
        pre = p;
        p = p->next;
    }
    maxpre->next = maxp->next;
    free(maxp);
}