#ifndef HAFFMAN_H_
#define HAFFMAN_H_
#define N 100
typedef struct {
  char data;
  double weight;
  int parent;
  int lchild;
  int rchild;
} HTNode;
typedef struct {
  char cd[N];
  int start;
} HCode;
void CreateHT(HTNode[], int);
void CreateHTCode(HTNode[], HCode[], int n0);
#endif