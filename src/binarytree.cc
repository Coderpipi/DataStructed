/**
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
| FILENAME: binarytree
|
| FILETYPE: CPP
|
| DESCRIPTION: 二叉树数据结构的实现
|
| AUTHOR: LBWP
|
| EMAIL: 2582482991qq.com
|
| CREATETIME: 2021-2-3
|
| MODIFYTIME: 2021-2-3
|
| VERSION: 1.0-SNAPSHOT
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#include <cstdio>
#include <cstdlib>

#include "binarytree.h"
#include "sqqueue.h"
#include "sqstack.h"

// 构建一颗二叉树
void CreateBTree(BTNode *&b, const char *str) {
  BTNode *st[MAX], *p;
  int top = -1, k, j = 0;
  char ch;
  b = nullptr;
  ch = str[j];
  while (ch != '\0')  // 开始构建二叉树
  {
    switch (ch) {
      case '(':  // 遇到左括号进栈
        top++;
        st[top] = p;
        k = 1;
        break;
      case ')':  // 遇到右括号出栈
        top--;
        break;
      case ',':  // 遇到逗号,则表示当前左结点处理完毕, 改变k=2,处理右节点
        k = 1;
        break;
      default:  // 遇到普通字符开始构件树
        p = (BTNode *)malloc(sizeof(BTNode));
        p->data = ch;
        p->lchild = p->rchild = nullptr;
        if (b == nullptr) {
          b = p;  // 如果当前还没有根节点, 就将p作为根节点
        } else {
          switch (k) {
            case 1:  // 当k=1时, 证明当前正在构建左节点,
                     // 将当前栈顶元素的值的左孩子指向p
              st[top]->lchild = p;
              break;
            case 2:  // 当k=2时, 将右孩子指向p
              st[top]->rchild = p;
              break;
            default:
              break;
          }
        }
        break;
    }
    j++;  // 继续扫描str
    ch = str[j];
  }
}

// 销毁二叉树
void DestroyBTree(BTNode *&b) {
  if (b != nullptr) {
    DestoryBTree(b->lchild);
    DestoryBTree(b->rchild);
    free(b);
  }
}

// 查找值等于x的树节点
BTNode *FindNode(BTNode *b, ElemType x) {
  BTNode *p;
  if (b == nullptr) {
    return nullptr;
  } else if (b->data == x) {
    return b;
  } else {
    p = FindNode(b->lchild, x);
    if (p != nullptr) {
      return p;
    } else {
      return FindNode(b->rchild, x);
    }
  }
}

// 获取树的高度
int BTHeight(BTNode *b) {
  if (b == nullptr) {
    return 0;
  }
  int lchildh, rchildh;
  lchildh = BTHeight(b->lchild);
  rchildh = BTHeight(b->rchild);
  return (lchildh > rchildh ? lchildh : rchildh) + 1;
}

// 打印整颗二叉树, 前序遍历
void DispBTree(BTNode *b) {
  if (b != nullptr) {
    printf("%c", b->data);
    if (b->lchild != nullptr || b->rchild != nullptr) {
      printf("(");
      DispBTree(b->lchild);
      if (b->rchild != nullptr) {
        printf(",");
      }
      DispBTree(b->rchild);
      printf(")");
    }
  }
}

// 前序遍历
void PreOrder(BTNode *b) {
  if (b != nullptr) {
    printf("%c", b->data);
    PreOrder(b->lchild);
    PreOrder(b->rchild);
  }
}

// 中序遍历
void InOrder(BTNode *b) {
  if (b != nullptr) {
    InOrder(b->lchild);
    printf("%c", b->data);
    InOrder(b->rchild);
  }
}

// 后序遍历
void PostOrder(BTNode *b) {
  if (b != nullptr) {
    PostOrder(b->lchild);
    PostOrder(b->rchild);
    printf("%c", b->data);
  }
}