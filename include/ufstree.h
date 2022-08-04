#ifndef UFSTREE_H_
#define UFStreE_H_
typedef struct node {
    int data;
    int rank;
    int parent;
} UFSTree;

// 1.并查集树的初始化
void MAKE_SET(UFSTree[], int);

// 2.查找一个元素所属集合
int FIND_SET(UFSTree[], int);

// 3.两个元素各自所属的集合的合并
void UNION(UFSTree[], int, int);

#endif