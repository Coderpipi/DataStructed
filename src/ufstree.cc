/**
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
| FILENAME: ufstree
|
| FILETYPE: CPP
|
| DESCRIPTION: 并查集的相关操作
|
| AUTHOR: LBW
|
| EMAIL: 2582482991qq.com
|
| CREATETIME:
|
| MODIFYTIME:
|
| VERSION: 1.0-SNAPSHOT
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
#include "ufstree.h"

void MAKE_SET(UFSTree t[], int n) {
    int i;
    for (i = 1; i <= n; i++) {
        t[i].data = i;
        t[i].rank = 0;
        t[i].parent = i;
    }
}

int FIND_SET(UFSTree t[], int x) {
    if (x != t[x].parent) {
        return FIND_SET(t, t[x].parent);
    } else {
        return x;
    }
}

void UNION(UFSTree t[], int x, int y) {
    x = FIND_SET(t, x);
    y = FIND_SET(t, y);
    if (t[x].rank > t[y].rank) {
        t[y].parent = x;
    } else {
        t[x].parent = y;
        if (t[x].rank == t[y].rank) {
            t[y].rank++;
        }
    }
}