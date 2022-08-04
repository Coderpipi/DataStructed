/**
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
| FILENAME: graph
|
| FILETYPE: CPP
|
| DESCRIPTION: 图有关的各种操作
|
| AUTHOR: LBW
|
| EMAIL: 2582482991@qq.com
|
| CREATETIME: 2021-02-23
|
| MODIFYTIME: 2021-02-23
|
| VERSION: 1.0-SNAPSHOT
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#include "graph.h"

#include <cstdio>
#include <cstdlib>

#include "sq_queue.h"

int visit[MAXV]{0};  // 访问元素标记, 0代表未被访问, 1代表已被访问过

void CreateGraph(AdjGraph *&G, int A[MAXV][MAXV], int n, int e) {
    ArcNode *p;
    constexpr int kInfinity = 32767;
    G = (AdjGraph *) malloc(sizeof(AdjGraph));
    for (int i = 0; i < n; ++i) {
        // 给邻接表的所有头结点指针域赋初值
        G->adjlist[i].firstarc = nullptr;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            if (A[i][j] != 0 && A[i][j] != kInfinity) {
                p = (ArcNode *) malloc(sizeof(AdjGraph));
                p->adjvex = j;
                p->weight = A[i][j];
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
            }
        }
    }
    G->n = n;
    G->e = e;
}

void DispGraph(AdjGraph *G) {
    ArcNode *p;
    for (int i = 0; i < G->n; ++i) {
        p = G->adjlist[i].firstarc;
        printf("%3d:", i);
        while (p != nullptr) {
            printf("%3d[%d]→", p->adjvex, p->weight);
            p = p->nextarc;
        }
    }
    printf("Λ\n");
}

void DestoryAdj(AdjGraph *&G) {
    ArcNode *pre, *p;
    for (int i = 0; i < G->n; ++i) {
        pre = G->adjlist[i].firstarc;
        if (pre != nullptr) {
            p = pre->nextarc;
            while (p != nullptr) {
                free(pre);
                pre = p;
                p = p->nextarc;
            }
            free(pre);
        }
    }
    free(G);
}

void DFS(AdjGraph *G, int v) {
    ArcNode *p;
    visit[v] = 1;  // 置已访问标记
    printf("%d", v);
    p = G->adjlist[v].firstarc;
    while (p != nullptr) {
        if (visit[p->adjvex] == 0) {
            // 如果该结点还未被访问过,访问该节点
            DFS(G, p->adjvex);
            p = p->nextarc;  // 指向下一个邻接结点
        }
    }
}

void BFS(AdjGraph *G, int v) {
    ElemType w;
    ArcNode *p;
    SqQueue *qu;
    InitQueue(qu);
    int visited[MAXV];
    for (int i = 0; i < G->n; ++i) {
        visited[i] = 0;
        printf("%2d", v);
        visited[v] = 1;
        offer(qu, v);
        while (!IsEmpty(qu)) {
            poll(qu, w);
            p = G->adjlist[w].firstarc;
            while (p != nullptr) {
                if (visited[p->adjvex] == 0) {
                    printf("%2d", p->adjvex);
                    visited[p->adjvex] = 1;
                    poll(qu, p->adjvex);
                }
                p = p->nextarc;
            }
        }
    }
    printf("\n");
}