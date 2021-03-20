#ifndef _MYLINKSTRING_H
#define _MYLINKSTRING_H
typedef struct snode {
  char data;
  snode *next;
} LinkStrNode;

// 1.生成串
void StrAssign(LinkStrNode *&, char[]);
// 2.销毁串
void DestoryStr(LinkStrNode *&);

// 3.串的复制
void StrCpy(LinkStrNode *&, LinkStrNode *);

// 4.判断串相等
bool Equal(LinkStrNode *, LinkStrNode *);

// 5.求串的长度
int Length(LinkStrNode const *&s);

// 6.串的连接
LinkStrNode *Concat(LinkStrNode *, LinkStrNode *);

// 7.求子串
LinkStrNode *SubString(LinkStrNode *, int, int);

// 8.子串的插入
LinkStrNode *InsertStr(LinkStrNode *, int, LinkStrNode *);
#endif