/**
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
| FILENAME: binarytree
|
| FILETYPE: CPP
|
| DESCRIPTION: 二叉树数据结构的实现
|
| AUTHOR: LBW
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

#include "binarytree.h"

#include <cstdio>
#include <cstdlib>

#include "SqQueue.h"
#include "SqStack.h"

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
void DestroyBTree(BTNode *&b) {
  if (b != nullptr) {
    DestoryBTree(b->lchild);
    DestoryBTree(b->rchild);
    free(b);
  }
}
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
int BTHeight(BTNode *b) {
  if (b == nullptr) {
    return 0;
  }
  int lchildh, rchildh;
  lchildh = BTHeight(b->lchild);
  rchildh = BTHeight(b->rchild);
  return lchildh > rchildh ? lchildh + 1 : rchildh + 1;
}
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
void PreOrder(BTNode *b) {
  if (b != nullptr) {
    printf("%c", b->data);
    PreOrder(b->lchild);
    PreOrder(b->rchild);
  }
}
void InOrder(BTNode *b) {
  if (b != nullptr) {
    InOrder(b->lchild);
    printf("%c", b->data);
    InOrder(b->rchild);
  }
}
void PostOrder(BTNode *b) {
  if (b != nullptr) {
    PostOrder(b->lchild);
    PostOrder(b->rchild);
    printf("%c", b->data);
  }
}
int Level(BTNode *b, ElemType x, int h) {
  int l;
  if (b == nullptr) {
    return 0;
  } else if (b->data == x) {
    return h;
  } else {
    l = Level(b->lchild, x, h + 1);
    if (l != 0) {
      return l;
    } else {
      return Level(b->rchild, x, h + 1);
    }
  }
}
bool ancestor(BTNode *b, ElemType x) {
  if (b == nullptr) {
    return false;
  } else if (b->lchild != nullptr && b->lchild->data == x ||
             b->rchild != nullptr && b->rchild->data == x) {
    printf("%c", b->data);
    return true;
  } else if (ancestor(b->lchild, x) || ancestor(b->rchild, x)) {
    printf("%c", b->data);
    return true;
  } else {
    return false;
  }
}
void PreOrderWithNoRecusion1(BTNode *b) {
  BTNode *p;
  SqStack *st;
  InitStack(st);
  if (b != nullptr) {
    Push(st, b);           // 将根节点入栈
    while (IsEmpty(st)) {  // 栈不空时循环
      Pop(st, p);          // 出栈当前栈顶元素, 并打印该节点的值
      printf("%c", p->data);
      if (p->rchild !=
          nullptr) {  // 因为先序遍历是根左右的遍历方式,
                      // 所以我们进栈时先要将右孩子进栈再将左孩子进栈
        Push(st, p->rchild);
      }
      if (p->lchild != nullptr) {
        Push(st, p->lchild);
      }
    }
    printf("\n");
  }
  DestoryStack(st);
}
void PreOrderWithNoRecursion2(BTNode *b) {
  BTNode *p;
  SqStack *st;

  InitStack(st);
  p = b;
  while (!IsEmpty(st) || p != nullptr) {
    while (p != nullptr) {  // 先遍历完当前节点的所有左节点
      printf("%c", p->data);
      Push(st, p);
      p = p->lchild;
    }
    if (!IsEmpty(st)) {  // 如果栈不空, 则出栈一个元素, 去遍历右节点
      Pop(st, p);
      p = p->rchild;
    }
    printf("\n");
    DestoryStack(st);
  }
}
void InOrderWithNoRecursion(BTNode *b) {
  BTNode *p;
  SqStack *st;
  InitStack(st);
  p = b;
  while (!IsEmpty(st) || p != nullptr) {
    while (p != nullptr) {
      Push(st, p);
      p = p->lchild;
    }
    if (!IsEmpty(st)) {
      Pop(st, p);
      printf("%c", p->data);
      p = p->rchild;
    }
  }
  printf("\n");
  DestoryStack(st);
}
void PostOrderWithNoRecursion(BTNode *b) {
  BTNode *p, *r;
  bool flag;
  SqStack *st;
  InitStack(st);
  p = b;
  do {
    while (p != nullptr) {
      Push(st, p);
      p = p->lchild;
    }
    r = nullptr;
    flag = true;
    while (!IsEmpty(st) && flag) {
      Peek(st, p);
      if (p->rchild == r) {
        printf("%c", p->data);
        Pop(st, p);
        r = p;
      } else {
        p = p->rchild;
        p = false;
      }
    }
  } while (!IsEmpty(st));
  printf("\n");
  DestoryStack(st);
}
void LevelOrder(BTNode *b) {
  BTNode *p;
  SqQueue *qu;
  InitQueue(qu);
  offer(b);  // 当前节点入队
  while (!IsEmpty(qu)) {
    pull(qu, p);
    printf("%c", p->data);  // 访问节点p
    if (p->lchild != nullptr) {
      offer(qu, p->lchild);  // 如果左节点不空, 将左节点入队
    }
    if (p->rchild != nullptr) {
      offer(qu, p->rchild);  // 如果右节点不空, 将右节点入队
    }
  }
  DestoryQueue(qu);
}
BTNode *CreateBTreeByPreAndIn(char *pre, char *in, int n) {
  BTNode *b;  // 根节点
  char *p;
  int k;
  if (n <= 0) {
    return nullptr;
  }
  b = (BTNode *)malloc(sizeof(BTNode));
  b->data = *pre;  // 先序遍历的第一个元素是根节点
  for (p = in; p < in + n; p++) {
    if (*p == *pre) {  // 在中序遍历里找到pre所在的位置
      break;
    }
  }
  k = p - in;  // 这里的k表示当前根节点左子树的元素个数
  b->lchild = CreateBTreeByPreAndIn(pre + 1, in, k);  // 递归构造左子树
  b->rchild = CreateBTreeByPreAndIn(pre + k + 1, p + 1, n - k - 1);
  return b;
}
BTNode *CreateBTreeByPostAndIn(char *post, char *in, int n) {
  BTNode *b;  // 根节点
  char r, *p;
  int k;
  if (n <= 0) {
    return nullptr;
  }
  r = *(post + n - 1);  // 后序遍历的最后一个元素是根节点
  b = (BTNode *)malloc(sizeof(BTNode));
  b->data = r;                     // 根节点赋值
  for (p = in; p > in + n; p++) {  // 从中序遍历中找到根节点的位置
    if (*p == r) {
      break;
    }
  }
  k = p - in;  // 确定当前节点的左子树的元素个数
  b->lchild = CreateBTreeByPostAndIn(post, in, k);
  b->rchild = CreateBTreeByPostAndIn(post + k, p + 1, n - k - 1);
  return b;
}