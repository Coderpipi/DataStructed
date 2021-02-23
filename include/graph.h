#ifndef DATASTRUCTED_GRAPH_H_
#define DATASTRUCTED_GRAPH_H_
#define MAXV 50
typedef struct ANode {
  int adjvex;             // 该边的临界点编号
  struct ANode *nextarc;  // 指向下一条边的指针
  int weight;             // 该边的相关信息,如权值
} ArcNode;                // 边结点类型
typedef struct Vnode {
  int info;           // 定点的其他信息
  ArcNode *firstarc;  // 指向第一个边结点
} VNode;              // 邻接表的头结点类型
typedef struct {
  VNode adjlist[MAXV];  // 邻接表的头结点数组
  int n, e;             // 图中的顶点数n和边数e
} AdjGraph;             // 完整的图邻接表类型
// 1.创建图
void CreateGraph(AdjGraph *&, int[MAXV][MAXV], int, int);
// 2.输出图的算法
void DispGraph(AdjGraph *);
// 3.销毁图的算法
void DestotyAdj(AdjGraph *&);
// 4.深度优先遍历
void DFS(AdjGraph *, int);
// 5.广度优先遍历
void BFS(AdjGraph *, int);
#endif