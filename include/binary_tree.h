#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#define MAX 50
typedef char ElemType;
typedef struct node {
    ElemType data;  // 数据元素
    node *lchild;   // 左节点
    node *rchild;   // 右节点
} BTNode;

// 1.创建二叉树
void CreateBTree(BTNode *&, const char *);

// 2.销毁二叉树
void DestoryBTree(BTNode *&);

// 3.查找结点
BTNode *FindNode(BTNode *, ElemType);

// 4.求数的高度
int BTHeight(BTNode *);

// 5.输出二叉树
void DispBTree(BTNode *b);

// 6.二叉树的先序遍历
void PreOrder(BTNode *);

// 7.二叉树的中序遍历
void InOrder(BTNode *);

// 8.二叉树的后序遍历
void PostOrder(BTNode *);

// 9.返回结点在树中的高度
int Level(BTNode *, ElemType, int);

// 10.输出值为x的所有祖先
bool ancestor(BTNode *, ElemType);

// 11.先序遍历的非递归算法
void PerOrderWithNoRecursion1(BTNode *);

void PerOrderWithNoRecursion2(BTNode *);

// 12.中序遍历非递归算法
void InOrderWithNoRecursion(BTNode *);

// 13.后序遍历非递归算法
void PostOrderWithNoRecursion(BTNode *);

// 14.层次遍历
void LevelOrder(BTNode *);

// 15.根据先序遍历和中序遍历还原整个树
BTNode *CreateBTreeByPreAndIn(char *, char *, int);

// 16.根据后序遍历和中序遍历还原整个树
BTNode *CreateBTreeByPostAndIn(char *, char *, int);

#endif