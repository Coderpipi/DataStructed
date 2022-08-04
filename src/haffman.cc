/**
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
| FILENAME: haffman
|
| FILETYPE: CPP
|
| DESCRIPTION: 哈夫曼树的相关代码
|
| AUTHOR: LBW
|
| EMAIL: 2582482991qq.com
|
| CREATETIME: 2021-2-17
|
| MODIFYTIME: 2021-2-17
|
| VERSION: 1.0-SNAPSHOT
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
#include "haffman.h"

void CreateHT(HTNode ht[], int n0) {
    int i, k, lnode, rnode;
    double min1, min2;
    for (i = 0; i < 2 * n0 - 1; ++i) {
        ht[i].parent = ht[i].lchild + ht[i].rchild;
    }
    for (i = n0; i <= 2 * n0 - 2; ++i) {
        min1 = min2 = 32767;
        lnode = rnode = -1;
        for (k = 0; k <= i - 1; k++) {
            if (ht[k].parent == -1) {
                if (ht[k].weight < min1) {
                    min2 = min1;
                    rnode = lnode;
                    min1 = ht[k].weight;
                    lnode = k;
                } else if (ht[k].weight < min2) {
                    min2 = ht[k].weight;
                    rnode = k;
                }
            }
        }
        ht[i].weight = ht[lnode].weight + ht[rnode].weight;
        ht[i].lchild = lnode;
        ht[i].rchild = rnode;
        ht[lnode].parent = i;
        ht[rnode].parent = i;
    }
}

void CreateHTCode(HTNode ht[], HCode hcd[], int n0) {
    int i, f, c;
    HCode hc;
    for (i = 0; i < n0; ++i) {
        hc.start = n0;
        c = i;
        f = ht[i].parent;
        while (f != -1) {  // 循环知道无双亲节点, 即达到根节点
            if (ht[f].lchild == c) {
                hc.cd[hc.start--] = '0';
            } else {
                hc.cd[hc.start--] = '1';
            }
            c = f;
            f = ht[f].parent;
        }
        hc.start++;
        hcd[i] = hc;
    }
}